#include <iostream>
#include "Array.h"

/*
���ø� : �ϳ��� ������ Ÿ���� �ƴ� �ʿ��� �� ���ϴ� Ÿ������ ������ �� �ִ� ����̴�. 

����
template <typename ���ϴ� Ÿ���̸�>

typename ��ſ� class Ű���带 �̿��ص� �ȴ�. 
template <class ���ϴ� Ÿ���̸�>

Ÿ���̸��� ������ ������ �����ϴ�.
template <typename ���ϴ��̸�1, typename ���ϴ��̸�2> �̷�������� �������� ����Ҽ� �ִ�.

�Լ�, Ŭ����, ����ü�� ����Ͽ� �������� Ÿ���� ������� �� �ִ�.

*/

int Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}

float Sum(float Num1, float Num2)
{

	return Num1 + Num2;
}

//T��� ����Ÿ���� ����� �־���. �� T�� �� �Լ��� ȣ���� ������ ���ϴ� Ÿ���� �����Ͽ� ȣ���� �� �ִ�.
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

	// Ŭ���� ��ü�� ���� ���ø��� �ִٰ� �ϴ��� �������� ����Լ����� ���ø��� ����� �� ���ִ�. 
	//
public:
	template <typename T1>
	void TestOutput()
	{
		//typeid(T).name() : T�� � Ÿ�������� �˾Ƴ��� ���ڿ��� ������ش�.
		std::cout << "T : " << typeid(T).name() << std::endl;
		std::cout << "T1 : " << typeid(T1).name() << std::endl;

	}
	void TestOutput1()
	{
	}

};

/*
operator : C++���� �����Ǵ� �����ڸ� ����ü Ȥ�� Ŭ�������� �ڽŸ��� ������� �������Ͽ� ����ϰ� ���ִ� ����̴�.

��ȯŸ�� operator ������(����)
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

	operator�� �Լ��� ����.
	�Լ�ó�� ȣ�ⰳ���̴�.
	�Ʒ��� pt1�� + operator �� ȣ�����ִµ� + operator�� ���ڿ�
	pt2�� �����ϴ� ���̴�.
	*/
	pt3 = pt1 + pt2; //pt3.x : 40 , pt3.y : 60

	pt3 = pt1 + 100; //pt3.x : 110 , pt3.y : 120

	pt3 = pt1[30]; //pt3.x : 40 , pt3.y : -10

	std::cout << "pt3 x : " << pt3.x << ", y : " << pt3.y <<
		std::endl;






	// �Ʒ��� template�� T�� intŸ���� �����Ͽ� Minus�Լ��� ���ڵ��� ��� intŸ������
	// �����Ǿ���.
	std::cout << Minus<int>(10, 20) << std::endl;

	// �Ʒ��� floatŸ������ �����Ǿ���.
	std::cout << Minus<float>(10.3f, 20.354f) << std::endl;

	// �Ʒ�ó�� ȣ���ϸ� ���ڷ� �� �Ҽ��� ������ f�� ���� ������ double Ÿ������
	// �ν��� �ȴ�. �׷��� Ÿ�� ���� ���� ���ڿ� �ٷ� �̷��� ���� �������شٸ� ���ø���
	// ���������� ������ Ÿ���� �м��Ͽ� �ش� Ÿ������ ������ �ȴ�.
	std::cout << Minus(3.14, 302.3) << std::endl;

	CArray1<int>	IntArray;
	CArray1<float>	FloatArray;


	IntArray.TestOutput<ETest>();  //T : int , T1 : enum ETest
	FloatArray.TestOutput<FTest>();//T : float , T1 : struct FTest

	return 0;
}