#include <iostream>
#include <time.h>

int main() {
	//�Է¹��� ���� ���� �� �Է�
	int Number;
	std::cout << "���ڸ� �Է��Ͻÿ� : ";
	std::cin >> Number;

	//10, 20 ���ؿ� ���� ���
	if (Number < 10)
		std::cout << "10���� �۴�" << std::endl;
	else if (Number < 20)
		std::cout << "10���� ũ�� 20���� �۴�" << std::endl;
	else
		std::cout << "20���� ũ�ų� ����" << std::endl;
	
	return 0;
}