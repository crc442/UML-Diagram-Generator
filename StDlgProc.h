BOOL CALLBACK StDlgProc(HWND hstDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem(hstDlgWnd,IDC_STSELECT);
						 SetFocus(hBtn);
						 diaSelected=5;
						break;
		case WM_CLOSE : EndDialog(hstDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
		case WM_COMMAND : switch(LOWORD(wParam))
						  {
							 
							case IDC_STELLIPSE: strcpy(tempID,"IDC_STELLIPSE");
												break;
							case IDC_STSELECT: strcpy(tempID,"IDC_STSELECT");
												break;
							case IDC_STDBLCIRCLE: strcpy(tempID,"IDC_STDBLCIRCLE");
												break;
							case IDC_STFCIRCLE: strcpy(tempID,"IDC_STFCIRCLE");
												break;
							case IDC_STCLINE: strcpy(tempID,"IDC_STCLINE");
												break;
						  }
						  break;
	}
	return FALSE;
}