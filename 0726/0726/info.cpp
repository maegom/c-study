#include "info.h" 

//��ȣ ����
void SaveNum(int* Number)
{
    //��ȣ ����
    for (int i = 0; i < 25; i++)
    {
        Number[i] = i + 1; // 1�� ���� ����
    }
}

//��ȣ ����
void Shuffle(int* Number)
{
    //���� ī�带 �����ϰ� ���´�.
    for (int i = 0; i < 100; ++i)
    {
        int   Index1 = rand() % 25;
        int   Index2 = rand() % 25;

        int   Temp = Number[Index1];
        Number[Index1] = Number[Index2];
        Number[Index2] = Temp;
    }
}
//������ ���
void PrintBingoBoard(int* Number) {

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
}

//�Է��� ���ڿ� * ���
void PrintStar(int* Number, int Input) {

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
}

//���� ����� üũ
void BingoCheck(int* Number, int* BingoCount) {

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
            ++*BingoCount;

        //���� ����
        if (CheckCount1 == 5)
            ++*BingoCount;
    }
    //�밢�� ���� üũ
       // ���ʻ��->�������ϴ� �밢��
    int CheckCount3 = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (Number[i * 6] == INT_MAX)
            ++CheckCount3;
    }

    if (CheckCount3 == 5)
        ++BingoCount;

    // ������ ��� -> ���� �ϴ� �밢��
    int CheckCount4 = 0;

    for (int i = 1; i <= 5; ++i)
    {
        if (Number[i * 4] == INT_MAX)
            ++CheckCount4;
    }

    if (CheckCount4 == 5)
        ++BingoCount;
}