#pragma once

#include "Info.h"

enum class EBattleMenu
{
	None,
	Easy,
	Normal,
	Hard,
	Back
};

class CBattleManager
{
public:
	CBattleManager();
	~CBattleManager();

private:
	EBattleMenu Menu();

public:
	bool Init();
	void Run();
};
