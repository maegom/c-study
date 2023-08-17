#pragma once
#include "Player.h"
class CGamePlayer :
    public CPlayer
{
public:
	CGamePlayer();
	CGamePlayer(const CGamePlayer& Obj);
	virtual ~CGamePlayer();

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual void Collision(CObject* Dest);
};

