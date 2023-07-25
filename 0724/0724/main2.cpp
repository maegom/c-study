
#include <iostream>

/*
�Լ� : ���ϴ� ����� ������ �� �ְ� ������ִ� ����̴�.

��ȯŸ�� �Լ��̸�(����)
{
   ���۽�ų �ڵ�
}

��ȯŸ�� : �Լ��� ������ �����ϰ� ������� �ǵ������ �� ��� �ǵ����ִ� ����
Ÿ�Կ� ���� �����ش�. void�� �ϸ� ��ȯ�� ���ٴ� �ǹ��̰� int�� �ϸ� �� �Լ���
������ ��ȯ���شٴ� �ǹ̰� �ȴ�.

�Լ��̸� : ���ϴ� �̸����� �ۼ��Ѵ�.

�Լ��� ȣ�� : ���ϴ� ������ �Լ��� �ڵ带 ���۽�Ű���� �Ҷ� ȣ���Ѵٰ� �Ѵ�.

���� : �Լ��� ȣ���� �� ȣ���ϴ� ������ �Լ��� � ���� �Ѱ���� �Ѵٸ�
���ڸ� ����ϰ� �׷� �ʿ䰡 ���� ��� ����д�.
�������� ������ ���� ��� ������ ���ϴ� ����ŭ ����� �����ϴ�.
*/
// �Ʒ� �Լ��� ��ȯŸ���� int�̱� ������ �ݵ�� �� �Լ��� ������ ����� ������
// ��ȯ���־�� �Ѵ�. ��ȯ�� return Ű���带 �̿��ؼ� ��ȯ�Ѵ�.
// ���ڴ� 2���� ����ϰ� �ִ�. intŸ�� ���� 2���� ���� �ִ�.
// call by value : ����Ÿ���� �̿��ؼ� ������� ��ȯ���ִ� ����.
// call by address : �Լ��� ���ڿ� �����͸� �־ ����� �������� ��ȯ���ִ� ����.
// call by Reference : 

/*
Ư�� �ڵ��� �ȿ� �� �ִ� ������ ����������� �Ѵ�.
�Լ��� ���ڵ� ���������̴�.
�ڵ��� �ȿ� ���� ������ ����������� �Ѵ�.
���������� ���������� �ѹ� �޸𸮰� �Ҵ��� �Ǹ� ���α׷��� ����ɶ� �޸𸮰�
���ŵȴ�.

�޸� ����
stack : ���������� �Ҵ�Ǵ� �����̴�.
data : �������� Ȥ�� ���������� �Ҵ�Ǵ� �����̴�.
code : ���������� �����Ҷ� ���������� �����ϰ� �ִ� ���̳ʸ��ڵ带
�Ͻ������� �����ϱ� ���� ����.
heap : �����Ҵ�� �޸𸮰� �Ҵ�Ǵ� �����̴�.
*/
int   gNumber = 500;

int Sum(int Number1, int Number2)
{
    // static : ���� ������ ������ִ� Ű�����̴�.
    // ���������� static�� �ٿ��ָ� �ش� ������ ���������� �ȴ�.
    int   Number3 = 300;
    ++Number3;
    std::cout << "Number3 : " << Number3 << std::endl;

    static int   Number4 = 300;
    ++Number4;
    std::cout << "Number4 : " << Number4 << std::endl;

    gNumber = 100;

    return Number1 + Number2;
}

void ChangeNumber(int Number)
{
    Number = 10120;
}

void ChangeNumber1(int* Number)
{
    *Number = 101110;
}

void ChangeNumber1(int* Number1, int* Number2)
{
    *Number1 = 101110;
    *Number2 = 22210;
}

void SetNumber(int* Array)
{
    for (int i = 0; i < 25; ++i)
    {
        Array[i] = i + 1;
    }
}

int main()
{
    // �Լ��� ȣ�� : �Լ��� ����̶� ���ϴ� ������ ȣ���� �����ϴ�.
    // int Sum(int Number1, int Number2) �� �Լ��� �Ʒ����� ȣ�������.
    // �Լ��� ���ڴ� int Ÿ�� ���� 2���� �ְ� Number1���� 100, Number2����
    // 200�� �־ ȣ�����־���.
    int Number = Sum(100, 200);

    std::cout << Number << std::endl;
    std::cout << Sum(500, 600) << std::endl;

    std::cout << gNumber << std::endl;

    ChangeNumber(Number);

    std::cout << Number << std::endl;

    ChangeNumber1(&Number);

    std::cout << Number << std::endl;

    int   Number1[25] = {};

    SetNumber(Number1);

    for (int i = 0; i < 25; ++i)
    {
        std::cout << Number1[i] << std::endl;
    }

    return 0;
}