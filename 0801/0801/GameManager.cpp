#include "GameManager.h"
#include "BattleManager.h"
#include "ObjectManager.h"

CGameManager* CGameManager::mInst = nullptr;

CGameManager::CGameManager()
{
}

CGameManager::~CGameManager()
{
	CObjectManager::DestroyInst();
	CBattleManager::DestroyInst();
}

EMainMenu CGameManager::Menu()
{
	system("cls");
	std::cout << "1. 전투" << std::endl;
	std::cout << "2. 상점" << std::endl;
	std::cout << "3. 가방" << std::endl;
	std::cout << "4. 종료" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EMainMenu::None || Input > (int)EMainMenu::Exit)
		return EMainMenu::None;

	return (EMainMenu)Input;
}

bool CGameManager::Init()
{
	// 오브젝트 관리자 초기화
	if (!CObjectManager::GetInst()->Init())
		return false;

	// 전투 관리자 클래스 생성과 초기화
	if (!CBattleManager::GetInst()->Init())
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
			CBattleManager::GetInst()->Run();
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
