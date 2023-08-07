#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"

CObjectManager* CObjectManager::mInst = nullptr;

CObjectManager::CObjectManager()	:
	mPlayer(nullptr)
{
}

CObjectManager::~CObjectManager()
{
	if (mPlayer)
	{
		delete mPlayer;
		mPlayer = nullptr;
	}
}

bool CObjectManager::Init()
{
	mPlayer = new CPlayer;
	
	if (!mPlayer->Init())
		return false;

	return true;
}

CMonster* CObjectManager::CreateMonster(EBattleType Type)
{
	CMonster* Monster = new CMonster;

	switch (Type)
	{
	case Easy:
		Monster->SetInfo("고블린", 25, 10, 100, 10, 1, 1000, 1000);
		break;
	case Normal:
		Monster->SetInfo("오크", 80, 50, 900, 100, 5, 8000, 8000);
		break;
	case Hard:
		Monster->SetInfo("오우거", 200, 150, 2000, 1000, 10, 15000, 15000);
		break;
	}

	Monster->Init();


	return Monster;
}
