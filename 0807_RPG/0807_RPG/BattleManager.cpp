#include "BattleManager.h"
// ���� Battle Ŭ������ ����ؾ� �ϱ� ������ include�� ���ش�.
#include "Battle.h"

CBattleManager* CBattleManager::mInst = nullptr;

CBattleManager::CBattleManager()	:
	mBattle{}
{
}

CBattleManager::~CBattleManager()
{
}

EBattleLevelMenu CBattleManager::Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. �����" << std::endl;
	std::cout << "4. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EBattleLevelMenu::None ||
		Input > (int)EBattleLevelMenu::Back)
		return EBattleLevelMenu::None;

	return (EBattleLevelMenu)Input;
}

bool CBattleManager::Init()
{
	// ���� 3���� ��� �����صд�.
	for (int i = 0; i < 3; ++i)
	{
		mBattle[i] = new CBattle;

		mBattle[i]->Init((EBattleType)i);
	}

	return true;
}

void CBattleManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EBattleLevelMenu::Easy:
			mBattle[0]->Run();
			break;
		case EBattleLevelMenu::Normal:
			mBattle[1]->Run();
			break;
		case EBattleLevelMenu::Hard:
			mBattle[2]->Run();
			break;
		case EBattleLevelMenu::Back:
			return;
		}
	}
}
