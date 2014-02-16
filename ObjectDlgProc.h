
BOOL CALLBACK ObjectDlgProc(HWND hobDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;
	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem(hobDlgWnd,IDC_OBJSELECT);
						 SetFocus(hBtn);
						 diaSelected=2;
						break;
		case WM_CLOSE : EndDialog(hobDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
		case WM_COMMAND : switch(LOWORD(wParam))
						  {
							 
							case IDC_OBJGENERLZN: strcpy(tempID,"IDC_OBJGENERLZN");
												break;
							case IDC_OBJSELECT: strcpy(tempID,"IDC_OBJSELECT");
												break;
							case IDC_OBJFDIAMOND: strcpy(tempID,"IDC_OBJFDIAMOND");
												break;
							case IDC_OBJRECT: strcpy(tempID,"IDC_OBJRECT");
												break;
							case IDC_OBJFTRIANGLE: strcpy(tempID,"IDC_OBJFTRIANGLE");
												break;
							case IDC_OBJCLINE: strcpy(tempID,"IDC_OBJCLINE");
												break;
							case IDC_OBJTARROW : strcpy(tempID,"IDC_OBJTARROW");
						  					break;
						  }
						  break;
							
	}
	return FALSE;
}