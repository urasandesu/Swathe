/* 
 * File: Signature.cpp
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



#include "stdafx.h"

#ifndef URASANDESU_SWATHE_METADATA_SIGNATURE_H
#include <Urasandesu/Swathe/Metadata/Signature.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IDISPENSER_H
#include <Urasandesu/Swathe/Metadata/IDispenser.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IASSEMBLY_H
#include <Urasandesu/Swathe/Metadata/IAssembly.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMODULE_H
#include <Urasandesu/Swathe/Metadata/IModule.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHOD_H
#include <Urasandesu/Swathe/Metadata/IMethod.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPARAMETER_H
#include <Urasandesu/Swathe/Metadata/IParameter.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IMETHODBODY_H
#include <Urasandesu/Swathe/Metadata/IMethodBody.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IPROPERTY_H
#include <Urasandesu/Swathe/Metadata/IProperty.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ILOCAL_H
#include <Urasandesu/Swathe/Metadata/ILocal.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ITYPE_H
#include <Urasandesu/Swathe/Metadata/IType.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_IFIELD_H
#include <Urasandesu/Swathe/Metadata/IField.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_ICUSTOMATTRIBUTE_H
#include <Urasandesu/Swathe/Metadata/ICustomAttribute.h>
#endif

#ifndef URASANDESU_SWATHE_METADATA_METADATASPECIALVALUES_H
#include <Urasandesu/Swathe/Metadata/MetadataSpecialValues.h>
#endif

namespace Urasandesu { namespace Swathe { namespace Metadata {

    namespace SignatureDetail {

        using boost::array;
        using boost::apply_visitor;
        using boost::blank;
        using boost::is_same;
        using boost::mpl::and_;
        using boost::mpl::not_;
        using boost::static_visitor;
        using boost::variant;
        using std::wstring;
        using Urasandesu::CppAnonym::SafeEnum;
        using Urasandesu::CppAnonym::SafeFlagsEnum;        

        typedef boost::mpl::bool_<false> False;

        
        namespace PutterDetail {

            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PutterHasIterator, iterator);
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(PutterHasValueType, value_type);

            template<class SignatureHolder>
            struct PutImplForPointer;

        }   // namespace PutterDetail {



        struct Putter
        {
            Putter(SimpleBlob& sb) : 
                m_sb(sb) 
            { }
            
            template<class SignatureHolder>
            Putter& operator <<(SignatureHolder const &v)
            {
                typedef PutterDetail::PutImplForPointer<SignatureHolder> Impl;
                Impl::Put(m_sb, v);
                return *this;
            }

            SimpleBlob& m_sb;
        };



        template<class T>
        Putter operator <<(SimpleBlob& blob, T const &v)
        {
            return Putter(blob) << v;
        }



        namespace PutterDetail {

            struct PutElemFromArgumentVisitor : 
                static_visitor<>
            {
                PutElemFromArgumentVisitor(SimpleBlob &sb, IType const *pType) : 
                    m_sb(sb), 
                    m_pType(pType)
                { }

                template<class T>
                void operator ()(T const &v) const
                {
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_VOID);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_STRING);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_PTR);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_BYREF);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_VALUETYPE);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_CLASS);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_VAR);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_ARRAY);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_GENERICINST);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_TYPEDBYREF);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_I);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_U);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_FNPTR);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_OBJECT);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_SZARRAY);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_MVAR);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_CMOD_REQD);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_CMOD_OPT);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_INTERNAL);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_MAX);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_MODIFIER);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_SENTINEL);
                    _ASSERTE(m_pType->GetKind() != TypeKinds::TK_PINNED);
                    //_ASSERTE(m_pType->GetKind() != TypeKinds::TK_R4_HFA);
                    //_ASSERTE(m_pType->GetKind() != TypeKinds::TK_R8_HFA);
                    m_sb.Put<T>(v); // TypeKinds::TK_BOOLEAN
                }

                template<>
                void operator ()<blank>(blank const &v) const
                {
                    // nop
                }

                template<>
                void operator ()<wstring>(wstring const &s) const
                {
                    _ASSERTE(m_pType->GetKind() == TypeKinds::TK_STRING);
                    m_sb << 
                        s
                    ;
                }

                template<>
                void operator ()<IType const *>(IType const *const &pType) const
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(m_pType->GetFullName()));
                    //auto const &fullName = pType->GetFullName();
                    //m_sb.Put<BYTE>(fullName.size());
                    //m_sb.Put(fullName.c_str(), fullName.size());
                }

                mutable SimpleBlob &m_sb;
                IType const *m_pType;
            };



            template<class T>
            struct CompressedCount
            {
                typedef T value_type;
            
                explicit CompressedCount(vector<T> &data) : 
                    m_data(data)
                { }

                explicit CompressedCount(vector<T> const &data) : 
                    m_data(const_cast<vector<T> &>(data))
                { }

                vector<T> &m_data;
            };

            template<class T>
            CompressedCount<T> CompressCount(vector<T> &data)
            {
                return CompressedCount<T>(data);
            }

            template<class T>
            CompressedCount<T> CompressCount(vector<T> const &data)
            {
                return CompressedCount<T>(data);
            }

            struct CompressToken
            {
                explicit CompressToken(mdToken mdt) : 
                    m_mdt(mdt) 
                { }
            
                mdToken m_mdt;
            };

            struct CompressData
            {
                explicit CompressData(ULONG data) : 
                    m_data(data)
                { }
            
                ULONG m_data;
            };

            template<class T>
            struct HeldData
            {
                typedef T value_type;
            
                explicit HeldData(T &data) : 
                    m_data(data) 
                { }
            
                T &m_data;
            };
        
            template<class T>
            HeldData<T> HoldData(T &data)
            {
                return HeldData<T>(data);
            }

            template<class T>
            struct Counted
            {
                typedef T value_type;

                explicit Counted(vector<T> &data) : 
                    m_data(data)
                { }

                vector<T> &m_data;
            };

            template<class T>
            Counted<T> Count(vector<T> &data)
            {
                return Counted<T>(data);
            }
        
            struct FixedArg
            {
                FixedArg(IType const *pType, CustomAttributeArgument const &arg) : 
                    m_pType(pType), 
                    m_arg(arg)
                { }

                IType const *m_pType;
                CustomAttributeArgument m_arg;
            };

            struct FixedArgs
            {
                explicit FixedArgs(ICustomAttribute const *pCa) : 
                    m_pCa(pCa)
                { }
            
                ICustomAttribute const *m_pCa;
            };

            struct Elem
            {
                Elem(IType const *pType, CustomAttributeArgument const &arg) : 
                    m_pType(pType), 
                    m_arg(arg)
                { }

                IType const *m_pType;
                CustomAttributeArgument m_arg;
            };
        
            struct NamedArgs
            {
                explicit NamedArgs(ICustomAttribute const *pCa) : 
                    m_pCa(pCa)
                { }
            
                ICustomAttribute const *m_pCa;
            };

            struct NamedArg
            {
                explicit NamedArg(BYTE fieldOrPropKind, IType const *pFieldOrPropType, wstring const &name, CustomAttributeArgument const &arg) : 
                    m_fieldOrPropKind(fieldOrPropKind), 
                    m_pFieldOrPropType(pFieldOrPropType), 
                    m_name(name), 
                    m_arg(arg)
                { }

                BYTE m_fieldOrPropKind;
                IType const *m_pFieldOrPropType;
                wstring m_name;
                CustomAttributeArgument m_arg;
            };



            template<class T>
            struct PutImplForAnother
            {
                static void Put(SimpleBlob &sb, T const &v)
                {
                    BOOST_MPL_ASSERT_RELATION(sizeof(COR_SIGNATURE), ==, sizeof(T));
                    sb.Put<COR_SIGNATURE>(v);
                }
            };

            template<class T>
            struct PutImplForAnother<CompressedCount<T> >
            {
                static void Put(SimpleBlob &sb, CompressedCount<T> const &c)
                {
                    auto data = array<BYTE, 4>();
                    auto length = ::CorSigCompressData(static_cast<ULONG>(c.m_data.size()), data.c_array());
                    _ASSERTE(length != static_cast<ULONG>(-1));
                    for (auto i = data.begin(), i_end = i + length; i != i_end; ++i)
                        sb.Put<COR_SIGNATURE>(*i);
                }
            };

            template<>
            struct PutImplForAnother<CompressToken>
            {
                static void Put(SimpleBlob &sb, CompressToken const &c)
                {
                    auto data = array<BYTE, 4>();
                    auto length = ::CorSigCompressToken(c.m_mdt, data.c_array());
                    _ASSERTE(length != static_cast<ULONG>(-1));
                    for (auto i = data.begin(), i_end = i + length; i != i_end; ++i)
                        sb.Put<COR_SIGNATURE>(*i);
                }
            };

            template<>
            struct PutImplForAnother<CompressData>
            {
                static void Put(SimpleBlob &sb, CompressData const &v)
                {
                    auto data = array<BYTE, 4>();
                    auto length = ::CorSigCompressData(v.m_data, data.c_array());
                    _ASSERTE(length != static_cast<ULONG>(-1));
                    for (auto i = data.begin(), i_end = i + length; i != i_end; ++i)
                        sb.Put<COR_SIGNATURE>(*i);
                }
            };

            template<class T>
            struct PutImplForAnother<HeldData<T> >
            {
                static void Put(SimpleBlob &sb, HeldData<T> const &h)
                {
                    sb.Put<typename HeldData<T>::value_type>(h.m_data);
                }
            };

            template<>
            struct PutImplForAnother<FixedArgs>
            {
                static void Put(SimpleBlob &sb, FixedArgs const &f)
                {
                    auto const pCa = f.m_pCa;
                    auto const *pCtor = pCa->GetConstructor();
                    auto const &params = pCtor->GetParameters();
                    auto const &constructorArgs = pCa->GetConstructorArguments();
                    _ASSERTE(params.size() == constructorArgs.size());
                    for (auto i = 0ul; i < params.size(); i++)
                    {
                        auto const *pParam = params[i];
                        auto const *pParamType = pParam->GetParameterType();
                        auto const &constructorArg = constructorArgs[i];

                        sb << 
                            FixedArg(pParamType, constructorArg)
                        ;
                    }
                }
            };

            template<>
            struct PutImplForAnother<FixedArg>
            {
                static void Put(SimpleBlob &sb, FixedArg const &f)
                {
                    auto const *pType = f.m_pType;
                    auto const &arg = f.m_arg;
                    auto kind = pType->GetKind();
                    if (kind == TypeKinds::TK_SZARRAY)
                    {
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                    }
                    else
                    {
                        sb <<
                            Elem(pType, arg)
                        ;
                    }
                }
            };

            template<>
            struct PutImplForAnother<Elem>
            {
                static void Put(SimpleBlob &sb, Elem const &e)
                {
                    apply_visitor(PutElemFromArgumentVisitor(sb, e.m_pType), e.m_arg);
                }
            };

            template<>
            struct PutImplForAnother<NamedArgs>
            {
                static void Put(SimpleBlob &sb, NamedArgs const &n)
                {
                    auto const *pCa = n.m_pCa;
                    // Properties
                    {
                        auto const &namedProperties = pCa->GetNamedProperties();
                        auto const &propertyValues = pCa->GetPropertyValues();
                        _ASSERTE(namedProperties.size() == propertyValues.size());
                        for (auto i = 0ul; i < namedProperties.size(); i++)
                        {
                            auto const *pProp = namedProperties[i];
                            auto const &propertyValue = propertyValues[i];

                            sb <<
                                NamedArg(SERIALIZATION_TYPE_PROPERTY, pProp->GetPropertyType(), pProp->GetName(), propertyValue)
                            ;
                        }
                    }

                    // Fields
                    {
                        auto const &namedFields = pCa->GetNamedFields();
                        auto const &fieldValues = pCa->GetFieldValues();
                        _ASSERTE(namedFields.size() == fieldValues.size());
                        for (auto i = 0ul; i < namedFields.size(); i++)
                        {
                            auto const *pField = namedFields[i];
                            auto const &fieldValue = fieldValues[i];

                            sb <<
                                NamedArg(SERIALIZATION_TYPE_FIELD, pField->GetFieldType(), pField->GetName(), fieldValue)
                            ;
                        }
                    }
                }
            };

            template<>
            struct PutImplForAnother<NamedArg>
            {
                static void Put(SimpleBlob &sb, NamedArg const &n)
                {
                    sb << 
                        HoldData(n.m_fieldOrPropKind) << 
                        n.m_pFieldOrPropType << 
                        n.m_name << 
                        FixedArg(n.m_pFieldOrPropType, n.m_arg)
                    ;
                }
            };

            template<>
            struct PutImplForAnother<wstring>
            {
                static void Put(SimpleBlob &sb, wstring const &s)
                {
                    using ATL::CW2A;
                    using std::string;

                    auto _s = string(CW2A(s.c_str()));
                    sb.Put<BYTE>(static_cast<BYTE>(_s.size()));
                    sb.Put(_s.c_str(), _s.size());
                }
            };

            template<class EnumDef, class EnumType>
            struct PutImplForAnother<SafeEnum<EnumDef, EnumType> >
            {
                static void Put(SimpleBlob &sb, SafeEnum<EnumDef, EnumType> const &e)
                {
                    sb.Put<COR_SIGNATURE>(e.Value());
                }
            };

            template<class EnumDef, class EnumType>
            struct PutImplForAnother<SafeFlagsEnum<EnumDef, EnumType> >
            {
                static void Put(SimpleBlob &sb, SafeFlagsEnum<EnumDef, EnumType> const &e)
                {
                    sb.Put<COR_SIGNATURE>(e.Value());
                }
            };



            template<class SignatureHolder, class IsSequence>
            struct PutImplForSequence
            {
                static void Put(SimpleBlob &sb, SignatureHolder const &sigs)
                {
                    typedef PutImplForPointer<typename SignatureHolder::value_type> Impl;
                    for (auto i = sigs.begin(), i_end = sigs.end(); i != i_end; ++i)
                        Impl::Put(sb, *i);
                }
            };

            template<class SignatureHolder>
            struct PutImplForSequence<SignatureHolder, False>
            {
                static void Put(SimpleBlob &sb, SignatureHolder const &sigHolder)
                {
                    typedef PutImplForAnother<SignatureHolder> Impl;
                    Impl::Put(sb, sigHolder);
                }
            };



            template<class SignatureHolder>
            struct PutImplForPointer
            {
                static void Put(SimpleBlob &sb, SignatureHolder const &sigHolder)
                {
                    typedef CPP_ANONYM_HAS_MEMBER_TYPE(PutterHasIterator, SignatureHolder)::type HasIterator;
                    typedef CPP_ANONYM_HAS_MEMBER_TYPE(PutterHasValueType, SignatureHolder)::type HasValueType;
                    typedef and_<HasIterator, HasValueType, not_<is_same<SignatureHolder, wstring> > >::type IsSequence;
                    typedef PutImplForSequence<SignatureHolder, IsSequence> Impl;
                    Impl::Put(sb, sigHolder);
                }
            };

            template<class SignatureHolder>
            struct PutImplForPointer<SignatureHolder *>
            {
                static void Put(SimpleBlob &sb, SignatureHolder const *pSigHolder)
                {
                    auto const &sig = pSigHolder->GetSignature();
                    auto const &blob = sig.GetBlob();
                    for (auto i = blob.begin(), i_end = blob.end(); i != i_end; ++i)
                        sb.Put<COR_SIGNATURE>(*i);
                }
            };

        }   // namespace PutterDetail {



        typedef variant<
            blank, 
            IType const *, 
            IMethod const *, 
            IMethodBody const *, 
            IProperty const *, 
            IField const *, 
            ICustomAttribute const *
        > SignatureProvider;

        namespace TakerDetail {

            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TakerHasIterator, iterator);
            CPP_ANONYM_DECLARE_HAS_MEMBER_TYPE(TakerHasValueType, value_type);

            template<class SignatureHolder>
            struct TakeImplForPointer;

        }   // namespace TakerDetail {



        struct Taker
        {
            Taker(vector<COR_SIGNATURE> const &blob, SignatureProvider const &provider) : 
                m_blob(blob), 
                m_index(0), 
                m_provider(provider)
            { }
            
            template<class SignatureHolder>
            Taker& operator >>(SignatureHolder &v)
            {
                typedef TakerDetail::TakeImplForPointer<SignatureHolder> Impl;
                Impl::Take(m_provider, m_blob, m_index, v);
                return *this;
            }

            vector<COR_SIGNATURE> const &m_blob;
            SIZE_T m_index;
            SignatureProvider m_provider;
        };

        struct _TakerWithIndex
        {
            _TakerWithIndex(vector<COR_SIGNATURE> const &blob, SIZE_T &index) : 
                m_blob(blob), 
                m_index(index)
            { }

            vector<COR_SIGNATURE> const &m_blob;
            SIZE_T &m_index;
        };

        struct TakerWithIndex
        {
            TakerWithIndex(vector<COR_SIGNATURE> const &blob, SIZE_T &index, SignatureProvider const &provider) : 
                m_blob(blob), 
                m_index(index), 
                m_provider(provider)
            { }
            
            template<class SignatureHolder>
            TakerWithIndex& operator >>(SignatureHolder &v)
            {
                typedef TakerDetail::TakeImplForPointer<SignatureHolder> Impl;
                Impl::Take(m_provider, m_blob, m_index, v);
                return *this;
            }

            vector<COR_SIGNATURE> const &m_blob;
            SIZE_T &m_index;
            SignatureProvider m_provider;
        };



        Taker operator ,(vector<COR_SIGNATURE> const &blob, SignatureProvider const &provider)
        {
            return Taker(blob, provider);
        }

        _TakerWithIndex operator ,(vector<COR_SIGNATURE> const &blob, SIZE_T &index)
        {
            return _TakerWithIndex(blob, index);
        }

        TakerWithIndex operator ,(_TakerWithIndex taker, SignatureProvider const &provider)
        {
            return TakerWithIndex(taker.m_blob, taker.m_index, provider);
        }



        namespace TakerDetail {

            struct GetTargetAssemblyVisitor : 
                static_visitor<IAssembly const *>
            {
                template<class T>
                IAssembly const *operator ()(T const &v) const
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }

                template<>
                IAssembly const *operator ()<IType const *>(IType const *const &pType) const
                {
                    auto const *pAsm = pType->GetAssembly();
                    return pAsm->GetTargetAssembly();
                }

                template<>
                IAssembly const *operator ()<IMethod const *>(IMethod const *const &pMethod) const
                {
                    auto const *pAsm = pMethod->GetAssembly();
                    return pAsm->GetTargetAssembly();
                }

                template<>
                IAssembly const *operator ()<IMethodBody const *>(IMethodBody const * const &pBody) const
                {
                    auto const *pAsm = pBody->GetAssembly();
                    return pAsm->GetTargetAssembly();
                }
            };
            
            struct GetAssemblyVisitor : 
                static_visitor<IAssembly const *>
            {
                template<class T>
                IAssembly const *operator ()(T const &v) const
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }

                template<>
                IAssembly const *operator ()<IType const *>(IType const *const &pType) const
                {
                    return pType->GetAssembly();
                }

                template<>
                IAssembly const *operator ()<IMethod const *>(IMethod const *const &pMethod) const
                {
                    return pMethod->GetAssembly();
                }

                template<>
                IAssembly const *operator ()<IProperty const *>(IProperty const *const &pProp) const
                {
                    return pProp->GetAssembly();
                }

                template<>
                IAssembly const *operator ()<IMethodBody const *>(IMethodBody const *const &pBody) const
                {
                    return pBody->GetAssembly();
                }
            };

            struct GetParameterVisitor : 
                static_visitor<IParameter const *>
            {
                GetParameterVisitor(ULONG position, IType const *pParamType) : 
                    m_position(position), 
                    m_pParamType(pParamType)
                { }

                template<class T>
                IParameter const *operator ()(T const &v) const
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }

                template<>
                IParameter const *operator ()<IMethod const *>(IMethod const *const &pMethod) const
                {
                    return pMethod->GetParameter(m_position, m_pParamType);
                }

                ULONG m_position;
                IType const *m_pParamType;
            };

            struct GetLocalVisitor : 
                static_visitor<ILocal const *>
            {
                GetLocalVisitor(ULONG index, IType const *pLocalType) : 
                    m_index(index), 
                    m_pLocalType(pLocalType)
                { }

                template<class T>
                ILocal const *operator ()(T const &v) const
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }

                template<>
                ILocal const *operator ()<IMethodBody const *>(IMethodBody const *const &pBody) const
                {
                    return pBody->GetLocal(m_index, m_pLocalType);
                }

                ULONG m_index;
                IType const *m_pLocalType;
            };
                        
            struct GetCustomAttributeVisitor : 
                static_visitor<ICustomAttribute const *>
            {
                template<class T>
                ICustomAttribute const *operator ()(T const &v) const
                {
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }

                template<>
                ICustomAttribute const *operator ()<blank>(blank const &) const
                {
                    return nullptr;
                }

                template<>
                ICustomAttribute const *operator ()<ICustomAttribute const *>(ICustomAttribute const *const &pCa) const
                {
                    return pCa;
                }
            };



            template<class T>
            struct CompressedCount
            {
                typedef T value_type;
            
                explicit CompressedCount(vector<T> &data) : 
                    m_data(data)
                { }

                explicit CompressedCount(vector<T> const &data) : 
                    m_data(const_cast<vector<T> &>(data))
                { }

                vector<T> &m_data;
            };

            template<class T>
            CompressedCount<T> CompressCount(vector<T> &data)
            {
                return CompressedCount<T>(data);
            }

            template<class T>
            CompressedCount<T> CompressCount(vector<T> const &data)
            {
                return CompressedCount<T>(data);
            }

            struct CompressToken
            {
                explicit CompressToken(mdToken mdt) : 
                    m_mdt(mdt) 
                { }
            
                mdToken m_mdt;
            };

            struct CompressData
            {
                explicit CompressData(ULONG &data) : 
                    m_data(data)
                { }
            
                ULONG &m_data;
            };

            template<class T>
            struct HeldData
            {
                typedef T value_type;
            
                explicit HeldData(T &data) : 
                    m_data(data) 
                { }
            
                T &m_data;
            };
        
            template<class T>
            HeldData<T> HoldData(T &data)
            {
                return HeldData<T>(data);
            }

            template<class T>
            struct Counted
            {
                typedef T value_type;

                explicit Counted(vector<T> &data) : 
                    m_data(data)
                { }

                vector<T> &m_data;
            };

            template<class T>
            Counted<T> Count(vector<T> &data)
            {
                return Counted<T>(data);
            }
        
            struct FixedArg
            {
                FixedArg(IType const *pType, CustomAttributeArgument &arg) : 
                    m_pType(pType), 
                    m_arg(arg)
                { }

                IType const *m_pType;
                CustomAttributeArgument &m_arg;
            };

            struct FixedArgs
            {
                explicit FixedArgs(vector<CustomAttributeArgument> &constructorArgs) : 
                    m_constructorArgs(constructorArgs)
                { }
            
                vector<CustomAttributeArgument> &m_constructorArgs;
            };

            struct Elem
            {
                Elem(IType const *pType, CustomAttributeArgument &arg) : 
                    m_pType(pType), 
                    m_arg(arg)
                { }

                IType const *m_pType;
                CustomAttributeArgument &m_arg;
            };
        
            struct NamedArgs
            {
                NamedArgs(USHORT numNamed, vector<IProperty const *> &namedProps, vector<CustomAttributeArgument> &propValues, vector<IField const *> &namedFields, vector<CustomAttributeArgument> &fieldValues) : 
                    m_numNamed(numNamed), 
                    m_namedProps(namedProps), 
                    m_propValues(propValues), 
                    m_namedFields(namedFields), 
                    m_fieldValues(fieldValues)
                { }
            
                USHORT m_numNamed;
                vector<IProperty const *> &m_namedProps;
                vector<CustomAttributeArgument> &m_propValues;
                vector<IField const *> &m_namedFields;
                vector<CustomAttributeArgument> &m_fieldValues;
            };

            struct NamedArg
            {
                explicit NamedArg(BYTE fieldOrPropKind, IType const *pFieldOrPropType, wstring const &name, CustomAttributeArgument const &arg) : 
                    m_fieldOrPropKind(fieldOrPropKind), 
                    m_pFieldOrPropType(pFieldOrPropType), 
                    m_name(name), 
                    m_arg(arg)
                { }

                BYTE m_fieldOrPropKind;
                IType const *m_pFieldOrPropType;
                wstring m_name;
                CustomAttributeArgument m_arg;
            };

            struct Params
            {
                explicit Params(vector<IParameter const *> &params) : 
                    m_params(params)
                { }

                vector<IParameter const *> &m_params;
            };

            struct Param
            {
                explicit Param(ULONG position, IParameter const *&pParam) : 
                    m_position(position), 
                    m_pParam(pParam)
                { }

                ULONG m_position;
                IParameter const *&m_pParam;
            };

            struct RetType
            {
                explicit RetType(IType const *&pRetType) : 
                    m_pRetType(pRetType)
                { }

                IType const *&m_pRetType;
            };

            struct Locals
            {
                explicit Locals(vector<ILocal const *> &locals) : 
                    m_locals(locals)
                { }

                vector<ILocal const *> &m_locals;
            };

            struct Local
            {
                explicit Local(ULONG index, ILocal const *&pLocal) : 
                    m_index(index), 
                    m_pLocal(pLocal)
                { }

                ULONG m_index;
                ILocal const *&m_pLocal;
            };



            template<class T>
            struct TakeImplForAnother
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, T &v)
                {
                    using boost::is_same;
                    using boost::mpl::identity;
                    BOOST_MPL_ASSERT((is_same<identity<T>::type, int>));

                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
    //                 BOOST_MPL_ASSERT_RELATION(sizeof(COR_SIGNATURE), ==, sizeof(T));
    //                 sb.Take<COR_SIGNATURE>(v);
                }
            };

            template<class T>
            struct TakeImplForAnother<HeldData<T> >
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, HeldData<T> &v)
                {
                    typedef typename HeldData<T>::value_type Value;
                    v.m_data = *reinterpret_cast<Value const *>(&blob[index]);
                    index += sizeof(Value);

                    if (8 <= index && 0 < v.m_data)
                    {
                        auto oss = std::wostringstream();
                        oss << L"Data: ";
                        oss << v.m_data;
                        oss << L", Index: ";
                        oss << index;
                        oss << std::endl;
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
                    }
                }
            };

            template<>
            struct TakeImplForAnother<FixedArgs>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, FixedArgs &v)
                {
                    auto const *pCa = apply_visitor(GetCustomAttributeVisitor(), provider);
                    auto const *pCtor = pCa->GetConstructor();
                    auto const &params = pCtor->GetParameters();
                    auto &constructorArgs = v.m_constructorArgs;
                    constructorArgs.resize(params.size());
                    for (auto i = 0ul; i < params.size(); i++)
                    {
                        auto const *pParam = params[i];
                        auto const *pParamType = pParam->GetParameterType();
                        auto &constructorArg = constructorArgs[i];

                        (blob, index, pCa) >> 
                            FixedArg(pParamType, constructorArg)
                        ;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<FixedArg>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, FixedArg &v)
                {
                    auto const *pCa = apply_visitor(GetCustomAttributeVisitor(), provider);
                    auto const *pType = v.m_pType;
                    auto &arg = v.m_arg;
                    auto kind = pType->GetKind();
                    if (kind == TypeKinds::TK_SZARRAY)
                    {
                        BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                    }
                    else
                    {
                        (blob, index, pCa) >> 
                            Elem(pType, arg)
                        ;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<Elem>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, Elem &v)
                {
                    auto const *pCa = apply_visitor(GetCustomAttributeVisitor(), provider);
                    auto const *pType = v.m_pType;
                    auto &arg = v.m_arg;
                    auto kind = pType->GetKind();
                    switch (kind.Value())
                    {
                        case TypeKinds::TK_U4:
                            {
                                arg = *reinterpret_cast<UINT const *>(&blob[index]);
                                index += sizeof(UINT);
                            }
                            break;

                        default:
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                            break;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<NamedArgs>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, NamedArgs &v)
                {
                    if (v.m_numNamed <= 0u)
                        return;

                    //auto const *pCa = n.m_pCa;
                    //// Properties
                    //{
                    //    auto const &namedProperties = pCa->GetNamedProperties();
                    //    auto const &propertyValues = pCa->GetPropertyValues();
                    //    _ASSERTE(namedProperties.size() == propertyValues.size());
                    //    for (auto i = 0ul; i < namedProperties.size(); i++)
                    //    {
                    //        auto const *pProp = namedProperties[i];
                    //        auto const &propertyValue = propertyValues[i];

                    //        sb <<
                    //            NamedArg(SERIALIZATION_TYPE_PROPERTY, pProp->GetPropertyType(), pProp->GetName(), propertyValue)
                    //        ;
                    //    }
                    //}

                    //// Fields
                    //{
                    //    auto const &namedFields = pCa->GetNamedFields();
                    //    auto const &fieldValues = pCa->GetFieldValues();
                    //    _ASSERTE(namedFields.size() == fieldValues.size());
                    //    for (auto i = 0ul; i < namedFields.size(); i++)
                    //    {
                    //        auto const *pField = namedFields[i];
                    //        auto const &fieldValue = fieldValues[i];

                    //        sb <<
                    //            NamedArg(SERIALIZATION_TYPE_FIELD, pField->GetFieldType(), pField->GetName(), fieldValue)
                    //        ;
                    //    }
                    //}
                    BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                }
            };

            template<class T>
            struct TakeImplForAnother<CompressedCount<T> >
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, CompressedCount<T> &c)
                {
                    auto count = 0ul;
                    index += ::CorSigUncompressData(&blob[index], &count);
                    if (0ul < count)
                        c.m_data.resize(count);
                }
            };

            template<>
            struct TakeImplForAnother<CompressData>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, CompressData &c)
                {
                    auto pos = 0ul;
                    index += ::CorSigUncompressData(&blob[index], &pos);
                    c.m_data = pos;
                }
            };

            template<class EnumDef, class EnumType>
            struct TakeImplForAnother<SafeFlagsEnum<EnumDef, EnumType> >
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, SafeFlagsEnum<EnumDef, EnumType> &v)
                {
                    v = SafeFlagsEnum<EnumDef, EnumType>(blob[index++]);
                }
            };

            template<class EnumDef, class EnumType>
            struct TakeImplForAnother<SafeEnum<EnumDef, EnumType> >
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, SafeEnum<EnumDef, EnumType> &v)
                {
                    v = SafeEnum<EnumDef, EnumType>(blob[index++]);
                }
            };

            template<>
            struct TakeImplForAnother<Params>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, Params &v)
                {
                    auto &params = v.m_params;
                    for (auto i = 0ul; i < params.size(); ++i)
                    {
                        (blob, index, provider) >> 
                            Param(i + 1, params[i])
                        ;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<Param>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, Param &v)
                {
                    auto kind = TypeKinds(TypeKinds::TK_UNREACHED);
                    auto _index = ::CorSigUncompressElementType(&blob[index], reinterpret_cast<CorElementType *>(&kind));
                    switch (kind.Value())
                    {
                        case TypeKinds::TK_BYREF:
                            {
                                index += _index;
                                auto const *pType = static_cast<IType *>(nullptr);

                                (blob, index, provider) >> 
                                    pType
                                ;

                                auto const *pParam = apply_visitor(GetParameterVisitor(v.m_position, pType->MakeByRefType()), provider);
                                v.m_pParam = pParam;
                            }
                            break;
                        
                        case TypeKinds::TK_TYPEDBYREF:
                        default:
                            {
                                auto const *pType = static_cast<IType *>(nullptr);
                                
                                (blob, index, provider) >> 
                                    pType
                                ;
                                
                                auto const *pParam = apply_visitor(GetParameterVisitor(v.m_position, pType), provider);
                                v.m_pParam = pParam;
                            }
                            break;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<RetType>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, RetType &v)
                {
                    auto kind = TypeKinds(TypeKinds::TK_UNREACHED);
                    auto _index = ::CorSigUncompressElementType(&blob[index], reinterpret_cast<CorElementType *>(&kind));
                    switch (kind.Value())
                    {
                        case TypeKinds::TK_BYREF:
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                            break;
                        
                        case TypeKinds::TK_TYPEDBYREF:
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                            break;
                        
                        case TypeKinds::TK_VOID:
                            {
                                index += _index;
                                auto const *pAsm = apply_visitor(GetAssemblyVisitor(), provider);
                                auto const *pMSCorLib = pAsm->GetAssembly(MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB, pAsm->GetProcessorArchitectures());
                                auto const *pMSCorLibDll = pMSCorLib->GetMainModule();
                                v.m_pRetType = pMSCorLibDll->GetType(MetadataSpecialValues::ToTypeName(kind));
                            }
                            break;

                        default:
                            (blob, index, provider) >> 
                                v.m_pRetType
                            ;
                            break;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<Locals>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, Locals &v)
                {
                    auto &locals = v.m_locals;
                    for (auto i = 0ul; i < locals.size(); ++i)
                    {
                        (blob, index, provider) >> 
                            Local(i, locals[i])
                        ;
                    }
                }
            };

            template<>
            struct TakeImplForAnother<Local>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, Local &v)
                {
                    auto kind = TypeKinds(TypeKinds::TK_UNREACHED);
                    auto _index = ::CorSigUncompressElementType(&blob[index], reinterpret_cast<CorElementType *>(&kind));
                    switch (kind.Value())
                    {
                        case TypeKinds::TK_BYREF:
                            {
                                index += _index;
                                auto const *pType = static_cast<IType *>(nullptr);

                                (blob, index, provider) >> 
                                    pType
                                ;

                                auto const *pLocal = apply_visitor(GetLocalVisitor(v.m_index, pType->MakeByRefType()), provider);
                                v.m_pLocal = pLocal;
                            }
                            break;
                        
                        case TypeKinds::TK_TYPEDBYREF:
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                            break;
                        
                        case TypeKinds::TK_SENTINEL:
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException());
                            break;
                        
                        case TypeKinds::TK_PINNED:
                            {
                                index += _index;
                                auto const *pTmpLocal = static_cast<ILocal *>(nullptr);

                                (blob, index, provider) >> 
                                    Local(v.m_index, pTmpLocal)
                                ;

                                auto const *pLocal = apply_visitor(GetLocalVisitor(v.m_index, pTmpLocal->GetLocalType()->MakePinnedType()), provider);
                                v.m_pLocal = pLocal;
                            }
                            break;

                        default:
                            {
                                auto const *pType = static_cast<IType *>(nullptr);
                                
                                (blob, index, provider) >> 
                                    pType
                                ;
                                
                                auto const *pLocal = apply_visitor(GetLocalVisitor(v.m_index, pType), provider);
                                v.m_pLocal = pLocal;
                            }
                            break;
                    }
                }
            };



            template<class SignatureHolder, class IsSequence>
            struct TakeImplForSequence
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, SignatureHolder &sigs)
                {
                    typedef typename SignatureHolder::value_type Value;
                    typedef TakeImplForPointer<Value> Impl;
                    for (auto i = 0ul; i < sigs.size(); ++i)
                    {
                        auto v = Value();
                        Impl::Take(provider, blob, index, v);
                        sigs[i] = v;
                    }
                }
            };

            template<class SignatureHolder>
            struct TakeImplForSequence<SignatureHolder, False>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, SignatureHolder &sigHolder)
                {
                    typedef TakeImplForAnother<SignatureHolder> Impl;
                    Impl::Take(provider, blob, index, sigHolder);
                }
            };



            template<class SignatureHolder>
            struct TakeImplForPointer
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, SignatureHolder &sigHolder)
                {
                    typedef CPP_ANONYM_HAS_MEMBER_TYPE(TakerHasIterator, SignatureHolder)::type HasIterator;
                    typedef CPP_ANONYM_HAS_MEMBER_TYPE(TakerHasValueType, SignatureHolder)::type HasValueType;
                    typedef and_<HasIterator, HasValueType, not_<is_same<SignatureHolder, wstring> > >::type IsSequence;
                    typedef TakeImplForSequence<SignatureHolder, IsSequence> Impl;
                    Impl::Take(provider, blob, index, sigHolder);
                }
            };

            template<>
            struct TakeImplForPointer<IType const *>
            {
                static void Take(SignatureProvider const &provider, vector<COR_SIGNATURE> const &blob, SIZE_T &index, IType const *&pType)
                {
                    auto kind = TypeKinds(TypeKinds::TK_UNREACHED);
                    index += ::CorSigUncompressElementType(&blob[index], reinterpret_cast<CorElementType *>(&kind));
                    switch (kind.Value())
                    {
                        case TypeKinds::TK_VOID:
                        case TypeKinds::TK_BOOLEAN:
                        case TypeKinds::TK_CHAR:
                        case TypeKinds::TK_I1:
                        case TypeKinds::TK_U1:
                        case TypeKinds::TK_I2:
                        case TypeKinds::TK_U2:
                        case TypeKinds::TK_I4:
                        case TypeKinds::TK_U4:
                        case TypeKinds::TK_I8:
                        case TypeKinds::TK_U8:
                        case TypeKinds::TK_R4:
                        case TypeKinds::TK_R8:
                        case TypeKinds::TK_STRING:
                        case TypeKinds::TK_TYPEDBYREF:
                        case TypeKinds::TK_I:
                        case TypeKinds::TK_OBJECT:
                            {
                                auto const *pAsm = apply_visitor(GetAssemblyVisitor(), provider);
                                auto const *pMSCorLib = pAsm->GetAssembly(MetadataSpecialValues::ASSEMBLY_FULL_NAME_OF_MSCORLIB, pAsm->GetProcessorArchitectures());
                                auto const *pMSCorLibDll = pMSCorLib->GetMainModule();
                                pType = pMSCorLibDll->GetType(MetadataSpecialValues::ToTypeName(kind));
                            }
                            break;

                        case TypeKinds::TK_PTR:
                            {
                                auto const *pType_ = static_cast<IType *>(nullptr);
                                
                                (blob, index, provider) >> 
                                    pType_
                                ;

                                pType = pType_->MakePointerType();
                            }
                            break;

                        case TypeKinds::TK_CLASS:
                        case TypeKinds::TK_VALUETYPE:
                            {
                                auto const *pAsm = apply_visitor(GetTargetAssemblyVisitor(), provider);
                                if (!pAsm)
                                    pAsm = apply_visitor(GetAssemblyVisitor(), provider);
                                _ASSERTE(pAsm);
                                auto mdt = mdTokenNil;
                                index += ::CorSigUncompressToken(&blob[index], &mdt);
                                pType = pAsm->GetType(mdt);
                            }
                            break;

                        case TypeKinds::TK_GENERICINST:
                            {
                                auto const *pType_ = static_cast<IType *>(nullptr);
                                auto genericArgs_ = vector<IType const *>();
                                
                                (blob, index, provider) >> 
                                    pType_ >> 
                                    CompressCount(genericArgs_) >> 
                                    genericArgs_
                                ;

                                pType = pType_->MakeGenericType(genericArgs_);
                            }
                            break;

                        case TypeKinds::TK_SZARRAY:
                            {
                                auto const *pType_ = static_cast<IType *>(nullptr);
                                
                                (blob, index, provider) >> 
                                    pType_
                                ;

                                pType = pType_->MakeArrayType();
                            }
                            break;

                        case TypeKinds::TK_VAR:
                            {
                                auto const *pAsm = apply_visitor(GetTargetAssemblyVisitor(), provider);
                                if (!pAsm)
                                    pAsm = apply_visitor(GetAssemblyVisitor(), provider);
                                _ASSERTE(pAsm);
                                auto pos = 0ul;
                                index += ::CorSigUncompressData(&blob[index], &pos);
                                pType = pAsm->GetGenericTypeParameter(pos);
                            }
                            break;

                        case TypeKinds::TK_MVAR:
                            {
                                auto const *pAsm = apply_visitor(GetTargetAssemblyVisitor(), provider);
                                if (!pAsm)
                                    pAsm = apply_visitor(GetAssemblyVisitor(), provider);
                                _ASSERTE(pAsm);
                                auto pos = 0ul;
                                index += ::CorSigUncompressData(&blob[index], &pos);
                                pType = pAsm->GetGenericMethodParameter(pos);
                            }
                            break;

                        default:
                            {
                                auto oss = std::wostringstream();
                                oss << boost::wformat(L"kind.Value():  %|1$02X|") % kind.Value();
                                BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
                            }
                            break;
                    }
                }
            };

        }   // namespace TakerDetail {



        class SignatureImplPimpl
        {
        public:
            SignatureImplPimpl(SignatureImpl *pClass) : 
                m_pClass(pClass) 
            { }



            void Encode(IType const *pType)
            {
                using namespace PutterDetail;

                _ASSERTE(pType);

                auto sb = SimpleBlob();

                auto kind = pType->GetKind();
                switch (kind.Value())
                {
                    case TypeKinds::TK_VOID:
                    case TypeKinds::TK_BOOLEAN:
                    case TypeKinds::TK_CHAR:
                    case TypeKinds::TK_I1:
                    case TypeKinds::TK_U1:
                    case TypeKinds::TK_I2:
                    case TypeKinds::TK_U2:
                    case TypeKinds::TK_I4:
                    case TypeKinds::TK_U4:
                    case TypeKinds::TK_I8:
                    case TypeKinds::TK_U8:
                    case TypeKinds::TK_R4:
                    case TypeKinds::TK_R8:
                    case TypeKinds::TK_STRING:
                    case TypeKinds::TK_I:
                    case TypeKinds::TK_OBJECT:
                        sb <<
                            kind
                        ;
                        break;

                    case TypeKinds::TK_PTR:
                    case TypeKinds::TK_BYREF:
                    case TypeKinds::TK_SZARRAY:
                        sb <<
                            kind << 
                            pType->GetDeclaringType()
                        ;
                        break;

                    case TypeKinds::TK_VALUETYPE:
                    case TypeKinds::TK_CLASS:
                        sb <<
                            kind << 
                            CompressToken(pType->GetToken())
                        ;
                        break;

                    case TypeKinds::TK_GENERICINST:
                        sb <<
                            kind << 
                            pType->GetDeclaringType()->GetKind() << 
                            CompressToken(pType->GetDeclaringType()->GetToken()) << 
                            CompressCount(pType->GetGenericArguments()) << 
                            pType->GetGenericArguments()
                        ;
                        break;

                    case TypeKinds::TK_VAR:
                    case TypeKinds::TK_MVAR:
                        sb <<
                            kind << 
                            CompressData(pType->GetGenericParameterPosition())
                        ;
                        break;

                    default:
                        {
                            auto oss = std::wostringstream();
                            oss << boost::wformat(L"kind.Value():  %|1$02X|") % kind.Value();
                            BOOST_THROW_EXCEPTION(Urasandesu::CppAnonym::CppAnonymNotImplementedException(oss.str()));
                        }
                        break;
                }

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sb.Size());
                m_blob.assign(sb.Ptr(), sb.Ptr() + sb.Size());
            }



            void Encode(IMethod const *pMethod)
            {
                using namespace PutterDetail;

                _ASSERTE(pMethod);

                auto sb = SimpleBlob();

                auto callingConvention = pMethod->GetCallingConvention();
                if (callingConvention & CallingConventions::CC_GENERIC_INST)
                {
                    sb << 
                        callingConvention << 
                        CompressCount(pMethod->GetGenericArguments()) << 
                        pMethod->GetGenericArguments()
                    ;
                }
                else if (callingConvention & CallingConventions::CC_GENERIC)
                {
                    sb << 
                        callingConvention << 
                        CompressCount(pMethod->GetGenericArguments()) << 
                        CompressCount(pMethod->GetParameters()) << 
                        pMethod->GetReturnType() << 
                        pMethod->GetParameters()
                    ;
                }
                else
                {
                    sb << 
                        callingConvention << 
                        CompressCount(pMethod->GetParameters()) << 
                        pMethod->GetReturnType() << 
                        pMethod->GetParameters()
                    ;
                }

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sb.Size());
                m_blob.assign(sb.Ptr(), sb.Ptr() + sb.Size());
            }



            void Encode(IMethodBody const *pBody)
            {
                using namespace PutterDetail;

                _ASSERTE(pBody != nullptr);

                auto sb = SimpleBlob();
                sb <<  
                    pBody->GetCallingConvention() << 
                    CompressCount(pBody->GetLocals()) << 
                    pBody->GetLocals()
                ;

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sb.Size());
                m_blob.assign(sb.Ptr(), sb.Ptr() + sb.Size());
            }


            void Encode(IProperty const *pProp)
            {
                using namespace PutterDetail;

                _ASSERTE(pProp != nullptr);

                auto sb = SimpleBlob();
                sb <<  
                    pProp->GetCallingConvention() << 
                    CompressCount(pProp->GetParameters()) << 
                    pProp->GetPropertyType() << 
                    pProp->GetParameters()
                ;

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sb.Size());
                m_blob.assign(sb.Ptr(), sb.Ptr() + sb.Size());
            }



            void Encode(IField const *pField)
            {
                _ASSERTE(pField != nullptr);

                auto sb = SimpleBlob();
                sb << 
                    pField->GetCallingConvention() << 
                    pField->GetFieldType()
                ;

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sb.Size());
                m_blob.assign(sb.Ptr(), sb.Ptr() + sb.Size());
            }



            void Encode(ICustomAttribute const *pCa)
            {
                using namespace PutterDetail;

                _ASSERTE(pCa != nullptr);
                auto const Prolog = static_cast<USHORT>(0x0001);
                auto const NumNamed = static_cast<USHORT>(pCa->GetNamedProperties().size() + pCa->GetNamedFields().size());
                
                auto sb = SimpleBlob();
                sb << 
                    HoldData(Prolog) << 
                    FixedArgs(pCa) << 
                    HoldData(NumNamed) << 
                    NamedArgs(pCa)
                ;

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sb.Size());
                m_blob.assign(sb.Ptr(), sb.Ptr() + sb.Size());
            }


            
            void Decode(IType const *pType, TypeKinds &kind, IType const *&pDeclaringType, vector<IType const *> &genericArgs) const
            {
                using namespace TakerDetail;

                _ASSERTE(pType);
                _ASSERTE(!m_blob.empty());

                (m_blob, pType) >> 
                    kind >> 
                    pDeclaringType >> 
                    CompressCount(genericArgs) >> 
                    genericArgs
                ;
            }



            void Decode(IType const *pType, TypeKinds &kind, IType const *&pDeclaringType) const
            {
                using namespace TakerDetail;

                _ASSERTE(pType);
                _ASSERTE(!m_blob.empty());

                (m_blob, pType) >> 
                    kind >> 
                    pDeclaringType
                ;
            }



            void Decode(IType const *pType, TypeKinds &kind, ULONG &genericParamPos) const
            {
                using namespace TakerDetail;

                _ASSERTE(pType);
                _ASSERTE(!m_blob.empty());

                (m_blob, pType) >> 
                    kind >> 
                    CompressData(genericParamPos)
                ;
            }



            void Decode(IMethod const *pMethod, CallingConventions &callingConvention, vector<IType const *> &genericArgs, IType const *&pRetType, vector<IParameter const *> &params) const
            {
                using namespace TakerDetail;

                _ASSERTE(pMethod != nullptr);
                _ASSERTE(!m_blob.empty());

                (m_blob, pMethod) >> 
                    callingConvention >>
                    CompressCount(genericArgs) >> 
                    CompressCount(params) >> 
                    RetType(pRetType) >> 
                    Params(params)
                ;
            }



            void Decode(IMethod const *pMethod, CallingConventions &callingConvention, IType const *&pRetType, vector<IParameter const *> &params) const
            {
                using namespace TakerDetail;

                _ASSERTE(pMethod != nullptr);
                _ASSERTE(!m_blob.empty());

                (m_blob, pMethod) >> 
                    callingConvention >>
                    CompressCount(params) >> 
                    RetType(pRetType) >> 
                    Params(params)
                ;
            }



            void Decode(IMethod const *pMethod, CallingConventions &callingConvention, vector<IType const *> &genericArgs) const
            {
                using namespace TakerDetail;

                _ASSERTE(pMethod != nullptr);
                _ASSERTE(!m_blob.empty());

                (m_blob, pMethod) >> 
                    callingConvention >>
                    CompressCount(genericArgs) >> 
                    genericArgs
                ;
            }



            void Decode(IMethodBody const *pBody, CallingConventions &callingConvention, vector<ILocal const *> &locals) const
            {
                using namespace TakerDetail;

                _ASSERTE(pBody != nullptr);
                _ASSERTE(!m_blob.empty());

                (m_blob, pBody) >> 
                    callingConvention >>
                    CompressCount(locals) >> 
                    Locals(locals)
                ;
            }



            void Decode(IProperty const *pProp, CallingConventions &callingConvention, IType const *&pPropType, vector<IParameter const *> &params) const
            {
                using namespace TakerDetail;

                _ASSERTE(pProp != nullptr);
                _ASSERTE(!m_blob.empty());

                (m_blob, pProp) >> 
                    callingConvention >> 
                    CompressCount(params) >> 
                    pPropType >> 
                    Params(params)
                ;
            }


            
            void Decode(ICustomAttribute const *pCa, vector<CustomAttributeArgument> &constructorArgs, vector<IProperty const *> &namedProps, vector<CustomAttributeArgument> &propValues, vector<IField const *> &namedFields, vector<CustomAttributeArgument> &fieldValues) const
            {
                using namespace TakerDetail;

                _ASSERTE(pCa != nullptr);
                _ASSERTE(!m_blob.empty());

                auto prolog = USHORT();
                auto numNamed = USHORT();

                (m_blob, pCa) >> 
                    HoldData(prolog) >> 
                    FixedArgs(constructorArgs) >> 
                    HoldData(numNamed) >> 
                    NamedArgs(numNamed, namedProps, propValues, namedFields, fieldValues)
                ;
            }



            void SetBlob(PCCOR_SIGNATURE pSig, ULONG sigLength)
            {
                _ASSERTE(pSig != nullptr);
                _ASSERTE(0ul < sigLength);

                m_blob = vector<COR_SIGNATURE>();
                m_blob.reserve(sigLength);
                m_blob.assign(pSig, pSig + sigLength);
            }



            vector<COR_SIGNATURE> const &GetBlob() const
            {
                return m_blob;
            }



        private:
            SignatureImpl *m_pClass;
            vector<COR_SIGNATURE> m_blob;
        };



        SignatureImpl::SignatureImpl()
        {
#ifdef _DEBUG
            BOOST_MPL_ASSERT_RELATION(sizeof(SignatureImplPimpl), <=, sizeof(storage_type));
#else
            BOOST_MPL_ASSERT_RELATION(sizeof(SignatureImplPimpl), ==, sizeof(storage_type));
#endif
            new(Pimpl())SignatureImplPimpl(this);
        }

        SignatureImpl::~SignatureImpl()
        {
            Pimpl()->~SignatureImplPimpl();
        }
        
        SignatureImplPimpl *SignatureImpl::Pimpl()
        {
            return reinterpret_cast<SignatureImplPimpl *>(&m_storage);
        }

        SignatureImplPimpl const *SignatureImpl::Pimpl() const
        {
            return const_cast<SignatureImpl *>(this)->Pimpl();
        }



        void SignatureImpl::Encode(IType const *pType)
        {
            Pimpl()->Encode(pType);
        }

        void SignatureImpl::Encode(IMethod const *pMethod)
        {
            Pimpl()->Encode(pMethod);
        }

        void SignatureImpl::Encode(IMethodBody const *pBody)
        {
            Pimpl()->Encode(pBody);
        }

        void SignatureImpl::Encode(IProperty const *pProp)
        {
            Pimpl()->Encode(pProp);
        }

        void SignatureImpl::Encode(IField const *pField)
        {
            Pimpl()->Encode(pField);
        }

        void SignatureImpl::Encode(ICustomAttribute const *pCa)
        {
            Pimpl()->Encode(pCa);
        }
        
        void SignatureImpl::Decode(IType const *pType, TypeKinds &kind, IType const *&pDeclaringType, vector<IType const *> &genericArgs) const
        {
            Pimpl()->Decode(pType, kind, pDeclaringType, genericArgs);
        }

        void SignatureImpl::Decode(IType const *pType, TypeKinds &kind, IType const *&pDeclaringType) const
        {
            Pimpl()->Decode(pType, kind, pDeclaringType);
        }

        void SignatureImpl::Decode(IType const *pType, TypeKinds &kind, ULONG &genericParamPos) const
        {
            Pimpl()->Decode(pType, kind, genericParamPos);
        }

        void SignatureImpl::Decode(IMethod const *pMethod, CallingConventions &callingConvention, vector<IType const *> &genericArgs, IType const *&pRetType, vector<IParameter const *> &params) const
        {
            Pimpl()->Decode(pMethod, callingConvention, genericArgs, pRetType, params);
        }

        void SignatureImpl::Decode(IMethod const *pMethod, CallingConventions &callingConvention, IType const *&pRetType, vector<IParameter const *> &params) const
        {
            Pimpl()->Decode(pMethod, callingConvention, pRetType, params);
        }

        void SignatureImpl::Decode(IMethod const *pMethod, CallingConventions &callingConvention, vector<IType const *> &genericArgs) const
        {
            Pimpl()->Decode(pMethod, callingConvention, genericArgs);
        }

        void SignatureImpl::Decode(IMethodBody const *pBody, CallingConventions &callingConvention, vector<ILocal const *> &locals) const
        {
            Pimpl()->Decode(pBody, callingConvention, locals);
        }

        void SignatureImpl::Decode(IProperty const *pProp, CallingConventions &callingConvention, IType const *&pPropType, vector<IParameter const *> &params) const
        {
            Pimpl()->Decode(pProp, callingConvention, pPropType, params);
        }

        void SignatureImpl::Decode(ICustomAttribute const *pCa, vector<CustomAttributeArgument> &constructorArgs, vector<IProperty const *> &namedProps, vector<CustomAttributeArgument> &propValues, vector<IField const *> &namedFields, vector<CustomAttributeArgument> &fieldValues) const
        {
            Pimpl()->Decode(pCa, constructorArgs, namedProps, propValues, namedFields, fieldValues);
        }

        void SignatureImpl::SetBlob(PCCOR_SIGNATURE pSig, ULONG sigLength)
        {
            Pimpl()->SetBlob(pSig, sigLength);
        }

        vector<COR_SIGNATURE> const &SignatureImpl::GetBlob() const
        {
            return Pimpl()->GetBlob();
        }

    }   // namespace SignatureDetail {

}}}   // namespace Urasandesu { namespace Swathe { namespace Metadata {
