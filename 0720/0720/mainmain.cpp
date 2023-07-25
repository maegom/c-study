#include <iostream>
//줄 수 입력을 받아 다이아몬드 모양으로 별찍기
int main() {
	int Line = 0; //입력받을 줄수 초기화 
	std::cout << "몇줄을 출력하시겠습니까? : \n";
	std::cin >> Line; //입력

	//입력 받은 수가 짝수일경우 모양이 잘 안나오므로 임의로 +1을 하여 홀수를 만듦
	if (Line % 2 == 0) 
	{
		Line += 1;
	}

	for (int i = 0; i < Line; i++)
	{
		int Count = i; // 반대로 줄어드는 것에 구현을 위한 변수 

		if (i > Line /2) // 줄수가 절반이 넘어가면  
		{
			Count = Line - i - 1;  //줄수가 늘어날수록 count 수가 줄어들며 
		}
		for (int j = 0; j < Line /2 - Count; j++) //빈칸의 출력수가 증가하고 
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * Count + 1; k++) //'*'출력수는 감소한다. 
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
	return 0;
}