void Disablemenu(HWND hWnd)
{
	HMENU hMenu;
	hMenu=GetMenu(hWnd);
	
	EnableMenuItem (hMenu,IDM_SAVE,MF_GRAYED);
	
	EnableMenuItem (hMenu,IDM_CLOSE,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_PRINT,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_UNDO,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_REDO,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_COPY,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_REFRESH,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_TOOLBOX,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_USECASE,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_OBJECT,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_COLLABORATION,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_SEQUENCE,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_ACTIVITY,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_STATE,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_COMPONENT,MF_GRAYED);
	EnableMenuItem (hMenu,IDM_DEPLOYMENT,MF_GRAYED);
 

}
