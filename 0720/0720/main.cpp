#include <iostream>
#include <time.h>

int main() {

	srand((unsigned int)time(0));
	rand();
	/*
	�迭 : �ѹ� �������� �������� ���� Ÿ���� ���� �������� �����Ҽ��ִ� ���

	����Ÿ�� �迭�̸�[����];
	int NumberArray[100];

	���� ���� int�迭 100��¥���� �����ϸ� 400byte��ŭ�� �ϳ��� �޸𸮺���� �����Ѵ�.

	�迭�� ����ҿ� �����ϱ� ���ؼ��� �ε����� �̿��Ѵ�.
	�ε����� 0~����-1���� �����Ѵ�.
	*/
	int NumberArray[100] = {};  // �迭�� ��ü ��Ҹ� 0���� �ʱ�ȭ �Ѵ�. 
	//int NumberArray[100] = {1,2,3,4}; // �������� 0���� �ʱ�ȭ
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
	������ �迭: 
	int Number[5][10];   //50��
	int Number[5][10][6];  //300��
	��� ������ �� ���Ͽ� ��ü ������ �����ش�.  
	*/
	int NumberArray1[5][10] = {};  // 1���� �迭�� 2���� �迭ó�� ����ϴ� �� : (���� ����) = ���� ���� * ���� ��ȣ + ���� ��ȣ
	int NumberArray2[50] = {};

	NumberArray2[2 * 10 + 7] = 1010;

	int Card[50] = {};

	//int Num1 = 10, Num2 = 20;
	//int Temp;
	//Temp = Num1;
	//Num1 = Num2;
	//Num2 = Temp;  //���� �˰���


	for (int i = 0; i < 50; i++)
	{
		Card[i] = i + 1; // Card �� 1~ 50���� ���ʷ� ����
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
		//Card[i] = i + 1; // Card �� 1~ 50���� ���ʷ� ����
		
		std::cout << Card[i] << std::endl;
	}

	for (int i = 0; i < 6; ++i)
	{
		// \t : Tab Ű�� 1�� �����Ͱ� ���� ȿ���̴�.
		std::cout << Card[i] << "\t";
	}

	return 0;
}