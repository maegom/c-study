#include <iostream>
#include <time.h>

/*
5x5 퍼즐
*/

int main()
{
	//난수 발생
	srand((unsigned int)time(0));
	rand();

	//숫자 저장 공간
	int Number[25] = {};

	// 숫자 넣기 
	for (int i = 0; i < 24; i++)
	{
		Number[i] = i + 1;
	}

	//25번째 *을 넣기
	Number[24] = INT_MAX;

	// 24번 인덱스를 제외하고 0 ~ 23번 인덱스를 섞어준다.
	for (int i = 0; i < 100; ++i)
	{
		int	Index1 = rand() % 24;
		int	Index2 = rand() % 24;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	int Location = 0; // '*' 위치    

	while (true)
	{
		//화면 정리 
		system("cls");

		//게임판 만들기
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int Index = i * 5 + j;

				//INT_MAX 와 값이 같으면 *출력
				if (Number[Index] == INT_MAX)
				{
					std::cout << "*" << "\t";
					Location = Index; // '*' 위치 저장
				}
				//아니면 숫자 출력
				else {
					std::cout << Number[Index] << "\t";
				}
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		//키보드 입력
		char Input = 0;
		std::cout << "    ^(w) " << std::endl;
		std::cout << "<(a)v(s)>(d) " << std::endl << std::endl;
		std::cout << "움직일 방향을 입력하시오! ";
		std::cin >> Input;

		//입력값에 따른 
		//"q" 입력시 게임 종료
		if (Input == 'q')
			break;
		//"w" 입력시 *이 위로 이동
		else if (Input == 'w')
		{
			// 맨윗줄일시 재입력
			if (Location < 5)
				continue;
			else
			{
				int Temp = Number[Location];
				Number[Location] = Number[Location - 5];
				Number[Location - 5] = Temp;
			}
		}
		//"a" 입력시 *이 좌로 이동
		else if (Input == 'a')
		{
			// 맨왼쪽줄일시 재입력
			if (Location % 5 == 0)
				continue;
			else {
				int Temp = Number[Location];
				Number[Location] = Number[Location - 1];
				Number[Location - 1] = Temp;
			}
		}
		//"s" 입력시 *이 아래로 이동
		else if (Input == 's')
		{
			// 맨아랫줄일시 재입력
			if (Location >= 20)
				continue;
			int Temp = Number[Location];
			Number[Location] = Number[Location + 5];
			Number[Location + 5] = Temp;
		}
		//"d" 입력시 *이 우로 이동
		else if (Input == 'd')
		{
			// 맨오른쪽줄일시 재입력
			if (Location % 5 == 4)
				continue;
			int Temp = Number[Location];
			Number[Location] = Number[Location + 1];
			Number[Location + 1] = Temp;
		}
		system("pause");

		//1~25까지 숫자 맞으면 게임 종료
		int Check = 0;
		for (int i = 0; i < 25; i++)
		{
			if (Number[i] == i + 1)
			{
				Check++;
			}
		}
		if (Check == 24)
		{
			std::cout << "완성하였습니다!! ";
			break;
		}
	}
	return 0;
}