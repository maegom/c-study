#include "GameLevel.h"
#include "../Object/GamePlayer.h"
#include "../Object/GameMonster.h"
#include "../Object/Door.h"

CGameLevel::CGameLevel()	:
	mScore(0)
{
}

CGameLevel::~CGameLevel()
{
}

void CGameLevel::Init()
{
	CLevel::Init();

	CreateObj<CGamePlayer>("Player", Vector2D(300.f, 600.f));

	CGameMonster* Monster = CreateObj<CGameMonster>("Monster", Vector2D(20.f, 500.f), Vector2D(50.f, 50.f));
	Monster->SetDir(EMonsterMoveDir::Right);

	Monster = CreateObj<CGameMonster>("Monster", Vector2D(1100.f, 400.f), Vector2D(50.f, 50.f));
	Monster->SetDir(EMonsterMoveDir::Left);

	Monster = CreateObj<CGameMonster>("Monster", Vector2D(500.f, 300.f), Vector2D(50.f, 50.f));
	Monster->SetDir(EMonsterMoveDir::Right);

	Monster = CreateObj<CGameMonster>("Monster", Vector2D(300.f, 200.f), Vector2D(50.f, 50.f));
	Monster->SetDir(EMonsterMoveDir::Left);



	CreateObj<CDoor>("Door", Vector2D(1280.f / 2.f - 50.f, 0.f));
}

void CGameLevel::Render(HDC hDC)
{
	// 오브젝트 출력은 무조건 동작되어야 하기 때문에 부모클래스의 Render함수를
	// 동작시켜준다.
	CLevel::Render(hDC);

	TCHAR	ScoreText[16] = {};

	wsprintf(ScoreText, TEXT("Score : %d"), mScore);

	TextOut(hDC, 30, 20, ScoreText, lstrlen(ScoreText));
}





