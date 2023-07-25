#include <iostream>
#include <time.h>

// _getch() 를 이용하기 위해 추가했다.
#include <conio.h>

/*
5x5 퍼즐
*/

int main()
{
	//난수 발생
	srand((unsigned int)time(0));
	rand();

	//숫자 저장 공간
	int	Number[25] = {};

	// 숫자 넣기
	for (int i = 0; i < 24; ++i)
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

	//'*' 위치 
	int	Location = 24;

	while (true)
	{
		//화면 정리 
		system("cls");

		//게임판 만들기
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				int	Index = i * 5 + j;

				//INT_MAX 와 값이 같으면 *출력
				if (Number[Index] == INT_MAX)
					std::cout << "*\t";

				//아니면 숫자 출력
				else
					std::cout << Number[Index] << "\t";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		//키보드 입력
		char	Input;
		std::cout << "    ^(w) " << std::endl;
		std::cout << "<(a)v(s)>(d) " << std::endl << std::endl;
		std::cout << "움직일 방향을 입력하시오! ";
		Input = _getch();  //누르자 마자 반응 위하여 _getch() 함수 사용.

		//입력값에 따른 
		//"q" 입력시 게임 종료
		if (Input == 'q' || Input == 'Q')
			break;

		//wasd 입력시 
		switch (Input)
		{
		case 'w':
		case 'W':
			if (Location >= 5)
			{
				// 위 인덱스를 구한다.
				int	Index = Location - 5;

				// 두 값을 바꿔준다.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		case 's':
		case 'S':
			if (Location <= 19)
			{
				// 위 인덱스를 구한다.
				int	Index = Location + 5;

				// 두 값을 바꿔준다.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		case 'a':
		case 'A':
			if (Location % 5 != 0)
			{
				// 위 인덱스를 구한다.
				int	Index = Location - 1;

				// 두 값을 바꿔준다.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		case 'd':
		case 'D':
			if (Location % 5 != 4)
			{
				// 위 인덱스를 구한다.
				int	Index = Location + 1;

				// 두 값을 바꿔준다.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		}

		// 24개의 숫자중 1 ~ 24가 다 들어가 있으면 true가 유지될 것이고
		// 하나라도 연속된 숫자가 아니라면 false가 될것이다.
		bool Complete = true;

		for (int i = 0; i < 24; ++i)
		{
			if (Number[i] != i + 1)
			{
				Complete = false;
				break;
			}
		}
		//1~25 숫자 맞으면 게임 종료
		if (Complete)
			break;
	}
	return 0;
}
