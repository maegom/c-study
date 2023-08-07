#include "Store.h"
#include "Item.h"
#include "Inventory.h"
#include "Player.h"
#include "ObjectManager.h"

CStore::CStore()
{
}

CStore::~CStore()
{
}

int CStore::Menu()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	system("cls");
	for (int i = 0; i < mItemArray.size(); ++i)
	{
		std::cout << i + 1 << ". ";
		mItemArray[i]->Output();
		std::cout << std::endl;
	}

	std::cout << mItemArray.size() + 1 << ". �ڷΰ���" << std::endl;

	std::cout << "�����ݾ� : " << Player->GetMoney() << std::endl;

	std::cout << "�������� �����ϼ��� : ";
	int	Input;
	std::cin >> Input;

	if (Input <= 0 ||
		Input > mItemArray.size() + 1)
		return 0;

	return Input;
}

bool CStore::Init(const char* FileName)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, FileName, "rb");

	if (!FileStream)
		return false;

	int	Count = 0;
	fread(&Count, sizeof(int), 1, FileStream);

	// ������ �о�� mItemCount�� �� �������� �Ǹ��ϴ� �������� ������� �����´�.
	// �׷��Ƿ� �������� �����ϱ� ���� �迭�� ��������� �����Ǿ� �����Ƿ� �ش� �迭��
	// ������ �о�� �������� ������ŭ �����迭�� �Ҵ����ش�.
	for (int i = 0; i < Count; ++i)
	{
		CItem* Item = new CItem;

		Item->Init(FileStream);

		mItemArray.push_back(Item);
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

		else if (Input == mItemArray.size() + 1)
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
		else if (Player->GetMoney() < mItemArray[ItemIndex]->GetPrice())
		{
			std::cout << "�������� �����մϴ�." << std::endl;
			system("pause");
			continue;
		}

		// �κ��丮�� �������� �߰����ش�.
		// ������ �������� ����������� ���ڿ� �������־ �κ��丮�� �߰��ϱ� ����
		// ���� �����ϴ� �������� ������ ������ �������� ������ �״�� �������ش�.
		CItem* InvenItem = new CItem(*mItemArray[ItemIndex]);

		// �κ��丮�� �������� �߰����ش�.
		CInventory::GetInst()->AddItem(InvenItem);

		Player->AddMoney(-InvenItem->GetPrice());
	}
}
