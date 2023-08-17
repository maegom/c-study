#pragma once
#include "Monster.h"
class CGameMonster :
    public CMonster
{
public:
	CGameMonster();
	CGameMonster(const CGameMonster& Obj);
	virtual ~CGameMonster();

private:
	EMonsterMoveDir	mDir;

public:
	void SetDir(EMonsterMoveDir Dir)
	{
		mDir = Dir;
	}

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual void Collision(CObject* Dest);
};

