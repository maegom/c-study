#include "Inventory.h"

//�κ��丮 �ʱ�ȭ
bool InventoryInit(ItemArray* Inventory)
{
    //���� ���� ���� �ʱ�ȭ
    FILE* FileStream = nullptr;

    //���̳ʸ� ���� �б�
    fopen_s(&FileStream, "Inventory.inv", "rb");

    if (!FileStream)
        return true;

    //�ݱ�
    fclose(FileStream);

    return true;
}

//�κ��丮 ����
void InventoryRun(ItemArray* Inventory, Player* player)
{
    while (true)
    {
        // �Է°� (��� ��ȣ �Ǵ� �ڷΰ���) �޾� ���� 
        int Input = OutputItemList(Inventory);

        //����ó�� ���Է� 
        if (Input == -1)
            continue;

        //�ڷΰ���
        else if (Input == Inventory->Count + 1)
            break;

        //��� ��ȣ�� 1�����̹Ƿ� -1
        int ItemIndex = Input - 1;

        //���� ��� 
        EItemEquip  equip;

        //�κ��丮 ������ ����� Ÿ�Կ� ���� ����
        switch (Inventory->ItemList[ItemIndex]->Type)
        {
            // ����
        case EItemType::Weapon:
            equip = Equip_Weapon;
            break;
            // ��
        case EItemType::Armor:
            equip = Equip_Armor;
            break;
        }

        // ���������� ������ �����ϰ� �ִ� �������� ���� ��� �κ��丮 �����۰� ���� ��ġ�� �ٲ��ְ�
        // ���� �����ϴ� �������� �κ��丮�� �Ѱ��ش�.
        if (player->EquipItem[equip])  //�̹� ������ ��� �ִٸ�
        {
            //���� �˰���
            Item* Temp = player->EquipItem[equip];
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex];
            Inventory->ItemList[ItemIndex] = Temp;
        }

        else //�̹� ������ ��� ���ٸ�
        {
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex]; //�־��ְ�

            //  �κ��丮 �������� �����Ǿ����Ƿ� ����־��� �κ��丮ĭ�� ����ش�.
            //memmove(�Ű��� �޸� ����Ű�� ������,�ű� �޸� ������,������ ������ ����)
            memmove(&Inventory->ItemList[ItemIndex], &Inventory->ItemList[ItemIndex + 1],
                sizeof(Item*) * (Inventory->Count - ItemIndex - 1));
            --Inventory->Count;
        }
    }
}
