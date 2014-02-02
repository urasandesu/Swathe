# 
# File: Swathe.VcxprojBuilder.ps1
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

$VcxprojBuilder = 
    Prototype VcxprojBuilder {
        Field m_vcxprojXml ([xml].Default) -Hidden
        Field m_nsm ([Xml.XmlNamespaceManager].Default) -Hidden
        Field m_clCompileItemGroup ([Xml.XmlNode].Default) -Hidden
        Field m_clCompileItemGroupTable ([Collections.Hashtable].Default) -Hidden
        Field m_clIncludeItemGroup ([Xml.XmlNode].Default) -Hidden
        Field m_clIncludeItemGroupTable ([Collections.Hashtable].Default) -Hidden
        
        New { 
            $Me.m_vcxprojXml = $($Params)
            $Me.m_nsm = New-Object Xml.XmlNamespaceManager $Me.m_vcxprojXml.NameTable 
            $Me.m_nsm.AddNamespace('x', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)

            $Me.m_clCompileItemGroupTable = @{ }
            $Me.m_clCompileItemGroup = $Me.m_vcxprojXml.SelectSingleNode('/x:Project/x:ItemGroup[x:ClCompile]', $Me.m_nsm)
            foreach ($node in $Me.m_clCompileItemGroup.ChildNodes) {
                $Me.m_clCompileItemGroupTable.Add($node.Include, $node)
            }

            $Me.m_clIncludeItemGroupTable = @{ }
            $Me.m_clIncludeItemGroup = $Me.m_vcxprojXml.SelectSingleNode('/x:Project/x:ItemGroup[x:ClInclude]', $Me.m_nsm)
            foreach ($node in $Me.m_clIncludeItemGroup.ChildNodes) {
                $Me.m_clIncludeItemGroupTable.Add($node.Include, $node)
            }
        }
        
        Method ToDefaultPathChar {
            $($Params) -replace '/', '\'
        } -Hidden
        
        Method GetClCompile {
            ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
            $newClCompile = $Me.m_vcxprojXml.CreateElement('ClCompile', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)
            $newInclude = $Me.m_vcxprojXml.CreateAttribute('Include')
            $newInclude.Value = $pathWithoutRoot
            [Void]$newClCompile.Attributes.Append($newInclude)
            $newClCompile
        } -Hidden
        
        Method AddClCompileIfNecessary {
            ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
            if (!$Me.m_clCompileItemGroupTable.ContainsKey($pathWithoutRoot)) {
                $newClCompile = $Me.GetClCompile(($pathWithoutRoot, $directoryWithoutRoot, $extension))
                [Void]$Me.m_clCompileItemGroup.AppendChild($newClCompile)
                $Me.m_clCompileItemGroupTable.Add($pathWithoutRoot, $newClCompile)
            }
        } -Hidden
        
        Method GetClInclude {
            ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
            $newClInclude = $Me.m_vcxprojXml.CreateElement('ClInclude', $Me.m_vcxprojXml.DocumentElement.NamespaceURI)
            $newInclude = $Me.m_vcxprojXml.CreateAttribute('Include')
            $newInclude.Value = $pathWithoutRoot
            [Void]$newClInclude.Attributes.Append($newInclude)
            $newClInclude
        } -Hidden
        
        Method AddClIncludeIfNecessary {
            ($pathWithoutRoot, $directoryWithoutRoot, $extension) = $Params
            if (!$Me.m_clIncludeItemGroupTable.ContainsKey($pathWithoutRoot)) {
                $newClInclude = $Me.GetClInclude(($pathWithoutRoot, $directoryWithoutRoot, $extension))
                [Void]$Me.m_clIncludeItemGroup.AppendChild($newClInclude)
                $Me.m_clIncludeItemGroupTable.Add($pathWithoutRoot, $newClInclude)
            }
        } -Hidden
        
        Method AddIfNecessary {
            ($baseDirectory, $prototype) = $Params
            if ($null -eq $prototype) {
                $prototype = $baseDirectory
                $pathWithoutRoot = $Me.ToDefaultPathChar($prototype.PathWithoutRoot)
            } else {
                $pathWithoutRoot = Join-Path $baseDirectory $Me.ToDefaultPathChar($prototype.PathWithoutRoot)
            }
            $directoryWithoutRoot = $Me.ToDefaultPathChar($prototype.DirectoryWithoutRoot)
            $extension = $prototype.Extension
            if ('.cpp' -eq $extension) {
                $Me.AddClCompileIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension))
            } elseif ('.h', '.hpp' -contains $extension) {
                $Me.AddClIncludeIfNecessary(($pathWithoutRoot, $directoryWithoutRoot, $extension))
            }
        }
    }
