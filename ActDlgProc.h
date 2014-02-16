BOOL CALLBACK ActDlgProc(HWND hactDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem(hactDlgWnd,IDC_ACTSELECT);
						 SetFocus(hBtn);
						break;
		case WM_CLOSE : EndDialog(hactDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
	case WM_COMMAND : switch(LOWORD(wParam))
						  {
							 
							case IDC_ACTFCIRCLE: strcpy(tempID,"IDC_ACTFCIRCLE");
												break;
							case IDC_ACTSELECT: strcpy(tempID,"IDC_ACTSELECT");
												break;
							case IDC_ACTDBLCIRCLE: strcpy(tempID,"IDC_ACTDBLCIRCLE");
												break;
							case IDC_ACTCRECT: strcpy(tempID,"IDC_ACTCRECT");
												break;
							case IDC_ACTDMD: strcpy(tempID,"IDC_ACTDMD");
												break;
							case IDC_ACTHLINE: strcpy(tempID,"IDC_ACTHLINE");
												break;
							case IDC_ACTDLINE: strcpy(tempID,"IDC_ACTDLINE");
						  					break;
						  }
					diaSelected=6;
						  break;
	}
	return FALSE;
}