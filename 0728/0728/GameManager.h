#pragma once

#include "Info.h"

enum class EMainMenu
{
	None,
	Battle,
	Store,
	Inventory,
	Exit
};

bool GameInit(ItemArray* store, ItemArray* Inventory, Player* player);
void Run(ItemArray* store, ItemArray* Inventory, Player* player);
void Destroy(ItemArray* store, ItemArray* Inventory, Player* player);
