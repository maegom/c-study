#include <iostream>

int main() {
	
	/*
	반복문 : 동일한 코드 반복 동작
	for, while, do while 

	for의 형태
	for (초기값; 조건식; 증감) 
	{동작할 코드}

	초기값 : for문이 시작할때 한번만 동작
	조건식 : 매번 for문이 동작할때마다 체크, 조건이 true/false 나오도록 구성
	증감 : for문이 반복해서 동작할때마다 증감을 한다. 

	동작방법
	초기값 -> 조건식 수행 -> 코드 실행 -> 증감 ->조건식 ->코드실행 ->증감 ->조건식 .... 
	조건식 false 일때 for 빠져나감

	무한루프 돌리고 싶으면 
	for(;;)	{}

	while

	*/
	
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " ";
	}
	
	for (int i = 0; i < 100; i++)
	{
		if (i % 4 == 0 && i % 7 == 0)
		{
			std::cout << i << std::endl;
			break;
		}
	}

	for (int i = 0; i < 100; i++)
	{
		
			if (i  == 30)		
			break;  //break 는 if 문에는 영향을 줄 수 없다. switch, while, do while, for문 빠져나가는용도 사용
			//continue : 현재반복을 스킵해준다.

			if (i % 2 == 0)
				continue;

			std::cout << i << std::endl;


	}
 
	return 0;
}