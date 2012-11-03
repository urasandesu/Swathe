// stdafx.cpp : 標準インクルード Test.Urasandesu.Swathe.pch のみを
// 含むソース ファイルは、プリコンパイル済みヘッダーになります。
// stdafx.obj にはプリコンパイル済み型情報が含まれます。

#include "stdafx.h"
#include <corhlpr.cpp>

// TODO: このファイルではなく、STDAFX.H で必要な
// 追加ヘッダーを参照してください。

struct OleCom 
{
    OleCom() 
    { 
#ifdef _DEBUG
        ::_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); 
        //::_CrtSetBreakAlloc(4540);
#endif
        ::CoInitialize(NULL); 
    }
    ~OleCom() 
    { ::CoUninitialize(); }
} olecom;
