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
	// "aaa" 이런 문자열을 전달받을 경우 const char* 타입을 사용한다.
	bool Init(const char* Name, int Attack, int Armor, int HP, int MP, int Level,
		int Exp, int Money);
};

