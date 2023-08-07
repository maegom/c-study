#include "Player.h"
#include "Item.h"

CPlayer::CPlayer()  :
    mJob(EJob::None),
    mEquipItem{}
{
}

CPlayer::~CPlayer()
{
    // ������ �������� ���� ��� �������� �޸𸮿��� �����Ѵ�.
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

// ������ true�� ��� ����, false�� ��� ���� �����̴�.
// 2��° ���ڴ� �����������̴�. �� ������ ������ �޸� �ּҸ� ��� �ִ�.
// �̸� �������ϰ� �Ǹ� ������ ������ �ȴ�. �׷��� �� ������ ������ �����ϰ� �ִ�
// �������� �޸� �ּҸ� �Ѱ��ش�.
bool CPlayer::Equip(CItem* ChangeItem, CItem** EquipItem)
{
    EEquipType Type = ChangeItem->GetEquipType();

    if (Type == Equip_None)
        return false;

    // ������ �����ϰ� �ִ� �������� �ּҸ� ���ڷ� �Ѿ�� ������ ������
    // �������ش�.
    *EquipItem = mEquipItem[Type];

    // �������� ��ü�Ѵ�.
    mEquipItem[Type] = ChangeItem;


    return true;
}

bool CPlayer::Init()
{
    std::cout << "�̸� : ";
    std::cin >> mName;

    while (true)
    {
        system("cls");
        std::cout << "1. ���" << std::endl;
        std::cout << "2. �ü�" << std::endl;
        std::cout << "3. ������" << std::endl;
        std::cout << "������ �����ϼ��� : ";
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
    std::cout << "�̸� : " << mName << "\t���� : ";

    switch (mJob)
    {
    case EJob::Knight:
        std::cout << "���" << std::endl;
        break;
    case EJob::Archer:
        std::cout << "�ü�" << std::endl;
        break;
    case EJob::Magicion:
        std::cout << "������" << std::endl;
        break;
    }

    std::cout << "���� : " << mLevel << "\t����ġ : " << mExp << std::endl;
    std::cout << "���ݷ� : " << mAttack;
    
    // �������Ⱑ ���� ��� ������ ���ݷµ� �Բ� ǥ�����ش�.
    if (nullptr != mEquipItem[Equip_Weapon])
        std::cout << " + " << mEquipItem[Equip_Weapon]->GetOption();
    
    std::cout << "\t���� : " << mArmor;

    if (nullptr != mEquipItem[Equip_Armor])
        std::cout << " + " << mEquipItem[Equip_Armor]->GetOption();

    std::cout << std::endl;

    std::cout << "ü�� : " << mHP << " / " << mHPMax << "\t���� : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "�����ݾ� : " << mMoney << std::endl;
    std::cout << "�������� : ";

    if (nullptr != mEquipItem[Equip_Weapon])
    {
        std::cout << mEquipItem[Equip_Weapon]->GetName();
    }

    else
        std::cout << "����";

    std::cout << "\t������ : ";

    if (nullptr != mEquipItem[Equip_Armor])
    {
        std::cout << mEquipItem[Equip_Armor]->GetName();
    }

    else
        std::cout << "����";

    std::cout << std::endl;
}
