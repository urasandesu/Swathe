# 
# File: Swathe.New-Declaration.ps1
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

$here = Split-Path $MyInvocation.MyCommand.Path
. (Join-Path $here Swathe.New-Declaration.DataRecord.ps1)
. (Join-Path $here Swathe.New-Declaration.Function.ps1)
. (Join-Path $here Swathe.New-Declaration.File.ps1)
. (Join-Path $here Swathe.New-Declaration.Custom.ps1)
. (Join-Path $here Swathe.New-Declaration.Common.ps1)
. (Join-Path $here Swathe.New-Declaration.Generator.ps1)
. (Join-Path $here Swathe.New-Declaration.Misc.ps1)
. (Join-Path $here Swathe.New-Declaration.SemiCommon.ps1)
. (Join-Path $here Swathe.New-Declaration.Assorted.ps1)





function New-ImportCommon {
    
    [CmdletBinding()]    
    param (
        [parameter(Mandatory = $true)]
        [String]
        $Name
    )
    
    if ($RecordsCache.Add($Name)) {
        Invoke-Expression ('${0}.New()' -f $Name)
    }
}

New-Alias Import New-ImportCommon -ErrorAction Stop





function New-Declaration {
    
    [CmdletBinding()]    
    param (
        [parameter(Mandatory = $true, ValueFromRemainingArguments = $true)]
        [String[]]
        $Items
    )
    
    if ($RecordsCache.Add(($Items -join ''))) {
        $declaration = $File.New((ToDataRecordItems -Items:$Items))
        Invoke-Expression ('${0}.New($declaration)' -f $declaration.CategoryName)
    }

}

New-Alias Declare New-Declaration -ErrorAction Stop
