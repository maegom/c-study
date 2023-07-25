
#include <iostream>
#include <time.h>

//�������
int main()
{
    //���� �߻�
    srand((unsigned int)time(0));
    rand();

    //���� ������ ���� ����
    int   Number[25] = {};

    // 0 ~ 24�� �ε����� 1 ~ 25���� ���� ���ʴ�� �־��ش�.
    for (int i = 0; i < 25; ++i)
    {
        Number[i] = i + 1;
    }

    //���� ī�带 �����ϰ� ���´�.
    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 25;
        int   Index2 = rand() % 25;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }

    //���� ����
    int   Input = 0;  //�Է��� ��
    int   BingoCount = 0; //���� �� üũ

    while (true)
    {
        system("cls"); //ȭ�� ����

        //������ ���
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                int   Index = i * 5 + j;

                //���ڰ� INT_MAX �϶� '*' ���
                if (Number[Index] == INT_MAX)
                    std::cout << "*\t";

                //�ƴϸ� �׳� ���� ���
                else
                    std::cout << Number[Index] << "\t";
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
        std::cout << "���� �� : " << BingoCount << std::endl;

        // ������ ī�� ��ȣ �Է� �ޱ�
        std::cout << std::endl << "������ ��ȣ�� �����Ͻÿ�(0:����) : ";
        std::cin >> Input;

        // �Է°� ���� ����
        if (Input == 0) //0�� �Է��ϸ� ����
            break;

        else if (Input < 0 || Input > 25) //��µ� ���� �� �Է��ϸ� ���Է�
            continue;

        // �Է¹��� ���ڸ� �迭���� ã�Ƽ� *�� �ٲ��ش�.
        for (int i = 0; i < 25; ++i)
        {
            // �Է¹��� ���ڿ� ���� ���ڰ� �迭�� ���� ���
            if (Number[i] == Input)
            {
                // INT_MAX�� int������ ǥ���� �� �ִ� ���� ū ���̴�.
                // �� ���� ��� *�� �Ǵ��Ͽ� ����� �� *�� ����Ѵ�.
                Number[i] = INT_MAX;

                // ���ڸ� ã�Ƽ� *�� �ٲ����� ���̻� �˻��� �ʿ䰡
                // ���� ������ for���� ����������.
                break;
            }
        }

        // ���� üũ�ϱ� ���� LineCount�� 0���� �ʱ�ȭ�ϰ�
        // �Ź� 12�� ��� ���Ӱ� üũ�� ���ش�.
        BingoCount = 0;

        int   CheckCount = 0, CheckCount1 = 0;

        for (int i = 0; i < 5; ++i)
        {
            //���� �ʱ�ȭ
            CheckCount = 0;
            CheckCount1 = 0;

            for (int j = 0; j < 5; ++j)
            {
                //������ üũ
                if (Number[i * 5 + j] == INT_MAX)
                    ++CheckCount;

                //������ üũ
                if (Number[j * 5 + i] == INT_MAX)
                    ++CheckCount1;
            }

            //���� ����
            if (CheckCount == 5)
                ++BingoCount;

            //���� ����
            if (CheckCount1 == 5)
                ++BingoCount;
        }

        //�밢�� ���� üũ
        // ���ʻ��->�������ϴ� �밢��
        CheckCount = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (Number[i * 6] == INT_MAX)
                ++CheckCount;
        }

        if (CheckCount == 5)
            ++BingoCount;

        // ������ ��� -> ���� �ϴ� �밢��
        CheckCount = 0;

        for (int i = 1; i <= 5; ++i)
        {
            if (Number[i * 4] == INT_MAX)
                ++CheckCount;
        }

        if (CheckCount == 5)
            ++BingoCount;
    }

    return 0;
}