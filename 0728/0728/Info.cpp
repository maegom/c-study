#include "Info.h"

int OutputItemList(const ItemArray* Array)
{
	system("cls");
	for (int i = 0; i < Array->Count; ++i)
	{
		std::cout << i + 1 << ". �̸� : " << Array->ItemList[i]->Name << "\t���� : ";

		switch (Array->ItemList[i]->Type)
		{
		case EItemType::Weapon:
			std::cout << "����\n";
			break;
		case EItemType::Armor:
			std::cout << "��\n";
			break;
		}

		std::cout << "Price : " << Array->ItemList[i]->Price << "\tSell : "
			<< Array->ItemList[i]->Sell << std::endl;
	}

	std::cout << Array->Count + 1 << ". �ڷΰ���" << std::endl;
	std::cout << "�������� �����ϼ��� : ";
	int	Input;
	std::cin >> Input;

	if (Input < 1 || Input > Array->Count + 1)
		return -1;

	return Input;
}
