#include "StoreManager.h"
#include "Store.h"

CStoreManager* CStoreManager::mInst = nullptr;

CStoreManager::CStoreManager()	:
	mStore{}
{
}

CStoreManager::~CStoreManager()
{
}

EStoreMenu CStoreManager::Menu()
{
	system("cls");
	std::cout << "1. 무기" << std::endl;
	std::cout << "2. 방어구" << std::endl;
	std::cout << "3. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EStoreMenu::None ||
		Input > (int)EStoreMenu::Back)
		return EStoreMenu::None;

	return (EStoreMenu)Input;
}

bool CStoreManager::Init()
{
	const char* FileNameArray[2] = { "ItemList.itl" , "ItemList.itl" };

	for (int i = 0; i < 2; ++i)
	{
		mStore[i] = new CStore;

		if (!mStore[i]->Init(FileNameArray[i]))
			return false;
	}

	return true;
}

void CStoreManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EStoreMenu::Weapon:
			mStore[0]->Run();
			break;
		case EStoreMenu::Armor:
			mStore[1]->Run();
			break;
		case EStoreMenu::Back:
			return;
		}
	}
}
