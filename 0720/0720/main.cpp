#include <iostream>
#include <time.h>

int main() {

	srand((unsigned int)time(0));
	rand();
	/*
	배열 : 한번 선언으로 여러개의 같은 타입의 변수 여러개를 생성할수있는 기능

	변수타입 배열이름[개수];
	int NumberArray[100];

	위와 같이 int배열 100개짜리를 생성하면 400byte만큼의 하나의 메모리블록을 생성한다.

	배열의 각요소에 접근하기 위해서는 인덱스를 이용한다.
	인덱스는 0~개수-1까지 존재한다.
	*/
	int NumberArray[100] = {};  // 배열의 전체 요소를 0으로 초기화 한다. 
	//int NumberArray[100] = {1,2,3,4}; // 나머지는 0으로 초기화
	int Index = 10;
	NumberArray[0] = 500; 
	NumberArray[1] = 20; 
	NumberArray[Index] = 10203;

	if (Index < 0 || Index >= 100)
		std::cout << "Index Error!";
	else
	std::cout << NumberArray[0] << std::endl;
	std::cout << NumberArray[Index] << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << NumberArray[i] << std::endl;
	}
	system("cls");
	/*
	다차원 배열: 
	int Number[5][10];   //50개
	int Number[5][10][6];  //300개
	모든 개수를 다 곱하여 전체 개수를 구해준다.  
	*/
	int NumberArray1[5][10] = {};  // 1차원 배열을 2차원 배열처럼 사용하는 법 : (접근 공식) = 가로 개수 * 새로 번호 + 가로 번호
	int NumberArray2[50] = {};

	NumberArray2[2 * 10 + 7] = 1010;

	int Card[50] = {};

	//int Num1 = 10, Num2 = 20;
	//int Temp;
	//Temp = Num1;
	//Num1 = Num2;
	//Num2 = Temp;  //스왑 알고리즘


	for (int i = 0; i < 50; i++)
	{
		Card[i] = i + 1; // Card 에 1~ 50까지 차례로 저장
		//Card[i] = rand() % 50 + 1;

	}

	for(int i =0 ; i <100 ; i++)

	{	int Index1 = rand() % 50;
		int Index2 = rand() % 50;
		int tmp = Card[Index1];
		Card[Index1] = Card[Index2];
		Card[Index2] = tmp;

	}

	for (int i = 0; i < 50; i++)
	{
		//Card[i] = i + 1; // Card 에 1~ 50까지 차례로 저장
		
		std::cout << Card[i] << std::endl;
	}

	for (int i = 0; i < 6; ++i)
	{
		// \t : Tab 키를 1번 누른것과 같은 효과이다.
		std::cout << Card[i] << "\t";
	}

	return 0;
}