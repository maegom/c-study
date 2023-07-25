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
	srand((unsigned int)time(0));  //����ȯ : (��ȯ�� Ÿ��) �� ���·� ����ϸ�, � ���̳� ������ �����ϴ� Ÿ������ �Ͻ������� �νĽ�����
	rand();

	int PlayerWinCount = 0, AiWinCount = 0;


	while (true) {

		system("cls"); // �ܼ�â �����

		std::cout << "������ ���� �����Ͻÿ�!\n" << std::endl;
		std::cout << "1.����" << std::endl;
		std::cout << "2.����" << std::endl;
		std::cout << "3.��" << std::endl;
		std::cout << "4.����\n" << std::endl;

		std::cout << "PlayerWin : " << PlayerWinCount << std::endl;
		std::cout << "AiWin	: " << AiWinCount << std::endl;



		int player;
		int AI;

		std::cin >> player;
		if (player < 1 || player >4) //(player < 1 || player >4)
			continue;
		else if (player == 4)
			break;

		AI = rand() % 3 + 1;

		system("cls"); // �ܼ�â �����

		switch (AI)
		{
		case SISSOR:	std::cout << "\nAI �� ������ �½��ϴ�.\n" << std::endl;  		break;
		case ROCK:	std::cout << "\nAI �� ������ �½��ϴ�.\n" << std::endl;	 		break;
		case PAPER:	std::cout << "\nAI �� ���� �½��ϴ�.\n" << std::endl;	  		break;
		}

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