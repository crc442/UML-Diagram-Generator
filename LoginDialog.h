BOOL CALLBACK LoginDlgProc(HWND hDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	static HWND hDlgItem,hDlgItem1;
	char szUserName[10],szPassword[10];
	switch(iMsg)
	{
		case WM_INITDIALOG : hDlgItem=GetDlgItem(hDlgWnd,IDC_USEREDIT);
							 hDlgItem1=GetDlgItem(hDlgWnd,IDC_PASSEDIT);
							 SetFocus (hDlgItem);
							 break;
		case WM_COMMAND : switch(LOWORD(wParam))
				  {
					case IDOK :GetDlgItemText (hDlgWnd,IDC_USEREDIT,szUserName,10);
							   GetDlgItemText (hDlgWnd,IDC_PASSEDIT,szPassword,10);
							   if(strcmp(szUserName,"uml")==0 && strcmp(szPassword,"uml")==0)
									EndDialog(hDlgWnd,0);
							   
							   else
							   {
								    MessageBox(hDlgWnd,"Wrong User Name or Password","UML Designer",MB_OK|MB_ICONERROR);
									SetWindowText(hDlgItem,"");
									SetWindowText(hDlgItem1,"");
									SetFocus(hDlgItem);
							   }
							   break;
					case IDCANCEL: EndDialog(hDlgWnd,0);
								   PostQuitMessage(0);
								   exit(0);
								   break;				
				  }
				 break;
		case WM_CLOSE : EndDialog(hDlgWnd,0);
						PostQuitMessage(0);
						exit(0);
					    break;
	}
	return FALSE;
}