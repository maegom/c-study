#include <iostream>

//일반재귀함수
int Factorial(int Number)
{
	// 재귀함수가 종료되는 조건.
	if (Number == 1)
		return 1;

	return Number * Factorial(Number - 1);
}

//꼬리재귀함수
int FactorialTail(int Number, int Result = 1)
{
	if (Number == 1)
		return Result;

	return FactorialTail(Number - 1, Number * Result);
}

int main()
{
	std::cout << "Factorial : " << Factorial(5) << std::endl;
	std::cout << "FactorialTail : " << FactorialTail(5) << std::endl;

	return 0;
}