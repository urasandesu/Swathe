# 
# File: Swathe.New-Declaration.File.ps1
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

$File = 
    $DataRecord, $Function | 
        Prototype File {
        
            New {
                param ([Object[]]$items) 
                $DataRecord.New($items)
                $Me.m_namespaces = $null
                $Me.m_dependentHeaders = $null
                $Me.m_dependentHeadersWithoutCommon = $null
            }
        
            OverrideProperty RootDirectory { $Me.Items[0] }
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }

            Field m_namespaces ([Object[]].Default) -Hidden
            OverrideProperty Namespaces { 
                if ($null -eq $Me.m_namespaces) {
                    $Me.m_namespaces = 
                        { $Me.Items[1..6] } | 
                            QWhere { $1 -ne '' } | 
                            QToArray
                }
                $Me.m_namespaces
            }
            
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Function { $Me.Items[4] }
            OverrideProperty Category { $Me.Items[5] }
            OverrideProperty FilePrefix { $Me.Items[6] }
            OverrideProperty Prefix { $Me.Items[7] }
            OverrideProperty Name { $Me.Prefix + $Me.Items[8] + $Me.Suffix }
            OverrideProperty ClassName { $Me.Items[8] }
            OverrideProperty Suffix { $Me.Items[9] }
            OverrideProperty FileSuffix { $Me.Items[10] }
            OverrideProperty Extension { $Me.Items[11] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty FileName { $Me.FilePrefix + $Me.Name + $Me.FileSuffix + $Me.Extension }
            OverrideProperty CategoryName { $Me.FilePrefix + $Me.Category + $Me.FileSuffix + ($Me.Extension -replace '\.', '').ToPascalCase() }
            OverrideProperty TypeName { $Me.FilePrefix + $Me.Name + $Me.FileSuffix + ($Me.Extension -replace '\.', '').ToPascalCase() }

            Field m_dependentHeaders ([Object[]].Default) -Hidden
            OverrideProperty DependentHeaders { 
                , $Me.m_dependentHeaders 
            } { 
                $Me.m_dependentHeadersWithoutCommon = $null
                $Me.m_dependentHeaders = @($Params) 
            }
            
            OverrideProperty Template { throw New-Object NotImplementedException }

            Field m_dependentHeadersWithoutCommon ([Object].Default) -Hidden
            OverrideProperty DependentHeadersWithoutCommon { 
                if ($null -eq $Me.m_dependentHeadersWithoutCommon) {
                    $Me.m_dependentHeadersWithoutCommon = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.psobject.TypeNames -notcontains 'Common' } | 
                            QDistinct { $1.Name } | 
                            QToArray
                }
                $Me.m_dependentHeadersWithoutCommon
            }
            
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty BeginTypedefAlias { "SWATHE_BEGIN_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
            OverrideProperty DeclareTypedefAlias { "SWATHE_DECLARE_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
            OverrideProperty EndTypedefAlias { "SWATHE_END_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
        }
