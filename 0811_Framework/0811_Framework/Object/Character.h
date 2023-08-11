#pragma once
#include "Object.h"
class CCharacter :
    public CObject
{
public:
	CCharacter();
	CCharacter(const CCharacter& Obj);
	virtual ~CCharacter();

protected:
	int		mHP;

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual void Collision(CObject* Dest);
};

