static char tempSave[MAX_PATH]=""; 
static char szSaveFileName[MAX_PATH];

void Savemenu(HWND hWnd)
{
	OPENFILENAME ofn;
		
	HANDLE hFile;

	ZeroMemory(&ofn,sizeof(ofn));
	ofn.lStructSize =sizeof(ofn);
	ofn.hwndOwner =hWnd;
	ofn.lpstrFilter ="Uml Files(*.uml)\0*.uml\0All Files(*.*)\0*.*\0";
	//ofn.nFilterIndex =1;
	ofn.lpstrFile =szSaveFileName;
	ofn.nMaxFile= MAX_PATH;
	ofn.lpstrDefExt ="txt";
	ofn.lpstrTitle ="Save UML Diagram";
	ofn.lpstrInitialDir ="c:\\My Document\\";
	if(GetSaveFileName(&ofn))
	{strcpy(tempSave,szSaveFileName);
	wsprintf(tempSave,"%s - UML Designer",szSaveFileName);
	hFile=CreateFile(szSaveFileName,GENERIC_WRITE,FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
	}
}
