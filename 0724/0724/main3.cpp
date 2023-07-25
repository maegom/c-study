#include <iostream>

//정수 Number을 인자로 받아 11로 바꿔준다. 
void ChangeNumber(int Number)
{
	Number = 11;  //Number가 지역변수라 main 함수의 Number 값은 바뀌지 않는다. 
}

//정수 Number의 주소 값을 인자로 받아 해당 주소에 있는 값을 222로 바꿔준다.  
void ChangeNumber1(int* Number)
{
	*Number = 222; //주소값을 통하여 Number를 변경하여 main 함수의 Number값이 바뀐다. 
}

//정수 Number1, Number2의 주소 값을 인자로 받아, 해당 주소에 있는 값을 3333, 44444로 바꿔준다.  
void ChangeNumber1(int* Number1, int* Number2)
{
	*Number1 = 3333;
	*Number2 = 44444; //마지막 바꾼 값으로 바뀐다. 
}

int main()
{
	//변수 생성
	int Number = 300;
	std::cout << Number << std::endl; //= 300

	//함수 실행 
	ChangeNumber(Number);
	std::cout << Number << std::endl; //= 300 

	ChangeNumber1(&Number);
	std::cout << Number << std::endl; // = 222

	ChangeNumber1(&Number, &Number);
	std::cout << Number << std::endl; //= 44444

	return 0;
}