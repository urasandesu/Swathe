# 
# File: Swathe.Formattable.ps1
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

function ConvertTo-Paragraph {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    "`r`n" + (($InputObject | ConvertTo-Array -Variable $Variable) -join "`r`n") + "`r`n"
}

New-Alias QToParagraph ConvertTo-Paragraph -ErrorAction Stop

function ConvertTo-ParagraphOrEmpty {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    $content = $InputObject | Invoke-Linq -Variable $Variable
    if ($null -eq $content) {
        [string]::Empty
    } else {
        "`r`n" + ($content -join "`r`n") + "`r`n"
    }
}

New-Alias QToParagraphOrEmpty ConvertTo-ParagraphOrEmpty -ErrorAction Stop

function ConvertTo-CommaParagraph {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    "`r`n" + (($InputObject | ConvertTo-Array -Variable $Variable) -join ",`r`n") + "`r`n"
}

New-Alias QToCommaParagraph ConvertTo-CommaParagraph -ErrorAction Stop

function ConvertTo-CommaParagraphOrEmptry {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    $content = $InputObject | Invoke-Linq -Variable $Variable
    if ($null -eq $content) {
        [string]::Empty
    } else {
        "`r`n" + ($content -join ",`r`n") + "`r`n"
    }
}

New-Alias QToCommaParagraphOrEmptry ConvertTo-CommaParagraphOrEmptry -ErrorAction Stop

function ConvertTo-ParagraphParagraph {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    "`r`n" + (($InputObject | ConvertTo-Array -Variable $Variable) -join "`r`n`r`n") + "`r`n"
}

New-Alias QToParagraphParagraph ConvertTo-ParagraphParagraph -ErrorAction Stop

function ConvertTo-ParagraphParagraphOrEmpty {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    $content = $InputObject | Invoke-Linq -Variable $Variable
    if ($null -eq $content) {
        [string]::Empty
    } else {
        "`r`n" + ($content -join "`r`n`r`n") + "`r`n"
    }
}

New-Alias QToParagraphParagraphOrEmpty ConvertTo-ParagraphParagraphOrEmpty -ErrorAction Stop

function ConvertTo-Lines {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    "`r`n" + (($InputObject | ConvertTo-Array -Variable $Variable) -join "`r`n")
}

New-Alias QToLines ConvertTo-Lines -ErrorAction Stop

function ConvertTo-LinesOrEmpty {
    [CmdletBinding()]
    param (
        [Parameter(Mandatory = $true, ValueFromPipeline = $true)]
        [scriptblock]
        $InputObject, 
        
        [scriptblock]
        $Variable
    )
    $content = $InputObject | Invoke-Linq -Variable $Variable
    if ($null -eq $content) {
        [string]::Empty
    } else {
        "`r`n" + ($content -join "`r`n")
    }
}

New-Alias QToLinesOrEmpty ConvertTo-LinesOrEmpty -ErrorAction Stop
