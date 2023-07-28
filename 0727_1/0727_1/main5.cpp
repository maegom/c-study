
#include "ItemEditor.h"

enum class EMainMenu
{
	None,
	CreateItem,
	DeleteItem,
	ModifyItem,
	OutputItem,
	SaveItem,
	LoadItem,
	Exit
};

int main()
{
	Item	item[100] = {};
	int		Count = 0;

	while (true)
	{
		system("cls");
		std::cout << "1. ������ ����" << std::endl;
		std::cout << "2. ������ ����" << std::endl;
		std::cout << "3. ������ ����" << std::endl;
		std::cout << "4. ������ ��� ���" << std::endl;
		std::cout << "5. ������ ������� ����" << std::endl;
		std::cout << "6. ������ ������� �ҷ�����" << std::endl;
		std::cout << "7. ����" << std::endl;
		std::cout << "�޴��� �����ϼ��� : ";
		int	Input;
		std::cin >> Input;

		if (Input == (int)EMainMenu::Exit)
			break;

		else if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
			continue;

		switch ((EMainMenu)Input)
		{
		case EMainMenu::CreateItem:
			CreateItem(item, Count);
			break;
		case EMainMenu::DeleteItem:
			DeleteItem(item, Count);
			break;
		case EMainMenu::ModifyItem:
			ModifyItem(item, Count);
			break;
		case EMainMenu::OutputItem:
			OutputItemList(item, Count);
			break;
		case EMainMenu::SaveItem:
			SaveItemList(item, Count);
			break;
		case EMainMenu::LoadItem:
			LoadItemList(item, Count);
			break;
		case EMainMenu::Exit:
			break;
		}
	}

	return 0;
}