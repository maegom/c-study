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
	const 클래스& 타입의 인자를 받는 생성자를 복사생성자라고 한다.
	복사생성자는 클래스를 이용해서 객체를 생성할때 다른 객체를 인자로 받아와서
	그 객체의 데이터를 그대로 복사한 새로운 객체를 만들어낼 때 사용한다.
	복사생성자는 복사방법이 2가지가 있다.
	얕은복사 : 모든 데이터를 그대로 복사하는 방식을 말한다.
	포인터 변수를 가지고 있고 해당 포인터 변수가 동적할당된 메모리 주소를 가지고 있을 경우
	단순하게 그 주소를 복사해버리기 때문에 원본과 복사본이 모두 같은 주소를 참조하게된다.
	이 경우 한곳에서 메모리를 제거해버리게 되면 다른곳은 댕글링 포인터가 되어 에러가
	발생할 수 있게 된다. 이를 해결할 수 있는 방법이 깊은복사이다.

	깊은복사 : 동적할당된 메모리 주소를 멤버변수로 가지고 있을 경우 해당 공간의 크기만큼
	복제본도 공간을 만들어준 후에 해당 공간의 값들을 그대로 복사하는 방식이다.
	일반 값들은 얕은복사와 같이 복사한다.
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

