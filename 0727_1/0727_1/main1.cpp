
#include <iostream>

int main()
{
	/*
	레퍼런스 : 변수에 별명을 붙여주는 기능이라고 볼 수 있다.
	참조하는 변수를 지정하면 역참조나 이런 번거로운 작업 없이
	참조하는 변수 그 자체가 되어서 쉽게 값을 변경하는 것이 가능하다.
	별명을 붙여주는 개념이기 때문에 마치 해당 변수를 직접 사용하는
	것처럼 바로 값을 변경할 수 있다.
	단, 레퍼런스는 처음 레퍼런스 변수를 생성할 때 선언과 동시에 참조하는
	변수를 반드시 지정해야 된다.
	*/
	int	Number = 500;
	int	Number1 = 600;
	int& Ref = Number;

	// 레퍼런스는 선언 이후에 다른 변수를 대입하면 참조대상을 바꾸는
	// 것이 아니라 변수가 가지고 있는 값을 레퍼런스에 대입해주게 되어
	// 레퍼런스가 참조하는 대상의 값을 변경해버리게 된다.
	Ref = Number1;

	std::cout << "Number = " << Number << std::endl;
	std::cout << "Number1 = " << Number1 << std::endl;

	const int& cRef = Number;

	// const 레퍼런스는 참조하는 대상의 값을 변경할 수 없다.
	//cRef = 1000;



	return 0;
}
