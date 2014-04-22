#include "UseCaseDlg.h"
#include "ObjectDlgProc.h"
#include "CollabDlgProc.h"
#include "SeqDlgProc.h"
#include "StDlgProc.h"
#include "ActDlgProc.h"
#include "CmptDlgProc.h"

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
	
	PlayMetaFile(hChildDc,hMf);
}