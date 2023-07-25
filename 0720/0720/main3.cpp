#include <iostream>
#include <time.h>

//짝 맞추기 게임
// 
// 동일한 특수문자 2개씩 총 10개를 만든다.
// 20개의 배열이 필요하다.
// 20개의 배열을 가로 5개 세로 4줄로 출력하고
// 뒤집어진 상태를 표현하기 위해서 번호를 부여하여 출력한다.
int main()
{
	//난수 생성
	srand((unsigned int)time(0));
	rand();

	//저장공간 생성 
	char   Card[20] = {};  // 카드쌍 저장공간
	bool   Open[20] = {};  // 열렸는지 판단
	char   CardSet[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' }; //특수문자 셋

	//Card[] 배열에 특수문자 쌍으로 저장
	for (int i = 0; i < 10; i++)
	{
		Card[i] = CardSet[i];
		Card[i + 10] = CardSet[i];
	}

	//Card[]  배열 섞기
	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 20; //난수 발생
		int Index2 = rand() % 20;

		char temp = Card[Index1]; //스왑 알고리즘
		Card[Index1] = Card[Index2];
		Card[Index2] = temp;
	}

	int   Input = -1; //입력값
	int   PrevInput = -1; //전에 입력값과 비교위한 변수
	bool   Check = false; //2개를 선택했을때 true, 그때 둘 비교

	while (true)
	{
		system("cls"); //화면 정리
		//i는 세로줄 번호, j는 가로줄번호.
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//인덱스 공식 : 세로번호 * 가로개수 + 가로번호 (1차원 배열을 2차원처럼 사용)
				int Index = i * 5 + j;

				//카드가 열려있으면 특수문자 출력, 카드가 닫혀 있으면 해당 Index 출력.
				if (Open[Index])
					std::cout << Card[Index] << "\t";
				else
				{
					std::cout << Index << "\t";
				}
			}
			std::cout << "\n";
		}

		//PrevInput, Input 번째 값을 비교
		if (Check)
		{
			if (Card[PrevInput] != Card[Input]) //다르면 
			{
				Open[PrevInput] = false;  //둘다 닫고 (특수문자 말고 숫자로 표시)
				Open[Input] = false;
			}
			PrevInput = -1; //PrevInput에 저장된 값 비워주고 
			Check = false;  //check 를 하지 않아도 되고 
			system("pause"); //2번째 본 특수문자를 확인하기 위해 멈춰준다.
			continue; //while문 다시 시작
		}

		// 뒤집을 카드 입력
		std::cout << "뒤집을 숫자를 입력하시오(-1은 종료) : ";
		std::cin >> Input;

		//입력값 예외처리
		if (Input == -1) //-1일때 종료
			break;

		else if (Input < -1 || Input>19) //그외값 입력시 다시 입력
			continue;

		else if (Open[Input]) //이미 열려있는 곳 선택시 다시 입력
			continue;

		//제대로 입력시 수행
		Open[Input] = true;  //오픈하고

		//쌍으로 두개 열었을 때 비교하기 위해
		if (PrevInput == -1)  //(첫번째 입력)PrevInput가 -1로 비어있으면 그곳에 입력값(Input) 저장
			PrevInput = Input;
		else				 //(두번째 입력)PrevInput값이 저장되어있으면 둘을 비교하기위하여 check를 true 로 변경
			Check = true;
	}
	return 0;
}