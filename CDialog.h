BOOL CALLBACK CDlgProc(HWND hDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	HWND hBtn;
	switch(iMsg)
	{
		case WM_COMMAND : switch(LOWORD(wParam))
						  {
							case IDOK :/*strcpy(CLASS[i].cname,(GetWindowText( */
										EndDialog(hDlgWnd,0);
								    break;
						  }
						  break;
		case WM_INITDIALOG :hBtn=GetDlgItem(hDlgWnd,IDOK);
		  				 SetFocus(hBtn);
						 break;
		case WM_CLOSE :	EndDialog(hDlgWnd);
						break;
	}
	return FALSE;
}