#include "Store.h"

bool StoreInit(ItemArray* store)
{
	FILE* FileStream = nullptr;

	fopen_s(&FileStream, "ItemList.itl", "rb");

	if (!FileStream)
		return false;

	// (*store).
	// store->
	// ���� 2���� ���ٹ���� ���� ���ٹ���̴�.
	fread(&store->Count, sizeof(int), 1, FileStream);

	for (int i = 0; i < store->Count; ++i)
	{
		Item	item = {};
		fread(&item, sizeof(Item), 1, FileStream);

		// ���� ����� �������� �����Ҵ����� �����Ѵ�.
		Item* StoreItem = new Item;

		// ������ ���Ϸκ��� �о�� ������ ���� ����� �������� �޸𸮿� �������ش�.
		memcpy(StoreItem, &item, sizeof(Item));

		store->ItemList[i] = StoreItem;
	}
	//fread(store->ItemList, sizeof(Item), store->Count, FileStream);

	fclose(FileStream);

    return true;
}

void StoreRun(ItemArray* store, ItemArray* Inventory, Player* player)
{
	while (true)
	{
		int Input = OutputItemList(store);

		if (Input == -1)
			continue;

		else if (Input == store->Count + 1)
			break;

		int	ItemIndex = Input - 1;

		// �κ��丮�� ĭ�� ������ ��� �߰��� �� ����.
		if (Inventory->Count == ITEMARRAY_MAXCOUNT)
		{
			std::cout << "������ ������ �����մϴ�." << std::endl;
			system("pause");
			continue;
		}

		// ������ �ִ� ������ ������ �Ǵ��Ѵ�.
		else if (player->Money < store->ItemList[ItemIndex]->Price)
		{
			std::cout << "�������� �����մϴ�." << std::endl;
			system("pause");
			continue;
		}

		// �κ��丮�� �������� �߰����ش�.
		Item* InvenItem = new Item;

		int Size = sizeof(Item);

		memcpy(InvenItem, store->ItemList[ItemIndex], sizeof(Item));

		Inventory->ItemList[Inventory->Count] = InvenItem;
		++Inventory->Count;

		player->Money -= InvenItem->Price;
	}
}
