#include "Player.h"
#include "Item.h"

CPlayer::CPlayer()  :
    mJob(EJob::None),
    mEquipItem{}
{
}

CPlayer::~CPlayer()
{
    // 장착한 아이템이 있을 경우 아이템을 메모리에서 제거한다.
    for (int i = 0; i < Equip_End; ++i)
    {
        if (nullptr != mEquipItem[i])
            delete mEquipItem[i];
    }
}

int CPlayer::GetAttack()
{
    int Attack = mAttack;

    if (nullptr != mEquipItem[Equip_Weapon])
        Attack += mEquipItem[Equip_Weapon]->GetOption();

    return Attack;
}

int CPlayer::GetArmor()
{
    int Armor = mArmor;

    if (nullptr != mEquipItem[Equip_Armor])
        Armor += mEquipItem[Equip_Armor]->GetOption();

    return Armor;
}

// 리턴이 true일 경우 장착, false일 경우 장착 실패이다.
// 2번째 인자는 이중포인터이다. 즉 포인터 변수의 메모리 주소를 담고 있다.
// 이를 역참조하게 되면 포인터 변수가 된다. 그래서 그 포인터 변수에 장착하고 있던
// 아이템의 메모리 주소를 넘겨준다.
bool CPlayer::Equip(CItem* ChangeItem, CItem** EquipItem)
{
    EEquipType Type = ChangeItem->GetEquipType();

    if (Type == Equip_None)
        return false;

    // 기존에 장착하고 있던 아이템의 주소를 인자로 넘어온 포인터 변수에
    // 대입해준다.
    *EquipItem = mEquipItem[Type];

    // 아이템을 교체한다.
    mEquipItem[Type] = ChangeItem;


    return true;
}

bool CPlayer::Init()
{
    std::cout << "이름 : ";
    std::cin >> mName;

    while (true)
    {
        system("cls");
        std::cout << "1. 기사" << std::endl;
        std::cout << "2. 궁수" << std::endl;
        std::cout << "3. 마법사" << std::endl;
        std::cout << "직업을 선택하세요 : ";
        int Job;

        std::cin >> Job;

        if (Job > (int)EJob::None && Job < (int)EJob::End)
        {
            mJob = (EJob)Job;
            break;
        }
    }

    switch (mJob)
    {
    case EJob::Knight:
        mAttack = 30;
        mArmor = 20;
        mHP = 500;
        mHPMax = 500;
        mMP = 100;
        mMPMax = 100;
        break;
    case EJob::Archer:
        mAttack = 40;
        mArmor = 15;
        mHP = 400;
        mHPMax = 400;
        mMP = 200;
        mMPMax = 200;
        break;
    case EJob::Magicion:
        mAttack = 50;
        mArmor = 10;
        mHP = 300;
        mHPMax = 300;
        mMP = 300;
        mMPMax = 300;
        break;
    }

    mLevel = 1;
    mExp = 0;
    mMoney = 10000;

    return true;
}

void CPlayer::Output()
{
    std::cout << "이름 : " << mName << "\t직업 : ";

    switch (mJob)
    {
    case EJob::Knight:
        std::cout << "기사" << std::endl;
        break;
    case EJob::Archer:
        std::cout << "궁수" << std::endl;
        break;
    case EJob::Magicion:
        std::cout << "마법사" << std::endl;
        break;
    }

    std::cout << "레벨 : " << mLevel << "\t경험치 : " << mExp << std::endl;
    std::cout << "공격력 : " << mAttack;
    
    // 장착무기가 있을 경우 무기의 공격력도 함께 표시해준다.
    if (nullptr != mEquipItem[Equip_Weapon])
        std::cout << " + " << mEquipItem[Equip_Weapon]->GetOption();
    
    std::cout << "\t방어력 : " << mArmor;

    if (nullptr != mEquipItem[Equip_Armor])
        std::cout << " + " << mEquipItem[Equip_Armor]->GetOption();

    std::cout << std::endl;

    std::cout << "체력 : " << mHP << " / " << mHPMax << "\t마나 : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "보유금액 : " << mMoney << std::endl;
    std::cout << "장착무기 : ";

    if (nullptr != mEquipItem[Equip_Weapon])
    {
        std::cout << mEquipItem[Equip_Weapon]->GetName();
    }

    else
        std::cout << "없음";

    std::cout << "\t장착방어구 : ";

    if (nullptr != mEquipItem[Equip_Armor])
    {
        std::cout << mEquipItem[Equip_Armor]->GetName();
    }

    else
        std::cout << "없음";

    std::cout << std::endl;
}
