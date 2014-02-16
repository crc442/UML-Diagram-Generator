#include "Includefiles.h"
#include"windows.h"
static char szChild[]="Child";
 
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow)
{
	
	static char szAppName[]="WProc";
	
	MSG msg;
	
	HACCEL hAccel;
	WNDCLASS WndClass;
	WndClass.style =CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc =WndProc;
	WndClass.cbClsExtra =0;
	WndClass.cbWndExtra =0;
	WndClass.hInstance =hInstance;
	WndClass.lpszMenuName ="MyMenu";
	WndClass.lpszClassName =szAppName;
	WndClass.hIcon =LoadIcon(hInstance,"IDI_UMLICON1");
	WndClass.hCursor =LoadCursor(NULL,IDC_ARROW);
	WndClass.hbrBackground =(HBRUSH)GetStockObject(LTGRAY_BRUSH);
	
	RegisterClass(&WndClass);

	WndClass.lpszClassName =szChild;
	WndClass.hbrBackground =(HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.style=CS_HREDRAW | CS_VREDRAW|CS_DBLCLKS;
	WndClass.lpfnWndProc =(WNDPROC)ChildProc;
	 
	//WndClass.lpszMenuName ="Float";

	RegisterClass(&WndClass);
 
	hInst=hInstance;

	hWnd=CreateWindow(szAppName,
		"UML Designer",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hWnd,3);

	UpdateWindow(hWnd);

	hAccel=LoadAccelerators(hInstance,"MYMENU");

	while(GetMessage(&msg,NULL,0,0))
	{
		if(!TranslateAccelerator(hWnd,hAccel,&msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}
