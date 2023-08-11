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
	// ������Ʈ ����� ������ ���۵Ǿ�� �ϱ� ������ �θ�Ŭ������ Render�Լ���
	// ���۽����ش�.
	CLevel::Render(hDC);

	TCHAR	ScoreText[16] = {};

	wsprintf(ScoreText, TEXT("Score : %d"), mScore);

	TextOut(hDC, 30, 20, ScoreText, lstrlen(ScoreText));
}
