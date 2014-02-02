# 
# File: Swathe.New-Declaration.Generator.PersistableHeapProvider.Template.ps1
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


$identity = $Me.ClassApiAt.TypeName.GetHashCode().ToString('x8')
#@"
#"@ + $({ $Me.ClassLabels } | QSelect { @"
#typedef typename $($Me.ClassApiAt.Name)<ApiHolder, $($1.Name)>::type $($1.Name.ToSnakeCase())_$($identity)_type;
#"@ } | QToArray) + @"
#"@ + $({ $Me.ClassPersistedHandlerLabels } | QSelect { @"
#typedef typename $($Me.ClassApiAt.Name)<ApiHolder, $($1.Name)>::type $($1.Name.ToSnakeCase())_$($identity)_type;
#"@ } | QToArray) + @"
#"@ + $({ $Me.ClassLabels } | QZip { $Me.ClassPersistedHandlerLabels } { ,($1, $2) } | QSelect { @"
#typedef DisposingInfo<$($1[0].Name.ToSnakeCase())_$($identity)_type, $1[1].NameAsSnakeCase)_$($identity)_type> $($1[0].NameAsSnakeCase)_disposing_info_type;
#"@ } | QToArray) + @"
#
#typedef DisposableHeapProvider<
#"@ + $(({ $Me.ClassLabels } | QSelect { @"
#    $($1[0].Name.ToSnakeCase())_disposing_info_type
#"@ } | QToArray) -join ",`r`n") + @"
#> base_heap_provider_type;
#
#"@ + $({ $Me.ClassLabels } | QSelect { @"
#typedef typename base_heap_provider_type::provider_of<$($1.Name.ToSnakeCase())_disposing_info_type>::type $($1.NameAsSnakeCase)_provider_type;
#"@ } | QToArray) + @"
#"@
#
