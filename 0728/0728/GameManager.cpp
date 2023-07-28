#include "GameManager.h"
#include "Store.h"
#include "Inventory.h"

bool GameInit(ItemArray* store, ItemArray* Inventory, Player* player)
{
	// ���� �ʱ�ȭ
	if (!StoreInit(store))
		return false;

	// ���� �ʱ�ȭ
	if (!InventoryInit(Inventory))
		return false;

	// �÷��̾� �ʱ�ȭ
	player->Money = 100000000;

    return true;
}

EMainMenu Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ����" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

void Run(ItemArray* store, ItemArray* Inventory, Player* player)
{
	while (true)
	{
		switch (Menu())
		{
		case EMainMenu::Battle:
			break;
		case EMainMenu::Store:
			StoreRun(store, Inventory, player);
			break;
		case EMainMenu::Inventory:
			InventoryRun(Inventory, player);
			break;
		case EMainMenu::Exit:
			return;
		}
	}
}

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
