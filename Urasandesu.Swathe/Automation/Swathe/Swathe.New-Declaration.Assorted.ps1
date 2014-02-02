# 
# File: Swathe.New-Declaration.Assorted.ps1
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

$Assorted = 
    $SemiCommon | 
        Prototype Assorted {
            New { param ([Object[]]$items) $SemiCommon.New($items) }
        }


$RuntimeHostChainMapperH = 
    $Assorted | 
        Prototype RuntimeHostChainMapperH {
            New { $Assorted.New((ToDataRecordItems Urasandesu Swathe Hosting / / / RuntimeHostChainMapper / / .h)) }
        }


$SwatheStorageFwdH = 
    $Assorted | 
        Prototype SwatheStorageFwdH {
            New { $Assorted.New((ToDataRecordItems Urasandesu Swathe / Class / / SwatheStorage / Fwd .h)) }
            OverrideProperty DirectoryWithoutRoot { $Me.Namespaces -join '/' }
            OverrideProperty Namespace { $Me.Namespaces -join '::' }
            OverrideProperty Namespaces { $Assorted.Namespaces[0..($Assorted.Namespaces.Length - 2)] }
            OverrideProperty FullName { $Me.Namespace + '::' + $Me.Name }
            OverrideProperty Path { $Me.Directory + '/' + $Me.FileName }
            OverrideProperty PathWithoutRoot { $Me.DirectoryWithoutRoot + '/' + $Me.FileName }
            OverrideProperty IncludeGuard { ($Me.PathWithoutRoot -replace '[/.]', '_').ToUpper() }
        }


$SwatheStorageLabelH = 
    $Assorted | 
        Prototype SwatheStorageLabelH {
            New { $Assorted.New((ToDataRecordItems Urasandesu Swathe / ClassLabel / / SwatheStorage Label / .h)) }
        }


$DefaultSwatheStorageApiHolderH = 
    $Assorted | 
        Prototype DefaultSwatheStorageApiHolderH {
            New { $Assorted.New((ToDataRecordItems Urasandesu Swathe / DefaultClassApiHolder / Default SwatheStorage ApiHolder / .h)) }
        }


$BaseSwatheStorageFwdH = 
    $Assorted | 
        Prototype BaseSwatheStorageFwdH {
            New { $Assorted.New((ToDataRecordItems Urasandesu Swathe / BaseClass / Base SwatheStorage / Fwd .h)) }
        }


$BaseSwatheStorageH = 
    $Assorted | 
        Prototype BaseSwatheStorageH {
            New { $Assorted.New((ToDataRecordItems Urasandesu Swathe / BaseClass / Base SwatheStorage / / .h)) }
        }
