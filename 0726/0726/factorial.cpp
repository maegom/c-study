#include <iostream>

//�Ϲ�����Լ�
int Factorial(int Number)
{
	// ����Լ��� ����Ǵ� ����.
	if (Number == 1)
		return 1;

	return Number * Factorial(Number - 1);
}

//��������Լ�
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