#include "info.h"

//�������
int main()
{
    //���� �߻�
    srand((unsigned int)time(0));
    rand();

    //���� ������ ���� ����
    int   Number[25] = {};

    // 0 ~ 24�� �ε����� 1 ~ 25���� ���� ���ʴ�� �־��ش�.
    SaveNum(Number);

    Shuffle(Number);

    //���� ����
    int   Input = 0;  //�Է��� ��
    int   BingoCount = 0; //���� �� üũ

    while (true)
    {
        system("cls"); //ȭ�� ����

        //������ ���
        PrintBingoBoard(Number);

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
        PrintStar(Number, Input);

        //�����ټ� üũ
        BingoCount = 0;    // �Ź� �ʱ�ȭ 
        BingoCheck(Number, &BingoCount);
    }

    return 0;
}