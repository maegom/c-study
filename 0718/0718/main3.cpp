#include <iostream>
#include <time.h>



int main()
{
	srand((unsigned int)time(0));
	rand();

	std::cout << "1.����" << std::endl;
	std::cout << "2.����" << std::endl;
	std::cout << "3.��" << std::endl;
	std::cout << "���ÿ�\n" << std::endl;

	enum RCP
	{
		SISSOR = 1,
		ROCK,
		PAPPER
	};

	int Player=0;
	int AI =0;

	AI = rand() % 3 + 1 ;

	std::cin >> Player;

	switch (AI)
	{
	case SISSOR: std::cout << std::endl << "AI�� ������" << std::endl;
		break;
	case ROCK: std::cout << std::endl << "AI�� ������" << std::endl;
		break;
	case PAPPER: std::cout << std::endl << "AI�� ����" << std::endl;
		break;
	}

	if (AI == Player)
	{
		 
		std::cout << "������� �ٽ� ����\n" << std::endl;
		return main();
	}
	else if ((AI == SISSOR && Player == ROCK)|| (AI == ROCK && Player == PAPPER)|| (AI == PAPPER && Player == SISSOR))
	{
		std::cout << "�̱�" << std::endl;
	}
	else
	{
		std::cout << "��" << std::endl;
	}


	
	
	return 0;

}