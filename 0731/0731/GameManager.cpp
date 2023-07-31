#include "GameManager.h"

CGameManager::CGameManager()	:
	mBattleMgr(nullptr)
{
}

CGameManager::~CGameManager()
{
	if (mBattleMgr)
	{
		delete mBattleMgr;
		mBattleMgr = nullptr;
	}
}

EMainMenu CGameManager::Menu()
{
	system("cls");
	std::cout << "1. ����" << std::endl;
	std::cout << "2. ����" << std::endl;
	std::cout << "3. ����" << std::endl;
	std::cout << "4. ����" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

bool CGameManager::Init()
{
	// ���� ������ Ŭ���� ������ �ʱ�ȭ
	mBattleMgr = new CBattleManager;

	if (!mBattleMgr->Init())
		return false;

	return true;
}

void CGameManager::Run()
{
	while (true)
	{
		switch (Menu())
		{
		case EMainMenu::Battle:
			mBattleMgr->Run();
			break;
		case EMainMenu::Store:
			break;
		case EMainMenu::Inventory:
			break;
		case EMainMenu::Exit:
			return;
		}
	}
}
