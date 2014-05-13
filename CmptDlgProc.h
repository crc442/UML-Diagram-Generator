BOOL CALLBACK CmptDlgProc(HWND hcmptDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem(hcmptDlgWnd,IDC_STSELECT);
						 SetFocus(hBtn);
						 diaSelected=7;
						break;
	case WM_COMMAND : switch(LOWORD(wParam))
						  {
							case IDC_CMPTRECT : strcpy(tempID,"IDC_CMPTRECT");
												break;
							case IDC_CMPTCIRCLE: strcpy(tempID,"IDC_CMPTCIRCLE");
												break;
							case IDC_CMPTSELECT: strcpy(tempID,"IDC_CMPTSELECT");
												break;
							case IDC_CMPTDVARROW: strcpy(tempID,"IDC_CMPTDVARROW");
												break;
							case IDC_CMPTCMPT: strcpy(tempID,"IDC_CMPTCMPT");
												break;
							case IDC_CMPTHLINE: strcpy(tempID,"IDC_CMPTHLINE");
												break;
						  }
						  break;
				
		case WM_CLOSE : EndDialog(hcmptDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
	}
	return FALSE;
}



