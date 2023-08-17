#pragma once
#include "Player.h"
class CMainPlayer :
    public CPlayer
{
public:
	CMainPlayer();
	CMainPlayer(const CMainPlayer& Obj);
	virtual ~CMainPlayer();

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual void Collision(CObject* Dest);
};

