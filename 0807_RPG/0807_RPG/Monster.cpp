#include "Monster.h"

CMonster::CMonster()
{
}

CMonster::~CMonster()
{
}

bool CMonster::Init()
{
    return true;
}

void CMonster::Output()
{
    std::cout << "�̸� : " << mName << "\t���� : " << mLevel << std::endl;
    std::cout << "���ݷ� : " << mAttack << "\t���� : " << mArmor << std::endl;
    std::cout << "ü�� : " << mHP << " / " << mHPMax << "\t���� : " << mMP << " / " <<
        mMPMax << std::endl;
    std::cout << "ȹ��ݾ� : " << mMoney << "\tȹ�����ġ : " << mExp << std::endl;
}
