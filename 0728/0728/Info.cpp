#include "Info.h"

int OutputItemList(const ItemArray* Array)
{
	system("cls");
	for (int i = 0; i < Array->Count; ++i)
	{
		std::cout << i + 1 << ". 이름 : " << Array->ItemList[i]->Name << "\t종류 : ";

		switch (Array->ItemList[i]->Type)
		{
		case EItemType::Weapon:
			std::cout << "무기\n";
			break;
		case EItemType::Armor:
			std::cout << "방어구\n";
			break;
		}

		std::cout << "Price : " << Array->ItemList[i]->Price << "\tSell : "
			<< Array->ItemList[i]->Sell << std::endl;
	}

	std::cout << Array->Count + 1 << ". 뒤로가기" << std::endl;
	std::cout << "아이템을 선택하세요 : ";
	int	Input;
	std::cin >> Input;

	if (Input < 1 || Input > Array->Count + 1)
		return -1;

	return Input;
}
