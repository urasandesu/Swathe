/* 
 * File: AssemblyResolver.h
 * 
 * Author: Akira Sugiura (urasandesu@gmail.com)
 * 
 * 
 * Copyright (c) 2014 Akira Sugiura
 *  
 *  This software is MIT License.
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */


#pragma once
#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYRESOLVER_H
#define URASANDESU_SWATHE_METADATA_ASSEMBLYRESOLVER_H

#ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYRESOLVERFWD_H
#include <Urasandesu/Swathe/Metadata/AssemblyResolverFwd.h>
#endif

#ifndef URASANDESU_SWATHE_FUSION_PLATFORM_H
#include <Urasandesu/Swathe/Fusion/Platform.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata { 
    
    namespace AssemblyResolverDetail {
    
        using boost::filesystem::path;
        using boost::unordered_map;
        using boost::unordered_set;
        using std::vector;
        using std::wstring;
        using Urasandesu::CppAnonym::Utilities::AutoPtr;
        using Urasandesu::CppAnonym::Utilities::Hash;
        using Urasandesu::CppAnonym::Utilities::EqualTo;
        using Urasandesu::Swathe::Fusion::Platform;

        template<class FusionInfoType>
        class AssemblyResolver : 
            boost::noncopyable
        {
        public: 
            typedef AssemblyResolver<FusionInfoType> this_type;
            
            AssemblyResolver() : 
                m_pFuInfo(nullptr)
            { }
            
            void Initialize(FusionInfoType const *pFuInfo)
            { 
                using boost::filesystem::current_path;

                _ASSERTE(!m_pFuInfo);
                _ASSERTE(pFuInfo);
                m_pFuInfo = pFuInfo;
                
                m_searchDirs.push_back(current_path());
                m_filteredSearchDirs.insert(current_path());
            }
            
            path Resolve(wstring const &fullName, vector<ProcessorArchitecture> &procArchs) const
            {
                using boost::remove_reference;
                using Urasandesu::Swathe::Fusion::NewAssemblyNameFlags;
                using Urasandesu::Swathe::Fusion::AssemblyCacheFlags;
                
                _ASSERTE(!fullName.empty());

                auto pCondition = m_pFuInfo->NewAssemblyName(fullName, NewAssemblyNameFlags::NANF_CANOF_PARSE_DISPLAY_NAME);
                auto pAsmNames = m_pFuInfo->EnumerateAssemblyName(pCondition, AssemblyCacheFlags::ACF_GAC);
                
                typedef remove_reference<decltype(*pAsmNames->end())>::type AssemblyName;
                auto orderedAsmNames = vector<AssemblyName>(pAsmNames->begin(), pAsmNames->end());
                sort(orderedAsmNames, [](AssemblyName const &x, AssemblyName const &y) { return x->GetVersion() < y->GetVersion(); });
                
                // NOTE: 'candidates' is overridden by the latest version assembly if there are multiple candidates.
                auto candidates = unordered_map<Platform, AssemblyName, Hash<Platform>, EqualTo<Platform> >();
                BOOST_FOREACH (auto const &pAsmName, orderedAsmNames)
                    candidates[pAsmName->GetPlatform()] = pAsmName;

                return candidates.empty() ? 
                            ResolveAssemblyPathBySearchDirectory(this, pCondition->GetName()) : 
                            ResolveAssemblyPathByGAC(this, candidates, procArchs);
            }
            
            void AddSearchDirectory(path const &searchDir)
            {
                auto result = m_filteredSearchDirs.insert(searchDir);
                if (result.second)
                    m_searchDirs.push_back(searchDir);
            }

        private:
            static Platform ToPlatform(ProcessorArchitecture const &procArchs)
            {
                using Urasandesu::CppAnonym::CppAnonymNotSupportedException;

                switch (procArchs.Value())
                {
                    case ProcessorArchitecture::PA_INTEL:
                        return Platform::PF_I386;
                    case ProcessorArchitecture::PA_IA64:
                        return Platform::PF_IA64;
                    case ProcessorArchitecture::PA_AMD64:
                        return Platform::PF_AMD64;
                    case ProcessorArchitecture::PA_MSIL:
                        return Platform::PF_MSIL;
                    default:
                        BOOST_THROW_EXCEPTION(CppAnonymNotSupportedException());
                }
            }

            static path ResolveAssemblyPathBySearchDirectory(this_type const *_this, wstring const &name)
            {
                using boost::filesystem::exists;
                using Urasandesu::CppAnonym::CppAnonymArgumentException;

                auto location = path();
                auto &searchDirs = _this->m_searchDirs;
                BOOST_FOREACH (auto const &searchDir, searchDirs)
                {
                    location = searchDir / (name + L".dll");
                    if (exists(location))
                        return location;
                    
                    location = searchDir / (name + L".exe");
                    if (exists(location))
                        return location;
                }
                
                auto oss = std::wostringstream();
                oss << L"The designated assembly is not found: " << name << std::endl;
                BOOST_FOREACH (auto const &searchDir, searchDirs)
                    oss << L"    Considering \"" << searchDir.native() << L"\"..." << std::endl;
                BOOST_THROW_EXCEPTION(CppAnonymArgumentException(oss.str()));
            }
            
            template<class AssemblyNameType>    
            static path ResolveAssemblyPathByGAC(this_type const *_this, unordered_map<Platform, AutoPtr<AssemblyNameType>, Hash<Platform>, EqualTo<Platform> > const &candidates, vector<ProcessorArchitecture> &procArchs)
            {
                using boost::adaptors::transformed;        
                using Urasandesu::CppAnonym::CppAnonymCOMException;
                using Urasandesu::CppAnonym::Collections::FindIf;
                using Urasandesu::Swathe::Fusion::AssemblyQueryTypes;

                auto const *pFuInfo = _this->m_pFuInfo;

                if (candidates.size() == 1)
                {
                    auto pAsmName = (*candidates.begin()).second;
                    auto pAsmCache = pFuInfo->NewAssemblyCache();
                    auto pAsmInfo = pAsmCache->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, pAsmName->GetFullName());
                    return pAsmInfo->GetAssemblyPath();
                }
                else
                {
                    if (procArchs.empty())
                    {
                        procArchs.resize(2);
#ifdef _M_IX86
                        procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_INTEL);
                        procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
#else
                        procArchs[0] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_AMD64);
                        procArchs[1] = ProcessorArchitecture(PROCESSOR_ARCHITECTURE_MSIL);
#endif
                    }

                    _ASSERTE(!procArchs.empty());
                    auto isTarget = [&](Platform const &platform) { return candidates.find(platform) != candidates.end(); };
                    auto result = FindIf(procArchs | transformed(ToPlatform), isTarget);
                    if (!result)
                        BOOST_THROW_EXCEPTION(CppAnonymCOMException(ERROR_FILE_NOT_FOUND));

                    auto pAsmName = candidates.at(*result);
                    auto pAsmCache = pFuInfo->NewAssemblyCache();
                    auto pAsmInfo = pAsmCache->QueryAssemblyInfo(AssemblyQueryTypes::AQT_DEFAULT, pAsmName->GetFullName());
                    return pAsmInfo->GetAssemblyPath();
                }
            }
            
            FusionInfoType const *m_pFuInfo;
            vector<path> m_searchDirs;
            unordered_set<path, Hash<path>, EqualTo<path> > m_filteredSearchDirs;
        };

    }   // namespace AssemblyResolverDetail {
    
}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {

#endif  // #ifndef URASANDESU_SWATHE_METADATA_ASSEMBLYRESOLVER_H
