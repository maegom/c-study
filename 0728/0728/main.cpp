
#include "GameManager.h"

int main()
{
	//����, ����, �÷��̾� ���� �ʱ�ȭ
	ItemArray	store = {};
	ItemArray	Inventory = {};
	Player	player = {};

	//���� �ʱ�ȭ
	if (!GameInit(&store, &Inventory, &player))
		return 0;

	//����
	Run(&store, &Inventory, &player);

	//�����Ҵ� ����
	Destroy(&store, &Inventory, &player);

	return 0;
}
