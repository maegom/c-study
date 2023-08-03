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

		// 체력이 0보다 작거나 같을 경우(죽었을 경우) true, 아니면  false를 리턴한다.
		return mHP <= 0;
	}

public:
	// "aaa" 이런 문자열을 전달받을 경우 const char* 타입을 사용한다.
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money);
	void Output();
};

