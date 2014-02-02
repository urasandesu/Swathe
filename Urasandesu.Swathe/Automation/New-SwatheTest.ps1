# 
# File: New-SwatheTest.ps1
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

param (
    [Parameter(Position = 0)]
    [string]
    $RootDirectory, 

    [Parameter(Position = 1)]
    [string]
    $Filter, 
    
    [Parameter(Position = 2)]
    [string]
    $Vcxproj, 
    
    [Parameter(Position = 3)]
    [string]
    $VcxprojFilters, 
    
    [switch]
    $WhatIf
)


$here = Split-Path $MyInvocation.MyCommand.Path
if ([string]::IsNullOrEmpty($RootDirectory)) {
    $RootDirectory = Join-Path $PWD ('SwatheTest.Published_' + [datetime]::Now.ToString('yyyyMMddHHmmss'))
    Write-Verbose ('$RootDirectory is null or empty. It is set default value "{0}".' -f $RootDirectory) 
    if (![IO.Directory]::Exists($RootDirectory)) {
        New-Item $RootDirectory -ItemType Directory -WhatIf:$WhatIf -ErrorAction Stop | Out-Null
    }
}

if ([string]::IsNullOrEmpty($Vcxproj)) {
    $Vcxproj = Join-Path $PWD 'Test.Urasandesu.Swathe.vcxproj'
    Write-Verbose ('$Vcxproj is null or empty. It is set default value "{0}".' -f $Vcxproj) 
}
if (![IO.File]::Exists($Vcxproj)) {
    throw New-Object IO.FileNotFoundException ('"{0}" is not foud.' -f $Vcxproj)
}

if ([string]::IsNullOrEmpty($VcxprojFilters)) {
    $VcxprojFilters = Join-Path $PWD 'Test.Urasandesu.Swathe.vcxproj.filters'
    Write-Verbose ('$VcxprojFilters is null or empty. It is set default value "{0}".' -f $VcxprojFilters) 
}
if (![IO.File]::Exists($VcxprojFilters)) {
    throw New-Object IO.FileNotFoundException ('"{0}" is not foud.' -f $VcxprojFilters)
}

Write-Progress New-SwatheTest 'Loading: Swathe.ps1' 1
Write-Verbose 'Loading: Swathe.ps1'
. (Join-Path (Join-Path $here Swathe) Swathe.ps1) $RootDirectory



$prototypes = 
    { $Records.GetEnumerator() } | 
        QWhere { ![string]::IsNullOrEmpty($1.Value.Path) } | 
        QWhere { ![string]::IsNullOrEmpty($1.Value.Directory) } | 
        QWhere { [string]::IsNullOrEmpty($Filter) -or ($1.Value.Path -match $Filter) } | 
        QOrderBy { $1.Value.Path } | 
        QToArray


$baseDirectory = '..\Urasandesu.Swathe'


$vcxprojFile = Split-Path $Vcxproj -Leaf
Write-Progress New-SwatheTest ('Saving: {0}' -f $vcxprojFile) 1 -PercentComplete 50
Write-Verbose ('Saving: {0}' -f $vcxprojFile)
$vcxprojXml = [xml](Get-Content $Vcxproj)
$vcxprojBldr = $VcxprojBuilder.New($vcxprojXml)
foreach ($entry in $prototypes) {
    $extension = $entry.Value.Extension
    if ('.cpp' -eq $extension) {
        $vcxprojBldr.AddIfNecessary(($baseDirectory, $entry.Value))
    }
}
$vcxprojXml.Save((Join-Path $RootDirectory $vcxprojFile))



$VcxprojFiltersFile = Split-Path $VcxprojFilters -Leaf
Write-Progress New-SwatheTest ('Saving: {0}' -f $VcxprojFiltersFile) 1 -PercentComplete 100
Write-Verbose ('Saving: {0}' -f $VcxprojFiltersFile)
$vcxprojFiltersXml = [xml](Get-Content $VcxprojFilters)
$vcxprojFiltersBldr = $VcxprojFiltersBuilder.New($vcxprojFiltersXml)
foreach ($entry in $prototypes) {
    $extension = $entry.Value.Extension
    if ('.cpp' -eq $extension) {
        $vcxprojFiltersBldr.AddIfNecessary(($baseDirectory, $entry.Value))
    }
}
$vcxprojFiltersXml.Save((Join-Path $RootDirectory $VcxprojFiltersFile))

