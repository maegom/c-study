#include "Monster.h"
#include "../GameManager.h"
#include "Bullet.h"
#include "GuidedBullet.h"
#include "../Level/LevelManager.h"
#include "../Level/MainLevel.h"

CMonster::CMonster()
{
	// CBullet의 고유한 번호를 저장한다.
	mTypeID = typeid(CMonster).hash_code();
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
}

void CMonster::Input(float DeltaTime)
{
	CCharacter::Input(DeltaTime);
}

void CMonster::Update(float DeltaTime)
{
	CCharacter::Update(DeltaTime);
}

void CMonster::Collision(float DeltaTime)
{
	CCharacter::Collision(DeltaTime);
}

void CMonster::Render(HDC hDC)
{
	CCharacter::Render(hDC);
}

void CMonster::Collision(CObject* Dest)
{
}
