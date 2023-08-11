#include "MainLevel.h"
#include "../Object/Player.h"
#include "../Object/Monster.h"

CMainLevel::CMainLevel()	:
	mScore(0)
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

void CMainLevel::Render(HDC hDC)
{
	// 오브젝트 출력은 무조건 동작되어야 하기 때문에 부모클래스의 Render함수를
	// 동작시켜준다.
	CLevel::Render(hDC);

	TCHAR	ScoreText[16] = {};

	wsprintf(ScoreText, TEXT("Score : %d"), mScore);

	TextOut(hDC, 30, 20, ScoreText, lstrlen(ScoreText));
}
