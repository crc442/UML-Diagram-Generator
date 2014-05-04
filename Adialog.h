BOOL CALLBACK ADlgProc(HWND hDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hDlgItem;
	switch(iMsg)
	{
		case WM_INITDIALOG : hDlgItem=GetDlgItem(hDlgWnd,ID_AOK);
						     SetFocus (hDlgItem);
						   break;
		case WM_COMMAND : switch(LOWORD(wParam))
						  {
								case ID_AOK : EndDialog(hDlgWnd,0);
											break;
						  }
						  break;
		case WM_CLOSE : EndDialog(hDlgWnd,0);
					    break;
	}
	return FALSE;
}