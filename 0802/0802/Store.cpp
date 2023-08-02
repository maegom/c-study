#include "Store.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "ObjectManager.h"

CStore::CStore()	:
	mItemCount(0),
	mItemArray(nullptr)
{
}

CStore::~CStore()
{
	if (mItemArray)
	{
		delete[] mItemArray;
	}
}

int CStore::Menu()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	system("cls");
	for (int i = 0; i < mItemCount; ++i)
	{
		std::cout << i + 1 << ". ";
		mItemArray[i].Output();
		std::cout << std::endl;
	}

	std::cout << mItemCount + 1 << ". �ڷΰ���" << std::endl;

	std::cout << "�����ݾ� : " << Player->GetMoney() << std::endl;

	std::cout << "�������� �����ϼ��� : ";
	int	Input;
	std::cin >> Input;

	if (Input <= 0 ||
		Input > mItemCount + 1)
		return 0;

	return Input;
}

bool CStore::Init(const char* FileName)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, FileName, "rb");

	if (!FileStream)
		return false;

	fread(&mItemCount, sizeof(int), 1, FileStream);

	// ������ �о�� mItemCount�� �� �������� �Ǹ��ϴ� �������� ������� �����´�.
	// �׷��Ƿ� �������� �����ϱ� ���� �迭�� ��������� �����Ǿ� �����Ƿ� �ش� �迭��
	// ������ �о�� �������� ������ŭ �����迭�� �Ҵ����ش�.
	mItemArray = new CItem[mItemCount];

	for (int i = 0; i < mItemCount; ++i)
	{
		mItemArray[i].Init(FileStream);
	}

	fclose(FileStream);

	return true;
}

void CStore::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();
	;
	while (true)
	{
		int Input = Menu();

		if (Input == -1)
			continue;

		else if (Input == mItemCount + 1)
			break;

		int	ItemIndex = Input - 1;

		// �κ��丮�� ĭ�� ������ ��� �߰��� �� ����.
		if (CInventory::GetInst()->IsFull())
		{
			std::cout << "������ ������ �����մϴ�." << std::endl;
			system("pause");
			continue;
		}

		// ������ �ִ� ������ ������ �Ǵ��Ѵ�.
		else if (Player->GetMoney() < mItemArray[ItemIndex].GetPrice())
		{
			std::cout << "�������� �����մϴ�." << std::endl;
			system("pause");
			continue;
		}

		// �κ��丮�� �������� �߰����ش�.
		// ������ �������� ����������� ���ڿ� �������־ �κ��丮�� �߰��ϱ� ����
		// ���� �����ϴ� �������� ������ ������ �������� ������ �״�� �������ش�.
		CItem* InvenItem = new CItem(mItemArray[ItemIndex]);

		// �κ��丮�� �������� �߰����ش�.
		CInventory::GetInst()->AddItem(InvenItem);

		Player->AddMoney(-InvenItem->GetPrice());
	}
}
