#include <iostream> 
#include <time.h>

/*
�÷��̾�� ����, ����, ���� �ϳ� ����
AI�� ����
���� �̰���� �Ǵ�.
*/

/*
����ü : ����� �̸��� �ο��ϴ� ����̴�. 
����ü�� �̿��Ͽ� �̸��� �ο��� ����� �����Ǵ� ������ ���� ���� ����� �� �ִ�.

���� 
enum ����ü��
{�̸��ο�} //�̸��� �ο��� ����� 0���� �����ؼ� ���� 1�� �����Ǿ� �����ȴ�.

�������� ����� ����� �̿��� ���� ������ �������� �̸� ��ü�� ������ ��������� ����Ÿ���� �ȴ�.

���������� ���� ������ �ش� �������� ��Ͽ� ������ ���� ������ �� �ִ�. 

�������� ������ 4byte �� ũ�� ����

enumclass �� Ÿ�Կ� ���� �� ����

*/

/*
switch : �б⹮�� �� ���� (�������� ����� �ϳ�)
���� 
switch (�б�ó���ϰ��� �ϴ� ��)
 {
	case üũ�� ��� :  ���۽�ų�ڵ�    break;   //���� �ȵǰ� �� ���  , break �� ������ switch �� ��������.
 }
*/

enum SRP
{
	SISSOR=1,  //�����Ȱ� �������� +1
	ROCK,
	PAPER
};

enum class SRP1 : unsigned char  //�̷��� Ÿ�� ���� ����
{
	SISSOR1 = 1,  //�����Ȱ� �������� +1
	ROCK1,		//2U : unsigned 
	PAPER1
};
int main()
{
	srand((unsigned int)time(0));  //����ȯ : (��ȯ�� Ÿ��) �� ���·� ����ϸ�, � ���̳� ������ �����ϴ� Ÿ������ �Ͻ������� �νĽ�����
	rand();

	std::cout << "������ ���� �����Ͻÿ�!\n" << std::endl;
	std::cout << "1.����" << std::endl;
	std::cout << "2.����" << std::endl;
	std::cout << "3.��\n" << std::endl;

	int player;
	int AI;

	std::cin >> player;
	AI = rand()%3 + 1;

	switch (AI)
	{
	case SISSOR :	std::cout << "AI �� ������ �½��ϴ�.\n" << std::endl;  		break;
	case ROCK	:	std::cout << "AI �� ������ �½��ϴ�.\n" << std::endl;	 		break;
	case PAPER	:	std::cout << "AI �� ���� �½��ϴ�.\n" << std::endl;	  		break;
	}
	
	/*if (AI == SISSOR)
		std::cout << "AI �� ������ �½��ϴ�.\n" << std::endl;
	else if (AI == ROCK)
		std::cout << "AI �� ������ �½��ϴ�.\n" << std::endl;
	else if (AI == PAPER)
		std::cout << "AI �� ���� �½��ϴ�.\n" << std::endl;*/

	SRP srp;
	srp = SISSOR;

	SRP1 srp1;
	srp1 = SRP1::SISSOR1; //enum �� enumclass����
	
	std::cout << "SRT size =" << sizeof(SRP) << std::endl;
	std::cout << "SRT1 size =" << sizeof(SRP1) << std::endl;
	
	if (player == AI)
		std::cout << "�����ϴ�." << std::endl;
	else if (player == SISSOR && AI == PAPER || player == ROCK && AI == SISSOR || player == PAPER && AI == ROCK)
		std::cout << "����� �̰���ϴ�." << std::endl;
	else
		std::cout << "����� �����ϴ�." << std::endl;

	return 0;
}