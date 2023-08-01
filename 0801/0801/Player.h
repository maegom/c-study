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

public:
	bool Init();
};

