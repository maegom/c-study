#include <iostream>
#include <time.h>

int main() {
	/*
	if�� : ������ üũ �Ͽ� ���ϴ� �ڵ� ���ۿ��� ����
	���� : if (���ǽ�) {���ǽ��� true �϶� ������ �ڵ�}
	*/

	if (false) {
		std::cout << "if �� true" << std::endl;
	}

	int Number = 100;

	//if�� ���� �ڵ尡 1���� ��� �ڵ��� ���� ����
	if (Number < 0) 
		std::cout << "0���� �۴�" << std::endl;
	else //if ���� false �϶� ����
		std::cout << "0���� ŭ" << std::endl;
		
	/*
	else if : if ���� �Բ� ���, ȥ�� ��� �Ұ�, ��� �߰��� �� �ִ�.
	else ���� ���� �־�� �Ѵ�. 
	else if (���ǽ�) {} 
	*/
	
	const int State1 = 0x1;
	const int State2 = 0x2;
	const int State3 = 0x4;
	const int State4 = 0x8;
	const int State5 = 0x10;
	const int State6 = 0x20;
	const int State7 = 0x40;

	int State = 0;
	State |= State2;
	State |= State3;
	State |= State6;

	if (State & State1)
		std::cout << "State1 On \n";
	if (State & State2)
		std::cout << "State2 On \n";
	if (State & State3)
		std::cout << "State3 On \n";
	if (State & State4)
		std::cout << "State4 On \n";
	if (State & State5)
		std::cout << "State5 On \n";
	if (State & State6)
		std::cout << "State6 On \n";
	if (State & State7)
		std::cout << "State7 On \n";

	std::cin >> Number;

	if (Number < 10)
		std::cout << "10���� �۴�" << std::endl;
	else if(Number <20)
		std::cout << "20���� �۴�" << std::endl;

	/*
	cin :  �ܼ�â���� �Է¹����� �ְ� ���ִ� ���
	*/

	/*
	���� : ����ǥ�� ���� �ʿ��Ҷ� ���� ���� �´�. 
	srand();
	*/
	srand(time(0));
	rand(); //�ð����� �Կ� ���� ù��° ������ �����ؼ� �ϳ� ���ſ�
	std::cout << rand() % 100 +100 << std::endl;  //100~199 ���� ���� 
	std::cout << rand() % 100 +100 << std::endl;
	std::cout << rand() % 100 +100 << std::endl;
	std::cout << rand() % 100 +100 << std::endl;
	std::cout << rand() % 100 +100 << std::endl;

	return 0;

}