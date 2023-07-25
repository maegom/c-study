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
	//난수 생성
	srand((unsigned int)time(0));
	rand();

	//누가 몇번이겼는지에 관한 변수 생성
	int PlayerWinCount = 0, AiWinCount = 0;

	//가위바위보 게임 반복
	while (true) {

		system("cls"); // 콘솔창 지우기

		std::cout << "무엇을 낼지 선택하시오!\n" << std::endl;
		std::cout << "1.가위" << std::endl;
		std::cout << "2.바위" << std::endl;
		std::cout << "3.보" << std::endl;
		std::cout << "4.종료\n" << std::endl;

		std::cout << "PlayerWin : " << PlayerWinCount << std::endl;  //플레이어 이긴 수 출력
		std::cout << "AiWin	: " << AiWinCount << std::endl;			//AI가 이긴 수 출력

		//플레이어, AI 뭐냈는지?
		int player;
		int AI;

		std::cin >> player; //플레이어 입력

		//예외 처리
		if (player < 1 || player >4) //다른거 입력시 다시 입력
			continue;
		else if (player == 4)  //4번 입력시 게임종료
			break;

		//난수 이용하여 랜덤 가위바위보 생성
		AI = rand() % 3 + 1;

		system("cls"); // 콘솔창 지우기

		//AI 뭐 선택 되었는지 출력
		switch (AI)
		{
		case SISSOR:	std::cout << "\nAI 는 가위를 냈습니다.\n" << std::endl;  		break;
		case ROCK:	std::cout << "\nAI 는 바위를 냈습니다.\n" << std::endl;	 		break;
		case PAPER:	std::cout << "\nAI 는 보를 냈습니다.\n" << std::endl;	  		break;
		}

		//플레이어와 AI 낸것 비교
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