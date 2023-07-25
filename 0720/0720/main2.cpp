
#include <iostream>
#include <time.h>

//로또 번호 생성기
int main()
{
	//난수 발생
	srand((unsigned int)time(0));
	rand();

	int   ResultNumber[7] = {}; //로또 당첨 번호 저장
	int   GameCount = 0;        //몇 세트 뽑을지
	int   Number[45] = {};      //45개 번호

	std::cout << "게임 수를 입력하세요 : ";
	std::cin >> GameCount;

	//로또 번호 저장
	for (int i = 0; i < 45; i++)
	{
		Number[i] = i + 1; // 1번 부터 저장
	}

	//랜덤 섞기
	for (int i = 0; i < 100; i++)  //100번 섞기
	{
		int Index1 = rand() % 45;  // 스왑할 두수 랜덤 생성
		int Index2 = rand() % 45;

		int Temp = 0;			//스왑 알고리즘 , 생성한 두숫자번째 해당하는 두 숫자 스왑

		Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	//오름차순 정렬 알고리즘
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++) //i번째와 i보다 뒤에 있는 j비교
		{
			if (Number[i] > Number[j])  //i 번째 숫자와 j번째 숫자를 비교하여 j가 더 크면 스왑
			{
				int Temp = Number[i];
				Number[i] = Number[j];
				Number[j] = Temp;
			}
		}
	}

	//당첨번호에 저장
	for (int i = 0; i < 6; i++)
	{
		std::cout << Number[i] << "\t";  //랜덤 생성된 당첨번호 6개 출력 및 저장
		ResultNumber[i] = Number[i];
	}
	ResultNumber[6] = Number[6];		//보너스 번호 저장
	std::cout << "/\t" << Number[6] << "\n\n";

	//입력된 숫자 만큼 랜덤 번호 생성 & 당첨여부 체크 & 출력 반복
	for (int i = 0; i < GameCount; i++)
	{
		//랜덤 번호 생성기 
		for (int i = 0; i < 100; i++)  //100번 섞기
		{
			int Index1 = rand() % 45;  // 스왑할 두수 랜덤 생성
			int Index2 = rand() % 45;

			int Temp = 0;			//스왑 알고리즘 , 생성한 두숫자번째 해당하는 두 숫자 스왑

			Temp = Number[Index1];
			Number[Index1] = Number[Index2];
			Number[Index2] = Temp;
		}

		//생성된 번호 오름차순 정렬 알고리즘
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++) //i번째와 i보다 뒤에 있는 j비교
			{
				if (Number[i] > Number[j])  //i 번째 숫자와 j번째 숫자를 비교하여 j가 더 크면 스왑
				{
					int Temp = Number[i];
					Number[i] = Number[j];
					Number[j] = Temp;
				}
			}
		}

		for (int i = 0; i < 6; i++)
		{
			std::cout << Number[i] << "\t";  //선택된 번호 6개 출력
		}

		//당첨번호와 비교
		int Pair = 0; //몇개 맞았는지

		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (ResultNumber[i] == Number[j]) //비교해보고 둘이 같으면 pair 하나씩 증가시킨다. 
					Pair++;
			}
		}

		switch (Pair) //pair 수에 따라 등수 출력
		{
		case 3:		std::cout << "(5등)";
			break;

		case 4:		std::cout << "(4등)";
			break;

		case 5:		for (int i = 0; i < 6; i++)  //5개 맞았으면 보너스 번호 맞았는지 검사해서 2,3등 판별
		{
			if (Number[i] == ResultNumber[6])
				std::cout << "(2등)";
			else
				std::cout << "(3등)";
		}
			  break;
			  //식별자 사용하여 보너스 번호 비교후 2,3등 판별	
			  /*
			  * case 5:
			  bool NumberCheck;
			  NumberCheck = false;
			  for (int i = 0; i < 6; ++i)
			  {
				  if (Number[i] == ResultNumber[6])
				  {
					  NumberCheck = true;
					  break;
				  }
			  }

			  // 위에서 보너스번호와 같은 값이 있을 경우
			  // NumberCheck 변수는 true로 변경되어 있다.
			  // 만약 같은 번호가 없을 경우
			  // NumberCheck 변수는 false를 유지하고 있다.
			  if (NumberCheck)
				  std::cout << ": 2등" << std::endl;

			  else
				  std::cout << ": 3등" << std::endl;
			  break;
			  */
		case 6:		std::cout << "(1등)";
			break;

		default:	std::cout << "꽝..";
			break;
		}
		std::cout << "\n";
	}

	return 0;
}