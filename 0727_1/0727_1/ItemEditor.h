#pragma once

#include "Info.h"

void SetItemData(Item* Array, int Index);
void CreateItem(Item* Array, int& Count);
void DeleteItem(Item* Array, int& Count);
void ModifyItem(Item* Array, int Count);
void OutputItemList(Item* Array, int Count);
void SaveItemList(Item* Array, int Count);
void LoadItemList(Item* Array, int& Count);
