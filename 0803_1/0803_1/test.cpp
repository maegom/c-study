#include <iostream>

//구조체 간의 합을 구하는 연산자 재정의
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

	pt3 = pt2;  //pt3.x : 30 , pt3.y : 40
	 
	pt3 = pt1 + pt2; //pt3.x : 40 , pt3.y : 60

	pt3 = pt1 + 100; //pt3.x : 110 , pt3.y : 120

	pt3 = pt1[30]; //pt3.x : 40 , pt3.y : -10

	std::cout << "pt3 x : " << pt3.x << ", y : " << pt3.y <<
		std::endl;

	return 0;
}