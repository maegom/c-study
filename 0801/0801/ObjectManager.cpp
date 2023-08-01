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
		Monster->Init("고블린", 25, 10, 100, 10, 1, 1000, 1000);
		break;
	case Normal:
		Monster->Init("고블린", 25, 10, 100, 10, 1, 1000, 1000);
		break;
	case Hard:
		Monster->Init("고블린", 25, 10, 100, 10, 1, 1000, 1000);
		break;
	}


	return Monster;
}
