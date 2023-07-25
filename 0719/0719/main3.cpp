#include <iostream> 
#include <time.h>

//���������� ����

enum SRP   //������������ ��ȣ�� �ƴ� ���������� �������� ������ ���
{
	SISSOR = 1,  //�����Ȱ� �������� +1
	ROCK,
	PAPER
};

int main()
{
	//���� ����
	srand((unsigned int)time(0));
	rand();

	//���� ����̰������ ���� ���� ����
	int PlayerWinCount = 0, AiWinCount = 0;

	//���������� ���� �ݺ�
	while (true) {

		system("cls"); // �ܼ�â �����

		std::cout << "������ ���� �����Ͻÿ�!\n" << std::endl;
		std::cout << "1.����" << std::endl;
		std::cout << "2.����" << std::endl;
		std::cout << "3.��" << std::endl;
		std::cout << "4.����\n" << std::endl;

		std::cout << "PlayerWin : " << PlayerWinCount << std::endl;  //�÷��̾� �̱� �� ���
		std::cout << "AiWin	: " << AiWinCount << std::endl;			//AI�� �̱� �� ���

		//�÷��̾�, AI ���´���?
		int player;
		int AI;

		std::cin >> player; //�÷��̾� �Է�

		//���� ó��
		if (player < 1 || player >4) //�ٸ��� �Է½� �ٽ� �Է�
			continue;
		else if (player == 4)  //4�� �Է½� ��������
			break;

		//���� �̿��Ͽ� ���� ���������� ����
		AI = rand() % 3 + 1;

		system("cls"); // �ܼ�â �����

		//AI �� ���� �Ǿ����� ���
		switch (AI)
		{
		case SISSOR:	std::cout << "\nAI �� ������ �½��ϴ�.\n" << std::endl;  		break;
		case ROCK:	std::cout << "\nAI �� ������ �½��ϴ�.\n" << std::endl;	 		break;
		case PAPER:	std::cout << "\nAI �� ���� �½��ϴ�.\n" << std::endl;	  		break;
		}

		//�÷��̾�� AI ���� ��
		if (player == AI)
			std::cout << "�����ϴ�.\n" << std::endl;
		else if (player == SISSOR && AI == PAPER || player == ROCK && AI == SISSOR || player == PAPER && AI == ROCK)
		{
			std::cout << "����� �̰���ϴ�.\n" << std::endl;
			++PlayerWinCount;
		}
		else
		{
			std::cout << "����� �����ϴ�.\n" << std::endl;
			++AiWinCount;
		}
		std::cout << "\n\nPlayerWin : " << PlayerWinCount << std::endl;
		std::cout << "AiWin	: " << AiWinCount << std::endl;

		system("pause"); //�ܼ�â �Ͻ�����
	}
	return 0;
}