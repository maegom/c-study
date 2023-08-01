#include "Monster.h"

CMonster::CMonster() :
    mName{},
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

CMonster::~CMonster()
{
}

bool CMonster::Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
	int Exp, int Money)
{
    // ������ ������ ���ڿ��� ���� ���ڿ� �������ش�.
    strcpy_s(mName, Name);
    mAttack = Attack;
    mArmor = Armor;
    mHP = HP;
    mHPMax = HP;
    mMP = MP;
    mMPMax = MP;
    mLevel = Level;
    mExp = Exp;
    mMoney = Money;

    return true;
}
