#include <iostream>
#include <time.h>



int main()
{
	srand((unsigned int)time(0));
	rand();

	std::cout << "1.°¡À§" << std::endl;
	std::cout << "2.¹ÙÀ§" << std::endl;
	std::cout << "3.º¸" << std::endl;
	std::cout << "°í¸£½Ã¿À\n" << std::endl;

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
	case SISSOR: std::cout << std::endl << "AI°¡ °¡À§³¿" << std::endl;
		break;
	case ROCK: std::cout << std::endl << "AI°¡ ¹ÙÀ§³¿" << std::endl;
		break;
	case PAPPER: std::cout << std::endl << "AI°¡ º¸³¿" << std::endl;
		break;
	}

	if (AI == Player)
	{
		 
		std::cout << "ºñ°åÀ¸´Ï ´Ù½Ã ¤¡¤¡\n" << std::endl;
		return main();
	}
	else if ((AI == SISSOR && Player == ROCK)|| (AI == ROCK && Player == PAPPER)|| (AI == PAPPER && Player == SISSOR))
	{
		std::cout << "ÀÌ±è" << std::endl;
	}
	else
	{
		std::cout << "Áü" << std::endl;
	}


	
	
	return 0;

}