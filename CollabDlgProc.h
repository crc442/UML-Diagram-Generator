BOOL CALLBACK CollabDlgProc(HWND hcbDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem();
						 SetFocus(hBtn);
						break;
		case WM_CLOSE : EndDialog(hcbDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
		case WM_COMMAND : switch(LOWORD(wParam))
						  {
							 
							case IDC_CBFTLINE: strcpy(tempID,"IDC_CBFTLINE");
												break;
							case IDC_CBSELECT: strcpy(tempID,"IDC_CBSELECT");
												break;
							case IDC_CBRECT: strcpy(tempID,"IDC_CBRECT");
												break;
							case IDC_CBCLINE: strcpy(tempID,"IDC_CBCLINE");
												break;
						  }
						  break;

	}
	return FALSE;
}