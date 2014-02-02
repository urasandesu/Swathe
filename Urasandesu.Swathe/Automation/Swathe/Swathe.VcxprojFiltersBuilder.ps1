# 
# File: Swathe.VcxprojFiltersBuilder.ps1
# 
# Author: Akira Sugiura (urasandesu@gmail.com)
# 
# 
# Copyright (c) 2012 Akira Sugiura
#  
#  This software is MIT License.
#  
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#  
#  The above copyright notice and this permission notice shall be included in
#  all copies or substantial portions of the Software.
#  
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
#  THE SOFTWARE.
#

$VcxprojFiltersBuilder = 
    $VcxprojBuilder | 
        Prototype VcxprojFiltersBuilder {
            Field m_filterItemGroup ([Xml.XmlNode].Default) -Hidden
            Field m_filterItemGroupTable ([Collections.Hashtable].Default) -Hidden
            Field m_filterItemGroupExtensionTable ([Collections.Hashtable].Default) -Hidden
            
            New { 
                $VcxprojBuilder.New($Params)
                
                $Me.m_filterItemGroupTable = @{ }
                $Me.m_filterItemGroupExtensionTable = @{ }
                $Me.m_filterItemGroup = $Me.m_vcxprojXml.SelectSingleNode('/x:Project/x:ItemGroup[x:Filter]', $Me.m_nsm)
                foreach ($node in $Me.m_filterItemGroup.ChildNodes) {
                    $Me.m_filterItemGroupTable.Add($node.Include, $node)
                    if ($null -ne $node.Extensions) {
                        $extensions = $node.Extensions -split ';' | % { '.' + $_ }
                        foreach ($extension in $extensions) {
                            $Me.m_filterItemGroupExtensionTable.Add($extension, $node)
                        }
                    }
                }
            }
        
            OverrideMethod GetClCompile {
                ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
                $newClCompile = $VcxprojBuilder.GetClCompile(($pathWithoutRoot, $directoryWithoutRoot, $extension))
                $newFilter = $Me.m_vcxprojXml.CreateElement('Filter', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)
                $newFilter.InnerText = $Me.ToDefaultPathChar([IO.Path]::Combine($Me.m_filterItemGroupExtensionTable[$extension].Include, $directoryWithoutRoot))
                [Void]$newClCompile.AppendChild($newFilter)
                $newClCompile
            } -Hidden
            
            OverrideMethod AddClCompileIfNecessary {
                ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
                $VcxprojBuilder.AddClCompileIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension))
                $filterInclude = $Me.ToDefaultPathChar([IO.Path]::Combine('Source Files', $directoryWithoutRoot))
                $Me.AddFilterIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension, $filterInclude))
            } -Hidden
            
            OverrideMethod GetClInclude {
                ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
                $newClInclude = $VcxprojBuilder.GetClInclude(($pathWithoutRoot, $directoryWithoutRoot, $extension))
                $newFilter = $Me.m_vcxprojXml.CreateElement('Filter', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)
                $newFilter.InnerText = $Me.ToDefaultPathChar([IO.Path]::Combine($Me.m_filterItemGroupExtensionTable[$extension].Include, $directoryWithoutRoot))
                [Void]$newClInclude.AppendChild($newFilter)
                $newClInclude
            } -Hidden
            
            OverrideMethod AddClIncludeIfNecessary {
                ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
                $VcxprojBuilder.AddClIncludeIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension))
                $filterInclude = $Me.ToDefaultPathChar([IO.Path]::Combine('Header Files', $directoryWithoutRoot))
                $Me.AddFilterIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension, $filterInclude))
            } -Hidden
            
            Method GetFilter {
                ($pathWithoutRoot, $directoryWithoutRoot, $extension, $filterInclude) = $Params
                $newFilter = $Me.m_vcxprojXml.CreateElement('Filter', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)
                $newInclude = $Me.m_vcxprojXml.CreateAttribute('Include')
                $newInclude.Value = $filterInclude
                [Void]$newFilter.Attributes.Append($newInclude)
                $newUniqueIdentifier = $Me.m_vcxprojXml.CreateElement('UniqueIdentifier', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)
                $newUniqueIdentifier.InnerText = [Guid]::NewGuid().ToString('B')
                [Void]$newFilter.AppendChild($newUniqueIdentifier)
                $newFilter
            } -Hidden
            
            Method AddFilterIfNecessary {
                ($pathWithoutRoot, $directoryWithoutRoot, $extension, $filterInclude) = $Params
                if (![string]::IsNullOrEmpty($filterInclude) -and !$Me.m_filterItemGroupTable.ContainsKey($filterInclude)) {
                    $newFilter = $Me.GetFilter(($pathWithoutRoot, $directoryWithoutRoot, $extension, $filterInclude))
                    [Void]$Me.m_filterItemGroup.AppendChild($newFilter)
                    $Me.m_filterItemGroupTable.Add($filterInclude, $newFilter)
                    $Me.AddFilterIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension, [IO.Path]::GetDirectoryName($filterInclude)))
                }
            }
        }
