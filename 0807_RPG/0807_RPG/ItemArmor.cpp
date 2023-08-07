#include "ItemArmor.h"

CItemArmor::CItemArmor()
{
	mType = EItemType::Armor;
}

CItemArmor::CItemArmor(const CItemArmor& ref) :
	CItem(ref)
{
	mType = EItemType::Armor;
}

CItemArmor::~CItemArmor()
{
}

bool CItemArmor::Init()
{
	return true;
}

void CItemArmor::Output()
{
	//CItem::Output();
	std::cout << "�̸� : " << mName << "\t���� : ��" << std::endl;
	std::cout << "���� : " << mOption << std::endl;

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
