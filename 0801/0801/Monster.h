#pragma once

#include "Info.h"

class CMonster
{
public:
	CMonster();
	~CMonster();

private:
	char	mName[32];
	int		mAttack;
	int		mArmor;
	int		mHP;
	int		mHPMax;
	int		mMP;
	int		mMPMax;
	int		mLevel;
	int		mExp;
	int		mMoney;

public:
	// "aaa" �̷� ���ڿ��� ���޹��� ��� const char* Ÿ���� ����Ѵ�.
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money);
};

