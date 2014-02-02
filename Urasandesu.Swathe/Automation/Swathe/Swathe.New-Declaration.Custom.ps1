# 
# File: Swathe.New-Declaration.Custom.ps1
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


$Custom = 
    $Function | 
        Prototype Custom {        
            Field m_file ([Object].Default)
            New { 
                param ($File) 
                $Me.m_file = $($File) 
            }
            OverrideProperty RootDirectory { $Me.m_file.RootDirectory }
            OverrideProperty Directory { $Me.m_file.Directory }
            OverrideProperty DirectoryWithoutRoot { $Me.m_file.DirectoryWithoutRoot }
            OverrideProperty Namespaces { $Me.m_file.Namespaces }
            OverrideProperty Namespace { $Me.m_file.Namespace }
            OverrideProperty Function { $Me.m_file.Function }
            OverrideProperty Category { $Me.m_file.Category }
            OverrideProperty FilePrefix { $Me.m_file.FilePrefix }
            OverrideProperty Prefix { $Me.m_file.Prefix }
            OverrideProperty Name { $Me.m_file.Name }
            OverrideProperty ClassName { $Me.m_file.ClassName }
            OverrideProperty Suffix { $Me.m_file.Prefix }
            OverrideProperty FileSuffix { $Me.m_file.FileSuffix }
            OverrideProperty Extension { $Me.m_file.Extension }
            OverrideProperty FullName { $Me.m_file.FullName }
            OverrideProperty FileName { $Me.m_file.FileName }
            OverrideProperty CategoryName { $Me.m_file.CategoryName }
            OverrideProperty TypeName { $Me.m_file.TypeName }
            OverrideProperty DependentHeaders { , $Me.m_file.DependentHeaders } { $Me.m_file.DependentHeaders = @($Params) }
            OverrideProperty DependentHeadersWithoutCommon { $Me.m_file.DependentHeadersWithoutCommon }
            OverrideProperty Path { $Me.m_file.Path }
            OverrideProperty PathWithoutRoot { $Me.m_file.PathWithoutRoot }
            OverrideProperty IncludeGuard { $Me.m_file.IncludeGuard }
            OverrideProperty BeginTypedefAlias { $Me.m_file.BeginTypedefAlias }
            OverrideProperty DeclareTypedefAlias { $Me.m_file.DeclareTypedefAlias }
            OverrideProperty EndTypedefAlias { $Me.m_file.EndTypedefAlias }
        }



$ClassApiAtH = 
    $Custom | 
        Prototype ClassApiAtH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassApiAtH.Template.ps1' }
            Property ClassApiLabelH { $Me.DependentHeaders[0] }
        }



$ClassApiLabelH = 
    $Custom | 
        Prototype ClassApiLabelH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassApiLabelH.Template.ps1' }
        }



$ClassFwdH = 
    $Custom | 
        Prototype ClassFwdH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassFwdH.Template.ps1' }
            Property BaseClassFwdH { $Me.DependentHeaders[0] }
        }



$ClassH = 
    $Custom | 
        Prototype ClassH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassH.Template.ps1' }
            Property BaseClassH { $Me.DependentHeaders[0] }
        }



$ClassLabelH = 
    $Custom | 
        Prototype ClassLabelH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassLabelH.Template.ps1' }
        }



$ClassFacadeFwdH = 
    $Custom | 
        Prototype ClassFacadeFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassFacadeFwdH.Template.ps1' }
        }



$ClassFacadeH = 
    $Custom | 
        Prototype ClassFacadeH {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_classLabels = $null
                $Me.m_classFwdHs = $null
                $Me.m_childGenerateStrategy = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_classLabels = $null
                $Me.m_classFwdHs = $null
                $Me.m_childGenerateStrategy = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassFacadeH.Template.ps1' }
            
            Property ClassApiAtH { $Me.DependentHeaders[0] }
            Property ClassPimplFwdH { $Me.DependentHeaders[1] }
            Property ClassFwdH { $Me.DependentHeaders[2] }
            
            Field m_classLabels ([Object[]].Default) -Hidden
            Property ClassLabels {
                if ($null -eq $Me.m_classLabels) {
                    $Me.m_classLabels = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.CategoryName -match 'Label' } | 
                            QDistinct { $1.Name } | 
                            QToArray
                }
                , $Me.m_classLabels
            }
            
            Field m_classFwdHs ([Object[]].Default) -Hidden
            Property ClassFwdHs {
                if ($null  -eq $Me.m_classFwdHs) {
                    $Me.m_classFwdHs = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.CategoryName -match 'FwdH$' } | 
                            QDistinct { $1.Name } | 
                            QToArray
                }
                , $Me.m_classFwdHs
            }
            
            Field m_childGenerateStrategy ([Object].Default) -Hidden
            Property ChildGenerateStrategy {
                if ($null -eq $Me.m_childGenerateStrategy) {
                    $strategyInfos = 
                        { $Me.DependentHeaders } | 
                            QSkipWhile { 'Generator' -ne $1.psobject.TypeNames[1] } | 
                            QToArray
                    $Me.m_childGenerateStrategy = $strategyInfos[0].New()
                    $Me.m_childGenerateStrategy.Items = $strategyInfos[1..($strategyInfos.Length - 1)]
                }
                $Me.m_childGenerateStrategy
            }            
        }



$DefaultClassApiHolderFwdH = 
    $Custom | 
        Prototype DefaultClassApiHolderFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.DefaultClassApiHolderFwdH.Template.ps1' }
        }



$DefaultClassApiHolderH = 
    $Custom | 
        Prototype DefaultClassApiHolderH {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_classLabelHs = $null
                $Me.m_classFwdHs = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_classLabelHs = $null
                $Me.m_classFwdHs = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.DefaultClassApiHolderH.Template.ps1' }

            Field m_classLabelHs ([Object[]].Default) -Hidden
            Property ClassLabelHs {
                if ($null -eq $Me.m_classLabelHs) {
                    $Me.m_classLabelHs = 
                        QRange | 
                            QZip { $Me.DependentHeaders } | 
                            QWhere { $1[0] % 2 -eq 0 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                , $Me.m_classLabelHs
            }

            Field m_classFwdHs ([Object[]].Default) -Hidden
            Property ClassFwdHs {
                if ($null -eq $Me.m_classFwdHs) {
                    $Me.m_classFwdHs = 
                        QRange | 
                            QZip { $Me.DependentHeaders } | 
                            QWhere { $1[0] % 2 -eq 1 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                , $Me.m_classFwdHs
            }
        }



$BaseClassFwdH = 
    $Custom | 
        Prototype BaseClassFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassFwdH.Template.ps1' }
            Property DefaultClassApiHolderFwdH { $Me.DependentHeaders[0] }
        }



$BaseClassH = 
    $Custom | 
        Prototype BaseClassH {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassH.Template.ps1' }
            Property ClassFacadeH { $Me.DependentHeaders[0] }
            Property BaseClassFwdH { $Me.DependentHeaders[1] }
            Property ClassPimplFwdH { $Me.ClassFacadeH.ClassPimplFwdH }
        }



$BaseClassHpp = 
    $Custom | 
        Prototype BaseClassHpp {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassHpp.Template.ps1' }
            Property BaseClassH { $Me.DependentHeaders[0] }
            Property ClassPimplFwdH { $Me.BaseClassH.ClassFacadeH.ClassPimplFwdH }
            Property DeclareAdditionalInstantiation { "SWATHE_DECLARE_$($Me.Name.ToAllCaps())_ADDITIONAL_INSTANTIATION" }
        }



$BaseClassCpp = 
    $Custom | 
        Prototype BaseClassCpp {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_baseClassesWithoutThis = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_baseClassesWithoutThis = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassCpp.Template.ps1' }
            
            Property BaseClassHpp { $Me.DependentHeaders[0] }

            Field m_baseClassesWithoutThis ([Object[]].Default) -Hidden
            Property BaseClassesWithoutThis {
                if ($null -eq $Me.m_baseClassesWithoutThis) {
                    $Me.m_baseClassesWithoutThis = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.CategoryName -cmatch '^BaseClass.*H$' } | 
                            QWhere { $1.FullName -ne $Me.BaseClassHpp.FullName } | 
                            QDistinct { $1.Name } | 
                            QToArray -Variable { $Me }
                }
                , $Me.m_baseClassesWithoutThis
            }
        }



$ClassPimplFwdH = 
    $Custom | 
        Prototype ClassPimplFwdH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPimplFwdH.Template.ps1' }
            Property BaseClassPimplFwdH { $Me.DependentHeaders[0] }
        }



$ClassPimplH = 
    $Custom | 
        Prototype ClassPimplH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPimplH.Template.ps1' }
            Property BaseClassPimplH { $Me.DependentHeaders[0] }
        }



$ClassPimplLabelH = 
    $Custom | 
        Prototype ClassPimplLabelH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPimplLabelH.Template.ps1' }
        }



$ClassPimplFacadeFwdH = 
    $Custom | 
        Prototype ClassPimplFacadeFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPimplFacadeFwdH.Template.ps1' }
        }



$ClassPimplFacadeH = 
    $Custom | 
        Prototype ClassPimplFacadeH {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_classLabels = $null 
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_classLabels = $null 
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPimplFacadeH.Template.ps1' }

            Property ClassApiAtH { $Me.DependentHeaders[0] }
            Property ClassFacadeH { $Me.DependentHeaders[1] }
            
            Field m_classLabels ([Object[]].Default) -Hidden
            Property ClassLabels {
                if ($null -eq $Me.m_classLabels) {
                    $Me.m_classLabels = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.CategoryName -match 'Label' } | 
                            QDistinct { $1.Name } | 
                            QToArray
                }
                , $Me.m_classLabels
            }
        }



$DefaultClassPimplApiHolderFwdH = 
    $Custom | 
        Prototype DefaultClassPimplApiHolderFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.DefaultClassPimplApiHolderFwdH.Template.ps1' }
        }



$DefaultClassPimplApiHolderH = 
    $Custom | 
        Prototype DefaultClassPimplApiHolderH {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_classLabelHs = $null
                $Me.m_classeFwdHs = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_classLabelHs = $null
                $Me.m_classeFwdHs = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.DefaultClassPimplApiHolderH.Template.ps1' }
            
            Property DefaultClassApiHolderH { $Me.DependentHeaders[0] }

            Field m_classLabelHs ([Object[]].Default) -Hidden
            Property ClassLabelHs {
                if ($null -eq $Me.m_classLabelHs) {
                    $Me.m_classLabelHs = 
                        QRange | 
                            QZip { $Me.DependentHeaders[1..($Me.DependentHeaders.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 0 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                , $Me.m_classLabelHs
            }

            Field m_classeFwdHs ([Object[]].Default) -Hidden
            Property ClasseFwdHs {
                if ($null -eq $Me.m_classeFwdHs) {
                    $Me.m_classeFwdHs = 
                        QRange | 
                            QZip { $Me.DependentHeaders[1..($Me.DependentHeaders.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 1 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                , $Me.m_classeFwdHs
            }
        }



$BaseClassPimplFwdH = 
    $Custom | 
        Prototype BaseClassPimplFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPimplFwdH.Template.ps1' }
            Property DefaultClassPimplApiHolderFwdH { $Me.DependentHeaders[0] }
        }



$BaseClassPimplH = 
    $Custom | 
        Prototype BaseClassPimplH {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPimplH.Template.ps1' }
            Property ClassPimplFacadeH { $Me.DependentHeaders[0] }
            Property BaseClassPimplFwdH { $Me.DependentHeaders[1] }
            Property ClassFwdH { $Me.ClassPimplFacadeH.ClassFacadeH.ClassFwdH }
        }



$BaseClassPimplHpp = 
    $Custom | 
        Prototype BaseClassPimplHpp {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPimplHpp.Template.ps1' }
            Property BaseClassPimplH { $Me.DependentHeaders[0] }
            Property ClassFwdH { $Me.BaseClassPimplH.ClassFwdH }
            Property DeclareAdditionalInstantiation { "SWATHE_DECLARE_$($Me.Name.ToAllCaps())_ADDITIONAL_INSTANTIATION" }
        }



$BaseClassPimplCpp = 
    $Custom | 
        Prototype BaseClassPimplCpp {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_baseClassesWithoutThis = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_baseClassesWithoutThis = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPimplCpp.Template.ps1' }
            
            Property BaseClassPimplHpp { $Me.DependentHeaders[0] }

            Field m_baseClassesWithoutThis ([Object[]].Default) -Hidden
            Property BaseClassesWithoutThis {
                if ($null -eq $Me.m_baseClassesWithoutThis) {
                    $Me.m_baseClassesWithoutThis = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.CategoryName -cmatch '^BaseClass.*H$' } | 
                            QWhere { $1.FullName -ne $Me.BaseClassPimplHpp.FullName } | 
                            QDistinct { $1.Name } | 
                            QToArray -Variable { $Me }
                }
                , $Me.m_baseClassesWithoutThis
            }
        }



$ClassPersistedHandlerFwdH = 
    $Custom | 
        Prototype ClassPersistedHandlerFwdH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPersistedHandlerFwdH.Template.ps1' }
            Property BaseClassPersistedHandlerFwdH { $Me.DependentHeaders[0] }
        }



$ClassPersistedHandlerH = 
    $Custom | 
        Prototype ClassPersistedHandlerH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPersistedHandlerH.Template.ps1' }
            Property BaseClassPersistedHandlerH { $Me.DependentHeaders[0] }
        }



$ClassPersistedHandlerLabelH = 
    $Custom | 
        Prototype ClassPersistedHandlerLabelH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPersistedHandlerLabelH.Template.ps1' }
        }



$ClassPersistedHandlerFacadeFwdH = 
    $Custom | 
        Prototype ClassPersistedHandlerFacadeFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPersistedHandlerFacadeFwdH.Template.ps1' }
        }



$ClassPersistedHandlerFacadeH = 
    $Custom | 
        Prototype ClassPersistedHandlerFacadeH {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_classLabelHs = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_classLabelHs = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.ClassPersistedHandlerFacadeH.Template.ps1' }

            Property ClassApiAtH { $Me.DependentHeaders[0] }
            Property ClassFacadeH { $Me.DependentHeaders[1] }
            
            Field m_classLabelHs ([Object[]].Default) -Hidden
            Property ClassLabelHs {
                if ($null -eq $Me.m_classLabelHs) {
                    $Me.m_classLabelHs = 
                        { $Me.DependentHeaders } | 
                            QWhere { 'ClassLabelH' -eq $1.psobject.TypeNames[0] } | 
                            QDistinct { $1.Name } | 
                            QToArray
                }
                , $Me.m_classLabelHs
            }
        }



$DefaultClassPersistedHandlerApiHolderFwdH = 
    $Custom | 
        Prototype DefaultClassPersistedHandlerApiHolderFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.DefaultClassPersistedHandlerApiHolderFwdH.Template.ps1' }
        }



$DefaultClassPersistedHandlerApiHolderH = 
    $Custom | 
        Prototype DefaultClassPersistedHandlerApiHolderH {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_classLabelHs = $null
                $Me.m_classeFwdHs = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_classLabelHs = $null
                $Me.m_classeFwdHs = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.DefaultClassPersistedHandlerApiHolderH.Template.ps1' }
            
            Property DefaultClassApiHolderH { $Me.DependentHeaders[0] }

            Field m_classLabelHs ([Object[]].Default) -Hidden
            Property ClassLabelHs {
                if ($null -eq $Me.m_classLabelHs) {
                    $Me.m_classLabelHs = 
                        QRange | 
                            QZip { $Me.DependentHeaders[1..($Me.DependentHeaders.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 0 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                , $Me.m_classLabelHs
            }

            Field m_classeFwdHs ([Object[]].Default) -Hidden
            Property ClasseFwdHs {
                if ($null -eq $Me.m_classeFwdHs) {
                    $Me.m_classeFwdHs = 
                        QRange | 
                            QZip { $Me.DependentHeaders[1..($Me.DependentHeaders.Length - 1)] } | 
                            QWhere { $1[0] % 2 -eq 1 } | 
                            QSelect { $1[1] } | 
                            QToArray
                }
                , $Me.m_classeFwdHs
            }
        }



$BaseClassPersistedHandlerFwdH = 
    $Custom | 
        Prototype BaseClassPersistedHandlerFwdH {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPersistedHandlerFwdH.Template.ps1' }
            Property DefaultClassPersistedHandlerApiHolderFwdH { $Me.DependentHeaders[0] }
        }



$BaseClassPersistedHandlerH = 
    $Custom | 
        Prototype BaseClassPersistedHandlerH {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPersistedHandlerH.Template.ps1' }
            Property ClassPersistedHandlerFacadeH { $Me.DependentHeaders[0] }
            Property BaseClassPersistedHandlerFwdH { $Me.DependentHeaders[1] }
            Property ClassFwdH { $Me.ClassPersistedHandlerFacadeH.ClassFacadeH.ClassFwdH }
        }



$BaseClassPersistedHandlerHpp = 
    $Custom | 
        Prototype BaseClassPersistedHandlerHpp {
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPersistedHandlerHpp.Template.ps1' }
            Property BaseClassPersistedHandlerH { $Me.DependentHeaders[0] }
            Property ClassFwdH { $Me.BaseClassPersistedHandlerH.ClassFwdH }
            Property DeclareAdditionalInstantiation { "SWATHE_DECLARE_$($Me.Name.ToAllCaps())_ADDITIONAL_INSTANTIATION" }
        }



$BaseClassPersistedHandlerCpp = 
    $Custom | 
        Prototype BaseClassPersistedHandlerCpp {
            New {
                param ($File) 
                $Custom.New($File)
                $Me.m_baseClassesWithoutThis = $null
            }
            
            OverrideProperty DependentHeaders {
                , $Custom.DependentHeaders
            } {
                $Me.m_baseClassesWithoutThis = $null
                $Custom.DependentHeaders = @($Params) 
            }
            OverrideProperty Template { 'Swathe.New-Declaration.BaseClassPersistedHandlerCpp.Template.ps1' }
            
            Property BaseClassPersistedHandlerHpp { $Me.DependentHeaders[0] }

            Field m_baseClassesWithoutThis ([Object[]].Default) -Hidden
            Property BaseClassesWithoutThis {
                if ($null -eq $Me.m_baseClassesWithoutThis) {
                    $Me.m_baseClassesWithoutThis = 
                        { $Me.DependentHeaders } | 
                            QWhere { $1.CategoryName -cmatch '^BaseClass.*H$' } | 
                            QWhere { $1.FullName -ne $Me.BaseClassPersistedHandlerHpp.FullName } | 
                            QDistinct { $1.Name } | 
                            QToArray -Variable { $Me }
                }
                , $Me.m_baseClassesWithoutThis
            }
        }



$AllH = 
    $Custom | 
        Prototype AllH {
            OverrideProperty Directory { $Me.RootDirectory + '/' + ($Me.Namespaces -join '/') }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Custom.Namespaces[0..($Custom.Namespaces.Length - 3)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
            OverrideProperty Template { 'Swathe.New-Declaration.AllH.Template.ps1' }
        }
