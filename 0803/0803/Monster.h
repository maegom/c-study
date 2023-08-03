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
	int GetAttack()
	{
		return mAttack;
	}

	int GetArmor()
	{
		return mArmor;
	}

	int GetMoney()
	{
		return mMoney;
	}

	int GetExp()
	{
		return mExp;
	}

	bool Damage(int Dmg)
	{
		mHP -= Dmg;

		// ü���� 0���� �۰ų� ���� ���(�׾��� ���) true, �ƴϸ�  false�� �����Ѵ�.
		return mHP <= 0;
	}

public:
	// "aaa" �̷� ���ڿ��� ���޹��� ��� const char* Ÿ���� ����Ѵ�.
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money);
	void Output();
};

