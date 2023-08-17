#include "GamePlayer.h"
#include "GameMonster.h"
#include "Door.h"
#include "../Level/LevelManager.h"
#include "../Level/GameLevel.h"

CGamePlayer::CGamePlayer()
{
	mTypeID = typeid(CGamePlayer).hash_code();
}

CGamePlayer::CGamePlayer(const CGamePlayer& Obj)	:
	CPlayer(Obj)
{
}

CGamePlayer::~CGamePlayer()
{
}

void CGamePlayer::Init()
{
	CPlayer::Init();

	SetMoveSpeed(500.f);
}

void CGamePlayer::Input(float DeltaTime)
{
	CPlayer::Input(DeltaTime);

	Vector2D	MoveDir;

	if (GetAsyncKeyState('W') & 0x8000)
	{
		MoveDir.y += -1.f;
	}

	if (GetAsyncKeyState('S') & 0x8000)
	{
		MoveDir.y += 1.f;
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		MoveDir.x += -1.f;
	}

	if (GetAsyncKeyState('D') & 0x8000)
	{
		MoveDir.x += 1.f;
	}

	MoveDir.Normalize();

	Move(MoveDir);
}

void CGamePlayer::Update(float DeltaTime)
{
	CPlayer::Update(DeltaTime);
}

void CGamePlayer::Collision(float DeltaTime)
{
	CPlayer::Collision(DeltaTime);
}

void CGamePlayer::Render(HDC hDC)
{
	CPlayer::Render(hDC);
}

void CGamePlayer::Collision(CObject* Dest)
{
	// �÷��̾�� ��, ���� ���� �ϳ��� �浹�� �Ѵ�.
	// �׷��Ƿ� � ������Ʈ�� �浹�Ǿ������� �Ǵ��ؾ� �Ѵ�.
	if (Dest->CheckType<CGameMonster>())
	{
		SetPos(Vector2D(300.f, 600.f));
	}

	else if (Dest->CheckType<CDoor>())
	{
		SetPos(Vector2D(300.f, 600.f));

		CGameLevel* Level = (CGameLevel*)CLevelManager::GetInst()->GetLevel();

		Level->AddScore(10);
	}
}
