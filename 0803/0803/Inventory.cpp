#include "Inventory.h"
#include "Item.h"
#include "ObjectManager.h"
#include "Player.h"

CInventory* CInventory::mInst = nullptr;

CInventory::CInventory()	:
	mItemArray{},
	mCount(0)
{
}

CInventory::~CInventory()
{
	// �κ��丮�� �������� �ϳ��ϳ��� ��� �����Ҵ�Ǿ� ������ �������̹Ƿ�
	// �κ��丮�� ������ �� �ݵ�� �� �����۵鵵 ���Ÿ� ���־�� �Ѵ�.
	for (int i = 0; i < mCount; ++i)
	{
		delete mItemArray[i];
	}
}

int CInventory::Menu()
{
	system("cls");
	for (int i = 0; i < mCount; ++i)
	{
		std::cout << i + 1 << ". ";
		mItemArray[i]->Output();
		std::cout << std::endl;
	}

	std::cout << mCount + 1 << ". �ڷΰ���" << std::endl;

	std::cout << "�������� �����ϼ��� : ";
	int	Input;
	std::cin >> Input;

	if (Input <= 0 || Input > mCount + 1)
		return -1;

	return Input;
}

bool CInventory::Init()
{
	return true;
}

void CInventory::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	while (true)
	{
		int Input = Menu();

		if (Input == -1)
			continue;

		else if (Input == mCount + 1)
			break;

		int	ItemIndex = Input - 1;

		CItem* ChangeItem = nullptr;

		if (Player->Equip(mItemArray[ItemIndex], &ChangeItem))
		{
			if (ChangeItem)
			{
				mItemArray[ItemIndex] = ChangeItem;
			}

			else
			{
				// �����ϰ� �ִ� �������� ���� ��� �κ��丮�� �ش� ĭ����
				// �ڿ� �ִ� ��� �������� ������ 1ĭ�� �̵���Ų��.
				for (int i = ItemIndex; i < mCount - 1; ++i)
				{
					mItemArray[i] = mItemArray[i + 1];
				}

				--mCount;
			}
		}
    }
}
