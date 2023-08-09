#include "Monster.h"
#include "../GameManager.h"

CMonster::CMonster()	:
	mDir(1)
{
}

CMonster::CMonster(const CMonster& Obj) :
	CCharacter(Obj)
{
}

CMonster::~CMonster()
{
}

void CMonster::Init()
{
	CCharacter::Init();

	SetMoveSpeed(300.f);
}

void CMonster::Input(float DeltaTime)
{
	CCharacter::Input(DeltaTime);

	Move((float)mDir, 0.f);
}

void CMonster::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);

	// GameManager�� ������ �ִ� ������ ũ�⸦ ���´�.
	Resolution	RS = CGameManager::GetInst()->GetResolution();

	// CObject�� Update���� �̵��� �Ǿ��� ���̴�.
	if (mPos.x + mSize.x >= RS.Width)
	{
		mPos.x = RS.Width - mSize.x;
		mDir = -1;
	}

	else if (mPos.x <= 0.f)
	{
		mPos.x = 0.f;
		mDir = 1;
	}
}

void CMonster::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CMonster::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}
