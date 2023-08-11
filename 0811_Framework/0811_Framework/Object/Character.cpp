#include "Character.h"

CCharacter::CCharacter()	:
	mHP(100)
{
}

CCharacter::CCharacter(const CCharacter& Obj)	:
	CObject(Obj)
{
	mHP = Obj.mHP;
}

CCharacter::~CCharacter()
{
}

void CCharacter::Init()
{
	CObject::Init();
}

void CCharacter::Input(float DeltaTime)
{
	CObject::Input(DeltaTime);
}

void CCharacter::Update(float DeltaTime)
{
	CObject::Update(DeltaTime);
}

void CCharacter::Collision(float DeltaTime)
{
	CObject::Collision(DeltaTime);
}

void CCharacter::Render(HDC hDC)
{
	CObject::Render(hDC);
}

void CCharacter::Collision(CObject* Dest)
{
}
