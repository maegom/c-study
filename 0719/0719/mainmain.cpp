#include <iostream> 
#include <time.h>

//가위바위보 게임

enum SRP   //가위바위보를 번호가 아닌 직관적으로 보기위해 열거형 사용
{
	SISSOR = 1,  //지정된거 다음부터 +1
	ROCK,
	PAPER
};

int main()
{
	srand((unsigned int)time(0));  //형변환 : (변환할 타입) 의 형태로 사용하며, 어떤 값이나 변수를 지정하는 타입으로 일시적으로 인식시켜줌
	rand();

	int PlayerWinCount = 0, AiWinCount = 0;


	while (true) {

		system("cls"); // 콘솔창 지우기

		std::cout << "무엇을 낼지 선택하시오!\n" << std::endl;
		std::cout << "1.가위" << std::endl;
		std::cout << "2.바위" << std::endl;
		std::cout << "3.보" << std::endl;
		std::cout << "4.종료\n" << std::endl;

		std::cout << "PlayerWin : " << PlayerWinCount << std::endl;
		std::cout << "AiWin	: " << AiWinCount << std::endl;



		int player;
		int AI;

		std::cin >> player;
		if (player < 1 || player >4) //(player < 1 || player >4)
			continue;
		else if (player == 4)
			break;

		AI = rand() % 3 + 1;

		system("cls"); // 콘솔창 지우기

		switch (AI)
		{
		case SISSOR:	std::cout << "\nAI 는 가위를 냈습니다.\n" << std::endl;  		break;
		case ROCK:	std::cout << "\nAI 는 바위를 냈습니다.\n" << std::endl;	 		break;
		case PAPER:	std::cout << "\nAI 는 보를 냈습니다.\n" << std::endl;	  		break;
		}

		if (player == AI)
			std::cout << "비겼습니다.\n" << std::endl;
		else if (player == SISSOR && AI == PAPER || player == ROCK && AI == SISSOR || player == PAPER && AI == ROCK)
		{
			std::cout << "당신이 이겼습니다.\n" << std::endl;
			++PlayerWinCount;
		}
		else
		{
			std::cout << "당신이 졌습니다.\n" << std::endl;
			++AiWinCount;
		}
		std::cout << "\n\nPlayerWin : " << PlayerWinCount << std::endl;
		std::cout << "AiWin	: " << AiWinCount << std::endl;

		system("pause"); //콘솔창 일시정지
	}

	return 0;
}