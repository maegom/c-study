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


// 섞는거 다시
//#include <iostream>
//#include <time.h>
//
///*
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 *
//
//0으로 표시된 부분에 1 ~ 24 사이의 숫자를 섞어서 출력한다.
//플레이어는 * 표시를 움직여줄 수 있다.
//w : 위로 이동 s : 아래로 이동 a : 왼쪽 이동 d : 오른쪽 이동 q : 종료
//
//이동 키를 누르면 해당 방향에 있는 값과 *의 위치를 변경해주고 숫자가 왼쪽 위부터
//차례대로 1 ~ 24 까지 나오면 게임을 종료한다.
//*/
//
//int main()
//{
//    srand((unsigned int)time(0));
//    rand();
//
//    int Number[25] = {};
//
//    for (int i = 0; i < 24; i++)
//    {
//        Number[i] = i;
//    }
//    Number[24] = INT_MAX;
//
//    for (int i = 0; i < 1000; i++)
//    {
//        int Index1 = rand() % 25;
//        int Case = rand() % 4 + 1;
//
//        int Temp = Number[Index1];
//        switch (Case)
//        {
//        case 1: //위
//            if (Index1 < 5)
//                break;
//            else {
//                Number[Index1] = Number[Index1 - 5];
//                Number[Index1 - 5] = Temp;
//                break;
//            }
//
//
//        case 2: //좌
//            if (Index1 % 5 == 0)
//                break;
//            else {
//                Number[Index1] = Number[Index1 - 1];
//                Number[Index1 - 1] = Temp;
//                break;
//
//            }
//
//
//        case 3: //아래
//            if (Index1 >= 20)
//                break;
//            else {
//                Number[Index1] = Number[Index1 + 5];
//                Number[Index1 + 5] = Temp;
//                break;
//            }
//
//        case 4: //우
//            if (Index1 % 5 == 4)
//                break;
//            else
//            {
//                Number[Index1] = Number[Index1 + 1];
//                Number[Index1 + 1] = Temp;
//                break;
//            }
//
//        }
//
//
//    }
//
//    int Location = 0; // * 위치    
//
//    while (true)
//    {
//        system("cls");
//        for (int i = 0; i < 5; i++)
//        {
//            for (int j = 0; j < 5; j++)
//            {
//                int Index = i * 5 + j;
//
//                if (Number[Index] == INT_MAX)
//                {
//                    std::cout << "*" << "\t";
//                    Location = Index;
//
//                }
//                else {
//                    std::cout << Number[Index] << "\t";
//                }
//
//            }
//            std::cout << std::endl;
//            std::cout << std::endl;
//        }
//        char Input = 0;
//        std::cout << "    ^(w) " << std::endl;
//        std::cout << "<(a)v(s)>(d) " << std::endl << std::endl;
//        std::cout << "움직일 방향을 입력하시오! ";
//
//        std::cin >> Input;
//
//        if (Input == 'q')
//            break;
//        else if (Input == 'w')
//        {
//            if (Location < 5)
//                continue;
//            else
//            {
//                int Temp = Number[Location];
//                Number[Location] = Number[Location - 5];
//                Number[Location - 5] = Temp;
//            }
//        }
//        else if (Input == 'a')
//        {
//            if (Location % 5 == 0)
//                continue;
//            else {
//                int Temp = Number[Location];
//                Number[Location] = Number[Location - 1];
//                Number[Location - 1] = Temp;
//            }
//        }
//        else if (Input == 's')
//        {
//            if (Location >= 20)
//                continue;
//            int Temp = Number[Location];
//            Number[Location] = Number[Location + 5];
//            Number[Location + 5] = Temp;
//        }
//        else if (Input == 'd')
//        {
//            if (Location % 5 == 4)
//                continue;
//            int Temp = Number[Location];
//            Number[Location] = Number[Location + 1];
//            Number[Location + 1] = Temp;
//        }
//        system("pause");
//
//        int Check = 0;
//        for (int i = 0; i < 25; i++)
//        {
//            if (Number[i] == i)
//            {
//                Check++;
//            }
//        }
//        if (Check == 24)
//        {
//            std::cout << "완성하였습니다!! ";
//            break;
//        }
//
//    }
//    return 0;
//}
