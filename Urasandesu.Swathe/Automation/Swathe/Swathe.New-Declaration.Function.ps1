# 
# File: Swathe.New-Declaration.Function.ps1
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

$Function = 
    Prototype Function {
        AbstractProperty RootDirectory -Getter
        AbstractProperty Directory -Getter
        AbstractProperty DirectoryWithoutRoot -Getter
        AbstractProperty Namespaces -Getter
        AbstractProperty Namespace -Getter
        AbstractProperty Function -Getter
        AbstractProperty Category -Getter
        AbstractProperty FilePrefix -Getter
        AbstractProperty Prefix -Getter
        AbstractProperty Name -Getter
        AbstractProperty ClassName -Getter
        AbstractProperty Suffix -Getter
        AbstractProperty FileSuffix -Getter
        AbstractProperty Extension -Getter
        AbstractProperty FullName -Getter
        AbstractProperty FileName -Getter
        AbstractProperty CategoryName -Getter
        AbstractProperty TypeName -Getter
        AbstractProperty DependentHeaders -Getter -Setter        
        AbstractProperty Template -Getter
        AbstractProperty DependentHeadersWithoutCommon -Getter
        AbstractProperty Path -Getter
        AbstractProperty PathWithoutRoot -Getter
        AbstractProperty IncludeGuard -Getter
        Field Here ([string].Default)
        Method Generate { . (Join-Path $Me.Here $Me.Template) }
        AbstractProperty BeginTypedefAlias -Getter
        AbstractProperty DeclareTypedefAlias -Getter
        AbstractProperty EndTypedefAlias -Getter
    }

$Function.Here = Split-Path $MyInvocation.MyCommand.Path
