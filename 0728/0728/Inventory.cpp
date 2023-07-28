#include "Inventory.h"

//인벤토리 초기화
bool InventoryInit(ItemArray* Inventory)
{
    //파일 받을 공간 초기화
    FILE* FileStream = nullptr;

    //바이너리 파일 읽기
    fopen_s(&FileStream, "Inventory.inv", "rb");

    if (!FileStream)
        return true;

    //닫기
    fclose(FileStream);

    return true;
}

//인벤토리 실행
void InventoryRun(ItemArray* Inventory, Player* player)
{
    while (true)
    {
        // 입력값 (장비 번호 또는 뒤로가기) 받아 수행 
        int Input = OutputItemList(Inventory);

        //예외처리 재입력 
        if (Input == -1)
            continue;

        //뒤로가기
        else if (Input == Inventory->Count + 1)
            break;

        //장비 번호는 1부터이므로 -1
        int ItemIndex = Input - 1;

        //장착 장비 
        EItemEquip  equip;

        //인벤토리 선택한 장비의 타입에 따른 구분
        switch (Inventory->ItemList[ItemIndex]->Type)
        {
            // 무기
        case EItemType::Weapon:
            equip = Equip_Weapon;
            break;
            // 방어구
        case EItemType::Armor:
            equip = Equip_Armor;
            break;
        }

        // 장착부위에 기존에 장착하고 있던 아이템이 있을 경우 인벤토리 아이템과 서로 위치를 바꿔주고
        // 기존 장착하던 아이템은 인벤토리에 넘겨준다.
        if (player->EquipItem[equip])  //이미 장착된 장비가 있다면
        {
            //스왑 알고리즘
            Item* Temp = player->EquipItem[equip];
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex];
            Inventory->ItemList[ItemIndex] = Temp;
        }

        else //이미 장착된 장비가 없다면
        {
            player->EquipItem[equip] = Inventory->ItemList[ItemIndex]; //넣어주고

            //  인벤토리 아이템은 장착되었으므로 들어있었던 인벤토리칸을 비워준다.
            //memmove(옮겨질 메모리 가리키는 포인터,옮길 메모리 포인터,복사할 데이터 길이)
            memmove(&Inventory->ItemList[ItemIndex], &Inventory->ItemList[ItemIndex + 1],
                sizeof(Item*) * (Inventory->Count - ItemIndex - 1));
            --Inventory->Count;
        }
    }
}
