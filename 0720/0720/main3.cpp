#include <iostream>
#include <time.h>

//¦ ���߱� ����
// 
// ������ Ư������ 2���� �� 10���� �����.
// 20���� �迭�� �ʿ��ϴ�.
// 20���� �迭�� ���� 5�� ���� 4�ٷ� ����ϰ�
// �������� ���¸� ǥ���ϱ� ���ؼ� ��ȣ�� �ο��Ͽ� ����Ѵ�.
int main()
{
	//���� ����
	srand((unsigned int)time(0));
	rand();

	//������� ���� 
	char   Card[20] = {};  // ī��� �������
	bool   Open[20] = {};  // ���ȴ��� �Ǵ�
	char   CardSet[10] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')' }; //Ư������ ��

	//Card[] �迭�� Ư������ ������ ����
	for (int i = 0; i < 10; i++)
	{
		Card[i] = CardSet[i];
		Card[i + 10] = CardSet[i];
	}

	//Card[]  �迭 ����
	for (int i = 0; i < 100; i++)
	{
		int Index1 = rand() % 20; //���� �߻�
		int Index2 = rand() % 20;

		char temp = Card[Index1]; //���� �˰���
		Card[Index1] = Card[Index2];
		Card[Index2] = temp;
	}

	int   Input = -1; //�Է°�
	int   PrevInput = -1; //���� �Է°��� ������ ����
	bool   Check = false; //2���� ���������� true, �׶� �� ��

	while (true)
	{
		system("cls"); //ȭ�� ����
		//i�� ������ ��ȣ, j�� �����ٹ�ȣ.
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				//�ε��� ���� : ���ι�ȣ * ���ΰ��� + ���ι�ȣ (1���� �迭�� 2����ó�� ���)
				int Index = i * 5 + j;

				//ī�尡 ���������� Ư������ ���, ī�尡 ���� ������ �ش� Index ���.
				if (Open[Index])
					std::cout << Card[Index] << "\t";
				else
				{
					std::cout << Index << "\t";
				}
			}
			std::cout << "\n";
		}

		//PrevInput, Input ��° ���� ��
		if (Check)
		{
			if (Card[PrevInput] != Card[Input]) //�ٸ��� 
			{
				Open[PrevInput] = false;  //�Ѵ� �ݰ� (Ư������ ���� ���ڷ� ǥ��)
				Open[Input] = false;
			}
			PrevInput = -1; //PrevInput�� ����� �� ����ְ� 
			Check = false;  //check �� ���� �ʾƵ� �ǰ� 
			system("pause"); //2��° �� Ư�����ڸ� Ȯ���ϱ� ���� �����ش�.
			continue; //while�� �ٽ� ����
		}

		// ������ ī�� �Է�
		std::cout << "������ ���ڸ� �Է��Ͻÿ�(-1�� ����) : ";
		std::cin >> Input;

		//�Է°� ����ó��
		if (Input == -1) //-1�϶� ����
			break;

		else if (Input < -1 || Input>19) //�׿ܰ� �Է½� �ٽ� �Է�
			continue;

		else if (Open[Input]) //�̹� �����ִ� �� ���ý� �ٽ� �Է�
			continue;

		//����� �Է½� ����
		Open[Input] = true;  //�����ϰ�

		//������ �ΰ� ������ �� ���ϱ� ����
		if (PrevInput == -1)  //(ù��° �Է�)PrevInput�� -1�� ��������� �װ��� �Է°�(Input) ����
			PrevInput = Input;
		else				 //(�ι�° �Է�)PrevInput���� ����Ǿ������� ���� ���ϱ����Ͽ� check�� true �� ����
			Check = true;
	}
	return 0;
}