#include <iostream>

//���� Number�� ���ڷ� �޾� 11�� �ٲ��ش�. 
void ChangeNumber(int Number)
{
	Number = 11;  //Number�� ���������� main �Լ��� Number ���� �ٲ��� �ʴ´�. 
}

//���� Number�� �ּ� ���� ���ڷ� �޾� �ش� �ּҿ� �ִ� ���� 222�� �ٲ��ش�.  
void ChangeNumber1(int* Number)
{
	*Number = 222; //�ּҰ��� ���Ͽ� Number�� �����Ͽ� main �Լ��� Number���� �ٲ��. 
}

//���� Number1, Number2�� �ּ� ���� ���ڷ� �޾�, �ش� �ּҿ� �ִ� ���� 3333, 44444�� �ٲ��ش�.  
void ChangeNumber1(int* Number1, int* Number2)
{
	*Number1 = 3333;
	*Number2 = 44444; //������ �ٲ� ������ �ٲ��. 
}

int main()
{
	//���� ����
	int Number = 300;
	std::cout << Number << std::endl; //= 300

	//�Լ� ���� 
	ChangeNumber(Number);
	std::cout << Number << std::endl; //= 300 

	ChangeNumber1(&Number);
	std::cout << Number << std::endl; // = 222

	ChangeNumber1(&Number, &Number);
	std::cout << Number << std::endl; //= 44444

	return 0;
}