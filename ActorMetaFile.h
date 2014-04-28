#include "UseCaseDlg.h"
#include "ObjectDlgProc.h"
#include "CollabDlgProc.h"
#include "SeqDlgProc.h"
#include "StDlgProc.h"
#include "ActDlgProc.h"
#include "CmptDlgProc.h"


static RECT lineRect[10];
static RECT ellipseRect[10],fcircleRect[10];
static RECT rectRect[10];
static POINT actorPt[10];

oid DrawActorMetaFile(HDC hChildDc ,int lx,int ly)
{
	
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
