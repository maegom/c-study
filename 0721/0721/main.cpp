#include<iostream> 
#include<time.h>

/*
	�������
	5x5 ���� 1~25 ������ ���� �����ϰ� ��� ����Ѵ�.
	����ڴ� ���� 1���� �Է��ϰ� 0�� �Է��ϸ� ����
	1~ 25������ ���ڸ� �Է��ϸ� �ش� ���ڸ� ã�Ƽ� *�� ��µǰ� �����.
	������ ���ںκе��� �ش� ���� �״�� ����Ѵ�.

	�� üũ�� �Ѵ�. ���� 5�� ���� 5�� �밢�� 2���� ���´�.
���� ������ �ϼ��ߴ��� �Ź� üũ�Ͽ� 5�� �̻��� �ϼ����� ���
������ �����Ѵ�.
	*/

int main() {
	//���� �߻�
	srand((unsigned int)time(0));
	rand();

	//���� �Ǵ� * ������ ���� ����
	int Number[25] = {};
	char Star[25] = {};

	//ī�忡 1~25���� ����
	for (int i = 0; i < 25; i++)
	{
		Number[i] = i + 1;
	}

	//�ٲ��� * 25�� ����
	for (int i = 0; i < 25; i++)
	{
		Star[i] = '*';
	}

	//���� ī�带 �����ϰ� ���´�.
	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 25;
		int Index2 = rand() % 25;

		int Temp = Number[Index1];
		Number[Index1] = Number[Index2];
		Number[Index2] = Temp;
	}

	//���� ����
	int Input = -1;   //�Է��� ��
	bool Open[25] = {}; //���� ���� Ȯ����

	bool Bingo[12] = {};  //���� üũ
	int BingoCount = 0;	  // ���� �� üũ


	while (true)
	{
		system("cls"); // ȭ�� ����

		//������ ���
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//������ ���������� ���� ���
				if (Open[i * 5 + j] == 0)
					std::cout << Number[i * 5 + j] << "\t";
				// ������ ���������� '*' ���
				else if (Open[i * 5 + j] == 1)
					std::cout << Star[i * 5 + j] << "\t";
			}
			std::cout << "\n";
			std::cout << "\n";
		}
		// �ϼ��� ���� 5�� �̻��̸� ����
		if (BingoCount >= 5)
		{
			std::cout << std::endl << "���� �ϼ��Ͽ����ϴ�.\n";
			break;
		}

		//���� ���� ���� ���
		std::cout << std::endl << "���� �� : " << BingoCount << std::endl;
		BingoCount = 0;

		// ������ ī�� ��ȣ �Է� �ޱ�
		std::cout << std::endl << "������ ��ȣ�� �����Ͻÿ�(0:����) : ";
		std::cin >> Input;

		// �Է°� ���� ����
		if (Input == 0)  //0�� �Է��ϸ� ����
		{
			break;
		}
		else if (Input < 0 || Input >25) //��µ� ���� �� �Է��ϸ� ���Է�
		{
			continue;
		}

		//�Է��� ���� ī�� ���� 
		for (int i = 0; i < 25; i++)
		{
			if (Input == Number[i])
			{
				Open[i] = true;
			}
		}

		//system("pause"); //�Է��� ���� �����

		//�������� üũ (�����ִ��� Ȯ���Ͽ� �� ��Ģ�� �ش�Ǵ� Bingo[]�� true �� ����)
		//���κ���
		for (int i = 0; i < 5; i++)
		{
			if (Open[5 * i] == 1 && Open[5 * i + 1] == 1 && Open[5 * i + 2] == 1 && Open[5 * i + 3] == 1 && Open[5 * i + 4] == 1)
			{
				Bingo[i] = true;
			}
		}
		//���κ���
		for (int i = 0; i < 5; i++)
		{
			if (Open[i] == 1 && Open[5 + i] == 1 && Open[10 + i] == 1 && Open[15 + i] == 1 && Open[20 + i] == 1)
			{
				Bingo[5 + i] = true;
			}
		}

		//�밢�� ����
		if (Open[0] == 1 && Open[6] == 1 && Open[12] == 1 && Open[18] == 1 && Open[24] == 1)
		{
			Bingo[10] = true;
		}
		if (Open[4] == 1 && Open[8] == 1 && Open[12] == 1 && Open[16] == 1 && Open[20] == 1)
		{
			Bingo[11] = true;
		}

		//���� �迭 true �� ���� ��ŭ BingoCount �� ����
		for (int i = 0; i < 12; i++)
		{
			if (Bingo[i] == 1)
				BingoCount++;
		}
	}
	return 0;
}