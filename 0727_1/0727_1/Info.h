#pragma once

#include <iostream>

enum class EItemType
{
	Weapon,
	Armor
};

struct Item
{
	char	Name[32];
	EItemType	Type;
	int		Price;
	int		Sell;
};
