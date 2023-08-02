#pragma once

#include "Info.h"

enum class EBattleMenu
{
	None,
	Attack,
	Back
};

enum class EBattleResult
{
	None,
	PlayerDeath,
	MonsterDeath
};

class CBattle
{
public:
	CBattle();
	~CBattle();

private:
	EBattleType	mBattleType;

private:
	EBattleMenu Menu();
	EBattleResult Attack(class CPlayer* Player, class CMonster* Monster);

public:
	bool Init(EBattleType Type);
	void Run();
};

