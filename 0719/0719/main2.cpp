#include <iostream>

int main() {

	/*
	whlie(���ǽ�)
	{	}

	���ǽ��� true �� ���� /	false�� ����������. 
	
	break, contiue �� ���� �帧 ���� ����


	do while //ó�� �ѹ��� ���ǽİ� ������� �ڵ尡 ���۵ȴ�. 

	do{�ݺ��� �ڵ�}
	while(���ǽ�);


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