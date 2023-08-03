#pragma once

#include "Info.h"

enum class EJob
{
	None,
	Knight,
	Archer,
	Magicion,
	End
};

class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	char	mName[32];
	EJob	mJob;
	int		mAttack;
	int		mArmor;
	int		mHP;
	int		mHPMax;
	int		mMP;
	int		mMPMax;
	int		mLevel;
	int		mExp;
	int		mMoney;
	class CItem* mEquipItem[Equip_End];

public:
	int GetAttack();
	int GetArmor();

	int GetMoney()
	{
		return mMoney;
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

	bool Equip(class CItem* ChangeItem,
		class CItem** EquipItem);

public:
	bool Init();
	void Output();
};

