#include "Level.h"
#include "../Object/Object.h"

CLevel::CLevel()
{
}

CLevel::~CLevel()
{
	// ������ ���ŵɶ� ������ ������ �ִ� ��� ������Ʈ�� �����Ѵ�.
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		SAFE_DELETE((*iter));
	}
}

void CLevel::Init()
{
}

void CLevel::Input(float DeltaTime)
{
}

void CLevel::Update(float DeltaTime)
{
}

void CLevel::Collision(float DeltaTime)
{
}

void CLevel::Render(HDC hDC)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		(*iter)->Render(hDC);
	}
}
