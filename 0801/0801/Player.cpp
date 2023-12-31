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
