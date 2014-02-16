/*************************Uml Diagram Generator*********************/

#include "Main.h"
#include"resource.h"
#include "Openmenu.h"
#include "Savemenu.h"
 
HANDLE hFile;
HWND hChiWnd;
HWND hPbWnd,hucDlg,hobDlg,hcbDlg,hsqDlg,hstDlg,hactDlg;
HWND hcmptDlg,hdeplDlg;
HDC clipdc,PyHANDLE;
HBITMAP hclipbmp;	
HPEN hpen;
 
BITMAP bm;
DWORD dwTextLength,dwWritten,reply;
DWORD dwFileSize,dwRead;

char string[20];
static char szFileBuff[100]="";
static int cshow;
static int saveFlag=0;
static int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0,flag6=0,flag7=0,flag8=0 ;
static int wd,ht,openflag=0,oldrop;
int  filecnt=9;
int width,height;
int newx,newy;
void SaveFile(int,int);

void EnableDiaMenu()
{
	EnableMenuItem(hMenu,IDM_USECASE,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_OBJECT,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_COLLABORATION,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_SEQUENCE,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_STATE,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_ACTIVITY,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_DEPLOYMENT,MF_ENABLED);
	EnableMenuItem(hMenu,IDM_COMPONENT,MF_ENABLED);
	
}
void DeleteDlg()
{
	 EndDialog(hucDlg,0);
	 EndDialog(hobDlg,0);
	 EndDialog(hcbDlg,0);
	 EndDialog(hsqDlg,0);
	 EndDialog(hstDlg,0);
	 EndDialog(hactDlg,0);
	 EndDialog(hcmptDlg,0);
	 EndDialog(hdeplDlg,0);
	 
}

void ShowToolBox(HWND hWnd,int cshow)
{
	DeleteDlg();
	switch(cshow)
	{
	

	case 8 : hdeplDlg=CreateDialog(hInst,"IDD_DEPLDIALOG",hWnd,(DLGPROC)DeplDlgProc);
			 SendDlgItemMessage(hdeplDlg,IDC_DEPLSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			 SendDlgItemMessage(hdeplDlg,IDC_DEPLHLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			 SendDlgItemMessage(hdeplDlg,IDC_DEPLDEPL,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DEPLICON"));
			 SendDlgItemMessage(hdeplDlg,IDC_DEPLRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			 break;
	case 7 : hcmptDlg=CreateDialog(hInst,"IDD_CMPTDIALOG",hWnd,(DLGPROC)CmptDlgProc);
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTCMPT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CMPTICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTDVARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DVARROW"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTHLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_EICON"));
			 SendDlgItemMessage(hcmptDlg,IDC_CMPTRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			 break;
	case 6 :hactDlg=CreateDialog(hInst,"IDD_ACTDIALOG",hWnd,(DLGPROC)ActDlgProc); 
		 
			SendDlgItemMessage(hactDlg,IDC_ACTDBLCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DBLCICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTFCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DCICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTCRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CRICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTHLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_LINEICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTDMD,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DMNDICON"));
			SendDlgItemMessage(hactDlg,IDC_ACTDLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DARKLINE"));
			break;
	case 5 : hstDlg=CreateDialog(hInst,"IDD_STDIALOG",hWnd,(DLGPROC)StDlgProc);
			  
			 SendDlgItemMessage(hstDlg,IDC_STDBLCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DBLCICON"));
			 SendDlgItemMessage(hstDlg,IDC_STFCIRCLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_DCICON"));
			 SendDlgItemMessage(hstDlg,IDC_STELLIPSE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_EICON"));
			 SendDlgItemMessage(hstDlg,IDC_STCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			 SendDlgItemMessage(hstDlg,IDC_STSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			 break;
	case 4 :hsqDlg=CreateDialog(hInst,"IDD_SQDIALOG",hWnd,(DLGPROC)SeqDlgProc); 
			SendDlgItemMessage(hsqDlg,IDC_SQSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			SendDlgItemMessage(hsqDlg,IDC_SQRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			SendDlgItemMessage(hsqDlg,IDC_SQCROSS,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CROSSICON"));
			SendDlgItemMessage(hsqDlg,IDC_SQDLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SEQLINE"));
			break;
	case 3 : hcbDlg=CreateDialog(hInst,"IDD_CBDIALOG",hWnd,(DLGPROC)CollabDlgProc);
			 SendDlgItemMessage(hcbDlg,IDC_CBSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			 SendDlgItemMessage(hcbDlg,IDC_CBCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			 SendDlgItemMessage(hcbDlg,IDC_CBRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			 SendDlgItemMessage(hcbDlg,IDC_CBFTLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_FTLICON"));
			 break;
	case 2 : hobDlg=CreateDialog(hInst,"IDD_OBJDIALOG",hWnd,(DLGPROC)ObjectDlgProc);
			  SendDlgItemMessage(hobDlg,IDC_OBJTARROW,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_LTICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJFTRIANGLE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_FTICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJGENERLZN,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_LDIAMOND"));
			  SendDlgItemMessage(hobDlg,IDC_OBJSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			  SendDlgItemMessage(hobDlg,IDC_OBJFDIAMOND,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_FDICON"));
			  break;
	case 1 :  hucDlg=CreateDialog(hInst,"IDD_UCDIALOG",hWnd,(DLGPROC)UseCaseDlgProc);
			  SendDlgItemMessage(hucDlg,IDC_UCACTOR,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_ACTORICON"));
			  SendDlgItemMessage(hucDlg,IDC_UCELLIPSE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_EICON"));
			  SendDlgItemMessage(hucDlg,IDC_UCCLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_CLICON"));
			  SendDlgItemMessage(hucDlg,IDC_UCRECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RICON"));
			  SendDlgItemMessage(hucDlg,IDC_UCDLINE,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_RLZNICON"));
			  SendDlgItemMessage(hucDlg,IDC_UCSELECT,BM_SETIMAGE,(WPARAM)IMAGE_ICON,(LPARAM)LoadIcon(hInst,"IDI_SELICON"));
			  break;
	}	
	EnableMenuItem(hMenu,IDM_TOOLBOX,MF_ENABLED);
	CheckMenuItem (hMenu,IDM_TOOLBOX,MF_CHECKED);
}
	

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMsg,WPARAM wParam, LPARAM lParam)
{
	
	RECT rect,windowRect;
	HDC hDcPrn;
	static HWND hAbout;
 	static int cxCell,cyCell,x,y,tempx,tempy,mx,my;
	static int checked;
	int pt[3],i=0,j,ccnt=0;
	static int pos;
	static char szBuffer[30],temp[20];
	//DWORD reply;
	//MENUITEMINFO mii;
	BOOL bSuccess; 
	static HDC hDc;
	PAINTSTRUCT ps;
	//HBRUSH hBrush;
	static PRINTDLG printdlg={sizeof(PRINTDLG)};
	static DOCINFO di = { sizeof (DOCINFO), TEXT ("EmfView: Printing") } ;
	hMenu=GetMenu(hWnd);
	static int width,height;
	
	INITCOMMONCONTROLSEX cc,pbcc,tvc;
	//For Statusbar class
	cc.dwSize =sizeof(cc);
	cc.dwICC =ICC_BAR_CLASSES;
	InitCommonControlsEx(&cc);
	//For Progressbar class
	pbcc.dwSize =sizeof(pbcc);
	pbcc.dwICC =ICC_PROGRESS_CLASS;
	InitCommonControlsEx(&pbcc);
	//For Treeview class
	tvc.dwSize =sizeof(tvc);
	tvc.dwICC =ICC_TREEVIEW_CLASSES;
	InitCommonControlsEx(&tvc);

	switch(iMsg)
	{
	case WM_TIMER : pos=SendMessage(hPbWnd,PBM_GETPOS,0,0);
					if(pos==100)
					{
						KillTimer(hWnd,TIMER1);
						DestroyWindow(hPbWnd);
					}
					else
						SendMessage(hPbWnd,PBM_STEPIT,1,0);
					break;
	case WM_SIZE : cxCell=LOWORD(lParam);
				   cyCell=HIWORD(lParam);
				   MoveWindow(hStatus1,cxCell,cyCell-15,cyCell,cxCell,TRUE);
				   MoveWindow(hChildWnd,120,37,cxCell-123,cyCell-54,TRUE);
				   				   
				   GetClientRect(hWnd,&rect);
				   GetWindowRect (hWnd,&windowRect);
				   
				   //MoveWindow(hucDlg,rect.left*4,(rect.top*8)+150,(rect.left*8) +76,(rect.top *8)+23+289,TRUE);

				   //MoveWindow(hucDlg,windowRect.left ,windowRect.top +288,122,240,TRUE) ;
				   //MoveWindow(hucDlg,windowRect.left,windowRect.top+288,76,289,TRUE);
				   pt[0]=rect.right /3;
				   pt[1]=rect.right *2/3;
				   pt[2]=rect.right ;
				   SendMessage(hStatus1,SB_SETPARTS,(WPARAM)3,(LPARAM)pt);
				   SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Ready");
			   
				    break;
	case WM_CREATE ://SetWindowOrgEx(hDc,120,38,NULL);
			        //SetViewportExtEx (hDc,120,38,NULL);
					//TextOut(GetDC(hWnd),5,0,"T&reeView",10);
					DialogBox(hInst,"IDD_LOGINDIALOG",hWnd,(DLGPROC)LoginDlgProc);
					hStatus1=CreateStatusWindow(WS_CHILD|WS_VISIBLE|WS_CLIPSIBLINGS,NULL,hWnd,NULL);
					hMenu=GetMenu(hWnd);
					hSubMenu=GetSubMenu(hMenu,0);
					//SendMessage((HWND)IDM_SAVE,MF_BITMAP,(WPARAM)IMAGE_ICON,(LPARAM)LoadBitmap(hInst,"IDB_SAVEBITMAP"));
				 
					//SetMenuItemBitmaps(hSubMenu,IDM_SAVE,MF_BYCOMMAND,(HBITMAP)LoadBitmap(hInst,"IDB_SAVEBMP"),(HBITMAP)LoadBitmap(hInst,"IDB_SAVEBMP"));
									
					Disablemenu(hWnd);
						 				
					break;
	case WM_MENUSELECT : switch(LOWORD(wParam))
						 {
						case IDM_NEWPROJECT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates New Project");
											  break;
						case IDM_OPEN : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Opens an existing Project");
											  break;
						case IDM_SAVE : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Saves the Project");
											  break;
						case IDM_CLOSE : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Closes Project");
											  break;
						case IDM_PRINT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Prints all diagrams of Project");
											  break;
						case IDM_EXIT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Quits the application; prompts to Save Project");
										break;
						case IDM_USECASE : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Use Case Diagram");
											  break;
						case IDM_OBJECT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Object Diagram");
											  break;
						case IDM_COLLABORATION : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Collaboration Diagram");
											  break;
						case IDM_ACTIVITY : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Activity Diagram");
											  break;
						case IDM_DEPLOYMENT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Deployment Diagram");
											  break;
						case IDM_COMPONENT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Component Diagram");
											  break;
						case IDM_SEQUENCE : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates Sequence Diagram");
											  break;
						case IDM_STATE : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Creates State Diagram");
											  break;
						case IDM_UNDO : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Undoes the last action");
											  break;
						case IDM_REDO : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Redoes the previously undone action");
											  break;
						case IDM_COPY : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Copies the selection to Clipboard");
											  break;
						
						case IDM_ABOUT : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Displays the program information and copyright");
											  break;
						case IDM_TOOLBOX : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Displays Toolbox");
											  break;
						default : SendMessage(hStatus1,SB_SETTEXT,0,(LPARAM)"Ready");
								  break;
						 }
						strcpy(tempID,"");
						break;


						

	
	case WM_NOTIFY : nmptr=(LPNMTREEVIEW)lParam;
					 if(nmptr->hdr.code==TVN_SELCHANGED)
					 {
						 if(nmptr->itemNew.hItem==hTreeWnd[1])
						 {//Use Case Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[1]);
							 diaSelected=1;
							 DeleteDlg();
							 ShowToolBox(hWnd,1);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[2])
						 {//Object Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[2]);
							 diaSelected=2;
							 DeleteDlg();
							 ShowToolBox(hWnd,2);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[3])
						 {//Collaboration Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[3]);
							 diaSelected=3;
							 DeleteDlg();
							 ShowToolBox(hWnd,3);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[4])
						 {//Sequence Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[4]);
							 diaSelected=4;
							 DeleteDlg();
							 ShowToolBox(hWnd,4);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[5])
						 {//State Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[5]);
							 diaSelected=5;
							 DeleteDlg();
							 ShowToolBox(hWnd,5);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[6])
						 {//Activity Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[6]);
							 diaSelected=6;
							 DeleteDlg();
							 ShowToolBox(hWnd,6);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[7])
						 {//Component Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[7]);
							 diaSelected=7;
							 DeleteDlg();
							 ShowToolBox(hWnd,7);
						 }
						 else if(nmptr->itemNew.hItem==hTreeWnd[8])
						 {//Deployment Diagram
							 InvalidateRect(hChildWnd,NULL,TRUE);
							 SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)hTreeWnd[8]);
							 diaSelected=8;
							 DeleteDlg();
							 ShowToolBox(hWnd,8);
						 }
						 
					 }
					 strcpy(tempID,"");
					 break;
	case WM_COMMAND : 
					  switch(LOWORD(wParam))
					  {
						case IDM_NEWPROJECT : SetWindowText(hWnd,"Untitled - UML Designer");
											//if any other project was already open so Disablemenu()
											  Disablemenu(hWnd);
										      Enablemenu(hWnd);
											  DeleteDlg();
											  cshow=0;
											  DestroyWindow(htvwWnd);
											  DestroyWindow(hChildWnd);

  											  htvwWnd=CreateWindow(WC_TREEVIEW,"",WS_BORDER|WS_TABSTOP|WS_CHILD|WS_VISIBLE|TVS_HASBUTTONS|WS_TABSTOP|TVS_HASLINES|TVS_LINESATROOT ,0,37,120,208,hWnd,NULL,hInst,NULL);
											  
											  tvi.mask=TVIF_TEXT|TVIF_STATE;
											  tvi.pszText="Diagrams";
											  tvs.hParent =TVI_ROOT;
											  tvs.hInsertAfter=TVI_SORT;
											  tvs.item=tvi;
											  hTreeItem=(HTREEITEM)SendMessage(htvwWnd,TVM_INSERTITEM,0,(WPARAM)&tvs);
											  SendMessage(htvwWnd,TVM_EXPAND,(WPARAM)TVE_EXPAND,(LPARAM)hTreeItem);
											  ShowWindow(htvwWnd,FALSE);
											  EnableDiaMenu();
											//Save Flag for new project
											  saveFlag=0;
											  sbHorz=0;
											  sbVert=0;
											  break;
						case IDM_OPEN :	sbHorz=0;
										sbVert=0;
										Openmenu(hWnd);
										//1..4 for closing previous project
										DeleteDlg();//1
										cshow=0;//2
										DestroyWindow(htvwWnd);//3
										DestroyWindow(hChildWnd);//4
											//saveFlag is set to 1 for saving same project without Save DialogBox
										saveFlag=1;
											//The file name from OpenDialogBox is used as name to Save project
										strcpy(szSaveFileName,szOpenFileName);
										
										if(strcmp(szOpenFileName,"")!=0)
										{
											SetWindowText(hWnd,tempOpen);
											CallProgressBar(hWnd,cxCell,cyCell);
											SetTimer(hWnd,TIMER1,5,NULL);
											strcpy(tempOpen,"");
										}
										else
											break;
										EnableMenuItem(hMenu,IDM_CLOSE,MF_ENABLED);
										htvwWnd=CreateWindow(WC_TREEVIEW,"",WS_BORDER|WS_TABSTOP|WS_CHILD|WS_VISIBLE|TVS_HASBUTTONS|WS_TABSTOP|TVS_HASLINES|TVS_LINESATROOT,0,37,120,208,hWnd,NULL,hInst  ,NULL);
										tvi.mask=TVIF_TEXT;		
										tvi.pszText="Diagrams";
										tvs.hParent =TVI_ROOT;
										tvs.hInsertAfter=TVI_SORT;
										tvs.item=tvi;
										hTreeItem=(HTREEITEM)SendMessage(htvwWnd,TVM_INSERTITEM,0,(WPARAM)&tvs);

										umlCnt=0;	
										hFile=CreateFile(szOpenFileName,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
										dwFileSize=20;
										while(1)
										{
											if(ReadFile(hFile,szFileBuff,dwFileSize,&dwRead,NULL))
											{
													//Within for loop spaces in szFileBuff are counted
												for(i=0,j=0;i<(signed int)strlen(szFileBuff);i++)
												{
													if(szFileBuff[i]==' ')
														j++;
												}
											         //If szFileBuff contains all spaces i.e. no UML structure
												if(j==(signed int)strlen(szFileBuff))
													break;
												else
												{												
													sscanf(szFileBuff,"%d%d%d%d%d%d",&UML[umlCnt].diaNo,&UML[umlCnt].type,&UML[umlCnt].Rect.left,&UML[umlCnt].Rect.top,&UML[umlCnt].Rect.right,&UML[umlCnt].Rect.bottom);
													umlCnt++;
												}
											}
											else
												break;
											strcpy(szFileBuff,"");
										}
										CloseHandle(hFile);
										EnableMenuItem(hMenu,IDM_UNDO,MF_ENABLED);
										//EnableMenuItem(hMenu,IDM_COPY,MF_ENABLED);
										 Enablemenu(hWnd);
										for(i=0;i<umlCnt;i++)
										{
											cshow=UML[i].diaNo;
											if(cshow==1 && flag1==0)
											{
													AddTreeItem("Use Case Diagram",cshow);
													EnableMenuItem(hMenu,IDM_USECASE,MF_GRAYED);
													flag1=1;
											}
											else if(cshow==2 && flag2==0)
											{
													AddTreeItem("Object Diagram",cshow);
													EnableMenuItem(hMenu,IDM_OBJECT,MF_GRAYED);
													flag2=1;
											}
											else if(cshow==3 && flag3==0)
											{
													AddTreeItem("Collaboration Diagram",cshow);
													EnableMenuItem(hMenu,IDM_COLLABORATION,MF_GRAYED);
													flag3=1;
											}
											else if(cshow==4 && flag4==0)
											{
													AddTreeItem("Sequence Diagram",cshow);
													EnableMenuItem(hMenu,IDM_SEQUENCE,MF_GRAYED);
													flag4=1;
											}
											else if(cshow==5 && flag5==0)
											{
													AddTreeItem("State Diagram",cshow);
													EnableMenuItem(hMenu,IDM_STATE,MF_GRAYED);
													flag5=1;
											}
											else if(cshow==6 && flag6==0)
											{
													AddTreeItem("Activity Diagram",cshow);
													EnableMenuItem(hMenu,IDM_ACTIVITY,MF_GRAYED);
													flag6=1;
											}
											else if(cshow==7 && flag7==0)
											{
													AddTreeItem("Component Diagram",cshow);
													EnableMenuItem(hMenu,IDM_COMPONENT,MF_GRAYED);
													flag7=1;
											}
											else if(cshow==8 && flag8==0)
											{
													AddTreeItem("Deployment Diagram",cshow);
													EnableMenuItem(hMenu,IDM_DEPLOYMENT,MF_GRAYED);
													flag8=1;
											}
											
										}
										SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)(HTREEITEM)hTreeWnd[cshow]);
										SetFocus(htvwWnd);
										TreeView_Select(htvwWnd,hTreeWnd[cshow],TVGN_CARET);
										TreeView_Expand(htvwWnd,hTreeWnd[cshow],TVE_EXPAND);
										diaSelected=cshow;
										ShowToolBox(hWnd,cshow);													
										break;
						case IDM_REDO : if(undoFlag>1)
										{
											EnableMenuItem(hMenu,IDM_UNDO,MF_ENABLED);
											for(i=0;i<umlCnt;i++)
											{
												if(UML[i].undo==1)
												{
													UML[i].undo =0;
													undoFlag=undoFlag-1;
													if(undoFlag==1)//if undoFlag=1 i.e. initial value
													{
														EnableMenuItem(hMenu,IDM_REDO,MF_GRAYED);
														EnableMenuItem(hMenu,IDM_UNDO,MF_ENABLED);
														
													}
													break;
												}	
											}
										}
										break;
						case IDM_UNDO :	
										if(undoFlag<=umlCnt)
									   {
										    EnableMenuItem(hMenu,IDM_REDO,MF_ENABLED);
											UML[umlCnt-undoFlag].undo =1;
											undoFlag=undoFlag+1;
									   }
									   if(undoFlag>umlCnt)
									   {
										    EnableMenuItem(hMenu,IDM_UNDO,MF_GRAYED);
									 
										    EnableMenuItem(hMenu,IDM_COPY,MF_GRAYED);
									 
									   }
									   break;
						case IDM_SAVE : SaveFile(cxCell,cyCell);
										break;
						case IDM_CLOSE :cshow=0;
										DestroyWindow(htvwWnd);
										DestroyWindow(hChildWnd);
										DeleteDlg();
										Disablemenu(hWnd);
										SetWindowText(hWnd,"UML Designer");
										SendMessage(hStatus1,SB_SETTEXT,2,(LPARAM)"");
										SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"");
										umlCnt=0;
										strcpy(szOpenFileName,"");
										strcpy(tempOpen,"");
										//strcpy(szSaveFileName,"");
										strcpy(tempSave,"");
										break;
						case IDM_TOOLBOX : if(MF_CHECKED==CheckMenuItem(hMenu,IDM_TOOLBOX,MF_UNCHECKED))
												DeleteDlg();
											else
											 {
												 CheckMenuItem(hMenu,IDM_TOOLBOX,MF_CHECKED);
												 ShowToolBox(hWnd,cshow);
											 }
										break;
						case IDM_EXIT :	
											PostQuitMessage(0);
										break;
					 
						


						case IDM_COPY : EnableMenuItem(hMenu,IDM_COPY,MF_GRAYED);
								 
										 /*TO DISAPPEAR THE DOTTED RECT*/
										 hChildDc=GetDC(hChildWnd);					
										 oldrop=SetROP2(hChildDc,R2_NOTXORPEN);
										 hpen=(HPEN)SelectObject(hChildDc,CreatePen(PS_DOT,1,RGB(0,0,0)));
										 Rectangle(hChildDc,DottedRect.left,DottedRect.top,DottedRect.right,DottedRect.bottom );
										 SelectObject(hChildDc,hpen);
										 DeleteObject(hpen);								
										 clipdc=CreateCompatibleDC(hChildDc);

										 width= DottedRect.right-DottedRect.left ;
										 height= DottedRect.bottom-DottedRect.top;

										 hclipbmp=CreateCompatibleBitmap(hChildDc,width,height);				
										 SelectObject(clipdc,hclipbmp);
										 BitBlt(clipdc,0,0,width,height,hChildDc,DottedRect.left+sbVert,DottedRect.top+sbHorz,SRCCOPY);
										
										
										 if(OpenClipboard(hChildWnd))
											{
												EmptyClipboard();
												SetClipboardData(CF_BITMAP,hclipbmp);
												CloseClipboard();
										 
											}
									
										DeleteDC(clipdc);
										DeleteObject(hclipbmp);
										ReleaseDC(hChildWnd,hChildDc);
										InvalidateRect(hChildWnd,NULL,TRUE);
										break;
 
			  
						case IDM_PRINT : printdlg.Flags = PD_RETURNDC | PD_NOPAGENUMS | PD_NOSELECTION ;

											if (!PrintDlg (&printdlg))
												return 0 ;
               
											if (NULL == (hDcPrn = printdlg.hDC)) 
											{
												MessageBox (hWnd, TEXT ("Cannot obtain printer DC"),
												"UML Designer...", MB_ICONEXCLAMATION | MB_OK) ;
												return 0 ;
											 }
											// Get size of printable area of page

											rect.left   = 0 ;
											rect.right  = GetDeviceCaps (hDcPrn, HORZRES) ;
											rect.top    = 0 ;
											rect.bottom = GetDeviceCaps (hDcPrn, VERTRES) ;

											bSuccess = FALSE ;

											// Play the EMF to the printer

											SetCursor (LoadCursor (NULL, IDC_WAIT)) ;
											ShowCursor (TRUE) ;
											hMetaDc=CreateMetaFile(NULL);
											Rectangle(hMetaDc,100,100,200,200);
											// DrawCmptMetaFile(GetDC(hChildWnd),lx,ly);
				
											hMf=CloseMetaFile(hMetaDc);
											 if ((StartDoc (hDcPrn, &di) > 0) && (StartPage (hDcPrn) > 0))
											{
                      
													PlayMetaFile (hDcPrn, hMf) ;
						 
				   
				   
                    
													if (EndPage (hDcPrn) > 0)
													{
														bSuccess = TRUE ;
														EndDoc (hDcPrn) ;
													}
											}
											ShowCursor (FALSE) ;
											SetCursor (LoadCursor (NULL, IDC_ARROW)) ;
											DeleteDC (hDcPrn) ;

											 if (!bSuccess)
											MessageBox (hWnd, TEXT ("Could not print metafile"),
											"UML Designer...", MB_ICONEXCLAMATION | MB_OK) ;
											return 0 ;
											break;
          
						
						case IDM_ABOUT :PlaySound("Setup0.wav",NULL,SND_FILENAME|SND_ASYNC);
										DialogBox(hInst,"IDD_ADIALOG",hWnd,(DLGPROC)ADlgProc);
										break;
						case IDM_DEPLOYMENT : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Deployment Diagram");
											  cshow=8;
											  AddTreeItem("Deployment Diagram",cshow);
											  ShowToolBox(hWnd,cshow);
											  EnableMenuItem(hMenu,IDM_DEPLOYMENT,MF_GRAYED);
											  break;
						
										  
						case IDM_COMPONENT : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Component Diagram");
											 cshow=7;
											 AddTreeItem("Component Diagram",cshow);
											 ShowToolBox(hWnd,cshow);
											 EnableMenuItem(hMenu,IDM_COMPONENT,MF_GRAYED);
											 break;
						case IDM_ACTIVITY : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Activity Diagram");
											cshow=6;
											AddTreeItem("Activity Diagram",cshow);
											ShowToolBox(hWnd,cshow);
											EnableMenuItem(hMenu,IDM_ACTIVITY,MF_GRAYED);
											break;
						case IDM_STATE : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"State Diagram");
										 cshow=5;
										 AddTreeItem("State Diagram",cshow);
										 ShowToolBox(hWnd,cshow);
										 EnableMenuItem(hMenu,IDM_STATE,MF_GRAYED);
										 break;
						case IDM_SEQUENCE : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Sequence Diagram");
											cshow=4;
											AddTreeItem("Sequence Diagram",cshow);
											ShowToolBox(hWnd,cshow);
											EnableMenuItem(hMenu,IDM_SEQUENCE,MF_GRAYED);
											break;
						case IDM_COLLABORATION : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Collaboration Diagram");
												 cshow=3;
												 AddTreeItem("Collaboration Diagram",cshow);
								 				 ShowToolBox(hWnd,cshow);
												 EnableMenuItem(hMenu,IDM_COLLABORATION,MF_GRAYED);
												 break;
						case IDM_OBJECT : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Object Diagram");
										  cshow=2;
										  AddTreeItem("Object Diagram",cshow);
										  DestroyWindow(hChildWnd);
										  ShowToolBox(hWnd,cshow);
										  EnableMenuItem(hMenu,IDM_OBJECT,MF_GRAYED);
										  break;
						
						case IDM_USECASE : SendMessage(hStatus1,SB_SETTEXT,1,(LPARAM)"Use Case Diagram");
										   cshow=1;
										   AddTreeItem("Use Case Diagram",cshow);
										   ShowToolBox(hWnd,cshow);
										   EnableMenuItem(hMenu,IDM_USECASE,MF_GRAYED);
										   break;
					  }
				if(cshow>=1 && cshow<=8)
				{
					DestroyWindow(hChildWnd);
		hChildWnd=CreateWindow(szChild,
		"",WS_VISIBLE|WS_CHILD|WS_BORDER|WS_VSCROLL|WS_HSCROLL,120, 37,cxCell-120,cyCell-55,
		hWnd,
		NULL,
		hInst,
		NULL);
		sbHorz=0;
		sbVert=0;
		SetScrollRange(hChildWnd,SB_HORZ,1,500,TRUE); 
		SetScrollRange(hChildWnd,SB_VERT,1,500,TRUE); 

		ShowWindow(htvwWnd,1);
		
		SendMessage(htvwWnd,TVM_SELECTITEM,(WPARAM)TVGN_CARET,(LPARAM)(HTREEITEM)hTreeWnd[cshow]);
		SetFocus(htvwWnd);
		TreeView_Select(htvwWnd,hTreeWnd[cshow],TVGN_CARET);
		TreeView_Expand(htvwWnd,hTreeWnd[cshow],TVE_EXPAND);
				}
				
				break;

    case WM_LBUTTONDOWN : x=LOWORD(lParam);
						  y=HIWORD(lParam);
						 break;


	
	case WM_PAINT : hdc=BeginPaint(hWnd,&ps);
					EndPaint(hWnd,&ps);
						break;

	case WM_DESTROY :PostQuitMessage(0);
						break;
	case WM_CLOSE :  
						break;
	}
	return  DefWindowProc(hWnd,iMsg,wParam,lParam);
}

void CallProgressBar(HWND hWnd,int cxCell,int cyCell)
{
	hPbWnd=CreateWindow(PROGRESS_CLASS,"",WS_CHILD|WS_VISIBLE|PBS_SMOOTH,10,10,cxCell*2/3,15,hWnd,NULL,(HINSTANCE)GetWindowLong(hWnd,GWL_HINSTANCE) ,NULL);
	MoveWindow(hPbWnd,cxCell/3+2,cyCell-17,cxCell/3-2,cyCell-2,TRUE);
	SendMessage(hPbWnd,PBM_SETRANGE,0,(LPARAM)MAKELONG(0,100));
	
	//SendMessage(hPbWnd,PBM_SETBKCOLOR,0,RGB(251,208,252));
	SendMessage(hPbWnd,PBM_SETBARCOLOR,0,RGB(213,15,166));
	SendMessage(hPbWnd,PBM_SETPOS,0,0);
}

void SaveFile(int cxCell,int cyCell)
{
	int i;
	if(saveFlag==0)
	{
	Savemenu(hWnd);
	if(strcmp(szSaveFileName,"")!=0)
	{
 		SetWindowText(hWnd,tempSave);
		strcpy(tempSave,"");	
		saveFlag=1;
	}
	else
		return;
	}
	CallProgressBar(hWnd,cxCell,cyCell);
	SetTimer(hWnd,TIMER1,1,NULL);
	
	cshow=0;

	hFile=CreateFile(szSaveFileName,GENERIC_WRITE,FILE_SHARE_WRITE,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL);
	dwTextLength=20;
	for(i=0;i<umlCnt;i++)
	{
		wsprintf(szFileBuff,"%d %d %d %d %d %d   ",UML[i].diaNo,UML[i].type,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);

		WriteFile(hFile,szFileBuff,dwTextLength,&dwWritten,NULL);
		strcpy(szFileBuff,"");
	}
	CloseHandle(hFile);
	strcpy(tempOpen,"");
	strcpy(szOpenFileName,"");
}
										

 