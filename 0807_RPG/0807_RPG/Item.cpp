#include "Item.h"

CItem::CItem()  :
    mType(EItemType::Weapon),
    mPrice(0),
    mSell(0),
	mOption(0)

{
}

CItem::CItem(const CItem& ref)
{
	// this�� ���� ������ ������ ��ü�� �ּ��̴�.
	// *this �� �ϰ� �Ǹ� ���� ������ ��ü�� �ȴ�.
	// �̷��� ���ָ� ��� ������ �״�� �����ϰ� �ȴ�.
	// �������簡 �Ͼ��.
	*this = ref;
}

CItem::~CItem()
{
}

bool CItem::Init(const char* Name, EItemType Type, int Price, int Sell,
	EEquipType EquipType)
{
    return true;
}

bool CItem::Init(FILE* FileStream)
{
    fread(mName, sizeof(char), 32, FileStream);

	fread(&mEquipType, sizeof(EEquipType), 1, FileStream);
	fread(&mOption, sizeof(int), 1, FileStream);

    fread(&mPrice, sizeof(int), 1, FileStream);
    fread(&mSell, sizeof(int), 1, FileStream);

    return true;
}

bool CItem::Init()
{
	return true;
}

void CItem::Output()
{
	std::cout << "�̸� : " << mName << "\t���� : ";

	switch (mType)
	{
	case EItemType::Weapon:
		std::cout << "����\n";
		std::cout << "���ݷ� : ";
		break;
	case EItemType::Armor:
		std::cout << "��\n";
		std::cout << "���� : ";
		break;
	}

	std::cout << mOption << std::endl;

	std::cout << "Price : " << mPrice << "\tSell : "
		<< mSell << std::endl;
}
