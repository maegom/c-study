#include <iostream>

int main() {

	/*
	whlie(조건식)
	{	}

	조건식이 true 면 동작 /	false면 빠져나간다. 
	
	break, contiue 로 실행 흐름 제어 가능


	do while //처음 한번은 조건식과 관계없이 코드가 동작된다. 

	do{반복할 코드}
	while(조건식);


	*/
	int Number = 0;
	while (Number < 10)
	{
		std::cout << ++Number << std::endl;
	}

	do {
		std::cout << ++Number << std::endl;
	} while (false);

	

	
	return 0;
}