#include <iostream>
#include <time.h>

int main() {
	//입력받을 숫자 생성 및 입력
	int Number;
	std::cout << "숫자를 입력하시오 : ";
	std::cin >> Number;

	//10, 20 기준에 따른 출력
	if (Number < 10)
		std::cout << "10보다 작다" << std::endl;
	else if (Number < 20)
		std::cout << "10보다 크고 20보다 작다" << std::endl;
	else
		std::cout << "20보다 크거나 같다" << std::endl;
	
	return 0;
}