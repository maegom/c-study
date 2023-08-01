#pragma once

#include "Info.h"

class CBattle
{
public:
	CBattle();
	~CBattle();

private:
	EBattleType	mBattleType;

public:
	bool Init(EBattleType Type);
	void Run();
};

