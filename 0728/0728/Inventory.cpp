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

        // 장착부위에 기존에 장착하고 있던 아이템이 있을 경우 인벤토리 아이템과 서로 위치를
        // 바꿔주고 기존 장착하던 아이템은 인벤토리에 넘겨준다.
        if (player->EquipItem[equip])
        {
            Item* Temp = player->EquipItem[equip];
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex];
            Inventory->ItemList[ItemIndex] = Temp;
        }

        else
        {
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex];

            //  인벤토리 아이템은 장착되었으므로 그 장착된 칸을 비워준다.
            memmove(&Inventory->ItemList[ItemIndex], &Inventory->ItemList[ItemIndex + 1],
                sizeof(Item*) * (Inventory->Count - ItemIndex - 1));
            --Inventory->Count;
        }
    }
}
