#pragma once
#include "Monster.h"
class CMainMonster :
    public CMonster
{
public:
	CMainMonster();
	CMainMonster(const CMainMonster& Obj);
	virtual ~CMainMonster();

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
	virtual void Collision(CObject* Dest);
};

