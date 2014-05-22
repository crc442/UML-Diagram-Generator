BOOL CALLBACK DeplDlgProc(HWND hdeplDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem();
						 SetFocus(hBtn);
						break;
	case WM_COMMAND : switch(LOWORD(wParam))
					  {
						
	
						case IDC_DEPLRECT : strcpy(tempID,"IDC_DEPLRECT");
											break;
						case IDC_DEPLSELECT: strcpy(tempID,"IDC_DEPLSELECT");
											break;
						case IDC_DEPLDEPL: strcpy(tempID,"IDC_DEPLDEPL");
											break;
						case IDC_DEPLHLINE: strcpy(tempID,"IDC_DEPLHLINE");
											break;
					  }
					  break;
	
		case WM_CLOSE : EndDialog();
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
	}
	return FALSE;
}