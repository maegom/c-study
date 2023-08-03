#include <iostream>
#include "Array.h"

/*
템플릿 : 하나의 고정된 타입이 아닌 필요할 때 원하는 타입으로 지정할 수 있는 기능이다. 

형태
template <typename 원하는 타입이름>

typename 대신에 class 키워드를 이용해도 된다. 
template <class 원하는 타입이름>

타입이름은 여러개 지정이 가능하다.
template <typename 원하는이름1, typename 원하는이름2> 이런방식으로 여러개를 사용할수 있다.

함수, 클래스, 구조체에 사용하여 가변적인 타입을 만들어줄 수 있다.

*/

int Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}

float Sum(float Num1, float Num2)
{

	return Num1 + Num2;
}

//T라는 변수타입을 만들어 주었다. 이 T는 이 함수를 호출할 때마다 원하는 타입을 지정하여 호출할 수 있다.
template <typename T>

T Minus(T Num1, T Num2)
{
	return Num1 + Num2;
}

struct FTest
{

};
enum ETest
{

};

template <typename T>
class CArray1
{
public: 
	 
	
	CArray1() {

	}
	~CArray1() {

	}
private:
	T	mArray[100];

	// 클래스 전체에 대한 템플릿이 있다고 하더라도 개별적인 멤버함수별로 템플릿을 사용할 수 도있다. 
	//
public:
	template <typename T1>
	void TestOutput()
	{
		//typeid(T).name() : T가 어떤 타입인지를 알아내고 문자열로 출력해준다.
		std::cout << "T : " << typeid(T).name() << std::endl;
		std::cout << "T1 : " << typeid(T1).name() << std::endl;

	}
	void TestOutput1()
	{
	}

};

/*
operator : C++에서 제공되는 연산자를 구조체 혹은 클래스에서 자신만의 기능으로 재정의하여 사용하게 해주는 기능이다.

반환타입 operator 연산자(인자)
{
}
*/

struct FPoint
{
	int x, y;

	FPoint operator + (const FPoint& pt) const
	{
		FPoint result;

		result.x = x + pt.x;
		result.y = y + pt.y;

		return result;
	}


	FPoint operator + (int Number)	const
	{
		FPoint	result;

		result.x = x + Number;
		result.y = y + Number;

		return result;
	}

	FPoint operator [] (int Index)
	{
		FPoint	result;

		result.x = x + Index;
		result.y = y - Index;

		return result;
	}
};


int main()
{
	FPoint pt1, pt2, pt3;

	pt1.x = 10;
	pt1.y = 20;

	pt2.x = 30;
	pt2.y = 40;

	pt3 = pt2; //pt3.x : 30 , pt3.y : 40
	/*
	FPoint operator + (const FPoint& pt)	const
	{
		FPoint	result;

		result.x = x + pt.x;
		result.y = y + pt.y;

		return result;
	}

	operator는 함수와 같다.
	함수처럼 호출개념이다.
	아래는 pt1의 + operator 를 호출해주는데 + operator의 인자에
	pt2를 전달하는 것이다.
	*/
	pt3 = pt1 + pt2; //pt3.x : 40 , pt3.y : 60

	pt3 = pt1 + 100; //pt3.x : 110 , pt3.y : 120

	pt3 = pt1[30]; //pt3.x : 40 , pt3.y : -10

	std::cout << "pt3 x : " << pt3.x << ", y : " << pt3.y <<
		std::endl;






	// 아래는 template의 T에 int타입을 지정하여 Minus함수의 인자들이 모두 int타입으로
	// 생성되었다.
	std::cout << Minus<int>(10, 20) << std::endl;

	// 아래는 float타입으로 지정되었다.
	std::cout << Minus<float>(10.3f, 20.354f) << std::endl;

	// 아래처럼 호출하면 인자로 들어간 소수점 값들은 f가 없기 때문에 double 타입으로
	// 인식이 된다. 그런데 타입 지정 없이 인자에 바로 이렇게 값을 대입해준다면 템플릿은
	// 내부적으로 인자의 타입을 분석하여 해당 타입으로 설정이 된다.
	std::cout << Minus(3.14, 302.3) << std::endl;

	CArray1<int>	IntArray;
	CArray1<float>	FloatArray;


	IntArray.TestOutput<ETest>();  //T : int , T1 : enum ETest
	FloatArray.TestOutput<FTest>();//T : float , T1 : struct FTest

	return 0;
}