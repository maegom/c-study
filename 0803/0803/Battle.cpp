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
	std::cout << "1. ����" << std::endl;
	std::cout << "2. �ڷΰ���" << std::endl;
	std::cout << "�޴��� �����ϼ��� : ";
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

	// ���׿����� : ������ üũ�Ͽ� true�϶��� false�϶��� ���� ������ �� �ִ�.
	Damage = Damage < 1 ? 1 : Damage;

	//if (Damage < 1)
	//	Damage = 1;

	// Damage �Լ��� �׾��� ��� true�� ��ȯ�ȴ�.
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
