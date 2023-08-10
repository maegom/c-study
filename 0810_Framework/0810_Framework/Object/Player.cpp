#include "Player.h"
#include "Bullet.h"
#include "../Level/LevelManager.h"
#include "../Level/Level.h"

CPlayer::CPlayer()
{
	// CBullet�� ������ ��ȣ�� �����Ѵ�.
	mTypeID = typeid(CPlayer).hash_code();
}

CPlayer::CPlayer(const CPlayer& Obj)	:
	CCharacter(Obj)
{
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	CCharacter::Init();

	SetMoveSpeed(500.f);
}

void CPlayer::Input(float DeltaTime)
{
	CCharacter::Input(DeltaTime);

	// VK_SPACE : Space Bar
	// VK_RETURN : Enter
	// VK_F1 : F1Ű

	// GetAsyncKeyState : Ű �Է��� �����Ѵ�. Ű�� ������ �ȴٸ�
	// 0x8000 �� ��ȯ�Ѵ�.
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

		// �÷��̾� �Ѿ��� ���� �̵��ؾ� �Ǳ� ������ y���� ���� �۾����� �Ѵ�.
		Bullet->SetDir(-1);
	}

	MoveDir.Normalize();

	Move(MoveDir);
}

void CPlayer::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);
}

void CPlayer::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CPlayer::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}

void CPlayer::Collision(CObject* Dest)
{
	SetActive(false);
}
