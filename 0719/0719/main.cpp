#include <iostream>

int main() {
	
	/*
	�ݺ��� : ������ �ڵ� �ݺ� ����
	for, while, do while 

	for�� ����
	for (�ʱⰪ; ���ǽ�; ����) 
	{������ �ڵ�}

	�ʱⰪ : for���� �����Ҷ� �ѹ��� ����
	���ǽ� : �Ź� for���� �����Ҷ����� üũ, ������ true/false �������� ����
	���� : for���� �ݺ��ؼ� �����Ҷ����� ������ �Ѵ�. 

	���۹��
	�ʱⰪ -> ���ǽ� ���� -> �ڵ� ���� -> ���� ->���ǽ� ->�ڵ���� ->���� ->���ǽ� .... 
	���ǽ� false �϶� for ��������

	���ѷ��� ������ ������ 
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
			break;  //break �� if ������ ������ �� �� ����. switch, while, do while, for�� ���������¿뵵 ���
			//continue : ����ݺ��� ��ŵ���ش�.

			if (i % 2 == 0)
				continue;

			std::cout << i << std::endl;


	}
 
	return 0;
}