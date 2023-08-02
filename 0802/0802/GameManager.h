#pragma once

#include "Info.h"

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
private:
	CGameManager();
	~CGameManager();

private:
	static CGameManager* mInst;

public:
	static CGameManager* GetInst()
	{
		if (nullptr == mInst)
			mInst = new CGameManager;
		
		return mInst;
	}

	static void DestroyInst()
	{
		if (nullptr != mInst)
		{
			delete mInst;
			mInst = nullptr;
		}
	}

private:

private:
	EMainMenu Menu();

public:
	bool Init();
	void Run();
};

