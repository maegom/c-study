#include "Inventory.h"

bool InventoryInit(ItemArray* Inventory)
{
    FILE* FileStream = nullptr;

    fopen_s(&FileStream, "Inventory.inv", "rb");

    if (!FileStream)
        return true;

    fclose(FileStream);

    return true;
}

void InventoryRun(ItemArray* Inventory, Player* player)
{
    while (true)
    {
        int Input = OutputItemList(Inventory);

        if (Input == -1)
            continue;

        else if (Input == Inventory->Count + 1)
            break;

        int ItemIndex = Input - 1;

        EItemEquip  equip;

        switch (Inventory->ItemList[ItemIndex]->Type)
        {
        case EItemType::Weapon:
            equip = Equip_Weapon;
            break;
        case EItemType::Armor:
            equip = Equip_Armor;
            break;
        }

        // ���������� ������ �����ϰ� �ִ� �������� ���� ��� �κ��丮 �����۰� ���� ��ġ��
        // �ٲ��ְ� ���� �����ϴ� �������� �κ��丮�� �Ѱ��ش�.
        if (player->EquipItem[equip])
        {
            Item* Temp = player->EquipItem[equip];
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex];
            Inventory->ItemList[ItemIndex] = Temp;
        }

        else
        {
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex];

            //  �κ��丮 �������� �����Ǿ����Ƿ� �� ������ ĭ�� ����ش�.
            memmove(&Inventory->ItemList[ItemIndex], &Inventory->ItemList[ItemIndex + 1],
                sizeof(Item*) * (Inventory->Count - ItemIndex - 1));
            --Inventory->Count;
        }
    }
}
