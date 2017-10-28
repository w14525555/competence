#include "GameApp.h"

//Command line Arguments 
int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd)
{
	GameApp gameApp(hInstance);

	if (!gameApp.Init())
	{
		return 1;
	}

	return gameApp.Run();

}
