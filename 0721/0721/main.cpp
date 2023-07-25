#include<iostream> 
#include<time.h>

/*
	빙고게임
	5x5 숫자 1~25 사이의 값을 랜덤하게 섞어서 출력한다.
	사용자는 숫자 1개를 입력하고 0을 입력하면 종료
	1~ 25사이의 숫자를 입력하면 해당 숫자를 찾아서 *로 출력되게 만든다.
	나머지 숫자부분들은 해당 숫자 그대로 출력한다.

	줄 체크를 한다. 가로 5줄 세로 5줄 대각선 2줄이 나온다.
이중 몇줄을 완성했는지 매번 체크하여 5줄 이상을 완성했을 경우
게임을 종료한다.
	*/

int main() {
	//난수 발생
	srand((unsigned int)time(0));
	rand();

	//숫자 또는 * 저장할 공간 생성
	int Number[25] = {};
	char Star[25] = {};

	//카드에 1~25까지 저장
	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
	}

	//바꿔줄 * 25개 저장
	for (int i = 0; i < 25; i++)
	{
		Star[i] = '*';
	}

	//숫자 카드를 랜덤하게 섞는다.
	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 25;
		int Index2 = rand() % 25;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	//변수 생성
	int Input = -1;   //입력할 값
	bool Open[25] = {}; //오픈 여부 확인자

	bool Bingo[12] = {};  //빙고 체크
	int BingoCount = 0;	  // 빙고 수 체크


	while (true)
	{
		system("cls"); // 화면 정리

		//빙고판 출력
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//빙고판 닫혀있으면 숫자 출력
				if (Open[i * 5 + j] == 0)
					std::cout << Number[i * 5 + j] << "\t";
				// 빙고판 열려있으면 '*' 출력
				else if (Open[i * 5 + j] == 1)
					std::cout << Star[i * 5 + j] << "\t";
			}
			std::cout << "\n";
			std::cout << "\n";
		}
		// 완성된 빙고가 5줄 이상이면 종료
		if (BingoCount >= 5)
		{
			std::cout << std::endl << "빙고를 완성하였습니다.\n";
			break;
		}

		//현재 빙고 개수 출력
		std::cout << std::endl << "빙고 수 : " << BingoCount << std::endl;
		BingoCount = 0;

		// 오픈할 카드 번호 입력 받기
		std::cout << std::endl << "오픈할 번호를 선택하시오(0:종료) : ";
		std::cin >> Input;

		// 입력값 예외 설정
		if (Input == 0)  //0을 입력하면 종료
		{
			break;
		}
		else if (Input < 0 || Input >25) //출력된 숫자 외 입력하면 재입력
		{
			continue;
		}

		//입력한 숫자 카드 오픈 
		for (int i = 0; i < 25; i++)
		{
			if (Input == Number[i])
			{
				Open[i] = true;
			}
		}

		//system("pause"); //입력한 숫자 보기용

		//빙고인지 체크 (열려있는지 확인하여 각 규칙에 해당되는 Bingo[]를 true 로 만듦)
		//가로빙고
		for (int i = 0; i < 5; i++)
		{
			if (Open[5 * i] == 1 && Open[5 * i + 1] == 1 && Open[5 * i + 2] == 1 && Open[5 * i + 3] == 1 && Open[5 * i + 4] == 1)
			{
				Bingo[i] = true;
			}
		}
		//세로빙고
		for (int i = 0; i < 5; i++)
		{
			if (Open[i] == 1 && Open[5 + i] == 1 && Open[10 + i] == 1 && Open[15 + i] == 1 && Open[20 + i] == 1)
			{
				Bingo[5 + i] = true;
			}
		}

		//대각선 빙고
		if (Open[0] == 1 && Open[6] == 1 && Open[12] == 1 && Open[18] == 1 && Open[24] == 1)
		{
			Bingo[10] = true;
		}
		if (Open[4] == 1 && Open[8] == 1 && Open[12] == 1 && Open[16] == 1 && Open[20] == 1)
		{
			Bingo[11] = true;
		}

		//빙고 배열 true 인 개수 만큼 BingoCount 에 저장
		for (int i = 0; i < 12; i++)
		{
			if (Bingo[i] == 1)
				BingoCount++;
		}
	}
	return 0;
}