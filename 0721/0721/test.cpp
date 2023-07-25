#include <iostream>
#include <time.h>

/*
5x5 ����
*/

int main()
{
	//���� �߻�
	srand((unsigned int)time(0));
	rand();

	//���� ���� ����
	int Number[25] = {};

	// ���� �ֱ� 
	for (int i = 0; i < 24; i++)
	{
		Number[i] = i + 1;
	}

	//25��° *�� �ֱ�
	Number[24] = INT_MAX;

	// 24�� �ε����� �����ϰ� 0 ~ 23�� �ε����� �����ش�.
	for (int i = 0; i < 100; ++i)
	{
		int	Index1 = rand() % 24;
		int	Index2 = rand() % 24;

		int	Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	int Location = 0; // '*' ��ġ    

	while (true)
	{
		//ȭ�� ���� 
		system("cls");

		//������ �����
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				int Index = i * 5 + j;

				//INT_MAX �� ���� ������ *���
				if (Number[Index] == INT_MAX)
				{
					std::cout << "*" << "\t";
					Location = Index; // '*' ��ġ ����
				}
				//�ƴϸ� ���� ���
				else {
					std::cout << Number[Index] << "\t";
				}
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		//Ű���� �Է�
		char Input = 0;
		std::cout << "    ^(w) " << std::endl;
		std::cout << "<(a)v(s)>(d) " << std::endl << std::endl;
		std::cout << "������ ������ �Է��Ͻÿ�! ";
		std::cin >> Input;

		//�Է°��� ���� 
		//"q" �Է½� ���� ����
		if (Input == 'q')
			break;
		//"w" �Է½� *�� ���� �̵�
		else if (Input == 'w')
		{
			// �������Ͻ� ���Է�
			if (Location < 5)
				continue;
			else
			{
				int Temp = Number[Location];
				Number[Location] = Number[Location - 5];
				Number[Location - 5] = Temp;
			}
		}
		//"a" �Է½� *�� �·� �̵�
		else if (Input == 'a')
		{
			// �ǿ������Ͻ� ���Է�
			if (Location % 5 == 0)
				continue;
			else {
				int Temp = Number[Location];
				Number[Location] = Number[Location - 1];
				Number[Location - 1] = Temp;
			}
		}
		//"s" �Է½� *�� �Ʒ��� �̵�
		else if (Input == 's')
		{
			// �ǾƷ����Ͻ� ���Է�
			if (Location >= 20)
				continue;
			int Temp = Number[Location];
			Number[Location] = Number[Location + 5];
			Number[Location + 5] = Temp;
		}
		//"d" �Է½� *�� ��� �̵�
		else if (Input == 'd')
		{
			// �ǿ��������Ͻ� ���Է�
			if (Location % 5 == 4)
				continue;
			int Temp = Number[Location];
			Number[Location] = Number[Location + 1];
			Number[Location + 1] = Temp;
		}
		system("pause");

		//1~25���� ���� ������ ���� ����
		int Check = 0;
		for (int i = 0; i < 25; i++)
		{
			if (Number[i] == i + 1)
			{
				Check++;
			}
		}
		if (Check == 24)
		{
			std::cout << "�ϼ��Ͽ����ϴ�!! ";
			break;
		}
	}
	return 0;
}