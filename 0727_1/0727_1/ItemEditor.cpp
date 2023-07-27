#include "ItemEditor.h"

void CreateItem(Item* Array, int& Count)
{
	//Item* item = new Item;

	system("cls");
	std::cout << "============= ������ ���� =============" << std::endl;
	std::cout << "�̸� : ";

	// ����ü �����ʹ� -> �̿��ؼ� �����ϴ� ����� ����� ������ �� �ִ�.
	//std::cin >> item->Name;
	std::cin >> Array[Count].Name;

	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ��" << std::endl;
	std::cout << "������ ������ �����ϼ��� : ";
	int	ItemType = 0;
	std::cin >> ItemType;

	Array[Count].Type = (EItemType)(ItemType - 1);

	std::cout << "Price : ";
	std::cin >> Array[Count].Price;

	std::cout << "Sell : ";
	std::cin >> Array[Count].Sell;

	++Count;
}

void OutputItemList(Item* Array, int Count)
{
	for (int i = 0; i < Count; ++i)
	{
		std::cout << "�̸� : " << Array[i].Name << "\t���� : ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "����\n";
			break;
		case EItemType::Armor:
			std::cout << "��\n";
			break;
		}

		std::cout << "Price : " << Array[i].Price << "\tSell : "
			<< Array[i].Sell << std::endl;
	}

	system("pause");
}

void SaveItemList(Item* Array, int Count)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "ItemList.itl", "wb");

	if (FileStream)
	{
		fwrite(&Count, sizeof(Count), 1, FileStream);
		fwrite(Array, sizeof(Item), Count, FileStream);

		fclose(FileStream);
	}
}

void LoadItemList(Item* Array, int& Count)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "ItemList.itl", "rb");

	if (FileStream)
	{
		fread(&Count, sizeof(Count), 1, FileStream);
		fread(Array, sizeof(Item), Count, FileStream);

		fclose(FileStream);
	}
}
