
#include "GameManager.h"

int main()
{
	//상점, 가방, 플레이어 공간 초기화
	ItemArray	store = {};
	ItemArray	Inventory = {};
	Player	player = {};

	//게임 초기화
	if (!GameInit(&store, &Inventory, &player))
		return 0;

	//동작
	Run(&store, &Inventory, &player);

	//동적할당 제거
	Destroy(&store, &Inventory, &player);

	return 0;
}
