#include "GameManager.h"

int main()
{
	if (CGameManager::GetInst()->Init() == false)
	{
		CGameManager::DestroyInst();
		return 0;
	}

	CGameManager::GetInst()->Run();

	CGameManager::DestroyInst();
	/*CGameManager	Mgr;

	Mgr.Init();

	Mgr.Run();*/

	return 0;
}
