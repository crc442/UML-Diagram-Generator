static char tempOpen[MAX_PATH];
static char szOpenFileName[MAX_PATH];	

void Openmenu(HWND hWnd)
{	
	OPENFILENAME ofn;
		
	//strcpy(tempOpen,"");
	//strcpy(szOpenFileName,"");
	ZeroMemory(&ofn,sizeof(ofn));
	ofn.lStructSize =sizeof(ofn);
	ofn.hwndOwner =hWnd;
	ofn.lpstrFilter ="Uml Files(*.uml)\0*.uml\0All Files(*.*)\0*.*\0";
	
	//ofn.nFilterIndex =1;
	ofn.lpstrFile =szOpenFileName;
	ofn.nMaxFile= MAX_PATH;
	ofn.lpstrDefExt ="txt";
	ofn.lpstrTitle ="Open UML Diagram";
	ofn.lpstrInitialDir ="c:\\My Document\\";
		
	if(GetOpenFileName(&ofn))
	{
		strcpy(tempOpen,szOpenFileName);
		wsprintf(tempOpen,"%s - UML Designer",szOpenFileName);
	}
}							