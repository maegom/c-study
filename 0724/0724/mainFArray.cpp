#include <iostream>

//���ڰ��� �迭�� �� ���� 1~ 10 �ֱ�
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

	SetNumber(Number1); //�Լ�

	//���
	for (int i = 0; i < 10; ++i)
	{
		std::cout << Number1[i] << "\t";
	}
	return 0;
}