#pragma once

#include "Info.h"

//메뉴
enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

//초기화, 동작, 파괴 함수 선언
bool GameInit(ItemArray* store, ItemArray* Inventory, Player* player);
void Run(ItemArray* store, ItemArray* Inventory, Player* player);
void Destroy(ItemArray* store, ItemArray* Inventory, Player* player);
