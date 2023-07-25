#include <iostream>
#include <time.h>

int main() {
	/*
	if문 : 조건을 체크 하여 원하는 코드 동작여부 결정
	형태 : if (조건식) {조건식이 true 일때 동작할 코드}
	*/

	if (false) {
		std::cout << "if 문 true" << std::endl;
	}

	int Number = 100;

	//if문 안의 코드가 1줄일 경우 코드블록 생략 가능
	if (Number < 0) 
		std::cout << "0보다 작다" << std::endl;
	else //if 문이 false 일때 동작
		std::cout << "0보다 큼" << std::endl;
		
	/*
	else if : if 문과 함께 사용, 혼자 사용 불가, 몇개든 추가할 수 있다.
	else 보다 위에 있어야 한다. 
	else if (조건식) {} 
	*/
	
	const int State1 = 0x1;
	const int State2 = 0x2;
	const int State3 = 0x4;
	const int State4 = 0x8;
	const int State5 = 0x10;
	const int State6 = 0x20;
	const int State7 = 0x40;

	int State = 0;
	State |= State2;
	State |= State3;
	State |= State6;

	if (State & State1)
		std::cout << "State1 On \n";
	if (State & State2)
		std::cout << "State2 On \n";
	if (State & State3)
		std::cout << "State3 On \n";
	if (State & State4)
		std::cout << "State4 On \n";
	if (State & State5)
		std::cout << "State5 On \n";
	if (State & State6)
		std::cout << "State6 On \n";
	if (State & State7)
		std::cout << "State7 On \n";

	std::cin >> Number;

	if (Number < 10)
		std::cout << "10보다 작다" << std::endl;
	else if(Number <20)
		std::cout << "20보다 작다" << std::endl;

	/*
	cin :  콘솔창에서 입력받을수 있게 해주는 기능
	*/

	/*
	난수 : 난수표를 만들어서 필요할때 마다 꺼내 온다. 
	srand();
	*/
	srand(time(0));
	rand(); //시간증가 함에 따라서 첫번째 난수도 증가해서 하나 제거용
	std::cout << rand() % 100 +100 << std::endl;  //100~199 까지 난수 
	std::cout << rand() % 100 +100 << std::endl;
	std::cout << rand() % 100 +100 << std::endl;
	std::cout << rand() % 100 +100 << std::endl;
	std::cout << rand() % 100 +100 << std::endl;

	return 0;

}