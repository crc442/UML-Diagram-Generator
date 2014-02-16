static HWND hWnd, hChildWnd;//Main Handle Of Window
HINSTANCE hInst,hInstance;
static HWND hEdit,hToolbar;
static HMETAFILE hClipboardEmf;

static int diaSelected;
static int undoArr[9];
static int umlCnt,clsCnt;
//Scroll Bar
static int sbVert,sbHorz,sbhzFlag,sbvtFlag,sbhzOld,sbvtOld;
static int vertPos,horzPos;


static int undoFlag=1;
static char szCppFile[20];
static RECT tempRect;
static HGLOBAL hGlobal;
//METAFILEPICT far * pGlobal ;

static struct UMLDia
{
	int diaNo;
	int type;
	RECT Rect;
	char figure[100];
	int undo,startx,starty;
 
}UML[100];

 

static int openFlag=0;
static char tempID[20]="",szEditText[50];

static HWND hStatus1;
static HMENU hMenu,hSubMenu;

static HWND htvwWnd;
static HTREEITEM hTreeItem,hTreeWnd[9];;
static int treecnt;
static TVITEMA tvi;

static TVINSERTSTRUCTA tvs;
NMTREEVIEW *nmptr; 

void AddTreeItem(char string[20],int cshow)
{
	 tvi.mask =TVIF_TEXT|TVIF_STATE;
	 tvi.pszText =string;
	 tvs.hInsertAfter=TVI_SORT;
	 tvs.hParent =hTreeItem;
	 tvs.item =tvi;
	 hTreeWnd[cshow]=(HTREEITEM)SendMessage(htvwWnd,TVM_INSERTITEM,treecnt++,(LPARAM)&tvs);
}

 