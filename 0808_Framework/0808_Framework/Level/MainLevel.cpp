#include "MainLevel.h"
#include "../Object/Player.h"
#include "../Object/Monster.h"

CMainLevel::CMainLevel()
{
}

CMainLevel::~CMainLevel()
{
}

void CMainLevel::Init()
{
	CLevel::Init();

	CreateObj<CPlayer>("Player", Vector2D(300.f, 500.f));
	CreateObj<CMonster>("Monster", Vector2D(500.f, 50.f), Vector2D(50.f, 50.f));
}
