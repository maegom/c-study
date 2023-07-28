#pragma once

#include <iostream>

enum class EItemType
{
	Weapon,
	Armor
};

enum EItemEquip
{
	Equip_Weapon,
	Equip_Armor,
	Equip_End
};

struct Item
{
	char	Name[32];
	EItemType	Type;
	int		Price;
	int		Sell;
};

#define	ITEMARRAY_MAXCOUNT	10

struct ItemArray
{
	Item*	ItemList[ITEMARRAY_MAXCOUNT];
	int		Count;
};

struct Player
{
	char	Name[32];
	int		Attack;
	int		Armor;
	int		HP;
	int		HPMax;
	int		MP;
	int		MPMax;
	int		Level;
	int		Exp;
	int		Money;
	Item*	EquipItem[Equip_End];
};

int OutputItemList(const ItemArray* Array);
