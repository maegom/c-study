
#include <iostream>
#include <time.h>
#include <Windows.h>

/*
함수 호출규약을 찾아서 한번 보세요.
*/

/*
함수는 반환타입과 인자를 이용해서 형태가 결정된다.
반환타입이 같고 인자의 개수와 타입이 같다면 두 함수는 같은 형태의
함수라고 할 수 있다.
함수의 이름은 함수의 형태와는 관계가 없다.

함수 오버로딩 : 이름은 같지만 인자의 수 혹은 타입이 다른 함수
여러개를 만들 수 있게 해주는 기능이다.

디폴트인자 : 함수의 인자에 기본값을 설정해두는 것이다.
만약 함수를 호출할때 기본값이 있는 인자에 값을 넣어준다면 넣어준 값으로
인자의 값이 설정되고 호출 시 값을 비워둘 경우 기본 인자의 값으로
설정된다.

주의할점
1. 가장 오른쪽부터 기본값을 설정할 수 있다.
2. 오버로딩이 되어 있는 함수에서 사용할 경우 주의가 필요하다.
오버로딩된 함수는 인자의 수와 타입을 이용해서 어떤 함수가 호출되는지
구분하고 있는데 만약 디폴트 인자를 잘못 사용한다면 인자의 수를 이용해서
오버로딩된 함수는 에러가 발생할 수 있다.
*/
// 이 함수는 인자를 int타입 1개만 사용할수도 있고
// int타입 2개를 사용할 수도 있다.
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

// 불가능.
//int Sum(int Num1, int Num2 = 50, int Num3)
//{
//   return Num1 + Num2 + Num3;
//}

// 가능.
//int Sum(int Num1, int Num2 = 30, int Num3 = 50)
//{
//   return Num1 + Num2 + Num3;
//}

/*
재귀함수 : 자기 자신을 호출하는 함수를 말한다.
A함수에서 A함수를 호출하는것을 말한다.
재귀함수 사용시 주의할점
반드시 종료코드가 동작되도록 해야 한다.
함수를 호출하면 스택에 메모리가 쌓이게 되는데 함수를 종료할 수 없게
되고 계속 호출만 된다면 메모리가 부족하게 될것이다.
*/
void Recursion()
{
    //Recursion();
}

__int64 Factorial(__int64 Number)
{
    // 재귀함수가 종료되는 조건.
    if (Number == 1)
        return 1;

    return Number * Factorial(Number - 1);
}

/*
꼬리재귀 : 위의 재귀 함수는 값을 받고 그 값에 연산을 하여 다른 함수에
전달을 한다.
꼬리재귀는 호출이 끝났을때 별다른 일없이 최종 연산된 결과만 바로
반환하게 해주는 방식이다.
*/
__int64 FactorialTail(__int64 Number, __int64 Result = 1)
{
    if (Number == 1)
        return Result;

    return FactorialTail(Number - 1, Number * Result);
}


int main()
{
    // 오버로딩된 함수 구분 방법
    // 1. 함수의 이름으로 우선 구분한다.
    // 2. 인자의 수와 타입을 이용해서 최종 호출할 함수를 결정한다.
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