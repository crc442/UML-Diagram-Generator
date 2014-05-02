void AddBtnImage(HMENU hMenu,int cshow)
{
	switch(cshow)
	{
	
	case 8 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Deployment Diagram");
		      AddTreeItem("Deployment Diagram");
		      DeleteDlg();
		      EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
		      CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
		      break;
	case 9 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Class Diagram");
			 AddTreeItem("Class Diagram");
			 DeleteDlg();
			 EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
			 CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			 break;
	case 7 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Component Diagram");
			 AddTreeItem("Component Diagram");
			 DeleteDlg();
			 hcmptDlg=CreateDialog(hInst,"IDD_CMPTDIALOG",hWnd,(DLGPROC)CmptDlgProc);
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTCMPT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CMPTICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTDVARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DVARROW"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTHLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_EICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			 EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
	  	     CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			 break;
	case 6 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Activity Diagram");
			AddTreeItem("Activity Diagram");
			DeleteDlg();
			hactDlg=CreateDialog(hInst,"IDD_ACTDIALOG",hWnd,(DLGPROC)ActDlgProc);
			SendDlgItemMessage(hactDlg,IDC_ACTHARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ARROW"));
			SendDlgItemMessage(hactDlg,IDC_ACTDBLCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DBLCICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTFCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DCICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTCRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CRICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTHLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_LINEICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTDMD,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DMNDICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTUDARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_UDARROW"));
			SendDlgItemMessage(hactDlg,IDC_ACTDLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DARKLINE"));
			EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
		    CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			break;
	case 5 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"State Diagram");
			 AddTreeItem("State Diagram");
			 DeleteDlg();
			 hstDlg=CreateDialog(hInst,"IDD_STDIALOG",hWnd,(DLGPROC)StDlgProc);
			 SendDlgItemMessage(hstDlg,IDC_STHARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ARROW"));
			 SendDlgItemMessage(hstDlg,IDC_STDBLCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DBLCICON"));
			 SendDlgItemMessage(hstDlg,IDC_STFCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DCICON"));
			 SendDlgItemMessage(hstDlg,IDC_STELLIPSE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_EICON"));
			 SendDlgItemMessage(hstDlg,IDC_STCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			 SendDlgItemMessage(hstDlg,IDC_STSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			 EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
			 CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			 break;
	case 4 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Sequence Diagram");
			AddTreeItem("Sequence Diagram");
			DeleteDlg();
			hsqDlg=CreateDialog(hInst,"IDD_SQDIALOG",hWnd,(DLGPROC)SeqDlgProc);
			SendDlgItemMessage(hsqDlg,IDC_SQHARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ARROW"));
			SendDlgItemMessage(hsqDlg,IDC_SQUDARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_UDARROW"));
			SendDlgItemMessage(hsqDlg,IDC_SQSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			SendDlgItemMessage(hsqDlg,IDC_SQRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			SendDlgItemMessage(hsqDlg,IDC_SQDBLLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DBLLINE"));
			SendDlgItemMessage(hsqDlg,IDC_SQCROSS,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CROSSICON"));
			SendDlgItemMessage(hsqDlg,IDC_SQDLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SEQLINE"));
			EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
			CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			break;
	case 3 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Collaboration Diagram");
				 AddTreeItem("Collaboration Diagram");
				 DeleteDlg();
				 hcbDlg=CreateDialog(hInst,"IDD_CBDIALOG",hWnd,(DLGPROC)CollabDlgProc);
				 SendDlgItemMessage(hcbDlg,IDC_CBHARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ARROW"));
				 SendDlgItemMessage(hcbDlg,IDC_CBUDARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_UDARROW"));
				 SendDlgItemMessage(hcbDlg,IDC_CBSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
				 SendDlgItemMessage(hcbDlg,IDC_CBCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
				 SendDlgItemMessage(hcbDlg,IDC_CBRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
				 SendDlgItemMessage(hcbDlg,IDC_CBFTLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_FTLICON"));
				 EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
				 CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
				 break;
	case 2 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Object Diagram");
			  AddTreeItem("Object Diagram");
			  DeleteDlg();
			  hobDlg=CreateDialog(hInst,"IDD_OBJECTDLG",hWnd,(DLGPROC)ObjectDlgProc);							  
			  SendDlgItemMessage(hobDlg,IDC_OBJHARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ARROW"));
			  SendDlgItemMessage(hobDlg,IDC_OBJUDARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_UDARROW"));
			  SendDlgItemMessage(hobDlg,IDC_OBJTARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_LTICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJFTRIANGLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_FTICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJGENERLZN,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_LDIAMOND"));
			  SendDlgItemMessage(hobDlg,IDC_OBJSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJFDIAMOND,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_FDICON"));
			  EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
			  CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			  break;
	case 1 : SendMessage(hStatus1,SB_SETTEXT,1,(WPARAM)"Use Case Diagram");
			   AddTreeItem("Use Case Diagram");
			   DeleteDlg();
			   hucDlg=CreateDialog(hInst,"IDD_UCDIALOG",hWnd,(DLGPROC)UseCaseDlgProc);
			   SendDlgItemMessage(hucDlg,IDC_UCHARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ARROW"));
			   SendDlgItemMessage(hucDlg,IDC_UCACTOR,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ACTORICON"));
			   SendDlgItemMessage(hucDlg,IDC_UCELLIPSE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_EICON"));
			   SendDlgItemMessage(hucDlg,IDC_UCCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			   SendDlgItemMessage(hucDlg,IDC_UCRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			   SendDlgItemMessage(hucDlg,IDC_UCDLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RLZNICON"));
			   SendDlgItemMessage(hucDlg,IDC_UCUDARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_UDARROW"));
			   SendDlgItemMessage(hucDlg,IDC_UCSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			   EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
			   CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
			   break;
	}		
}
				