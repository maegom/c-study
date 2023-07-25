
#include <iostream>
#include <time.h>

//�ζ� ��ȣ ������
int main()
{
	//���� �߻�
	srand((unsigned int)time(0));
	rand();

	int   ResultNumber[7] = {}; //�ζ� ��÷ ��ȣ ����
	int   GameCount = 0;        //�� ��Ʈ ������
	int   Number[45] = {};      //45�� ��ȣ

	std::cout << "���� ���� �Է��ϼ��� : ";
	std::cin >> GameCount;

	//�ζ� ��ȣ ����
	for (int i = 0; i < 45; i++)
	{
		Number[i] = i + 1; // 1�� ���� ����
	}

	//���� ����
	for (int i = 0; i < 100; i++)  //100�� ����
	{
		int Index1 = rand() % 45;  // ������ �μ� ���� ����
		int Index2 = rand() % 45;

		int Temp = 0;			//���� �˰��� , ������ �μ��ڹ�° �ش��ϴ� �� ���� ����

		Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	//�������� ���� �˰���
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++) //i��°�� i���� �ڿ� �ִ� j��
		{
			if (Number[i] > Number[j])  //i ��° ���ڿ� j��° ���ڸ� ���Ͽ� j�� �� ũ�� ����
			{
				int Temp = Number[i];
				Number[i] = Number[j];
				Number[j] = Temp;
			}
		}
	}

	//��÷��ȣ�� ����
	for (int i = 0; i < 6; i++)
	{
		std::cout << Number[i] << "\t";  //���� ������ ��÷��ȣ 6�� ��� �� ����
		ResultNumber[i] = Number[i];
	}
	ResultNumber[6] = Number[6];		//���ʽ� ��ȣ ����
	std::cout << "/\t" << Number[6] << "\n\n";

	//�Էµ� ���� ��ŭ ���� ��ȣ ���� & ��÷���� üũ & ��� �ݺ�
	for (int i = 0; i < GameCount; i++)
	{
		//���� ��ȣ ������ 
		for (int i = 0; i < 100; i++)  //100�� ����
		{
			int Index1 = rand() % 45;  // ������ �μ� ���� ����
			int Index2 = rand() % 45;

			int Temp = 0;			//���� �˰��� , ������ �μ��ڹ�° �ش��ϴ� �� ���� ����

			Temp = Number[Index1];
			Number[Index1] = Number[Index2];
			Number[Index2] = Temp;
		}

		//������ ��ȣ �������� ���� �˰���
		for (int i = 0; i < 5; i++)
		{
			for (int j = i + 1; j < 6; j++) //i��°�� i���� �ڿ� �ִ� j��
			{
				if (Number[i] > Number[j])  //i ��° ���ڿ� j��° ���ڸ� ���Ͽ� j�� �� ũ�� ����
				{
					int Temp = Number[i];
					Number[i] = Number[j];
					Number[j] = Temp;
				}
			}
		}

		for (int i = 0; i < 6; i++)
		{
			std::cout << Number[i] << "\t";  //���õ� ��ȣ 6�� ���
		}

		//��÷��ȣ�� ��
		int Pair = 0; //� �¾Ҵ���

		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (ResultNumber[i] == Number[j]) //���غ��� ���� ������ pair �ϳ��� ������Ų��. 
					Pair++;
			}
		}

		switch (Pair) //pair ���� ���� ��� ���
		{
		case 3:		std::cout << "(5��)";
			break;

		case 4:		std::cout << "(4��)";
			break;

		case 5:		for (int i = 0; i < 6; i++)  //5�� �¾����� ���ʽ� ��ȣ �¾Ҵ��� �˻��ؼ� 2,3�� �Ǻ�
		{
			if (Number[i] == ResultNumber[6])
				std::cout << "(2��)";
			else
				std::cout << "(3��)";
		}
			  break;
			  //�ĺ��� ����Ͽ� ���ʽ� ��ȣ ���� 2,3�� �Ǻ�	
			  /*
			  * case 5:
			  bool NumberCheck;
			  NumberCheck = false;
			  for (int i = 0; i < 6; ++i)
			  {
				  if (Number[i] == ResultNumber[6])
				  {
					  NumberCheck = true;
					  break;
				  }
			  }

			  // ������ ���ʽ���ȣ�� ���� ���� ���� ���
			  // NumberCheck ������ true�� ����Ǿ� �ִ�.
			  // ���� ���� ��ȣ�� ���� ���
			  // NumberCheck ������ false�� �����ϰ� �ִ�.
			  if (NumberCheck)
				  std::cout << ": 2��" << std::endl;

			  else
				  std::cout << ": 3��" << std::endl;
			  break;
			  */
		case 6:		std::cout << "(1��)";
			break;

		default:	std::cout << "��..";
			break;
		}
		std::cout << "\n";
	}

	return 0;
}