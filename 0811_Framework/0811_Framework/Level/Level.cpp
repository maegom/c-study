#include "Level.h"
#include "../Object/Bullet.h"
#include "../Object/GuidedBullet.h"
#include "../GameManager.h"

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

CObject* CLevel::FindObject(const char* Name)
{
	std::list<CObject*>::iterator	iter;
	std::list<CObject*>::iterator	iterEnd = mObjList.end();

	for (iter = mObjList.begin(); iter != iterEnd; ++iter)
	{
		// strcmp : �� ���ڿ��� ���Ͽ� ���� ��� 0�� ��ȯ�Ѵ�.
		if (strcmp((*iter)->GetName(), Name) == 0)
		{
			return *iter;
		}
	}

	return nullptr;
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
	--iterEnd;

	for (iter = mObjList.begin(); iter != iterEnd;)
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

		Vector2D	Pos = (*iter)->GetPos();
		Vector2D	Size = (*iter)->GetSize();

		std::list<CObject*>::iterator	iter1 = iter;
		++iter1;
		std::list<CObject*>::iterator	iter1End = mObjList.end();

		for (; iter1 != iter1End; ++iter1)
		{
			Vector2D	Pos1 = (*iter1)->GetPos();
			Vector2D	Size1 = (*iter1)->GetSize();

			Resolution	RS = CGameManager::GetInst()->GetResolution();

			size_t	TypeID1 = (*iter)->GetTypeID();
			size_t	TypeID2 = (*iter1)->GetTypeID();

			// ���� �浹�� �Ͼ���� �Ǵ��Ѵ�.
			if (Pos.x <= Pos1.x + Size1.x && Pos.x + Size.x >= Pos1.x &&
				Pos.y <= Pos1.y + Size1.y && Pos.y + Size.y >= Pos1.y)
			{
				(*iter)->Collision((*iter1));
				(*iter1)->Collision((*iter));
			}
		}

		++iter;
	}

	//for (iter = mObjList.begin(); iter != iterEnd; )
	//{
	//	if (!(*iter)->GetActive())
	//	{
	//		// �޸� �ּҸ� �̿��ؼ� �Ҵ�� ��ü�� �����Ѵ�.
	//		delete* iter;

	//		// erase �Լ��� ���� ����� ���� ��带 ��ȯ�Ѵ�.
	//		iter = mObjList.erase(iter);
	//		iterEnd = mObjList.end();

	//		continue;
	//	}

	//	(*iter)->Collision(DeltaTime);
	//	++iter;
	//}
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
