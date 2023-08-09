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
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			// �޸� �ּҸ� �̿��ؼ� �Ҵ�� ��ü�� �����Ѵ�.
			delete* iter;

			// erase �Լ��� ���� ����� ���� ��带 ��ȯ�Ѵ�.
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Input(DeltaTime);
		++iter;
	}
}

void CLevel::Update(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			// �޸� �ּҸ� �̿��ؼ� �Ҵ�� ��ü�� �����Ѵ�.
			delete* iter;

			// erase �Լ��� ���� ����� ���� ��带 ��ȯ�Ѵ�.
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Update(DeltaTime);
		++iter;
	}
}

void CLevel::Collision(float DeltaTime)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			// �޸� �ּҸ� �̿��ؼ� �Ҵ�� ��ü�� �����Ѵ�.
			delete* iter;

			// erase �Լ��� ���� ����� ���� ��带 ��ȯ�Ѵ�.
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Collision(DeltaTime);
		++iter;
	}
}

void CLevel::Render(HDC hDC)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; )
	{
		if (!(*iter)->GetActive())
		{
			// �޸� �ּҸ� �̿��ؼ� �Ҵ�� ��ü�� �����Ѵ�.
			delete *iter;

			// erase �Լ��� ���� ����� ���� ��带 ��ȯ�Ѵ�.
			iter = mObjList.erase(iter);
			iterEnd = mObjList.end();

			continue;
		}

		(*iter)->Render(hDC);
		++iter;
	}
}
