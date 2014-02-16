#include <windows.h>
#include <commctrl.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "smenu.h"
#include <Mmsystem.h>
#include "CDialog.h"
#include "LoginDialog.h"
#include "Adialog.h"
#include "Disablemenu.h"
#include "Enablemenu.h"
#include "ChildProc.h"
#define TIMER1 100

void Openmenu(HWND);

void Disablemenu(HWND);

void Enablemenu(HWND);

void CallProgressBar(HWND,int,int);

/*BOOL CALLBACK CDlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK ADlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK LoginDlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK UseCaseDlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK ObjectDlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK CollabDlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK SeqDlgProc(HWND,UINT,WPARAM,LPARAM);

BOOL CALLBACK ClsDlgProc(HWND,UINT,WPARAM,LPARAM);*/

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

LRESULT CALLBACK ChildProc(HWND,UINT,WPARAM,LPARAM);


 

