#include "ItemEditor.h"

enum class ESearchType
{
	None,
	Name,
	Number,
	End
};

void SetItemData(Item* Array, int Index)
{
	system("cls");
	std::cout << "이름 : ";

	// 구조체 포인터는 -> 이용해서 참조하는 대상의 멤버에 접근할 수 있다.
	//std::cin >> item->Name;
	std::cin >> Array[Index].Name;

	std::cout << "1. 무기" << std::endl;
	std::cout << "2. 방어구" << std::endl;
	std::cout << "아이템 종류를 선택하세요 : ";
	int	ItemType = 0;
	std::cin >> ItemType;

	Array[Index].Type = (EItemType)(ItemType - 1);

	std::cout << "Price : ";
	std::cin >> Array[Index].Price;

	std::cout << "Sell : ";
	std::cin >> Array[Index].Sell;
}

void CreateItem(Item* Array, int& Count)
{
	//Item* item = new Item;

	std::cout << "============= 아이템 생성 =============" << std::endl;

	SetItemData(Array, Count);

	++Count;
}

void DeleteItem(Item* Array, int& Count)
{
	ESearchType	SearchType = ESearchType::None;
	while (true)
	{
		system("cls");
		std::cout << "============= 아이템 제거 =============" << std::endl;
		std::cout << "1. 이름 탐색" << std::endl;
		std::cout << "2. 번호 선택" << std::endl;
		std::cout << "메뉴를 선택하세요 : ";
		int	Input = 0;
		std::cin >> Input;

		if (Input > (int)ESearchType::None && Input < (int)ESearchType::End)
		{
			SearchType = (ESearchType)Input;
			break;
		}
	}

	system("cls");
	std::cout << "============= 아이템 제거 =============" << std::endl;
	for (int i = 0; i < Count; ++i)
	{
		std::cout << i + 1 << ". 이름 : " << Array[i].Name << "\t종류 : ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "무기\n";
			break;
		case EItemType::Armor:
			std::cout << "방어구\n";
			break;
		}

		std::cout << "Price : " << Array[i].Price << "\tSell : "
			<< Array[i].Sell << std::endl;
	}

	int	DeleteIndex = -1;

	switch (SearchType)
	{
	case ESearchType::Name:
		std::cout << "이름을 입력하세요 : ";
		char	Name[32];
		std::cin >> Name;

		for (int i = 0; i < Count; ++i)
		{
			// strcmp의 결과가 0일 경우 두 문자열은 같다.
			if (strcmp(Array[i].Name, Name) == 0)
			{
				DeleteIndex = i;
				break;
			}
		}
		break;
	case ESearchType::Number:
		std::cout << "지울 번호를 선택하세요 : ";
		std::cin >> DeleteIndex;

		if (DeleteIndex < 1 || DeleteIndex > Count)
			DeleteIndex = -1;

		// 1번부터 번호가 시작하고 있다. 이를 인덱스로 만들기 위해 1을 빼주어서
		// 0부터 시작되는 인덱스로 만들어준다.
		--DeleteIndex;
		break;
	}

	// DeleteIndex가 -1이라면 잘못된 인덱스이다.
	if (DeleteIndex != -1)
	{
		memmove(&Array[DeleteIndex], &Array[DeleteIndex + 1],
			sizeof(Item) * (Count - DeleteIndex - 1));
		//memset()
		//memcpy()
		/*for (int i = DeleteIndex; i < Count - 1; ++i)
		{
			Array[i] = Array[i + 1];
		}*/

		--Count;
	}

	system("pause");
}

void ModifyItem(Item* Array, int Count)
{
	ESearchType	SearchType = ESearchType::None;
	while (true)
	{
		system("cls");
		std::cout << "============= 아이템 수정 =============" << std::endl;
		std::cout << "1. 이름 탐색" << std::endl;
		std::cout << "2. 번호 선택" << std::endl;
		std::cout << "메뉴를 선택하세요 : ";
		int	Input = 0;
		std::cin >> Input;

		if (Input > (int)ESearchType::None && Input < (int)ESearchType::End)
		{
			SearchType = (ESearchType)Input;
			break;
		}
	}

	system("cls");
	std::cout << "============= 아이템 수정 =============" << std::endl;
	for (int i = 0; i < Count; ++i)
	{
		std::cout << i + 1 << ". 이름 : " << Array[i].Name << "\t종류 : ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "무기\n";
			break;
		case EItemType::Armor:
			std::cout << "방어구\n";
			break;
		}

		std::cout << "Price : " << Array[i].Price << "\tSell : "
			<< Array[i].Sell << std::endl;
	}

	int	ModifyIndex = -1;

	switch (SearchType)
	{
	case ESearchType::Name:
		std::cout << "이름을 입력하세요 : ";
		char	Name[32];
		std::cin >> Name;

		for (int i = 0; i < Count; ++i)
		{
			// strcmp의 결과가 0일 경우 두 문자열은 같다.
			if (strcmp(Array[i].Name, Name) == 0)
			{
				ModifyIndex = i;
				break;
			}
		}
		break;
	case ESearchType::Number:
		std::cout << "수정할 번호를 선택하세요 : ";
		std::cin >> ModifyIndex;

		if (ModifyIndex < 1 || ModifyIndex > Count)
			ModifyIndex = -1;

		// 1번부터 번호가 시작하고 있다. 이를 인덱스로 만들기 위해 1을 빼주어서
		// 0부터 시작되는 인덱스로 만들어준다.
		--ModifyIndex;
		break;
	}

	// ModifyIndex가 -1이라면 잘못된 인덱스이다.
	if (ModifyIndex != -1)
	{
		SetItemData(Array, ModifyIndex);
	}

	system("pause");
}

void OutputItemList(Item* Array, int Count)
{
	system("cls");
	for (int i = 0; i < Count; ++i)
	{
		std::cout << "이름 : " << Array[i].Name << "\t종류 : ";

		switch (Array[i].Type)
		{
		case EItemType::Weapon:
			std::cout << "무기\n";
			break;
		case EItemType::Armor:
			std::cout << "방어구\n";
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
