#pragma once

#include "Info.h"

enum class EItemType
{
	Weapon,
	Armor
};

class CItem
{
public:
	CItem();
	/* 
	const Ŭ����& Ÿ���� ���ڸ� �޴� �����ڸ� ��������ڶ�� �Ѵ�.
	��������ڴ� Ŭ������ �̿��ؼ� ��ü�� �����Ҷ� �ٸ� ��ü�� ���ڷ� �޾ƿͼ�
	�� ��ü�� �����͸� �״�� ������ ���ο� ��ü�� ���� �� ����Ѵ�.
	��������ڴ� �������� 2������ �ִ�.
	�������� : ��� �����͸� �״�� �����ϴ� ����� ���Ѵ�.
	������ ������ ������ �ְ� �ش� ������ ������ �����Ҵ�� �޸� �ּҸ� ������ ���� ���
	�ܼ��ϰ� �� �ּҸ� �����ع����� ������ ������ ���纻�� ��� ���� �ּҸ� �����ϰԵȴ�.
	�� ��� �Ѱ����� �޸𸮸� �����ع����� �Ǹ� �ٸ����� ��۸� �����Ͱ� �Ǿ� ������
	�߻��� �� �ְ� �ȴ�. �̸� �ذ��� �� �ִ� ����� ���������̴�.

	�������� : �����Ҵ�� �޸� �ּҸ� ��������� ������ ���� ��� �ش� ������ ũ�⸸ŭ
	�������� ������ ������� �Ŀ� �ش� ������ ������ �״�� �����ϴ� ����̴�.
	�Ϲ� ������ ��������� ���� �����Ѵ�.
	*/
	CItem(const CItem& ref);
	~CItem();

private:
	char		mName[32];
	EItemType	mType;
	EEquipType	mEquipType;
	int			mOption;
	int			mPrice;
	int			mSell;

public:
	const char* GetName()
	{
		return mName;
	}

	int GetOption()
	{
		return mOption;
	}

	EEquipType GetEquipType()
	{
		return mEquipType;
	}

	int GetPrice()
	{
		return mPrice;
	}

public:
	bool Init(const char* Name, EItemType Type, int Price, int Sell,
		EEquipType EquipType = Equip_None);
	bool Init(FILE* FileStream);
	void Output();
};

