#pragma once

#include "BattleManager.h"

enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

class CGameManager
{
public:
	CGameManager();
	~CGameManager();

private:
	CBattleManager* mBattleMgr;

private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};

