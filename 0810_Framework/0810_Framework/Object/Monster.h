#pragma once

#include "Character.h"

class CMonster :
    public CCharacter
{
public:
	CMonster();
	CMonster(const CMonster& Obj);
	virtual ~CMonster();

private:
	// �̵� ������ �����Ѵ�.
	// �̵� ������ 1�� ��� ������ -1�� ��� �������� �����δ�.
	int		mDir;
	float	mAccTime;
	int		mCount;

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
};

