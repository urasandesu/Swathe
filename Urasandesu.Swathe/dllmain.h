// dllmain.h : モジュール クラスの宣言

class CUrasandesuSwatheModule : public ATL::CAtlDllModuleT< CUrasandesuSwatheModule >
{
public :
	DECLARE_LIBID(LIBID_UrasandesuSwatheLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_URASANDESUSWATHE, "{65D7C327-59C7-44FF-BD9C-65B4B3EB6204}")
};

extern class CUrasandesuSwatheModule _AtlModule;
