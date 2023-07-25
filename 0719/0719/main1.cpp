#include <iostream>

int main() {

	/*
	중첩 for문 : for문 안쪽에 다른 for문을 추가하여 사용하는 방식

	*/

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << "i = " << i << ",  j = " << j << std::endl;
		}
	}*/

	//구구단을 2~9단까지 이중 for 문을 이용해서 출력

	//std::cout << "구구단을 외자 구구단을 외자~ " << std::endl;

	//for (int i = 2; i < 10; i++)
	//{
	//	std::cout << std::endl << i << "  단 "  << std::endl;

	//	for (int j = 1; j < 10; j++)
	//	{
	//		std::cout << i << " X " << j << " = " << i*j << std::endl;
	//	}
	//}


   // 아래의 내용을 이중for문을 이용해서 출력한다.
   // std::cout << "*"; 이 코드를 이용해서 출력해야 한다.
   /*
   *
   **
   ***
   ****
   *****
   */
	int Line = 0;
	std::cin >> Line;

	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < Line; j++)
		{
			if (i >= j)
				std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;


	/*
	*****
	****
	***
	**
	*
	*/

	for (int i = 0; i < Line; i++)
	{
		//std::cout << "*";

		for (int j = 0; j < Line; j++)
		{
			if (i <= j)
				std::cout << "*";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < Line - i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}


	 
	/*
	*****
	 ****
	  ***
	   **
		*
	*/

	for (int i = 0; i < Line; i++)
	{

		for (int j = 0; j < Line; j++)
		{
			if (i <= j)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;


	for (int i = 0; i < Line; i++)
	{
		for (int j = 0; j < i; j++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < Line - i; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;



	/*
		*
	   **
	  ***
	 ****
	*****
	*/

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i + j > 3)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < i + 1; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	 

	std::cout << std::endl;
	std::cout << std::endl;


	/*
	   *
	  ***
	 *****
	*******
	*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i + j >= 3 && i - j >= -3)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}


	std::cout << std::endl;
	std::cout << std::endl;

	

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3 - i; j++)
		{
			std::cout << " ";
		}

		for (int j = 0; j < (i * 2) + 1; j++)
		{
			std::cout << "*";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	/*
		  *
		 ***
		*****
	   *******
		*****
		 ***
		  *
	   */

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i + j >= 3 && i - j > -4 && i - j < 4 && i + j < 10)
				std::cout << "*";
			else
				std::cout << " ";
		}
		std::cout << std::endl;

	}

	std::cout << std::endl;

	std::cout << std::endl;

	int Count = 0;

	if(Line%2==0)
	{
		Line += 1;
	}

	for (int i = 0; i < 7; i++)
	{
		int Count = i; // 반대로 줄어드는 것에 구현을 위한 변수 

		if (i >= 4) // 4번째보다 커지면  
		{
			Count = 6 - i;  //줄수가 늘어날수록 count 수가 줄어들며 
		}
		for (int j = 0; j < 3 - Count; j++) //빈칸의 출력수가 증가하고 
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * Count + 1; k++) //*출력수는 감소한다. 
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	 
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

		if (i > Line / 2) // 줄수가 절반이 넘어가면  
		{
			Count = Line - i - 1;  //줄수가 늘어날수록 count 수가 줄어들며 
		}
		for (int j = 0; j < Line / 2 - Count; j++) //빈칸의 출력수가 증가하고 
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