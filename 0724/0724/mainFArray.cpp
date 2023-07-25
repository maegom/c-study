#include <iostream>

//인자값이 배열일 때 값에 1~ 10 넣기
void SetNumber(int* Array)
{
	for (int i = 0; i < 10; ++i)
	{
		Array[i] = i + 1;
	}
}

int main()
{
	int   Number1[25] = {};

	SetNumber(Number1); //함수

	//출력
	for (int i = 0; i < 10; ++i)
	{
		std::cout << Number1[i] << "\t";
	}
	return 0;
}