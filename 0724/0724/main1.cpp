
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
    모든 변수는 선언하면 메모리에 공간이 만들어지고 데이터를 저장하게 된다.
    메모리 주소는 16진수로 표현이 된다.
    메모리 주소는 32비트 시스템에서는 4바이트, 64비트 시스템에서는 8바이트를 사용한다.

    포인터 : 메모리 주소를 저장하기 위한 변수이다.
    모든 변수 타입은 포인터 타입을 가질 수 있다.
    int변수의 메모리 주소는 int의 포인터타입 변수에 저장을 하고
    float 변수의 메모리 주소는 float의 포인터 타입 변수에 저장을 한다.

    포인터 변수의 크기는 x86이면 4바이트 x64는 8바이트이다.
    즉, 16진수로 표현되므로 x86에서는 16진수 8자리, x64에서는 16진수 16자리로 구성된다.

    변수타입* 포인터명;

    변수 앞에 & 을 붙이면 해당 변수의 메모리 주소가 된다.

    포인터 변수도 초기화가 없을 경우 쓰레기값이 들어가 있다.
    그러므로 포인터 변수를 사용할 때는 반드시 0 혹은 NULL 혹은 nullptr로
    초기화하고 사용하는 것이 좋다.
    0, NULL은 C언어에서 주로 사용하던 방식이고 C++에서는 nullptr로 초기화한다.
    nullptr로 초기화 하면 0으로 초기화된다.
    */
    int   Number = 100;

    // 아래는 int 포인터 타입 변수인 NumberAddr 을 선언하고 Number의 메모리 주소를
    // NumberAddr 변수의 값으로 대입해주었다.
    int* NumberAddr = &Number;

    /*
    포인터 변수가 다른 변수의 메모리 주소를 저장하고 있다면 해당 메모리 주소를 참조
    하고 있다 라고 표현한다.

    포인터 변수에 다른 변수의 메모리 주소가 저장되어 있을 경우 역참조를 통해서 해당
    메모리 주소에 접근하여 거기에 있는 값을 얻어오거나 변경할 수 있다.
    역참조 때문에 타입에 맞는 주소를 저장하게 되어 있는 것이다.
    int 포인터 라면 정수이기 때문에 역참조로 정수를 처리하고 float 포인터라면 실수이기
    때문에 역참조로 실수를 처리하는 방식이다.

    *포인터명 을 하면 포인터가 가지고 있는 메모리 주소에 역참조를 수행한다.
    */
    // 아래와 같이 역참조로 접근하여 500을 넣으면 NumberAddr은 Number변수의 메모리 주소를
    // 저장하고 있으므로 Number에 500을 넣어주는 것과 같다.
    * NumberAddr = 500;

    std::cout << "Number = " << Number << std::endl;
    std::cout << "Number Address = " << &Number << std::endl;
    std::cout << "NumberAddr = " << NumberAddr << std::endl;
    std::cout << "NumberAddr Address = " << &NumberAddr << std::endl;

    /*
    배열과 포인터의 관계
    배열이름은 해당 배열의 시작 메모리 주소이다.
    즉, 배열의 0번인덱스의 메모리 주소라는 의미이다.
    이 주소는 int타입의 주소이므로  int의 포인터 타입 변수에 메모리 주소를
    저장할 수 있다.

    배열의 인덱스에 접근할때 배열이름[인덱스] 로 접근한다.
    배열시작주소[인덱스] 로 접근하는 것이다.
    만약 포인터변수가 배열의 메모리 주소를 가지고 있을 경우 같은 방법으로 인덱스 접근
    이 가능하다.

    int Array[100] = { 1, 2, 3, 4, 5 };
    int* ArrayAddr = Array;

    위와 같이 선언되었다면 ArrayAddr는 배열의 시작주소를 가지고 있으므로 이 포인터
    변수를 이용해서 배열의 각 요소에 Array를 이용해서 접근하는 것과 같이 접근할 수 있다.
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
    void : 타입이 없다는 의미이다.
    타입이 없기 때문에 void 타입의 일반 변수는 사용할 수 없다.
    하지만 포인터 타입은 선언이 가능하다.
    void* Addr1 = nullptr;

    void 포인터는 어떤 타입의 메모리 주소라도 모두 저장이 가능하다.
    단, 타입이 없기 때문에 역참조는 불가능하다.
    */
    float   Number1 = 3.14f;

    // int타입의 메모리 주소를 저장했다.
    void* voidAddr = &Number;

    //*((float*)voidAddr) = 5.32f;

    std::cout << Number << std::endl;

    /*
    포인터는 +, - 2가지 연산을 지원한다.

    1을 더하면 단순히 메모리주소가 1 증가하는 것이 아닌 타입의 크기만큼 증가한다.
    int 포인터라면 int의 크기인 4만큼 증가하는 것이다.
    2를 더하면 8만큼 증가하게 될 것이다.
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
    포인터변수에 const를 붙이는 방법은 3가지가 있다.
    변수타입 앞, 뒤, 둘다 3가지가 있다.
    const int* Addr;
    int* const Addr;
    const int* const Addr;
    */
    int   Number2 = 300;

    // const 가 앞에 붙을 경우 참조하는 대상 메모리주소는 변경이 가능하지만
    // 참조하는 대상의 값은 변경할 수 없다.
    const int* Addr1 = &Number;
    Addr1 = &Number2;

    //*Addr1 = 500;

    // const가 타입의 뒤(오른쪽)에 붙을 경우 참조하는 대상 메모리주소를 변경할 수 없다.
    int* const Addr2 = &Number;
    //Addr2 = &Number2;
    *Addr2 = 500;

    // const가 앞뒤로 모두 붙어있다면 위의 2가지 특성을 모두 가지게 된다.
    // 참조하는 대상도 변경할 수 없고 참조하는 대상의 값도 변경할 수 없다.
    const int* const Addr3 = &Number;
    //Addr3 = &Number2;
    //*Addr3 = 500;


    /*
    이중포인터 : 포인터 변수의 메모리 주소를 담아놓기 위한 변수이다.
    int**
    */
    int** NumberAddr2 = &NumberAddr;

    int   Number4 = 5030;

    *NumberAddr2 = &Number4;
    **NumberAddr2 = 400;

    std::cout << Number4 << std::endl;

    /*
    동적할당 : 동적으로 메모리를 할당하는 방법이다.
    프로그램이 동작될때 무조건 메모리가 생성되는 것이 아니라
    프로그래머가 필요한 상황이 되면 메모리를 생성하고 더이상 필요가 없다면
    메모리에서 제거해주는 방식이다.
    new와 delete를 통해서 지원된다.
    new : 메모리를 동적으로 생성하고 그 메모리주소를 반환해준다.
    delete : new를 이용해서 생성한 메모리는 반드시 delete를 이용해서 제거해줘야 한다.
    만약 new로 생성한 메모리를 지우지 않고 그냥 넘어간다면 해당 메모리는 더이상 사용을
    할 수 없지만 계속해서 공간은 만들어져 있게 된다.
    이렇게 new로 생성한 메모리를 delete를 이용해 지우지 않는 경우 메모리 릭이라고 한다.

    이미 지워진 메모리 주소를 가지고 있는 포인터변수를 댕글링 포인터라고 한다.
    댕글링 포인터는 역참조를 할 경우 에러가 발생한다.

    new 원하는 타입; 을 하면 적상한 타입의 메모리 크기만큼 공간을 만들어주고
    그 주소를 반환한다.
    */
    std::cout << sizeof(Player) << std::endl;
    std::cout << sizeof(TestStr) << std::endl;

    // Player의 크기인 52바이트 만큼 메모리에 공간을 만들어주고 그 주소를 반환한다.
    // 만약 그 주소를 가지고 있지 않을 경우 메모리를 해제할 수 없다.
    Player* player = new Player;

    delete player;

    // .이 *(역참조)보다 연산자 우선순위가 높기 때문에 역참조를 괄호로 묶어준다.
    //*player.
    (*player).Option1 = 1020;


    // 동적할당으로 배열을 만든다.
    int* DynamicArray = new int[100];

    delete[] DynamicArray;

    return 0;
}