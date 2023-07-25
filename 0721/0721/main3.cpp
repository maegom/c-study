#include <iostream>
#include <time.h>

// _getch() �� �̿��ϱ� ���� �߰��ߴ�.
#include <conio.h>

/*
5x5 ����
*/

int main()
{
	//���� �߻�
	srand((unsigned int)time(0));
	rand();

	//���� ���� ����
	int	Number[25] = {};

	// ���� �ֱ�
	for (int i = 0; i < 24; ++i)
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

	//'*' ��ġ 
	int	Location = 24;

	while (true)
	{
		//ȭ�� ���� 
		system("cls");

		//������ �����
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				int	Index = i * 5 + j;

				//INT_MAX �� ���� ������ *���
				if (Number[Index] == INT_MAX)
					std::cout << "*\t";

				//�ƴϸ� ���� ���
				else
					std::cout << Number[Index] << "\t";
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
		//Ű���� �Է�
		char	Input;
		std::cout << "    ^(w) " << std::endl;
		std::cout << "<(a)v(s)>(d) " << std::endl << std::endl;
		std::cout << "������ ������ �Է��Ͻÿ�! ";
		Input = _getch();  //������ ���� ���� ���Ͽ� _getch() �Լ� ���.

		//�Է°��� ���� 
		//"q" �Է½� ���� ����
		if (Input == 'q' || Input == 'Q')
			break;

		//wasd �Է½� 
		switch (Input)
		{
		case 'w':
		case 'W':
			if (Location >= 5)
			{
				// �� �ε����� ���Ѵ�.
				int	Index = Location - 5;

				// �� ���� �ٲ��ش�.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		case 's':
		case 'S':
			if (Location <= 19)
			{
				// �� �ε����� ���Ѵ�.
				int	Index = Location + 5;

				// �� ���� �ٲ��ش�.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		case 'a':
		case 'A':
			if (Location % 5 != 0)
			{
				// �� �ε����� ���Ѵ�.
				int	Index = Location - 1;

				// �� ���� �ٲ��ش�.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		case 'd':
		case 'D':
			if (Location % 5 != 4)
			{
				// �� �ε����� ���Ѵ�.
				int	Index = Location + 1;

				// �� ���� �ٲ��ش�.
				int	Temp = Number[Location];
				Number[Location] = Number[Index];
				Number[Index] = Temp;

				Location = Index;
			}
			break;
		}

		// 24���� ������ 1 ~ 24�� �� �� ������ true�� ������ ���̰�
		// �ϳ��� ���ӵ� ���ڰ� �ƴ϶�� false�� �ɰ��̴�.
		bool Complete = true;

		for (int i = 0; i < 24; ++i)
		{
			if (Number[i] != i + 1)
			{
				Complete = false;
				break;
			}
		}
		//1~25 ���� ������ ���� ����
		if (Complete)
			break;
	}
	return 0;
}
