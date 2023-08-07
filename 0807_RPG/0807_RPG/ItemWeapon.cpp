#include "ItemWeapon.h"

CItemWeapon::CItemWeapon()
{
	mType = EItemType::Weapon;
}

CItemWeapon::CItemWeapon(const CItemWeapon& ref)	:
	CItem(ref)
{
	mType = EItemType::Weapon;
}

CItemWeapon::~CItemWeapon()
{
}

bool CItemWeapon::Init()
{
    return true;
}

void CItemWeapon::Output()
{
	std::cout << "�̸� : " << mName << "\t���� : ����" << std::endl;
	std::cout << "���ݷ� : " << mOption << std::endl;

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
