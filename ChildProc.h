#include<windows.h>
#include "UseCaseDlg.h"
#include "ObjectDlgProc.h"
#include "CollabDlgProc.h"
#include "SeqDlgProc.h"
#include "StDlgProc.h"
#include "ActDlgProc.h"
#include "CmptDlgProc.h"
#include "DeplDlgProc.h"

#include"resource.h"
//#define IDC_MAIN_EDIT	101
                     

#include <tchar.h>
 int href=0,vref=0;
//HWND htext;
 char ssp[20];
POINT pte;
HWND hDlg1;
char sztemp[20];

static POINT Pt[6],ptx;
static RECT DottedRect;
static int lx,ly,oldx,oldy,flag,x2,y2,maxx,maxy,resized;
static int hbarpos=0,vbarpos=0,numlines,nolines,x,y,num,draw_wd=1,draw_sty=1;
HMETAFILE hMf;
HDC hMetaDc,hChildDc,hdc,memdc,hdcmeta;
char str[80],szString[100];
HPEN hPen;
HBRUSH hBrush;
HRGN hRgn;
int saveflag=1;	
RECT rt; 
static DWORD clr;
static int rectFlag;
POINT pt2;
char edittext[1000];
int x1,y1,cxchar,cychar,cyclient;
LRESULT CALLBACK Text(HWND , UINT , WPARAM , LPARAM );

void DrawActorMetaFile(HDC hChildDc,int lx,int ly)
{//type=4 Draws Actor Symbol
	hMetaDc=CreateMetaFile(NULL);
    MoveToEx(hMetaDc,lx+sbHorz+sbVert,ly+sbHorz+sbVert+15,NULL);
	LineTo(hMetaDc,lx+sbHorz+sbVert,ly+sbHorz+sbVert+30);
	MoveToEx(hMetaDc,lx+sbHorz+sbVert,ly+sbHorz+sbVert+22,NULL);
	LineTo(hMetaDc,lx+sbHorz+sbVert-20,ly+sbHorz+sbVert+22);
	MoveToEx(hMetaDc,lx+sbHorz+sbVert,ly+sbHorz+sbVert+22,NULL);
	LineTo(hMetaDc,lx+sbHorz+sbVert+20,ly+sbHorz+sbVert+22);
	MoveToEx(hMetaDc,lx+sbHorz+sbVert,ly+sbHorz+sbVert+30,NULL);
	LineTo(hMetaDc,lx+sbHorz+sbVert-20,ly+sbHorz+sbVert+44);
	MoveToEx(hMetaDc,lx+sbHorz+sbVert,ly+sbHorz+sbVert+30,NULL);
	LineTo(hMetaDc,lx+sbHorz+sbVert+20,ly+sbHorz+sbVert+44);
	Ellipse(hMetaDc,lx+sbHorz+sbVert-15,ly+sbHorz+sbVert-15,lx+sbHorz+sbVert+15,ly+sbHorz+sbVert+15);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawRlznMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=6 Draws Realization i.e. Dotted Line with Triangle 
	hMetaDc=CreateMetaFile(NULL);
	if(newx>lx)
	{
		MoveToEx(hMetaDc,newx+20+sbHorz,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert-20);
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert-20,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert+20);
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert+20,NULL);
		LineTo(hMetaDc,newx+sbHorz+20,ly+sbVert);
	}
	if(newx<lx)
	{
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert-20,NULL);
		LineTo(hMetaDc,newx+sbHorz-20,ly+sbVert);
		MoveToEx(hMetaDc,newx+sbHorz-20,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert+20);
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert+20,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert-20);
	}
	hPen=CreatePen(PS_DOT,1,RGB(0,0,0));
	SelectObject(hMetaDc,hPen);
	MoveToEx(hMetaDc,lx+sbHorz,ly+sbVert,NULL);
	LineTo(hMetaDc,newx+sbHorz,ly+sbVert);
	DeleteObject(hPen);
	
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawGlznMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=7 Draws Generalization i.e. Line with Triangle
	hMetaDc=CreateMetaFile(NULL);
	MoveToEx(hMetaDc,lx+sbHorz,ly+sbVert,NULL);
	LineTo(hMetaDc,newx+sbHorz,ly+sbVert);
	if(newx>lx)
	{
		MoveToEx(hMetaDc,newx+20+sbHorz,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert-20);
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert-20,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert+20);
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert+20,NULL);
		LineTo(hMetaDc,newx+sbHorz+20,ly+sbVert);
	}
	if(newx<lx)
	{
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert-20,NULL);
		LineTo(hMetaDc,newx+sbHorz-20,ly+sbVert);
		MoveToEx(hMetaDc,newx+sbHorz-20,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert+20);
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert+20,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert-20);
	}
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawAgrnMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=8 Draws Aggregation i.e. Line with Diamond
	hMetaDc=CreateMetaFile(NULL);
	MoveToEx(hMetaDc,lx+sbHorz,ly+sbVert,NULL);
	LineTo(hMetaDc,newx+sbHorz,ly+sbVert);
	if(lx<newx)
	{
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz+20,ly+sbVert-20);
		MoveToEx(hMetaDc,newx+sbHorz+20,ly+sbVert-20,NULL);
		LineTo(hMetaDc,newx+sbHorz+40,ly+sbVert);
		MoveToEx(hMetaDc,newx+sbHorz+40,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz+20,ly+sbVert+20);
		MoveToEx(hMetaDc,newx+sbHorz+20,ly+sbVert+20,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert);
	}
	if(lx>newx)
	{
		MoveToEx(hMetaDc,newx+sbHorz,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz-20,ly+sbVert-20);
		MoveToEx(hMetaDc,newx+sbHorz-20,ly+sbVert-20,NULL);
		LineTo(hMetaDc,newx+sbHorz-40,ly+sbVert);
		MoveToEx(hMetaDc,newx+sbHorz-40,ly+sbVert,NULL);
		LineTo(hMetaDc,newx+sbHorz-20,ly+sbVert+20);
		MoveToEx(hMetaDc,newx+sbHorz-20,ly+sbVert+20,NULL);
		LineTo(hMetaDc,newx+sbHorz,ly+sbVert);
	}
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

 

void DrawLnfDmndMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=10 Draws Symbol Line with filled Diamond
	hMetaDc=CreateMetaFile(NULL);
	MoveToEx(hMetaDc,lx+sbHorz,ly+sbVert,NULL);
	LineTo(hMetaDc,newx+sbHorz,ly+sbVert);
	hBrush=CreateSolidBrush(RGB(0,0,0));
	SelectObject(hMetaDc,hBrush);
	if(lx<newx)
	{
		Pt[0].x=newx+sbHorz;		Pt[0].y=ly+sbVert;
		Pt[1].x=newx+sbHorz+20;		Pt[1].y=ly+sbVert-20;
		Pt[2].x=newx+sbHorz+40;		Pt[2].y=ly+sbVert;
		Pt[3].x=newx+sbHorz+20;		Pt[3].y=ly+sbVert+20;
		Pt[4].x=newx+sbHorz;		Pt[4].y=ly+sbVert;
	}
	if(lx>newx)
	{
		Pt[0].x=newx+sbHorz;		Pt[0].y=ly+sbVert;
		Pt[1].x=newx+sbHorz-20;		Pt[1].y=ly+sbVert-20;
		Pt[2].x=newx+sbHorz-40;		Pt[2].y=ly+sbVert;
		Pt[3].x=newx+sbHorz-20;		Pt[3].y=ly+sbVert+20;
		Pt[4].x=newx+sbHorz;		Pt[4].y=ly+sbVert;
	}
	hRgn=CreatePolygonRgn(Pt,5,WINDING);
	FillRgn(hMetaDc,hRgn,hBrush);
	DeleteObject(hBrush);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawObjFTriangleMetaFile(HDC hChildDc,int lx,int ly)
{//type=11 Draws Filled Triangle
	hMetaDc=CreateMetaFile(NULL);
	Pt[0].x =lx+15;		Pt[0].y =ly;
	Pt[1].x =lx-15;		Pt[1].y =ly-15;
	Pt[2].x =lx-15;		Pt[2].y =ly+15;
	Pt[3].x =lx+15;		Pt[3].y =ly;
	hBrush=CreateSolidBrush(RGB(0,0,0));
	SelectObject(hChildDc,hBrush);
	Polygon(hChildDc,Pt,4);
	DeleteObject(hBrush);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawLineFtMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=12 Draws Line with Filled Triangle 
	hMetaDc=CreateMetaFile(NULL);
	MoveToEx(hMetaDc,lx,ly,NULL);
	LineTo(hMetaDc,newx,ly);
	hBrush=CreateSolidBrush(RGB(0,0,0));
	if(newx>lx)
	{
		Pt[0].x =newx+20;	Pt[0].y =ly;
		Pt[1].x =newx;		Pt[1].y =ly-20;
		Pt[2].x =newx;		Pt[2].y =ly+20;
		Pt[3].x =newx+20;	Pt[3].y =ly;
	}
	if(newx<lx)
	{
		Pt[0].x =newx;		Pt[0].y =ly-20;
		Pt[1].x =newx-20;	Pt[1].y =ly;
		Pt[2].x =newx;		Pt[2].y =ly+20;
		Pt[3].x =newx;		Pt[3].y =ly-20;
	}
	hRgn=CreatePolygonRgn(Pt,4,WINDING);
	FillRgn(hMetaDc,hRgn,hBrush);
	DeleteObject(hBrush);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawDottedLineMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=13 Draws Vertical  Line
	hMetaDc=CreateMetaFile(NULL);
	hPen=CreatePen(PS_DOT,1,RGB(0,0,0));
	SelectObject(hMetaDc,hPen);
	MoveToEx(hMetaDc,lx,ly,NULL);
	LineTo(hMetaDc,newx,newy);
	DeleteObject(hPen);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawCrossMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=14 Draws Cross Symbol
	hMetaDc=CreateMetaFile(NULL);
	MoveToEx(hChildDc,lx,ly,NULL);
	LineTo(hChildDc,newx,newy);
	MoveToEx(hChildDc,lx,newy,NULL);
	LineTo(hChildDc,newx,ly);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawStartMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=15 Draws Filled Circle
	hMetaDc=CreateMetaFile(NULL);
	hBrush=CreateSolidBrush(RGB(0,0,0));
	SelectObject(hMetaDc,hBrush);
	Ellipse(hMetaDc,lx,ly,newx,newy);
	DeleteObject(hBrush);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawEndMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=16 Draws Filled Circle with And circle Sorrounding it
	hMetaDc=CreateMetaFile(NULL);
	Ellipse(hMetaDc,lx,ly,newx,newy);
 
     hBrush=CreateSolidBrush(RGB(0,0,0));
		 
	SelectObject(hMetaDc,hBrush);
	if(lx<newx)
		Ellipse(hMetaDc,lx+15,ly+15,newx-15,newy-15);
	if(lx>newx)
		Ellipse(hMetaDc,lx-15,ly-15,newx+15,newy+15);

 

	DeleteObject(hBrush);

	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawDmndMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=18 Draws Diamond 
	int center;
	center=(newx-lx)/2;
	hMetaDc=CreateMetaFile(NULL);
	MoveToEx(hMetaDc,lx,ly,NULL);
	LineTo(hMetaDc,lx+center,ly-center);
    MoveToEx(hMetaDc,lx,ly,NULL);
	LineTo(hMetaDc,lx+center,ly+center);
	MoveToEx(hMetaDc,newx,ly,NULL);
	LineTo(hMetaDc,newx-center,ly-center);
	MoveToEx(hMetaDc,newx,ly,NULL);
	LineTo(hMetaDc,newx-center,ly+center);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawCmptMetaFile(HDC hChildDc,int lx,int ly)
{//type=20 Draws Component Symbol
	hMetaDc=CreateMetaFile(NULL);
	
	MoveToEx(hChildDc,lx-60,ly-60,NULL);
    LineTo(hChildDc,lx-60,ly-30);
	Rectangle(hChildDc,lx-80,ly-30,lx-40,ly-15);
	MoveToEx(hChildDc,lx-60,ly-15,NULL);
	LineTo(hChildDc,lx-60,ly+15);
	Rectangle(hChildDc,lx-80,ly+15,lx-40,ly+30);
	MoveToEx(hChildDc,lx-60,ly+30,NULL);
	LineTo(hChildDc,lx-60,ly+60);
	MoveToEx(hChildDc,lx-60,ly+60,NULL);
	LineTo(hChildDc,lx+60,ly+60);
	MoveToEx(hChildDc,lx-60,ly-60,NULL);
	LineTo(hChildDc,lx+60,ly-60);
	MoveToEx(hChildDc,lx+60,ly-60,NULL);
	LineTo(hChildDc,lx+60,ly+60);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}
							  
void DrawVertArrowMetaFile(HDC hChildDc,int lx,int ly,int newx,int newy)
{//type=21 Draws Vertical Arrow With Dotted Line
	hMetaDc=CreateMetaFile(NULL);
	hPen=CreatePen(PS_DOT,1,RGB(0,0,0));
	SelectObject(hMetaDc,hPen);
	
	MoveToEx(hMetaDc,lx,ly,NULL);
	LineTo(hMetaDc,lx,newy);
	DeleteObject(hPen);
	if(newy<ly)
	{
		MoveToEx(hChildDc,lx-15,newy+15,NULL);
		LineTo(hChildDc,lx,newy);
		MoveToEx(hChildDc,lx+15,newy+15,NULL);
		LineTo(hChildDc,lx,newy);
	}
	if(newy>ly)
	{
		MoveToEx(hChildDc,lx-15,newy-15,NULL);
		LineTo(hChildDc,lx,newy);
		MoveToEx(hChildDc,lx+15,newy-15,NULL);
		LineTo(hChildDc,lx,newy);
	}
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

void DrawDeplMetaFile(HDC hChildDc,int lx,int ly)
{//type=22 Draws Deployment Symbol
	hMetaDc=CreateMetaFile(NULL);
	Rectangle(hChildDc,lx-60,ly-60,lx+60,ly+60);
    MoveToEx(hChildDc,lx-60,ly-60,NULL);
	LineTo(hChildDc,lx-30,ly-90);
	MoveToEx(hChildDc,lx+60,ly-60,NULL);
	LineTo(hChildDc,lx+90,ly-90);
	MoveToEx(hChildDc,lx-30,ly-90,NULL);
	LineTo(hChildDc,lx+90,ly-90);
	MoveToEx(hChildDc,lx+60,ly+59,NULL);
	LineTo(hChildDc,lx+90,ly+29);
	MoveToEx(hChildDc,lx+90,ly-90,NULL);
	LineTo(hChildDc,lx+90,ly+30);
	hMf=CloseMetaFile(hMetaDc);
	PlayMetaFile(hChildDc,hMf);
}

 
	

LRESULT CALLBACK ChildProc(HWND hChildWnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{	
	
 
	static HMENU hfloatMenu,hSubMenu;
	static int cxCell,cyCell,newx,newy;
	POINT point;
	static char temp[10];
	int i;
    static HBITMAP hbit;
	PAINTSTRUCT ps;

		
	switch(iMsg)
	{
	case WM_MENUSELECT: strcpy(tempID,"");
						break;
 
	
	case WM_COMMAND : switch(LOWORD(wParam))
					  {
						   
						case IDM_UNDO :SendMessage(hWnd,WM_COMMAND,IDM_UNDO,0);
									   break;
						case IDM_REDO :SendMessage(hWnd,WM_COMMAND,IDM_REDO,0);
									   break;
						case IDM_COPY : SendMessage(hWnd,WM_COMMAND,IDM_COPY,0);
									   break;
					 
					  }
					  break;
	case WM_LBUTTONDOWN :
		                   lx=LOWORD(lParam);//+horzPos;
						   ly=HIWORD(lParam);//+vertPos;
						   hChildDc=GetDC(hChildWnd);

							 if(strcmp(tempID,"IDC_DEPLDEPL")==0)
						   {//type=22 For deployment symbol
							 DrawDeplMetaFile(GetDC(hChildWnd),lx,ly);
							 UML[umlCnt].diaNo =diaSelected;
							 UML[umlCnt].type =22;
							 UML[umlCnt].undo =0;
							 SetRect(&UML[umlCnt++].Rect,lx,ly,0,0);
							 EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							 EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						   }

						  if(strcmp(tempID,"IDC_CMPTCMPT")==0)
						  {//type=20 For Component Symbol
							  DrawCmptMetaFile(GetDC(hChildWnd),lx,ly);
							  UML[umlCnt].diaNo =diaSelected;
							  UML[umlCnt].type =20;
							  UML[umlCnt].undo =0;
							  SetRect(&UML[umlCnt++].Rect,lx,ly,0,0);
							  EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							  EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						  }
						  if(strcmp(tempID,"IDC_OBJFDIAMOND")==0)
						  {//type=10  Draws Symbol Line with filled Diamond
							  
								flag=1;
						  }
						  if(strcmp(tempID,"IDC_OBJFTRIANGLE")==0)
						  {//type=11 Draws Filled Triangle


							  DrawObjFTriangleMetaFile(GetDC(hChildWnd),lx,ly);
							  UML[umlCnt].diaNo =diaSelected;
							  UML[umlCnt].type =11;
							  UML[umlCnt].undo =0;
							  SetRect(&UML[umlCnt++].Rect,lx,ly,0,0);
							  EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							  EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						  }
						  if(strcmp(tempID,"IDC_CBFTLINE")==0)
						  {//type=12
							  flag=1;
						  }
						 /* if(strcmp(tempID,"IDC_ACTDBLCIRCLE")==0||strcmp(tempID,"IDC_STDBLCIRCLE")==0)
						  {//type16 
							 // DrawEndMetaFile(GetDC(hChildWnd),lx,ly,newx,newy);
							  SetROP2(hChildDc,R2_BLACK);
							  UML[umlCnt].diaNo =diaSelected;
							  UML[umlCnt].type =16;
							  UML[umlCnt].undo =0;
							  SetRect(&UML[umlCnt++].Rect,lx,ly,0,0);
							  EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
						  }*/
						
						  if(strcmp(tempID,"IDC_UCACTOR")==0)
						  {//type=4 for Actor
								
							  //SetMapMode (hMetaDc,MM_LOENGLISH) ;
								DrawActorMetaFile(GetDC(hChildWnd),lx,ly);  
								UML[umlCnt].diaNo =1;//diaSelected;
								UML[umlCnt].type =4;
								UML[umlCnt].undo =0;
								SetRect(&UML[umlCnt++].Rect,lx,ly,0,0);
								EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
								EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						  }
						  if(strcmp(tempID,"IDC_DEPLSELECT")==0 || strcmp(tempID,"IDC_CLSSELECT")==0 || strcmp(tempID,"IDC_UCSELECT")==0 || strcmp(tempID,"IDC_ACTSELECT")==0 || strcmp(tempID,"IDC_OBJSELECT")==0 || strcmp(tempID,"IDC_SQSELECT")==0 || strcmp(tempID,"IDC_CMPTSELECT")==0 || strcmp(tempID,"IDC_STSELECT")==0 || strcmp(tempID,"IDC_CBSELECT")==0) 
						  {
							//If previously dotted rect is drawn then it erased and rectFlag=0
						  	  if(rectFlag==1)
							  {
								  InvalidateRect(hChildWnd,NULL,TRUE);
								  rectFlag=0;
							  }
						  }
					  	   
						  break; 
 
 
	case WM_HSCROLL:
			switch(LOWORD(wParam))
			{
			case SB_LINELEFT:
				horzPos-=5;
				if(horzPos<0)
					horzPos = 0;
				sbhzFlag=0;
				break;
			case SB_LINERIGHT:
				horzPos+=5;
				if(horzPos>500)
					horzPos =500;
				sbhzFlag=1;
				break;
			case SB_PAGELEFT:
				horzPos-=10;
				if(horzPos<0)
					horzPos = 0;
				sbhzFlag=0;
				break;
			case SB_PAGERIGHT:
				horzPos+=10;
				if(horzPos>500)
					horzPos =500;
				sbhzFlag=1;
				break;
			case SB_THUMBPOSITION:
				if(sbhzOld<horzPos)
					sbhzFlag=1;
				else
					sbhzFlag=0;
				horzPos = HIWORD(wParam);
			}
			sbHorz=horzPos;
//sbHorz * -1 is done to move to left and if left scroll button
//is pressed then it is incremented by 1 because it takes the
//default Rect from UML not updated by scrolling right
				sbHorz=sbHorz*-1;
			 if(sbhzFlag==0)
				sbHorz=sbHorz+1;
			SetScrollPos(hChildWnd,SB_HORZ,horzPos,TRUE);
			InvalidateRect(hChildWnd,NULL,TRUE);
			break;
	case WM_VSCROLL:
			switch(LOWORD(wParam))
			{
			case SB_LINEUP:
				vertPos-=5;
				if(vertPos<0)
					vertPos = 0;
				sbvtFlag=0;
				break;
			case SB_LINEDOWN:
				vertPos+=5;
				if(vertPos>500)
					vertPos =500;
				sbvtFlag=1;
				break;
			case SB_PAGEUP:
				vertPos-=10;
				if(vertPos<0)
					vertPos = 0;
				sbvtFlag=0;
				break;
			case SB_PAGEDOWN:
				vertPos+=10;
				if(vertPos>500)
					vertPos =500;
				sbvtFlag=1;
				break;
			case SB_THUMBPOSITION:
				if(sbhzOld<vertPos)
					sbvtFlag=1;
				else
					sbvtFlag=0;
				vertPos = HIWORD(wParam);
			}
			sbVert=vertPos;
//sbHorz * -1 is done to move to up and if up scroll button
//is pressed then it is incremented by 1 because it takes the
//default Rect from UML not updated by scrolling down
				sbVert=sbVert*-1;
			 if(sbvtFlag==0)
				sbVert=sbVert+1;
			SetScrollPos(hChildWnd,SB_VERT,vertPos,TRUE);
			InvalidateRect(hChildWnd,NULL,TRUE);
			break;
	
	case WM_MOUSEMOVE : newx=LOWORD(lParam);
					    newy=HIWORD (lParam);
						hChildDc=GetDC(hChildWnd);
						if(strcmp(tempID,"IDC_DEPLRECT")==0 || strcmp(tempID,"IDC_CMPTRECT")==0 || strcmp(tempID,"IDC_SQRECT")==0 || strcmp(tempID,"IDC_STRECT")==0 || strcmp(tempID,"IDC_UCRECT")==0 || strcmp(tempID,"IDC_OBJRECT")==0 || strcmp(tempID,"IDC_CBRECT")==0)
						{//type=1
							if(wParam & MK_LBUTTON) 
							{
								SetROP2(hChildDc,R2_NOTXORPEN);/*R2_MERGEPENNOT*///MERGEPEN);
								Rectangle(hChildDc,lx,ly,oldx,oldy);
								Rectangle(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_CLSHLINE")==0 || strcmp(tempID,"IDC_DEPLHLINE")==0 || strcmp(tempID,"IDC_CMPTHLINE")==0 || strcmp(tempID,"IDC_ACTHLINE")==0 || strcmp(tempID,"IDC_STCLINE")==0 || strcmp(tempID,"IDC_UCCLINE")==0 || strcmp(tempID,"IDC_OBJCLINE")==0|| strcmp(tempID,"IDC_CBCLINE")==0)
						{//type=2
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
						if(strcmp(tempID,"IDC_CMPTCIRCLE")==0 || strcmp(tempID,"IDC_UCELLIPSE")==0 || strcmp(tempID,"IDC_STELLIPSE")==0)
						{//type=3
							if(wParam & MK_LBUTTON) 
							{
								SetROP2(hChildDc,R2_NOTXORPEN);//R2_MERGEPENNOT;
								Ellipse(hChildDc,lx,ly-5,oldx,oldy);
								Ellipse(hChildDc,lx,ly-5,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_UCDLINE")==0)
						{//type=6
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawRlznMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawRlznMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_OBJTARROW")==0)
						{//type=7
							if(wParam &MK_LBUTTON)
							{  
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawGlznMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawGlznMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_OBJGENERLZN")==0)
						{//type=8
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawAgrnMetaFile(hChildDc,lx,ly,oldx,oldy);		
								DrawAgrnMetaFile(hChildDc,lx,ly,newx,newy);		
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_OBJFDIAMOND")==0)
						{//type=10 
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								if(flag==1)
								{
									DrawLnfDmndMetaFile(hChildDc,lx,ly,newx,newy);
									flag=0;
								}
								else
								{
									DrawLnfDmndMetaFile(hChildDc,lx,ly,oldx,oldy);
									DrawLnfDmndMetaFile(hChildDc,lx,ly,newx,newy);
								}
							}
							oldx=newx;
							oldy=newy;
						}
                        

						if(strcmp(tempID,"IDC_CBFTLINE")==0)
						{//type=12
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								if(flag==1)
								{
									DrawLineFtMetaFile(hChildDc,lx,ly,newx,newy);		
									flag=0;
								}
								else
								{
									DrawLineFtMetaFile(hChildDc,lx,ly,oldx,oldy);		
									DrawLineFtMetaFile(hChildDc,lx,ly,newx,newy);		
								}
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_SQDLINE")==0)
						{//type=13
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawDottedLineMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawDottedLineMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}						
						if(strcmp(tempID,"IDC_SQCROSS")==0)
						{//type=14
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawCrossMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawCrossMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_ACTFCIRCLE")==0 || strcmp(tempID,"IDC_STFCIRCLE")==0)
						{//type=15
							if(wParam & MK_LBUTTON) 
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawStartMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawStartMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_ACTDBLCIRCLE")==0||strcmp(tempID,"IDC_STDBLCIRCLE")==0)
						{//type16
							if(wParam & MK_LBUTTON)
							{
							  SetROP2(hChildDc,R2_NOTXORPEN);
							  DrawEndMetaFile(hChildDc,lx,ly,oldx,oldy);
							  DrawEndMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_ACTCRECT")==0)
						{//type=17
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								RoundRect(hChildDc,lx,ly,oldx,oldy,oldy-ly,oldx-lx);
								RoundRect(hChildDc,lx,ly,newx,newy,newy-ly,newx-lx);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_ACTDMD")==0)		
						{//type=18
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawDmndMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawDmndMetaFile(hChildDc,lx,ly,newx,newy);
								//Rectangle(hChildDc,lx-((ly-oldy)/2),ly,lx+((ly-oldy)/2),oldy);
								//Rectangle(hChildDc,lx-((ly-newy)/2),ly,lx+((ly-newy)/2),newy);
							}
							oldx=newx;
							oldy=newy;
						}
						if(strcmp(tempID,"IDC_ACTDLINE")==0)
						{//type=19
							if(wParam & MK_LBUTTON) 
							{
								hPen=CreatePen(PS_SOLID,5,RGB(0,0,0));
								SelectObject(hChildDc,hPen);
								SetROP2(hChildDc,R2_NOTXORPEN);
								MoveToEx(hChildDc,lx-5,ly,NULL);
								LineTo(hChildDc,oldx,oldy);
								MoveToEx(hChildDc,lx-5,ly,NULL);
								LineTo(hChildDc,newx,newy);
								DeleteObject(hPen);
							}
							oldx=newx;
							oldy=newy;
						}	  

						/*if(strcmp(tempID,"IDC_DEPLDEPL")==0)
						 {//type=22
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawDeplMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawDeplMetaFile(hChildDc,lx,ly,newx,newx);
							}
							 UML[umlCnt].diaNo =diaSelected;
							 UML[umlCnt].type =22;
							 UML[umlCnt].undo =0;
							 SetRect(&UML[umlCnt++].Rect,lx,ly,0,0);
							 EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							oldx=newx;
							oldy=newy;
						 }*/
						if(strcmp(tempID,"IDC_CMPTDVARROW")==0)
						{//type=21
							if(wParam & MK_LBUTTON)
							{
								SetROP2(hChildDc,R2_NOTXORPEN);
								DrawVertArrowMetaFile(hChildDc,lx,ly,oldx,oldy);
								DrawVertArrowMetaFile(hChildDc,lx,ly,newx,newy);
							}
							oldx=newx;
							oldy=newy;
						}
						 
						if(strcmp(tempID,"IDC_DEPLSELECT")==0 || strcmp(tempID,"IDC_CLSSELECT")==0 || strcmp(tempID,"IDC_UCSELECT")==0 || strcmp(tempID,"IDC_ACTSELECT")==0 || strcmp(tempID,"IDC_OBJSELECT")==0 || strcmp(tempID,"IDC_SQSELECT")==0 || strcmp(tempID,"IDC_CMPTSELECT")==0 || strcmp(tempID,"IDC_STSELECT")==0 || strcmp(tempID,"IDC_CBSELECT")==0)
						{//For Select Arrow Button
							if(wParam & MK_LBUTTON)
							{
								if(umlCnt>0)
								{
								if(rectFlag==1)
								InvalidateRect(hChildWnd,NULL,TRUE);
								hPen=CreatePen(PS_DOT,1,RGB(0,0,0));
								SelectObject(hChildDc,hPen);
								SetROP2(hChildDc,R2_NOTXORPEN);
									 
						 	     Rectangle(hChildDc,lx,ly,oldx,oldy);
							 
						 	      Rectangle(hChildDc,lx,ly,newx,newy);
								  DeleteObject(hPen);
								  ReleaseDC(hChildWnd,hChildDc);
								}
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

						hSubMenu=GetSubMenu(hMenu,1);
						ClientToScreen(hChildWnd,&point);
						TrackPopupMenu(hSubMenu,TPM_RIGHTBUTTON,cxCell,cyCell,0,hChildWnd,NULL);
						EnableMenuItem(hfloatMenu,IDM_REFRESH,MF_GRAYED);
						break;
	case WM_LBUTTONUP : if(strcmp(tempID,"IDC_SQRECT")==0 || strcmp(tempID,"IDC_STRECT")==0 || strcmp(tempID,"IDC_UCRECT")==0 || strcmp(tempID,"IDC_OBJRECT")==0 || strcmp(tempID,"IDC_CBRECT")==0||strcmp(tempID,"IDC_DEPLRECT")==0 || strcmp(tempID,"IDC_CMPTRECT")==0)
						{//type=1 for Rectangle
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].type =1;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
                            

						/*if(strcmp(tempID,"IDC_TEXT")==0)
						{

                            UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].type =1;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);


						}*/
						if(strcmp(tempID,"IDC_ACTDBLCIRCLE")==0||strcmp(tempID,"IDC_STDBLCIRCLE")==0)
						{//type16 
							 
							 SetROP2(hChildDc,R2_BLACK);
							 UML[umlCnt].diaNo =diaSelected;
							 UML[umlCnt].type =16;
							 UML[umlCnt].undo =0;
							 SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							 EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_ACTFCIRCLE")==0 || strcmp(tempID,"IDC_STFCIRCLE")==0)
						{
							 SetROP2(hChildDc,R2_BLACK);
							 UML[umlCnt].diaNo =diaSelected;
						     UML[umlCnt].type =15;
							 UML[umlCnt].undo =0;
						     SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							 EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
						}

						if(strcmp(tempID,"IDC_CLSHLINE")==0 || strcmp(tempID,"IDC_DEPLHLINE")==0 || strcmp(tempID,"IDC_CMPTHLINE")==0 || strcmp(tempID,"IDC_ACTHLINE")==0 || strcmp(tempID,"IDC_STCLINE")==0 || strcmp(tempID,"IDC_UCCLINE")==0 || strcmp(tempID,"IDC_OBJCLINE")==0 || strcmp(tempID,"IDC_CBCLINE")==0)						
						{//type=2 for Line
							//diagram no
							//1 : Use Case, 2 : Object
							//3 : Collaboration , 4 : Sequence
							//5 : State , 6 : Activity
							//7 : Component , 8 : Deployment
							//9 : Class
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].type =2;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_UCELLIPSE")==0 || strcmp(tempID,"IDC_STELLIPSE")==0||strcmp(tempID,"IDC_CMPTCIRCLE")==0)
						{//type=3 for Ellipse
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].type =3;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						//	CreateTextbox(lx,ly+((newy-ly)/2)-10,newx-lx);
						}
						if(strcmp(tempID,"IDC_UCDLINE")==0)
						{//type=6
							UML[umlCnt].type =6;
							UML[umlCnt].diaNo =diaSelected;
							SetRect(&UML[umlCnt].Rect,lx,ly,newx,newy);
							UML[umlCnt++].undo =0;
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_OBJTARROW")==0)
						{//type=7 
							UML[umlCnt].type =7;
							UML[umlCnt].diaNo =diaSelected;
							SetRect(&UML[umlCnt].Rect,lx,ly,newx,newy);
							UML[umlCnt++].undo =0;
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_OBJGENERLZN")==0)
						{//type=8
							UML[umlCnt].type =8;
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}		
						if(strcmp(tempID,"IDC_OBJFDIAMOND")==0)
						{//type=10
							UML[umlCnt].type =10;
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_CBFTLINE")==0)
						{//type=12
							UML[umlCnt].type =12;
							UML[umlCnt].diaNo =diaSelected;
							SetRect(&UML[umlCnt].Rect,lx,ly,newx,newy);
							UML[umlCnt++].undo =0;
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_SQDLINE")==0)
						{//type=13
							UML[umlCnt].type =13;
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_SQCROSS")==0)
						{//type=14
							  UML[umlCnt].diaNo =diaSelected;
							  UML[umlCnt].type =14;
							  UML[umlCnt].undo =0;
							  SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							  EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							  EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
					 

					
						if(strcmp(tempID,"IDC_ACTCRECT")==0)
						{//type=17
							UML[umlCnt].type =17;
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_ACTDMD")==0)
						{//type=18
							  UML[umlCnt].diaNo =diaSelected;
							  UML[umlCnt].type =18;
							  UML[umlCnt].undo =0;
							  SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							  EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							  EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_ACTDLINE")==0)
						{//type=19
							UML[umlCnt].type =19;
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						if(strcmp(tempID,"IDC_CMPTDVARROW")==0)
						{//type=21
							UML[umlCnt].type =21;
							UML[umlCnt].diaNo =diaSelected;
							UML[umlCnt].undo =0;
							SetRect(&UML[umlCnt++].Rect,lx,ly,newx,newy);
							EnableMenuItem(hMenu,IDM_SAVE,MF_ENABLED);
							EnableMenuItem(hMenu,IDM_PRINT,MF_ENABLED);
						}
						 							
						 
						 
						if(umlCnt>0)//Used to enable item from Floating menu
						{
						  EnableMenuItem(hMenu,IDM_UNDO,MF_ENABLED);
						   
						}
						if(strcmp(tempID,"IDC_DEPLSELECT")==0 || strcmp(tempID,"IDC_CLSSELECT")==0 || strcmp(tempID,"IDC_UCSELECT")==0 || strcmp(tempID,"IDC_ACTSELECT")==0 || strcmp(tempID,"IDC_OBJSELECT")==0 || strcmp(tempID,"IDC_SQSELECT")==0 || strcmp(tempID,"IDC_CMPTSELECT")==0 || strcmp(tempID,"IDC_STSELECT")==0 || strcmp(tempID,"IDC_CBSELECT")==0)
						{//rectFlag=1 i.e. dotted Rect is drawn for Selection
							rectFlag=1;
							 
							EnableMenuItem(hMenu,IDM_COPY,MF_ENABLED);
							 
							SetRect(&DottedRect,lx,ly,LOWORD(lParam),HIWORD(lParam));
							
							for(i=0;i<umlCnt;i++)
							{
							   if(DottedRect.left<=UML[i].Rect.left && DottedRect.top <=UML[i].Rect.top)
							   {
								   
								    
								        hClipboardEmf=CopyMetaFile(hMf,NULL);
										SetClipboardData(CF_ENHMETAFILE,hMf);
								        // InvalidateRect(hChildWnd,DottedRect,FALSE);
								   break;
							   }
							}  
						}
						break;
	case WM_LBUTTONDBLCLK:
				
				  
				 	        
		
						ptx.x = LOWORD(lParam)+120;
				        ptx.y =HIWORD(lParam)+76;	 

						 hChildDc=GetDC(hChildWnd);
						 
						 DialogBox(hInst,(LPCSTR)IDD_DIALOG2,hChildWnd,(DLGPROC)Text);
						ScreenToClient(hChildWnd,&ptx);
						ReleaseDC(hChildWnd,hChildDc);

						
	break;
		 
	case WM_PAINT : hChildDc=BeginPaint(hChildWnd,&ps);
		              
					switch(diaSelected)
					{
					case 1 :for(i=0;i<umlCnt;i++)
							{
								if(UML[i].diaNo==1)//Use Case Diagram
								{
									if(UML[i].undo==0)
									{
										switch(UML[i].type)
										{
											case 1 : //Rectangle
													 Rectangle(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													 break;
											case 2 : //Line
													 MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
													 LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													 break;
											case 3 : //Ellipse
													 Ellipse(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
												//	BitBlt (hChildDc,0,0,maxx,maxy,memdc,href,vref,SRCCOPY);	
													 break;
											case 4 : //Actor
													 DrawActorMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top);
													 break;
											case 5 : //
													 break;
											case 6 : //Realiaztion 
													 DrawRlznMetaFile(hChildDc,UML[i].Rect.left, UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
													 break;
											 
											 
											 
												
												break;


										}
									}
								}
							}
						break;
					case 2 :for(i=0;i<umlCnt;i++)
							{
								if(UML[i].diaNo==2)//Object Diagram
								{
									if(UML[i].undo==0)
									{
										switch(UML[i].type)
										{
											case 1 : //Rectangle
													 Rectangle(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													 break;
											case 2 : //Line
													 MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
													 LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													 break;
											case 5 : break;
											case 7 : DrawGlznMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
													 break;
											case 8 : DrawAgrnMetaFile(hChildDc,UML[i].Rect.left, UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
													 break;
											case 10 :DrawLnfDmndMetaFile(hChildDc,UML[i].Rect.left, UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
													 break;
											case 11 :DrawObjFTriangleMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top);
													 break;
										}
									}
								}
							}
						break;
						case 3 :for(i=0;i<umlCnt;i++)
								{
									if(UML[i].diaNo==3)//For Collaboration Diagram
									{
										if(UML[i].undo==0)
										{	
											switch(UML[i].type)
											{
											case 1 : //Rectangle
													Rectangle(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													 break;
											case 2 : //Line
													 MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
													 LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													 break;
											case 5 : break;
											case 12 :DrawLineFtMetaFile(hChildDc,UML[i].Rect.left, UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
													 break;
											}
										}
									}
								}
						break;
						case 4 : for(i=0;i<umlCnt;i++)
								 {
									if(UML[i].diaNo==4)//For Sequence Diagram
									{
										if(UML[i].undo==0)
										{
											switch(UML[i].type)
											{
												case 1 : //Rectangle
														 Rectangle(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 5 : break;	
												case 13 :DrawDottedLineMetaFile(hChildDc,UML[i].Rect.left, UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
	 													 break;
												case 14 :DrawCrossMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom); 
														 break;
											}
										}
									}
								 }
						break;
						case 5 :for(i=0;i<umlCnt;i++)
								{
									if(UML[i].diaNo==5)//For State Diagram
									{
										if(UML[i].undo==0)
										{
											switch(UML[i].type)
											{
												case 2 : //Line
														MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
														LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
													    break;
												case 3 : //Ellipse
														 Ellipse(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 5 : break;
												case 15 :DrawStartMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom); 
														 break;
												case 16 :DrawEndMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom); 
														 break;
											}
										}
									}
								}
							break;
						case 6 :for(i=0;i<umlCnt;i++)
								{
									if(UML[i].diaNo==6)//For Activity Diagram
									{
										if(UML[i].undo==0)
										{
											switch(UML[i].type)
											{
												case 2 : //Line
														MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
														LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														break;
												case 5 : break;
												case 15 :DrawStartMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom); 
														 break;
												case 16 :DrawEndMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom); 
														 break;
												case 17 :RoundRect(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom,UML[i].Rect.bottom-UML[i].Rect.top,UML[i].Rect.right-UML[i].Rect.left);
														 break;
												case 18 :DrawDmndMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
														 break;
												case 19 :hPen=CreatePen(PS_SOLID,5,RGB(0,0,0));
														 SelectObject(hChildDc,hPen);
														 MoveToEx(hChildDc,UML[i].Rect.left-5,UML[i].Rect.top,NULL);
														 LineTo(hChildDc,UML[i].Rect.right,UML[i].Rect.bottom);
														 DeleteObject(hPen);
														 break;
											}
										}
									}
								}
							break;
						case 7 :for(i=0;i<umlCnt;i++)
								{
									if(UML[i].diaNo==7)//For Component Diagram
									{
										if(UML[i].undo==0)
										{
											switch(UML[i].type)
											{
												case 1 : //Rectangle
														 Rectangle(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 2 : //Line
														 MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
														 LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 3 : //Ellipse
														 Ellipse(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 20 :DrawCmptMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top);
														 break;
												case 21 :DrawVertArrowMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top,UML[i].Rect.right,UML[i].Rect.bottom);
														 break;
											}
										}
									}
								}
							break;
						case 8 :for(i=0;i<umlCnt;i++)
								{
									if(UML[i].diaNo==8)//For Deployment Diagram
									{
										if(UML[i].undo==0)
										{
											switch(UML[i].type)
											{
												case 1 : //Rectangle
														 Rectangle(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 2 : //Line
														 MoveToEx(hChildDc,UML[i].Rect.left+sbHorz,UML[i].Rect.top+sbVert,NULL);
														 LineTo(hChildDc,UML[i].Rect.right+sbHorz,UML[i].Rect.bottom+sbVert);
														 break;
												case 22 :DrawDeplMetaFile(hChildDc,UML[i].Rect.left,UML[i].Rect.top);
														 break;
											}
										}
									}
								}
							break;
							}
						 
				EndPaint(hChildWnd,&ps);
				break;
	}

		 
	return DefWindowProc(hChildWnd,iMsg,wParam,lParam);
}
	LRESULT CALLBACK Text(HWND hDlg1, UINT message, WPARAM wParam, LPARAM lParam)
{
	 int i=0;
	 switch (message)
	 {
		case WM_INITDIALOG: 
			 return TRUE;
	
		case WM_COMMAND:
		  	 switch(LOWORD(wParam))
			 {char szString[100];
			   case IDCANCEL :
				   //Destroys DIALOG Window
			    	EndDialog(hDlg1, LOWORD(wParam));
				    break;

				
			   case IDOK :
					//Gets Text of TextBox On Dialog Box
				    GetDlgItemText (hDlg1, IDC_EDIT1,sztemp, 10) ;
					EndDialog (hDlg1, TRUE) ;
			         hChildDc =GetDC(hChildWnd);
					//Converts Screen Coordinates to Client Coordinate
					ScreenToClient(hChildWnd,&ptx);	 
					TextOut(hChildDc,ptx.x,ptx.y,sztemp,strlen(sztemp));
	 
					for (i=0;i<(strlen(sztemp));i++)
					{ 
						if(szString[i]!=' ') 
							ssp[i] = sztemp[i];
						else
							ssp[i] = '*';
					}
					ssp[i] = '\0';
				 
				  
					 
					ReleaseDC(hChildWnd,hChildDc);
				
					break;
			}
		  	break;
	 }
	 return FALSE;

	}
		 
	
