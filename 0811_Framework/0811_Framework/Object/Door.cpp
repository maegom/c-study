
#include "Door.h"

CDoor::CDoor()
{
	mTypeID = typeid(CDoor).hash_code();
}

CDoor::CDoor(const CDoor& Obj) :
	CObject(Obj)
{
}

CDoor::~CDoor()
{
}

void CDoor::Init()
{
	CObject::Init();
}

void CDoor::Input(float DeltaTime)
{
	CObject::Input(DeltaTime);
}

void CDoor::Update(float DeltaTime)
{
	CObject::Update(DeltaTime);
}

void CDoor::Collision(float DeltaTime)
{
	CObject::Collision(DeltaTime);
}

void CDoor::Render(HDC hDC)
{
	CObject::Render(hDC);
}

void CDoor::Collision(CObject* Dest)
{
}
