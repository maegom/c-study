#include "Battle.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Monster.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

EBattleMenu CBattle::Menu()
{
	std::cout << "1. 공격" << std::endl;
	std::cout << "2. 뒤로가기" << std::endl;
	std::cout << "메뉴를 선택하세요 : ";
	int	Input;

	std::cin >> Input;

	if (Input <= (int)EBattleMenu::None ||
		Input > (int)EBattleMenu::Back)
		return EBattleMenu::None;

	return (EBattleMenu)Input;
}

EBattleResult CBattle::Attack(CPlayer* Player, CMonster* Monster)
{
	int	Damage = Player->GetAttack() - Monster->GetArmor();

	// 삼항연산자 : 조건을 체크하여 true일때와 false일때의 값을 지정할 수 있다.
	Damage = Damage < 1 ? 1 : Damage;

	//if (Damage < 1)
	//	Damage = 1;

	// Damage 함수는 죽었을 경우 true가 반환된다.
	if (Monster->Damage(Damage))
	{
		Player->AddExp(Monster->GetExp());
		Player->AddMoney(Monster->GetMoney());
		return EBattleResult::MonsterDeath;
	}

	Damage = Monster->GetAttack() - Player->GetArmor();

	Damage = Damage < 1 ? 1 : Damage;

	if (Player->Damage(Damage))
	{
		Player->Resurrection();
		return EBattleResult::PlayerDeath;
	}

	return EBattleResult::None;
}

bool CBattle::Init(EBattleType Type)
{
	mBattleType = Type;

	return true;
}

void CBattle::Run()
{
	CPlayer* Player = CObjectManager::GetInst()->GetPlayer();

	CMonster* Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);

	while (true)
	{
		system("cls");

		std::cout << "=================== Player ===================" << std::endl;
		Player->Output();
		std::cout << std::endl;


		std::cout << "=================== Monster ===================" << std::endl;
		Monster->Output();
		std::cout << std::endl;

		switch (Menu())
		{
		case EBattleMenu::Attack:
			switch (Attack(Player, Monster))
			{
			case EBattleResult::None:
				break;
			case EBattleResult::PlayerDeath:
				break;
			case EBattleResult::MonsterDeath:
				delete Monster;
				Monster = CObjectManager::GetInst()->CreateMonster(mBattleType);
				break;
			default:
				break;
			}
			break;
		case EBattleMenu::Back:
			delete Monster;
			return;
		}
	}
}
