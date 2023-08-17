#pragma once
#include "Object.h"
class CDoor :
    public CObject
{
public:
	CDoor();
	CDoor(const CDoor& Obj);
	virtual ~CDoor();

public:
	virtual void Init();
	virtual void Input(float DeltaTime);
	virtual void Update(float DeltaTime);
	virtual void Collision(float DeltaTime);
	virtual void Render(HDC hDC);
	virtual void Collision(CObject* Dest);
};

