
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
		std::cout << "1. 아이템 생성" << std::endl;
		std::cout << "2. 아이템 제거" << std::endl;
		std::cout << "3. 아이템 수정" << std::endl;
		std::cout << "4. 아이템 목록 출력" << std::endl;
		std::cout << "5. 아이템 목록파일 저장" << std::endl;
		std::cout << "6. 아이템 목록파일 불러오기" << std::endl;
		std::cout << "7. 종료" << std::endl;
		std::cout << "메뉴를 선택하세요 : ";
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