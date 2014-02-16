
void Enablemenu(HWND hWnd)
{
	HMENU hMenu;
	hMenu=GetMenu(hWnd);
	
	EnableMenuItem (hMenu,IDM_SAVE,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_CLOSE,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_REFRESH,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_USECASE,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_OBJECT,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_COLLABORATION,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_SEQUENCE,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_ACTIVITY,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_STATE,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_COMPONENT,MF_ENABLED);
	EnableMenuItem (hMenu,IDM_DEPLOYMENT,MF_ENABLED);
 

}
