# 
# File: Swathe.New-Dependency.ps1
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

New-Variable Records @{ } -Option ReadOnly -ErrorAction Stop
New-Variable RecordsCache (New-Object Collections.Generic.HashSet[string]) -Option ReadOnly -ErrorAction Stop

function New-Dependency {
    
    [CmdletBinding()]    
    param (
        [parameter(Mandatory = $true, Position = 0)]
        [String]
        $TypeName, 
        
        [parameter(ValueFromRemainingArguments = $true)]
        [String[]]
        $TypeNames
    )

    if ($null -ne $TypeNames) {
        $Records[$TypeName].DependentHeaders = @(foreach ($TypeNames_ in $TypeNames) { $Records[$TypeNames_] })
    }
}

New-Alias DependsOn New-Dependency -ErrorAction Stop
