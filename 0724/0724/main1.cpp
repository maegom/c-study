
#include <iostream>

struct TestStr
{

};

struct Player
{
    char   Name[32];
    char   Test1;
    char   Test2;
    int      Option1;
    char   Test3;
    int      Option2;
    int      Option3;
};

int main()
{
    /*
    ��� ������ �����ϸ� �޸𸮿� ������ ��������� �����͸� �����ϰ� �ȴ�.
    �޸� �ּҴ� 16������ ǥ���� �ȴ�.
    �޸� �ּҴ� 32��Ʈ �ý��ۿ����� 4����Ʈ, 64��Ʈ �ý��ۿ����� 8����Ʈ�� ����Ѵ�.

    ������ : �޸� �ּҸ� �����ϱ� ���� �����̴�.
    ��� ���� Ÿ���� ������ Ÿ���� ���� �� �ִ�.
    int������ �޸� �ּҴ� int�� ������Ÿ�� ������ ������ �ϰ�
    float ������ �޸� �ּҴ� float�� ������ Ÿ�� ������ ������ �Ѵ�.

    ������ ������ ũ��� x86�̸� 4����Ʈ x64�� 8����Ʈ�̴�.
    ��, 16������ ǥ���ǹǷ� x86������ 16���� 8�ڸ�, x64������ 16���� 16�ڸ��� �����ȴ�.

    ����Ÿ��* �����͸�;

    ���� �տ� & �� ���̸� �ش� ������ �޸� �ּҰ� �ȴ�.

    ������ ������ �ʱ�ȭ�� ���� ��� �����Ⱚ�� �� �ִ�.
    �׷��Ƿ� ������ ������ ����� ���� �ݵ�� 0 Ȥ�� NULL Ȥ�� nullptr��
    �ʱ�ȭ�ϰ� ����ϴ� ���� ����.
    0, NULL�� C���� �ַ� ����ϴ� ����̰� C++������ nullptr�� �ʱ�ȭ�Ѵ�.
    nullptr�� �ʱ�ȭ �ϸ� 0���� �ʱ�ȭ�ȴ�.
    */
    int   Number = 100;

    // �Ʒ��� int ������ Ÿ�� ������ NumberAddr �� �����ϰ� Number�� �޸� �ּҸ�
    // NumberAddr ������ ������ �������־���.
    int* NumberAddr = &Number;

    /*
    ������ ������ �ٸ� ������ �޸� �ּҸ� �����ϰ� �ִٸ� �ش� �޸� �ּҸ� ����
    �ϰ� �ִ� ��� ǥ���Ѵ�.

    ������ ������ �ٸ� ������ �޸� �ּҰ� ����Ǿ� ���� ��� �������� ���ؼ� �ش�
    �޸� �ּҿ� �����Ͽ� �ű⿡ �ִ� ���� �����ų� ������ �� �ִ�.
    ������ ������ Ÿ�Կ� �´� �ּҸ� �����ϰ� �Ǿ� �ִ� ���̴�.
    int ������ ��� �����̱� ������ �������� ������ ó���ϰ� float �����Ͷ�� �Ǽ��̱�
    ������ �������� �Ǽ��� ó���ϴ� ����̴�.

    *�����͸� �� �ϸ� �����Ͱ� ������ �ִ� �޸� �ּҿ� �������� �����Ѵ�.
    */
    // �Ʒ��� ���� �������� �����Ͽ� 500�� ������ NumberAddr�� Number������ �޸� �ּҸ�
    // �����ϰ� �����Ƿ� Number�� 500�� �־��ִ� �Ͱ� ����.
    * NumberAddr = 500;

    std::cout << "Number = " << Number << std::endl;
    std::cout << "Number Address = " << &Number << std::endl;
    std::cout << "NumberAddr = " << NumberAddr << std::endl;
    std::cout << "NumberAddr Address = " << &NumberAddr << std::endl;

    /*
    �迭�� �������� ����
    �迭�̸��� �ش� �迭�� ���� �޸� �ּ��̴�.
    ��, �迭�� 0���ε����� �޸� �ּҶ�� �ǹ��̴�.
    �� �ּҴ� intŸ���� �ּ��̹Ƿ�  int�� ������ Ÿ�� ������ �޸� �ּҸ�
    ������ �� �ִ�.

    �迭�� �ε����� �����Ҷ� �迭�̸�[�ε���] �� �����Ѵ�.
    �迭�����ּ�[�ε���] �� �����ϴ� ���̴�.
    ���� �����ͺ����� �迭�� �޸� �ּҸ� ������ ���� ��� ���� ������� �ε��� ����
    �� �����ϴ�.

    int Array[100] = { 1, 2, 3, 4, 5 };
    int* ArrayAddr = Array;

    ���� ���� ����Ǿ��ٸ� ArrayAddr�� �迭�� �����ּҸ� ������ �����Ƿ� �� ������
    ������ �̿��ؼ� �迭�� �� ��ҿ� Array�� �̿��ؼ� �����ϴ� �Ͱ� ���� ������ �� �ִ�.
    */
    int   Array[100] = { 1, 2, 3, 4, 5 };
    int* ArrayAddr = Array;

    std::cout << "Array Start Address = " << Array << std::endl;
    std::cout << "ArrayAddr = " << ArrayAddr << std::endl;

    ArrayAddr[0] = 1010;

    std::cout << "Array[0] = " << Array[0] << std::endl;
    std::cout << "Array[1] = " << Array[1] << std::endl;

    std::cout << "ArrayAddr[0] = " << ArrayAddr[0] << std::endl;
    std::cout << "ArrayAddr[1] = " << ArrayAddr[1] << std::endl;

    /*
    void : Ÿ���� ���ٴ� �ǹ��̴�.
    Ÿ���� ���� ������ void Ÿ���� �Ϲ� ������ ����� �� ����.
    ������ ������ Ÿ���� ������ �����ϴ�.
    void* Addr1 = nullptr;

    void �����ʹ� � Ÿ���� �޸� �ּҶ� ��� ������ �����ϴ�.
    ��, Ÿ���� ���� ������ �������� �Ұ����ϴ�.
    */
    float   Number1 = 3.14f;

    // intŸ���� �޸� �ּҸ� �����ߴ�.
    void* voidAddr = &Number;

    //*((float*)voidAddr) = 5.32f;

    std::cout << Number << std::endl;

    /*
    �����ʹ� +, - 2���� ������ �����Ѵ�.

    1�� ���ϸ� �ܼ��� �޸��ּҰ� 1 �����ϴ� ���� �ƴ� Ÿ���� ũ�⸸ŭ �����Ѵ�.
    int �����Ͷ�� int�� ũ���� 4��ŭ �����ϴ� ���̴�.
    2�� ���ϸ� 8��ŭ �����ϰ� �� ���̴�.
    */

    std::cout << "Array Start Address = " << Array << std::endl;
    std::cout << "ArrayAddr = " << ArrayAddr << std::endl;
    std::cout << "ArrayAddr + 1 = " << ArrayAddr + 1 << std::endl;
    std::cout << "ArrayAddr + 2 = " << ArrayAddr + 2 << std::endl;

    std::cout << "Array[0] Address = " << &Array[0] << std::endl;
    std::cout << "Array[1] Address = " << &Array[1] << std::endl;
    std::cout << "Array[2] Address = " << &Array[2] << std::endl;


    std::cout << "Array[0] = " << Array[0] << std::endl;
    std::cout << "Array[1] = " << Array[1] << std::endl;
    std::cout << "Array[2] = " << Array[2] << std::endl;
    std::cout << "*(ArrayAddr + 0) = " << *(ArrayAddr + 0) << std::endl;
    std::cout << "*(ArrayAddr + 1) = " << *(ArrayAddr + 1) << std::endl;
    std::cout << "*(ArrayAddr + 2) = " << *(ArrayAddr + 2) << std::endl;

    /*
    �����ͺ����� const�� ���̴� ����� 3������ �ִ�.
    ����Ÿ�� ��, ��, �Ѵ� 3������ �ִ�.
    const int* Addr;
    int* const Addr;
    const int* const Addr;
    */
    int   Number2 = 300;

    // const �� �տ� ���� ��� �����ϴ� ��� �޸��ּҴ� ������ ����������
    // �����ϴ� ����� ���� ������ �� ����.
    const int* Addr1 = &Number;
    Addr1 = &Number2;

    //*Addr1 = 500;

    // const�� Ÿ���� ��(������)�� ���� ��� �����ϴ� ��� �޸��ּҸ� ������ �� ����.
    int* const Addr2 = &Number;
    //Addr2 = &Number2;
    *Addr2 = 500;

    // const�� �յڷ� ��� �پ��ִٸ� ���� 2���� Ư���� ��� ������ �ȴ�.
    // �����ϴ� ��� ������ �� ���� �����ϴ� ����� ���� ������ �� ����.
    const int* const Addr3 = &Number;
    //Addr3 = &Number2;
    //*Addr3 = 500;


    /*
    ���������� : ������ ������ �޸� �ּҸ� ��Ƴ��� ���� �����̴�.
    int**
    */
    int** NumberAddr2 = &NumberAddr;

    int   Number4 = 5030;

    *NumberAddr2 = &Number4;
    **NumberAddr2 = 400;

    std::cout << Number4 << std::endl;

    /*
    �����Ҵ� : �������� �޸𸮸� �Ҵ��ϴ� ����̴�.
    ���α׷��� ���۵ɶ� ������ �޸𸮰� �����Ǵ� ���� �ƴ϶�
    ���α׷��Ӱ� �ʿ��� ��Ȳ�� �Ǹ� �޸𸮸� �����ϰ� ���̻� �ʿ䰡 ���ٸ�
    �޸𸮿��� �������ִ� ����̴�.
    new�� delete�� ���ؼ� �����ȴ�.
    new : �޸𸮸� �������� �����ϰ� �� �޸��ּҸ� ��ȯ���ش�.
    delete : new�� �̿��ؼ� ������ �޸𸮴� �ݵ�� delete�� �̿��ؼ� ��������� �Ѵ�.
    ���� new�� ������ �޸𸮸� ������ �ʰ� �׳� �Ѿ�ٸ� �ش� �޸𸮴� ���̻� �����
    �� �� ������ ����ؼ� ������ ������� �ְ� �ȴ�.
    �̷��� new�� ������ �޸𸮸� delete�� �̿��� ������ �ʴ� ��� �޸� ���̶�� �Ѵ�.

    �̹� ������ �޸� �ּҸ� ������ �ִ� �����ͺ����� ��۸� �����Ͷ�� �Ѵ�.
    ��۸� �����ʹ� �������� �� ��� ������ �߻��Ѵ�.

    new ���ϴ� Ÿ��; �� �ϸ� ������ Ÿ���� �޸� ũ�⸸ŭ ������ ������ְ�
    �� �ּҸ� ��ȯ�Ѵ�.
    */
    std::cout << sizeof(Player) << std::endl;
    std::cout << sizeof(TestStr) << std::endl;

    // Player�� ũ���� 52����Ʈ ��ŭ �޸𸮿� ������ ������ְ� �� �ּҸ� ��ȯ�Ѵ�.
    // ���� �� �ּҸ� ������ ���� ���� ��� �޸𸮸� ������ �� ����.
    Player* player = new Player;

    delete player;

    // .�� *(������)���� ������ �켱������ ���� ������ �������� ��ȣ�� �����ش�.
    //*player.
    (*player).Option1 = 1020;


    // �����Ҵ����� �迭�� �����.
    int* DynamicArray = new int[100];

    delete[] DynamicArray;

    return 0;
}