#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

// copy a string into the clipboard
void to_clip(char * str){

	const size_t len = strlen(str) + 1;
	HGLOBAL hMem =  GlobalAlloc(GMEM_MOVEABLE, len);
	
	memcpy(GlobalLock(hMem), str, len);
	GlobalUnlock(hMem);
	
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_TEXT, hMem);
	CloseClipboard();
}

int main(int argc, char ** argv){
	
	// Concatenates all arguments (with spaces) if there is more than 1
	if(argc > 2)
	{
		int i;
		char * str;
		int size;
		
		// Compute the resulting string size to then alloc memory
		for(i = 1; i < argc; i++){
			size += strlen(argv[i]) + 1;
		}
		
		str = (char*)malloc(sizeof(char)*size);
		
		// Concatenates every argument
		for(i = 1; i < argc; i++){
			if(i != 1)
				strcat(str, " ");
			strcat(str, argv[i]);
		}
		
		to_clip(str);
		
		free(str);
		
		return 0;	
	}
	else if (argc == 2) // One argument: Give it directly to the clipboard
	{
		to_clip(argv[1]);
		return 0;
	}
	else
	{
		return -1;
	}
}