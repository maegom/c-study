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


// ���°� �ٽ�
//#include <iostream>
//#include <time.h>
//
///*
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 0
//0 0 0 0 *
//
//0���� ǥ�õ� �κп� 1 ~ 24 ������ ���ڸ� ��� ����Ѵ�.
//�÷��̾�� * ǥ�ø� �������� �� �ִ�.
//w : ���� �̵� s : �Ʒ��� �̵� a : ���� �̵� d : ������ �̵� q : ����
//
//�̵� Ű�� ������ �ش� ���⿡ �ִ� ���� *�� ��ġ�� �������ְ� ���ڰ� ���� ������
//���ʴ�� 1 ~ 24 ���� ������ ������ �����Ѵ�.
//*/
//
//int main()
//{
//    srand((unsigned int)time(0));
//    rand();
//
//    int Number[25] = {};
//
//    for (int i = 0; i < 24; i++)
//    {
//        Number[i] = i;
//    }
//    Number[24] = INT_MAX;
//
//    for (int i = 0; i < 1000; i++)
//    {
//        int Index1 = rand() % 25;
//        int Case = rand() % 4 + 1;
//
//        int Temp = Number[Index1];
//        switch (Case)
//        {
//        case 1: //��
//            if (Index1 < 5)
//                break;
//            else {
//                Number[Index1] = Number[Index1 - 5];
//                Number[Index1 - 5] = Temp;
//                break;
//            }
//
//
//        case 2: //��
//            if (Index1 % 5 == 0)
//                break;
//            else {
//                Number[Index1] = Number[Index1 - 1];
//                Number[Index1 - 1] = Temp;
//                break;
//
//            }
//
//
//        case 3: //�Ʒ�
//            if (Index1 >= 20)
//                break;
//            else {
//                Number[Index1] = Number[Index1 + 5];
//                Number[Index1 + 5] = Temp;
//                break;
//            }
//
//        case 4: //��
//            if (Index1 % 5 == 4)
//                break;
//            else
//            {
//                Number[Index1] = Number[Index1 + 1];
//                Number[Index1 + 1] = Temp;
//                break;
//            }
//
//        }
//
//
//    }
//
//    int Location = 0; // * ��ġ    
//
//    while (true)
//    {
//        system("cls");
//        for (int i = 0; i < 5; i++)
//        {
//            for (int j = 0; j < 5; j++)
//            {
//                int Index = i * 5 + j;
//
//                if (Number[Index] == INT_MAX)
//                {
//                    std::cout << "*" << "\t";
//                    Location = Index;
//
//                }
//                else {
//                    std::cout << Number[Index] << "\t";
//                }
//
//            }
//            std::cout << std::endl;
//            std::cout << std::endl;
//        }
//        char Input = 0;
//        std::cout << "    ^(w) " << std::endl;
//        std::cout << "<(a)v(s)>(d) " << std::endl << std::endl;
//        std::cout << "������ ������ �Է��Ͻÿ�! ";
//
//        std::cin >> Input;
//
//        if (Input == 'q')
//            break;
//        else if (Input == 'w')
//        {
//            if (Location < 5)
//                continue;
//            else
//            {
//                int Temp = Number[Location];
//                Number[Location] = Number[Location - 5];
//                Number[Location - 5] = Temp;
//            }
//        }
//        else if (Input == 'a')
//        {
//            if (Location % 5 == 0)
//                continue;
//            else {
//                int Temp = Number[Location];
//                Number[Location] = Number[Location - 1];
//                Number[Location - 1] = Temp;
//            }
//        }
//        else if (Input == 's')
//        {
//            if (Location >= 20)
//                continue;
//            int Temp = Number[Location];
//            Number[Location] = Number[Location + 5];
//            Number[Location + 5] = Temp;
//        }
//        else if (Input == 'd')
//        {
//            if (Location % 5 == 4)
//                continue;
//            int Temp = Number[Location];
//            Number[Location] = Number[Location + 1];
//            Number[Location + 1] = Temp;
//        }
//        system("pause");
//
//        int Check = 0;
//        for (int i = 0; i < 25; i++)
//        {
//            if (Number[i] == i)
//            {
//                Check++;
//            }
//        }
//        if (Check == 24)
//        {
//            std::cout << "�ϼ��Ͽ����ϴ�!! ";
//            break;
//        }
//
//    }
//    return 0;
//}
