#pragma once

#include "Character.h"

class CMonster	:
	public CCharacter
{
public:
	CMonster();
	~CMonster();

public:
	// "aaa" �̷� ���ڿ��� ���޹��� ��� const char* Ÿ���� ����Ѵ�.
	bool Init()	override;
	void Output()	override;
};

