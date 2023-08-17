#include "GameMonster.h"
#include "../GameManager.h"

CGameMonster::CGameMonster()	:
	mDir(EMonsterMoveDir::Right)
{
	mTypeID = typeid(CGameMonster).hash_code();
}

CGameMonster::CGameMonster(const CGameMonster& Obj)	:
	CMonster(Obj)
{
}

CGameMonster::~CGameMonster()
{
}

void CGameMonster::Init()
{
	CMonster::Init();

	SetMoveSpeed(600.f);
}

void CGameMonster::Input(float DeltaTime)
{
	CMonster::Input(DeltaTime);

	Move((float)mDir, 0.f);
}

void CGameMonster::Update(float DeltaTime)
{
	CMonster::Update(DeltaTime);

	Resolution	RS = CGameManager::GetInst()->GetResolution();

	if (mPos.x + mSize.x >= RS.Width)
	{
		mPos.x = RS.Width - mSize.x;
		mDir = EMonsterMoveDir::Left;
	}

	else if (mPos.x <= 0.f)
	{
		mPos.x = 0.f;
		mDir = EMonsterMoveDir::Right;
	}
}

void CGameMonster::Collision(float DeltaTime)
{
	CMonster::Collision(DeltaTime);
}

void CGameMonster::Render(HDC hDC)
{
	CMonster::Render(hDC);
}

void CGameMonster::Collision(CObject* Dest)
{
}
