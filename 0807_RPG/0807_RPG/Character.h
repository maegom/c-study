#pragma once

#include "Info.h"

class CCharacter
{
public:
	CCharacter();
	virtual ~CCharacter();

protected:
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
	void SetInfo(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money)
	{
		// 오른쪽 인자의 문자열을 왼쪽 인자에 복사해준다.
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
	}

public:
	virtual int GetAttack()
	{
		return mAttack;
	}

	virtual int GetArmor()
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

	void AddExp(int Exp)
	{
		mExp += Exp;
	}

	void AddMoney(int Money)
	{
		mMoney += Money;
	}

	void SetAttack(int Attack)
	{
		mAttack = Attack;
	}

	void Resurrection()
	{
		mExp = (int)(mExp * 0.9f);
		mMoney = (int)(mMoney * 0.9f);

		mHP = mHPMax;
		mMP = mMPMax;
	}

public:
	virtual bool Init();
	virtual void Output();
};

