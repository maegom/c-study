#include <iostream>

int main() {

	/*
	��ø for�� : for�� ���ʿ� �ٸ� for���� �߰��Ͽ� ����ϴ� ���

	*/

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			std::cout << "i = " << i << ",  j = " << j << std::endl;
		}
	}*/

	//�������� 2~9�ܱ��� ���� for ���� �̿��ؼ� ���

	//std::cout << "�������� ���� �������� ����~ " << std::endl;

	//for (int i = 2; i < 10; i++)
	//{
	//	std::cout << std::endl << i << "  �� "  << std::endl;

	//	for (int j = 1; j < 10; j++)
	//	{
	//		std::cout << i << " X " << j << " = " << i*j << std::endl;
	//	}
	//}


   // �Ʒ��� ������ ����for���� �̿��ؼ� ����Ѵ�.
   // std::cout << "*"; �� �ڵ带 �̿��ؼ� ����ؾ� �Ѵ�.
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
		int Count = i; // �ݴ�� �پ��� �Ϳ� ������ ���� ���� 

		if (i >= 4) // 4��°���� Ŀ����  
		{
			Count = 6 - i;  //�ټ��� �þ���� count ���� �پ��� 
		}
		for (int j = 0; j < 3 - Count; j++) //��ĭ�� ��¼��� �����ϰ� 
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * Count + 1; k++) //*��¼��� �����Ѵ�. 
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}

	std::cout << std::endl;
	std::cout << std::endl;

	 
	int Line = 0; //�Է¹��� �ټ� �ʱ�ȭ 
	std::cout << "������ ����Ͻðڽ��ϱ�? : \n";
	std::cin >> Line; //�Է�

	//�Է� ���� ���� ¦���ϰ�� ����� �� �ȳ����Ƿ� ���Ƿ� +1�� �Ͽ� Ȧ���� ����
	if (Line % 2 == 0)
	{
		Line += 1;
	}

	for (int i = 0; i < Line; i++)
	{
		int Count = i; // �ݴ�� �پ��� �Ϳ� ������ ���� ���� 

		if (i > Line / 2) // �ټ��� ������ �Ѿ��  
		{
			Count = Line - i - 1;  //�ټ��� �þ���� count ���� �پ��� 
		}
		for (int j = 0; j < Line / 2 - Count; j++) //��ĭ�� ��¼��� �����ϰ� 
		{
			std::cout << " ";
		}
		for (int k = 0; k < 2 * Count + 1; k++) //'*'��¼��� �����Ѵ�. 
		{
			std::cout << "*";
		}
		std::cout << "\n";
	}
	return 0;

}