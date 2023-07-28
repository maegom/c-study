#pragma once

#include "Info.h"

//상점 초기화
bool StoreInit(ItemArray* store);
//상점 실행
void StoreRun(ItemArray* store, ItemArray* Inventory, Player* player);
