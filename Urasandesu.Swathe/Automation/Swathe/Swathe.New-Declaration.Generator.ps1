# 
# File: Swathe.New-Declaration.Generator.ps1
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

$Generator = 
    $Common | 
        Prototype Generator {
            New { 
                param ([Object[]]$items) 
                $Common.New($items) 
                $Me.m_previousClassLabels = $null
                $Me.m_previousClassPersistedHandlerLabels = $null
                $Me.m_previousClassFwdHs = $null
                $Me.m_previousClassPersistedHandlerFwdHs = $null
            }
            
            Property ClassApiAt { $Me.Items[0] }
            
            OverrideProperty DeclareTypedefAlias { "SWATHE_DECLARE_$($Me.ClassApiAt.ClassName.ToAllCaps())_$($Me.Name.ToAllCaps())_TYPEDEF_ALIAS" }
            
            Field m_previousClassLabels ([Object[]].Default) -Hidden
            Property PreviousClassLabels {
                if ($null-eq $Me.m_previousClassLabels) {
                    $Me.m_previousClassLabels = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QSkipWhile { 'Nil' -ne $1.Name } | 
                            QSkip 1 | 
                            QWhere { 'ClassLabel' -eq $1.Category } | 
                            QToArray
                }
                $Me.m_previousClassLabels
            }
            
            Field m_previousClassPersistedHandlerLabels ([Object[]].Default) -Hidden
            Property PreviousClassPersistedHandlerLabels {
                if ($null-eq $Me.m_previousClassPersistedHandlerLabels) {
                    $Me.m_previousClassPersistedHandlerLabels = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QSkipWhile { 'Nil' -ne $1.Name } | 
                            QSkip 1 | 
                            QWhere { 'ClassPersistedHandlerLabel' -eq $1.Category } | 
                            QToArray
                }
                $Me.m_previousClassPersistedHandlerLabels
            }
            
            Field m_previousClassFwdHs ([Object[]].Default) -Hidden
            Property PreviousClassFwdHs {
                if ($null-eq $Me.m_previousClassFwdHs) {
                    $Me.m_previousClassFwdHs = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QSkipWhile { 'Nil' -ne $1.Name } | 
                            QSkip 1 | 
                            QWhere { 'ClassFwdH' -eq $1.CategoryName } | 
                            QToArray
                }
                $Me.m_previousClassFwdHs
            }
            
            Field m_previousClassPersistedHandlerFwdHs ([Object[]].Default) -Hidden
            Property PreviousClassPersistedHandlerFwdHs {
                if ($null-eq $Me.m_previousClassPersistedHandlerFwdHs) {
                    $Me.m_previousClassPersistedHandlerFwdHs = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QSkipWhile { 'Nil' -ne $1.Name } | 
                            QSkip 1 | 
                            QWhere { 'ClassPersistedHandlerFwdH' -eq $1.CategoryName } | 
                            QToArray
                }
                $Me.m_previousClassPersistedHandlerFwdHs
            }
        }



$SimpleHeapProvider = 
    $Generator | 
        Prototype SimpleHeapProvider {
            New {
                param ([Object[]]$items) 
                $Generator.New($items)
                $Me.m_classLabels = $null
                $Me.m_classFwdHs = $null
                $Me.m_tags = $null
            }
            
            OverrideProperty Template { 'Swathe.New-Declaration.Generator.SimpleHeapProvider.Template.ps1' }
            
            Field m_classLabels ([Object[]].Default) -Hidden
            Property ClassLabels {
                if ($null -eq $Me.m_classLabels) {
                    $Me.m_classLabels = 
                        QRange | 
                            QZip { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 0 } | 
                            QSelect { $1[1] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassLabel' -eq $1.Category } | 
                            QToArray
                }
                $Me.m_classLabels
            }
            
            Field m_classFwdHs ([Object[]].Default) -Hidden
            Property ClassFwdHs {
                if ($null -eq $Me.m_classFwdHs) {
                    $Me.m_classFwdHs = 
                        QRange | 
                            QZip { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 0 } | 
                            QSelect { $1[1] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassFwdH' -eq $1.CategoryName } | 
                            QToArray
                }
                $Me.m_classFwdHs
            }
            
            Field m_tags ([Object[]].Default) -Hidden
            Property Tags {
                if ($null -eq $Me.m_tags) {
                    $Me.m_tags = 
                        QRange | 
                            QZip { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 1 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                $Me.m_tags
            }
        }



$SmartHeapProvider = 
    $Generator | 
        Prototype SmartHeapProvider {
            New {
                param ([Object[]]$items) 
                $Generator.New($items)
                $Me.m_classLabels = $null
                $Me.m_classFwdHs = $null
            }
            
            OverrideProperty Template { 'Swathe.New-Declaration.Generator.SmartHeapProvider.Template.ps1' }
            
            Field m_classLabels ([Object[]].Default) -Hidden
            Property ClassLabels {
                if ($null -eq $Me.m_classLabels) {
                    $Me.m_classLabels = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassLabel' -eq $1.Category } | 
                            QToArray
                }
                $Me.m_classLabels
            }
            
            Field m_classFwdHs ([Object[]].Default) -Hidden
            Property ClassFwdHs {
                if ($null -eq $Me.m_classFwdHs) {
                    $Me.m_classFwdHs = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassFwdH' -eq $1.CategoryName } | 
                            QToArray
                }
                $Me.m_classFwdHs
            }
        }



$PersistableHeapProvider = 
    $Generator | 
        Prototype PersistableHeapProvider {
            OverrideProperty Template { 'Swathe.New-Declaration.Generator.PersistableHeapProvider.Template.ps1' }
        }



$DisposableHeapProvider = 
    $Generator | 
        Prototype DisposableHeapProvider {
            New {
                param ([Object[]]$items) 
                $Generator.New($items)
                $Me.m_classLabels = $null
                $Me.m_classPersistedHandlerLabels = $null
            }
            
            OverrideProperty Template { 'Swathe.New-Declaration.Generator.DisposableHeapProvider.Template.ps1' }
            
            Field m_classLabels ([Object[]].Default) -Hidden
            Property ClassLabels {
                if ($null -eq $Me.m_classLabels) {
                    $Me.m_classLabels = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassLabel' -eq $1.Category } | 
                            QToArray
                }
                $Me.m_classLabels
            }
            
            Field m_classPersistedHandlerLabels ([Object[]].Default) -Hidden
            Property ClassPersistedHandlerLabels {
                if ($null-eq $Me.m_classPersistedHandlerLabels) {
                    $Me.m_classPersistedHandlerLabels = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassPersistedHandlerLabel' -eq $1.Category } | 
                            QToArray
                }
                $Me.m_classPersistedHandlerLabels
            }
            
            Field m_classFwdHs ([Object[]].Default) -Hidden
            Property ClassFwdHs {
                if ($null -eq $Me.m_classFwdHs) {
                    $Me.m_classFwdHs = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassFwdH' -eq $1.CategoryName } | 
                            QToArray
                }
                $Me.m_classFwdHs
            }
            
            Field m_classPersistedHandlerFwdHs ([Object[]].Default) -Hidden
            Property ClassPersistedHandlerFwdHs {
                if ($null-eq $Me.m_classPersistedHandlerFwdHs) {
                    $Me.m_classPersistedHandlerFwdHs = 
                        { $Me.Items[1..($Me.Items.Length - 1)] } | 
                            QTakeWhile { 'Nil' -ne $1.Name } | 
                            QWhere { 'ClassPersistedHandlerFwdH' -eq $1.CategoryName } | 
                            QToArray
                }
                $Me.m_classPersistedHandlerFwdHs
            }
        }



$EmptyHeapProvider = 
    $Generator | 
        Prototype EmptyHeapProvider {
            OverrideProperty Template { 'Swathe.New-Declaration.Generator.EmptyHeapProvider.Template.ps1' }
        }
