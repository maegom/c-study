#pragma once

#include "Character.h"

enum class EJob
{
	None,
	Knight,
	Archer,
	Magicion,
	End
};

class CPlayer	:
	public CCharacter
{
public:
	CPlayer();
	~CPlayer();

private:
	EJob	mJob;
	class CItem* mEquipItem[Equip_End];

public:
	int GetAttack()	override;
	int GetArmor()	override;

	bool Equip(class CItem* ChangeItem,
		class CItem** EquipItem);

public:
	bool Init()	override;
	void Output()	override;
};

