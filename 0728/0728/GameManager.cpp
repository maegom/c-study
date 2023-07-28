#include "GameManager.h"
#include "Store.h"
#include "Inventory.h"

//게임 초기화 구현
bool GameInit(ItemArray* store, ItemArray* Inventory, Player* player)
{
	// 상점 초기화
	if (!StoreInit(store))
		return false;

	// 가방 초기화
	if (!InventoryInit(Inventory))
		return false;

	// 플레이어 초기화
	player->Money = 100000000;

    return true;
}

//메뉴 
EMainMenu Menu()
{
	system("cls");
	std::cout << "1. 전투" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 가방" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";

	//입력과 예외처리
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

//동작
void Run(ItemArray* store, ItemArray* Inventory, Player* player)
{
	while (true)
	{ 
		switch (Menu())
		{
		case EMainMenu::Battle:
			break;
		case EMainMenu::Store:  //상점
			StoreRun(store, Inventory, player);
			break;
		case EMainMenu::Inventory://인벤토리
			InventoryRun(Inventory, player);
			break;
		case EMainMenu::Exit: //종료
			return;
		}
	}
}

//동적할당 제거
void Destroy(ItemArray* store, ItemArray* Inventory, Player* player)
{
	for (int i = 0; i < store->Count; ++i)
	{
		delete store->ItemList[i];
	}

	for (int i = 0; i < Inventory->Count; ++i)
	{
		delete Inventory->ItemList[i];
	}

	for (int i = 0; i < Equip_End; ++i)
	{
		if (player->EquipItem[i])
			delete player->EquipItem[i];
	}
}
