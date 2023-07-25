
#include <iostream>

/*
함수 : 원하는 기능을 동작할 수 있게 만들어주는 기능이다.

반환타입 함수이름(인자)
{
   동작시킬 코드
}

반환타입 : 함수가 동작을 수행하고 결과값을 되돌려줘야 할 경우 되돌려주는 값의
타입에 따라 정해준다. void를 하면 반환이 없다는 의미이고 int를 하면 이 함수는
정수를 반환해준다는 의미가 된다.

함수이름 : 원하는 이름으로 작성한다.

함수의 호출 : 원하는 곳에서 함수의 코드를 동작시키고자 할때 호출한다고 한다.

인자 : 함수를 호출할 때 호출하는 곳에서 함수로 어떤 값을 넘겨줘야 한다면
인자를 사용하고 그럴 필요가 없을 경우 비워둔다.
없을수도 있지만 있을 경우 개수는 원하는 수만큼 사용이 가능하다.
*/
// 아래 함수는 반환타입이 int이기 때문에 반드시 이 함수를 수행한 결과로 정수를
// 반환해주어야 한다. 반환은 return 키워드를 이용해서 반환한다.
// 인자는 2개를 사용하고 있다. int타입 인자 2개를 쓰고 있다.
// call by value : 리턴타입을 이용해서 결과값을 반환해주는 형태.
// call by address : 함수의 인자에 포인터를 주어서 결과를 역참조로 반환해주는 형태.
// call by Reference : 

/*
특정 코드블록 안에 들어가 있는 변수를 지역변수라고 한다.
함수의 인자도 지역변수이다.
코드블록 안에 없는 변수를 전역변수라고 한다.
전역변수와 정적변수는 한번 메모리가 할당이 되면 프로그램이 종료될때 메모리가
제거된다.

메모리 영역
stack : 지역변수가 할당되는 영역이다.
data : 정적변수 혹은 전역변수가 할당되는 영역이다.
code : 실행파일을 실행할때 실행파일을 구성하고 있는 바이너리코드를
일시적으로 저장하기 위한 공간.
heap : 동적할당된 메모리가 할당되는 공간이다.
*/
int   gNumber = 500;

int Sum(int Number1, int Number2)
{
    // static : 정적 변수를 만들어주는 키워드이다.
    // 지역변수에 static을 붙여주면 해당 변수는 정적변수가 된다.
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
    // 함수의 호출 : 함수는 몇번이라도 원하는 곳에서 호출이 가능하다.
    // int Sum(int Number1, int Number2) 이 함수를 아래에서 호출해줬다.
    // 함수의 인자는 int 타입 변수 2개가 있고 Number1에는 100, Number2에는
    // 200을 넣어서 호출해주었다.
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