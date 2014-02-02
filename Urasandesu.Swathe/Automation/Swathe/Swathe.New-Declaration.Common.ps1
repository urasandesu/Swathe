# 
# File: Swathe.New-Declaration.Common.ps1
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

$Common = 
    $DataRecord, $Function | 
        Prototype Common {
            New { param ([Object[]]$items) $DataRecord.New($items) }
            OverrideProperty RootDirectory { }
            OverrideProperty Directory { }
            OverrideProperty DirectoryWithoutRoot { }
            OverrideProperty Namespaces { }
            OverrideProperty Namespace { }
            OverrideProperty Function { }
            OverrideProperty Category { 'Common' }
            OverrideProperty FilePrefix { }
            OverrideProperty Prefix { }
            OverrideProperty Name { $Me.TypeName }
            OverrideProperty ClassName { }
            OverrideProperty Suffix { }
            OverrideProperty FileSuffix { }
            OverrideProperty Extension { }
            OverrideProperty FullName { $Me.Name }
            OverrideProperty FileName { }
            OverrideProperty CategoryName { }
            OverrideProperty TypeName { $Me.psobject.TypeNames[0] }
            OverrideProperty DependentHeaders { } { }
            OverrideProperty Template { }
            OverrideProperty DependentHeadersWithoutCommon { }
            OverrideProperty Path { }
            OverrideProperty PathWithoutRoot { }
            OverrideProperty IncludeGuard { }
            OverrideProperty BeginTypedefAlias { }
            OverrideProperty DeclareTypedefAlias { }
            OverrideProperty EndTypedefAlias { }
            Method GenerateWithIndentationAt {
                param ($Indent)
                ($Me.Generate() -split "`r`n" | 
                    ForEach-Object { $_ -replace '^', ('    ' * $Indent) }) -join "`r`n"
            }
        }

$Common.Here = Split-Path $MyInvocation.MyCommand.Path
