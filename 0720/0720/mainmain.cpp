#include <iostream>
//�� �� �Է��� �޾� ���̾Ƹ�� ������� �����
int main() {
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

		if (i > Line /2) // �ټ��� ������ �Ѿ��  
		{
			Count = Line - i - 1;  //�ټ��� �þ���� count ���� �پ��� 
		}
		for (int j = 0; j < Line /2 - Count; j++) //��ĭ�� ��¼��� �����ϰ� 
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