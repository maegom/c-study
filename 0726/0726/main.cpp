
#include <iostream>
#include <time.h>
#include <Windows.h>

/*
�Լ� ȣ��Ծ��� ã�Ƽ� �ѹ� ������.
*/

/*
�Լ��� ��ȯŸ�԰� ���ڸ� �̿��ؼ� ���°� �����ȴ�.
��ȯŸ���� ���� ������ ������ Ÿ���� ���ٸ� �� �Լ��� ���� ������
�Լ���� �� �� �ִ�.
�Լ��� �̸��� �Լ��� ���¿ʹ� ���谡 ����.

�Լ� �����ε� : �̸��� ������ ������ �� Ȥ�� Ÿ���� �ٸ� �Լ�
�������� ���� �� �ְ� ���ִ� ����̴�.

����Ʈ���� : �Լ��� ���ڿ� �⺻���� �����صδ� ���̴�.
���� �Լ��� ȣ���Ҷ� �⺻���� �ִ� ���ڿ� ���� �־��شٸ� �־��� ������
������ ���� �����ǰ� ȣ�� �� ���� ����� ��� �⺻ ������ ������
�����ȴ�.

��������
1. ���� �����ʺ��� �⺻���� ������ �� �ִ�.
2. �����ε��� �Ǿ� �ִ� �Լ����� ����� ��� ���ǰ� �ʿ��ϴ�.
�����ε��� �Լ��� ������ ���� Ÿ���� �̿��ؼ� � �Լ��� ȣ��Ǵ���
�����ϰ� �ִµ� ���� ����Ʈ ���ڸ� �߸� ����Ѵٸ� ������ ���� �̿��ؼ�
�����ε��� �Լ��� ������ �߻��� �� �ִ�.
*/
// �� �Լ��� ���ڸ� intŸ�� 1���� ����Ҽ��� �ְ�
// intŸ�� 2���� ����� ���� �ִ�.
int Sum(int Num1, int Num2 = 100)
{
    return Num1 + Num2;
}

int Sum(float Num1, int Num2)
{
    return Num1 + Num2;
}

int Sum(int Num1, int Num2, int Num3)
{
    return Num1 + Num2 + Num3;
}

// �Ұ���.
//int Sum(int Num1, int Num2 = 50, int Num3)
//{
//   return Num1 + Num2 + Num3;
//}

// ����.
//int Sum(int Num1, int Num2 = 30, int Num3 = 50)
//{
//   return Num1 + Num2 + Num3;
//}

/*
����Լ� : �ڱ� �ڽ��� ȣ���ϴ� �Լ��� ���Ѵ�.
A�Լ����� A�Լ��� ȣ���ϴ°��� ���Ѵ�.
����Լ� ���� ��������
�ݵ�� �����ڵ尡 ���۵ǵ��� �ؾ� �Ѵ�.
�Լ��� ȣ���ϸ� ���ÿ� �޸𸮰� ���̰� �Ǵµ� �Լ��� ������ �� ����
�ǰ� ��� ȣ�⸸ �ȴٸ� �޸𸮰� �����ϰ� �ɰ��̴�.
*/
void Recursion()
{
    //Recursion();
}

__int64 Factorial(__int64 Number)
{
    // ����Լ��� ����Ǵ� ����.
    if (Number == 1)
        return 1;

    return Number * Factorial(Number - 1);
}

/*
������� : ���� ��� �Լ��� ���� �ް� �� ���� ������ �Ͽ� �ٸ� �Լ���
������ �Ѵ�.
������ʹ� ȣ���� �������� ���ٸ� �Ͼ��� ���� ����� ����� �ٷ�
��ȯ�ϰ� ���ִ� ����̴�.
*/
__int64 FactorialTail(__int64 Number, __int64 Result = 1)
{
    if (Number == 1)
        return Result;

    return FactorialTail(Number - 1, Number * Result);
}


int main()
{
    // �����ε��� �Լ� ���� ���
    // 1. �Լ��� �̸����� �켱 �����Ѵ�.
    // 2. ������ ���� Ÿ���� �̿��ؼ� ���� ȣ���� �Լ��� �����Ѵ�.
    std::cout << Sum(10, 20) << std::endl;
    std::cout << Sum(10, 20, 30) << std::endl;
    std::cout << Sum(10) << std::endl;

    LARGE_INTEGER   time1, time2, second;
    QueryPerformanceFrequency(&second);
    QueryPerformanceCounter(&time1);

    std::cout << second.QuadPart << std::endl;

    std::cout << Factorial(500) << std::endl;

    QueryPerformanceCounter(&time2);

    std::cout <<
        (time2.QuadPart - time1.QuadPart) / (double)second.QuadPart <<
        std::endl;

    QueryPerformanceCounter(&time1);

    std::cout << FactorialTail(500) << std::endl;

    QueryPerformanceCounter(&time2);

    std::cout <<
        (time2.QuadPart - time1.QuadPart) / (double)second.QuadPart <<
        std::endl;

    return 0;
}