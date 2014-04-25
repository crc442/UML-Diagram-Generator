#include "UseCaseDlg.h"
#include "ObjectDlgProc.h"
#include "CollabDlgProc.h"
#include "SeqDlgProc.h"
#include "StDlgProc.h"
#include "ActDlgProc.h"
#include "CmptDlgProc.h"

static int linecnt,ellipsecnt,rectcnt,actorcnt,fcirclecnt;

	static RECT lineRect[10];
	static RECT ellipseRect[10],fcircleRect[10];
	static RECT rectRect[10];
	static POINT actorPt[10];


	
	static HMETAFILE hMf;
HDC hChildDc,hMetaDc;

void DrawActorMetaFile(HDC hChildDc ,int lx,int ly)
{
	hMetaDc=CreateMetaFile(NULL);
    	MoveToEx(hMetaDc,lx,ly+15,NULL);
	LineTo(hMetaDc,lx,ly+30);
	
	MoveToEx(hMetaDc,lx,ly+22,NULL);
	LineTo(hMetaDc,lx-20,ly+22);

	MoveToEx(hMetaDc,lx,ly+22,NULL);
	LineTo(hMetaDc,lx+20,ly+22);

	MoveToEx(hMetaDc,lx,ly+30,NULL);
	LineTo(hMetaDc,lx-20,ly+44);

	MoveToEx(hMetaDc,lx,ly+30,NULL);
	LineTo(hMetaDc,lx+20,ly+44);

	Ellipse(hMetaDc,lx-15,ly-15,lx+15,ly+15);
	hMf=CloseMetaFile(hMetaDc);
	
	PlayMetaFile(hChildDc,hMf);
}


LRESULT CALLBACK ChildProc(HWND hChildWnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{
	static HMENU hMenu,hSubMenu;
	static int cxCell,cyCell,newx,newy,oldx,oldy;
	POINT point;
	static int lx,ly;
	static char temp[10];
	int i;
	
	
	HBRUSH hBrush;
	PAINTSTRUCT ps;
		
	MENUITEMINFO mii;

	switch(iMsg)
	{
	case WM_LBUTTONDOWN : lx=LOWORD(lParam);
						  ly=HIWORD(lParam);
						  /*if(strcmp(tempID,"IDC_UCACTOR")==0)
						  {
								DrawActorMetaFile(GetDC(hChildWnd),lx,ly);  
								actorPt[actorcnt].x=lx;
								actorPt[actorcnt++].y =ly;
						  }*/
						  if(strcmp(tempID,"IDC_UCSELECT")==0 || strcmp(tempID,"IDC_ACTSELECT")==0 || strcmp(tempID,"IDC_OBJSELECT")==0 || strcmp(tempID,"IDC_SQSELECT")==0 || strcmp(tempID,"IDC_CMPTSELECT")==0 || strcmp(tempID,"IDC_STSELECT")==0 || strcmp(tempID,"IDC_CBSELECT")==0)
						  {
							  MessageBox(hChildWnd,"Select","UML Designer...",MB_OK);
						  } 
						  	
						  break;
	case WM_MOUSEMOVE : newx=LOWORD(lParam);
					    newy=HIWORD (lParam);
						hChildDc=GetDC(hChildWnd);
						if(strcmp(tempID,"IDC_UCACTOR")==0)
						{
							//if(wParam)// & MK_LBUTTON)
							//{
							SetROP2(hChildDc,R2_NOTXORPEN);
							

								DrawActorMetaFile(GetDC(hChildWnd),newx,newy);  
								Sleep(10);
								InvalidateRect(hChildWnd,NULL,TRUE);
							//}
						}
						
						/*if(strcmp(tempID,"IDC_ACTHLINE")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,R2_NOT);

								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,oldx,oldy);
								
								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,newx,newy);

								
							}
							oldx=newx;
							oldy=newy;
						}*/


						if(strcmp(tempID,"IDC_CMPTCIRCLE")==0 || strcmp(tempID,"IDC_UCELLIPSE")==0 || strcmp(tempID,"IDC_STELLIPSE")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,/*R2_MASKPENNOT */ R2_NOTXORPEN);//R2_MERGEPENNOT);
					
								Ellipse(hChildDc,lx,ly-5,oldx,oldy);
								Ellipse(hChildDc,lx,ly-5,newx,newy);

								
							}
							oldx=newx;
							oldy=newy;
						}


						if(strcmp(tempID,"IDC_CMPTRECT")==0 || strcmp(tempID,"IDC_SQRECT")==0 || strcmp(tempID,"IDC_STRECT")==0 || strcmp(tempID,"IDC_UCRECT")==0 || strcmp(tempID,"IDC_OBJRECT")==0 || strcmp(tempID,"IDC_CBRECT")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,R2_NOTXORPEN/*R2_MERGEPENNOT*/);//MERGEPEN);

								Rectangle(hChildDc,lx,ly,oldx,oldy);

								Rectangle(hChildDc,lx,ly,newx,newy);
						
							}
							oldx=newx;
							oldy=newy;
						}

						if(strcmp(tempID,"IDC_UCHARROW")==0 || strcmp(tempID,"IDC_OBJHARROW")==0 ||strcmp(tempID,"IDC_CBHARROW")==0 ||strcmp(tempID,"IDC_SQHARROW")==0||strcmp(tempID,"IDC_STHARROW")==0||strcmp(tempID,"IDC_ACTHARROW")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,R2_NOTXORPEN);


								MoveToEx(hChildDc,oldx,oldy,NULL);
								LineTo(hChildDc,oldx-25,oldy+25);

								
								/*MoveToEx(hChildDc,newx,newy,NULL);
								LineTo(hChildDc,oldx-25,oldy+25);
								*/
								
								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,newx,newy);

								
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_CMPTHLINE")==0 || strcmp(tempID,"IDC_ACTHLINE")==0 || strcmp(tempID,"IDC_STCLINE")==0 || strcmp(tempID,"IDC_UCCLINE")==0 || strcmp(tempID,"IDC_OBJCLINE")==0 || strcmp(tempID,"IDC_CBCLINE")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,R2_NOT);

								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,oldx,oldy);
								
								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,newx,newy);

								
							}
							oldx=newx;
							oldy=newy;
						}
						
						if(strcmp(tempID,"IDC_ACTFCIRCLE")==0 || strcmp(tempID,"IDC_STFCIRCLE")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,R2_NOT);

								Ellipse(hChildDc,lx,ly,oldx,oldy);

								Ellipse(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}


						if(strcmp(tempID,"IDC_ACTDLINE")==0)
						{
							if(wParam & MK_LBUTTON) 
							{
								
								SetROP2(hChildDc,R2_NOTXORPEN);

								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,oldx,oldy);
								
								MoveToEx(hChildDc,lx,ly+1,NULL);
								LineTo(hChildDc,oldx,oldy+1);
								
								MoveToEx(hChildDc,lx,ly+2,NULL);
								LineTo(hChildDc,oldx,oldy+2);
								
								MoveToEx(hChildDc,lx,ly+3,NULL);
								LineTo(hChildDc,oldx,oldy+3);
								
								MoveToEx(hChildDc,lx,ly+4,NULL);
								LineTo(hChildDc,oldx,oldy+4);

								MoveToEx(hChildDc,lx,ly,NULL);
								LineTo(hChildDc,newx,newy);

								MoveToEx(hChildDc,lx,ly+1,NULL);
								LineTo(hChildDc,newx,newy+1);
								
								MoveToEx(hChildDc,lx,ly+2,NULL);
								LineTo(hChildDc,newx,newy+2);

								MoveToEx(hChildDc,lx,ly+3,NULL);
								LineTo(hChildDc,newx,newy+3);

								MoveToEx(hChildDc,lx,ly+4,NULL);
								LineTo(hChildDc,newx,newy+4);
								
								/*Rectangle(hChildDc,lx,ly,oldx,oldy+4);

								Rectangle(hChildDc,lx,ly,newx,newy+4);
								*/
							}
							oldx=newx;
							oldy=newy;
						}

					   ReleaseDC(hChildWnd,hChildDc);

					   wsprintf(temp,"X=%d, Y=%d",newx,newy);
					   SendMessage(hStatus1,SB_SETTEXT,2,(LPARAM)temp);
					   break;
	case WM_RBUTTONUP : cxCell=LOWORD(lParam)+120;
						cyCell=HIWORD(lParam)+76;
						point.x =cxCell;
						point.y =cyCell;
						//hMenu=GetMenu(hChildWnd);
						//hSubMenu=GetSubMenu(hMenu,0);
						ClientToScreen(hChildWnd,&point);
						TrackPopupMenu(hSubMenu,TPM_RIGHTBUTTON,cxCell,cyCell,0,hChildWnd,NULL);
						EnableMenuItem(hMenu,IDM_REFRESH,MF_GRAYED);
						break;
	case WM_LBUTTONUP : //PlayMetaFile(GetDC(hChildWnd),hMf);
						if(strcmp(tempID,"IDC_ACTHLINE")==0 || strcmp(tempID,"IDC_STCLINE")==0 || strcmp(tempID,"IDC_UCCLINE")==0 || strcmp(tempID,"IDC_OBJCLINE")==0 || strcmp(tempID,"IDC_CBCLINE")==0)						
							SetRect(&lineRect[linecnt++],lx,ly,newx,newy);
						if(strcmp(tempID,"IDC_UCELLIPSE")==0 || strcmp(tempID,"IDC_STELLIPSE")==0)
							
						if(strcmp(tempID,"IDC_SQRECT")==0 || strcmp(tempID,"IDC_STRECT")==0 || strcmp(tempID,"IDC_UCRECT")==0 || strcmp(tempID,"IDC_OBJRECT")==0 || strcmp(tempID,"IDC_CBRECT")==0)
							SetRect(&rectRect[rectcnt++],lx,ly,newx,newy);
						if(strcmp(tempID,"IDC_ACTFCIRCLE")==0 || strcmp(tempID,"IDC_STFCIRCLE")==0)
							SetRect(&fcircleRect[fcirclecnt++],lx,ly,newx,newy);
						if(strcmp(tempID,"IDC_UCACTOR")==0)
						{
							HIWORD(lParam));  
								actorPt[actorcnt].x=LOWORD(lParam);
								actorPt[actorcnt++].y =HIWORD(lParam);
						}
							
							
						break;

	case WM_CREATE : hMenu=/*GetMenu(hChildWnd);//*/CreateMenu();
					 hSubMenu=/*GetSubMenu(hMenu,0);//*/CreatePopupMenu();
					 mii.cbSize =sizeof(MENUITEMINFO);
					 mii.fMask =MIIM_TYPE;
					 mii.fType =MFT_STRING;

					 mii.wID =IDM_UNDO;
					 mii.dwTypeData ="&Undo";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,0,1,&mii);
					 mii.wID =IDM_REDO;
					 mii.dwTypeData ="&Redo";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,1,1,&mii);
					 
					 mii.wID =IDM_CUT;
					 mii.dwTypeData ="Cu&t";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,2,1,&mii);
 					 mii.wID =IDM_COPY;
					 mii.dwTypeData ="&Copy";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,3,1,&mii);
					 mii.wID =IDM_PASTE;
					 mii.dwTypeData ="&Paste";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,4,1,&mii);
					 mii.wID =IDM_DELETE;
					 mii.dwTypeData ="&Delete";
					 mii.cch =8;
					 ii);

					 mii.wID =IDM_REFRESH;
					 mii.dwTypeData ="Re&fresh";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,7,1,&mii);

					 mii.wID =IDM_PROPERTIES;
					 mii.dwTypeData ="Prop&erties";
					 mii.cch =8;
					 InsertMenuItem(hSubMenu,8,1,&mii);

 					 mii.fMask =MIIM_SUBMENU|MIIM_TYPE;
					 mii.dwTypeData ="Float";
					 mii.cch =8;
					 mii.hSubMenu =hSubMenu;
					 InsertMenuItem(hMenu,0,1,&mii);
					 EnableMenuItem(hMenu,IDM_CUT,MF_GRAYED);
					 break;
	case WM_PAINT : hChildDc=BeginPaint(hChildWnd,&ps);
					SetROP2(hChildDc,R2_NOTXORPEN);
					
					//PlayMetaFile(hChildDc,hMf);
					for(i=0;i<linecnt;i++)
					{
						MoveToEx(hChildDc,lineRect[i].left,lineRect[i].top,NULL);
						LineTo(hChildDc,lineRect[i].right,lineRect[i].bottom);
					}

					for(i=0;i<rectcnt;i++)
					{
						Rectangle(hChildDc,rectRect[i].left ,rectRect[i].top ,rectRect[i].right ,rectRect[i].bottom );
					}

					for(i=0;i<ellipsecnt;i++)
					{
						Ellipse(hChildDc,ellipseRect[i].left ,ellipseRect[i].top ,ellipseRect[i].right ,ellipseRect[i].bottom );
					}

					for(i=0;i<actorcnt;i++)
					{
						DrawActorMetaFile(hChildDc,actorPt[i].x ,actorPt[i].y);
					    
					}
					hBrush=(HBRUSH)GetStockObject(BLACK_BRUSH);
					for(i=0;i<fcirclecnt;i++)
					{
						SelectObject(hChildDc,hBrush);
						Ellipse(hChildDc,fcircleRect[i].left ,fcircleRect[i].top ,fcircleRect[i].right ,fcircleRect[i].bottom );
					}
					DeleteObject(hBrush);
					EndPaint(hChildWnd,&ps);
					break;
	}
	return DefWindowProc(hChildWnd,iMsg,wParam,lParam);
}