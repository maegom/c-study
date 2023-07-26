#include <iostream>

/*
함수포인터 
*/

void Output()
{
	std::cout << "Output Function" << std::endl;
}

void Output1()
{
	std::cout << "Output1 Function" << std::endl;
}

int Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}

int Minus(int Num1, int Num2)
{
	return Num1 - Num2;
}

int Sum1(int Num1, int Num2 = 100)
{
	return Num1 + Num2;
}

int main()
{
	// 아래와 같이 함수를 호출하면 함수의 이름은 곧 주소이기 때문에
	// 해당 주소로 코드의 실행흐름이 이동되고 해당 함수가 호출될때
	// 돌아오는 지점인 여기의 메모리 주소가 저장되게 된다.
	// 함수의 호출은 함수주소(인자); 로 호출하게 되는 것이다.
	Output();

	std::cout << Output << std::endl;
	std::cout << Output1 << std::endl;
	std::cout << Sum << std::endl;
	std::cout << Minus << std::endl;

	// 함수포인터 선언방법
	// 반환타입 (*포인터이름)(인자타입); 으로 선언한다.
	void (*Func)();

	Func = Output;

	Func();

	Func = Output1;

	Func();

	int   (*Func1)(int, int);

	Func1 = Sum;
	std::cout << Func1(10, 20) << std::endl;

	Func1 = Minus;
	std::cout << Func1(10, 20) << std::endl;

	Func1 = Sum1;
	std::cout << Func1(10, 20) << std::endl;

	return 0;
}