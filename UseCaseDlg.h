#include "Declare.h"
#include"resource.h"
 
HWND htext;
	char shapeflag;
	int shapid;
	int wmid;
	
BOOL CALLBACK UseCaseDlgProc(HWND hucDlgWnd,UINT iMsg,WPARAM wParam,LPARAM lParam) 
{
	HWND hBtn;

	//int wmid;

	switch(iMsg)
	{
	case WM_INITDIALOG : hBtn=GetDlgItem(hucDlgWnd,IDC_UCSELECT);
						 SetFocus(hBtn);
						 diaSelected=1;
						break;
		case WM_COMMAND : SendMessage(GetDlgItem(hucDlgWnd,wmid ),BM_SETSTATE,(WPARAM)FALSE,(LPARAM)NULL);
						 shapid=wmid;
						  
			               if(shapeflag==1)
						 {
							DestroyCaret();
							if(htext)
							DestroyWindow(htext);
						 }
						 wmid=LOWORD(wParam);
							switch(wmid)
						  {
							 
							case IDC_UCELLIPSE: strcpy(tempID,"IDC_UCELLIPSE");
												break;
							case IDC_UCSELECT: strcpy(tempID,"IDC_UCSELECT");
												break;
							case IDC_UCACTOR: strcpy(tempID,"IDC_UCACTOR");
												break;
							case IDC_UCRECT: strcpy(tempID,"IDC_UCRECT");
												break;
							case IDC_UCDLINE: strcpy(tempID,"IDC_UCDLINE");
												break;
							case IDC_UCCLINE: strcpy(tempID,"IDC_UCCLINE");
												break;
							 
											 
							 
						  }
						  break;
		case WM_CLOSE : EndDialog(hucDlgWnd,0);
						CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED);
					    break;
	}
	return FALSE;
}