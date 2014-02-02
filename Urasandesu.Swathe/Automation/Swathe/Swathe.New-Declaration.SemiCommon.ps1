# 
# File: Swathe.New-Declaration.SemiCommon.ps1
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

$SemiCommon = 
    $DataRecord, $Function | 
        Prototype SemiCommon {
            New { 
                param ([Object[]]$items) 
                $DataRecord.New($items) 
                $Me.m_namespaces = $null
            }

            OverrideProperty RootDirectory { }
            OverrideProperty Directory { }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            
            Field m_namespaces ([Object[]].Default) -Hidden
            OverrideProperty Namespaces { 
                if ($null -eq $Me.m_namespaces) {
                    $Me.m_namespaces = 
                        { $Me.Items[0..3] } | 
                            QWhere { $1 -ne '' } | 
                            QToArray
                }
                $Me.m_namespaces
            }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Function { $Me.Items[2] }
            OverrideProperty Category { $Me.Items[3] }
            OverrideProperty FilePrefix { $Me.Items[4] }
            OverrideProperty Prefix { $Me.Items[5] }
            OverrideProperty Name { $Me.Prefix + $Me.Items[6] + $Me.Suffix }
            OverrideProperty ClassName { $Me.Items[6] }
            OverrideProperty Suffix { $Me.Items[7] }
            OverrideProperty FileSuffix { $Me.Items[8] }
            OverrideProperty Extension { $Me.Items[9] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty FileName { $Me.FilePrefix + $Me.Name + $Me.FileSuffix + $Me.Extension }
            OverrideProperty CategoryName { $Me.FilePrefix + $Me.Category + $Me.FileSuffix + ($Me.Extension -replace '\.', '').ToPascalCase() }
            OverrideProperty TypeName { $Me.FilePrefix + $Me.Name + $Me.FileSuffix + ($Me.Extension -replace '\.', '').ToPascalCase() }
            OverrideProperty DependentHeaders { } { }
            OverrideProperty Template { }
            OverrideProperty DependentHeadersWithoutCommon { }
            OverrideProperty Path { }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty BeginTypedefAlias { "SWATHE_BEGIN_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
            OverrideProperty DeclareTypedefAlias { "SWATHE_DECLARE_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
            OverrideProperty EndTypedefAlias { "SWATHE_END_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
        }
