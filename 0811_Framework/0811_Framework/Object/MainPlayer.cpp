
#include "MainPlayer.h"
#include "Bullet.h"
#include "../Level/LevelManager.h"
#include "../Level/Level.h"

CMainPlayer::CMainPlayer()
{
	// CBullet의 고유한 번호를 저장한다.
	mTypeID = typeid(CMainPlayer).hash_code();
}

CMainPlayer::CMainPlayer(const CMainPlayer& Obj) :
	CPlayer(Obj)
{
}

CMainPlayer::~CMainPlayer()
{
}

void CMainPlayer::Init()
{
	CPlayer::Init();

	SetMoveSpeed(500.f);
}

void CMainPlayer::Input(float DeltaTime)
{
	CPlayer::Input(DeltaTime);

	// VK_SPACE : Space Bar
	// VK_RETURN : Enter
	// VK_F1 : F1키

	// GetAsyncKeyState : 키 입력을 감지한다. 키를 누르게 된다면
	// 0x8000 을 반환한다.
	// 0 & 1000 0000 0000 0000 = 0
	// 1000 0000 0000 0000 & 1000 0000 0000 0000 = 1000 0000 0000 0000
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

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		CLevel* Level = CLevelManager::GetInst()->GetLevel();

		CBullet* Bullet = Level->CreateObj<CBullet>("Bullet");

		Bullet->SetSize(25.f, 25.f);

		Bullet->SetPos(mPos.x + mSize.x * 0.5f - Bullet->GetSize().x * 0.5f,
			mPos.y - Bullet->GetSize().y);

		// 플레이어 총알은 위로 이동해야 되기 때문에 y값이 점점 작아져야 한다.
		Bullet->SetDir(-1);
	}

	MoveDir.Normalize();

	Move(MoveDir);
}

void CMainPlayer::Update(float DeltaTime)
{
	CPlayer::Update(DeltaTime);
}

void CMainPlayer::Collision(float DeltaTime)
{
	CPlayer::Collision(DeltaTime);
}

void CMainPlayer::Render(HDC hDC)
{
	CPlayer::Render(hDC);

	TCHAR	HPText[16] = {};

	wsprintf(HPText, TEXT("HP : %d"), mHP);

	TextOut(hDC, (int)mPos.x, (int)mPos.y - 20, HPText, lstrlen(HPText));
}

void CMainPlayer::Collision(CObject* Dest)
{
	if (strcmp(Dest->GetName(), "MonsterBullet") != 0)
		return;

	mHP -= 1;
}
