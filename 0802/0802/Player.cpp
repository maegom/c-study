#include "Player.h"

CPlayer::CPlayer()  :
    mName{},
    mJob(EJob::None),
    mAttack(0),
    mArmor(0),
    mHP(0),
    mHPMax(0),
    mMP(0),
    mMPMax(0),
    mLevel(0),
    mExp(0),
    mMoney(0)
{
}

CPlayer::~CPlayer()
{
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
    std::cout << "���ݷ� : " << mAttack << "\t���� : " << mArmor << std::endl;
    std::cout << "ü�� : " << mHP << " / " << mHPMax << "\t���� : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "�����ݾ� : " << mMoney << std::endl;
}
