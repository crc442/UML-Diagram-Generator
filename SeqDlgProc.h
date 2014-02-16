BOOL CALLBACK SeqDlgProc(HWND hsqDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem(hsqDlgWnd,IDC_SQSELECT);
						 SetFocus(hBtn);
						 diaSelected=4;
						break;
		case WM_CLOSE : EndDialog(hsqDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED); 
					    break;
	case WM_COMMAND : switch(LOWORD(wParam))
						  {
							 
							case IDC_SQDBLLINE: strcpy(tempID,"IDC_SQDBLLINE");
												break;
							case IDC_SQSELECT: strcpy(tempID,"IDC_SQSELECT");
												break;
							case IDC_SQRECT: strcpy(tempID,"IDC_SQRECT");
												break;
							case IDC_SQDLINE: strcpy(tempID,"IDC_SQDLINE");
												break;
							case IDC_SQCROSS : strcpy(tempID,"IDC_SQCROSS");
												break;
							
						  }
						  break;
	}
	return FALSE;
}