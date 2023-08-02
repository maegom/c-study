#include "Battle.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Monster.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

bool CBattle::Init(EBattleType Type)
{
	mBattleType = Type;

	return true;
}

void CBattle::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);

	while (true)
	{
	}
}
