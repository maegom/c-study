// #:��ó���� : ������ ���� ���� ó���� �ϰ� �������� ����
// #include : ������ ���� ������� ������ ���Խ��Ѽ� ���
/*
�������� ���� ����
������ -> ��ũ > �������� ����
*/
#include <iostream>

int main()  //������ main 
{//�ڵ���

	//using namespace std; //�Ⱦ��°� ���� (�̸� �浹�� �����ϱ� ���� ����)

	// �����ʿ��� �������� �۵�

	std::cout << "console \"ū����ǥ\" output\n"; // :: <-���� ���� ������ 
	
	std::cout << "test output1" << std::endl;  //cout ������ ��� ���� 
	std::cout << "test output2\n";
	 
/*
�뷮 �ּҴ��� : bit
1 bit �� 0 or 1 �����Ҽ� �ִ� ����
1byte : 8 bit

���ڸ� ����� ���� ������ �ƽ�Ű�ڵ� ǥ�� �����Ͽ� ���� �´� ���ڸ� ����ϴ� �ý����̴�.
���ĺ�, ����, ������ Ư�μ����ڵ��� 1byte�� ǥ���� ����������
�ѱ�, �߱���� 2byte. �� ǥ�� �ȴ�. 

Ÿ��   ��  ǥ�� ���� ��   ũ��   ��  ǥ������
bool       ��/����       1byte     true(1)/false(0) // 0�̾ƴ� ��� ���� ������ �Ǵ��Ѵ�. 
Char		����			1byte     -128~ 127
short		����			2byte	-32768~ 32767  //�����Ҷ� �� �Ⱦ�
int			����			4byte	-2147483648 ~ 2147483647
__int64		����			8byte	
float	  �ε��Ҽ���		4byte	
double	  �ε��Ҽ���		8byte	

signed : �⺻Ÿ���̴�. ��ȣ�� �ִ� Ÿ��
unsighned : ��ȣ�� ���� Ÿ���̴�. ���� ���� ��� ����� ��ȯ�Ǿ� 0~ ǥ���Ǵ� ���� ������ �о�����.

00000000 �� ���� ��ȣ ��Ʈ 

*/
	//FLT_MAX;

	//���� ������  : Ư�����ڴ� _�� ���, ù���ڴ� ���ĺ��̳� _�� ����.
	// Ÿ�� �����̸�;

	bool	test = true; // = : ���� ������ , �������� ���� �������� ����
	std::cout << test << std::endl;

	char	text = 'B';
	std::cout << text << std::endl;
	std::cout << (int)text << std::endl;

	for (int i = 0; i < 255; i++)
	{
		char	text2 = i;
		std::cout << text2 << " ";
	}

	char	text1 = 67;
	std::cout << text1 << std::endl;
	 
	short	number = 32767;  //������ ǥ�������� ��� ��� +������ ǥ�������� ����� -���� �ּҰ����� �̵��Ͽ� ǥ��
	//-������ ǥ�������� ����� +���� �ִ밪���� �̵��Ͽ� ǥ��
	std::cout << number << std::endl;

	unsigned char r = 230;
	std::cout << r << std::endl;

	int number1 = 2147483647;
	std::cout << number1 << std::endl;

	__int64 number2 = 2147483647999999990;
	std::cout << number2 << std::endl;

	float number3 = 3.14125962f;  //�Ҽ����� �⺻������ double�ν� ,3.14f �ٿ��� ���
	std::cout << number3 << std::endl;  //cout �� �Ҽ��� 5��° �ڸ����� ���, 6��° �ڸ����� �ݿø�

	double	 number4 = 3.141259623;
	std::cout << number4 << std::endl;
	
	/*
	��� : ���� �ٲ� �� ���� ��
	������ ����� �ٲ㼭 ����� ���� �ִ�.

	const Ű���带 �̿��ؼ� ������ ����� �ٲ� �� �ִ�. 
	const Ű����� ������ Ÿ�� ���ʿ� �ٿ��ش�.
	������ ����� ����� �Ǹ� �ݵ�� ����� ���ÿ� ���� �ʱ�ȭ ���Ѿ��Ѵ�. ���� ���Ŀ��� ���� ������ �� ����.

	*/
	const int	number5 = 1010;
	//number5 = 200;

	/*
	��Ģ������ : + , - ,* , / ,%(������������)
	10/3 = 3.33333333...
	but 10/3 = 3   
	  ����/���� = ������ ���´�.
	 ���� ������� �Ҽ��������� ���� ���;� �Ѵٸ� �����ϳ��� �Ǽ����� �Ѵ�. 
	*/ 

	std::cout << "10 / 3 = " << 10.0f / 3.0f << std::endl;  //0���� �����°� ����
	std::cout << "10 % 3 = " << 10 % 3 << std::endl; //������ ������ ���� ���길 �����Ѵ�. 
	std::cout << "10 +3 * 1 = " << 10 + 3 * 1  << std::endl;

	/*
	���迬���� : < , > , >=, <= , == (����), !=(�ٸ���)
	�� �� ���� �����ؼ� ����� ��,������ ������ �ȴ�. 
	10 > 20 = false 
	10 == 20 = false 
	*/

	std::cout << "10 < 20 = " << (10 < 20) << std::endl;
	std::cout << "10 > 20 = " << (10 > 20) << std::endl;
	std::cout << "10 == 20 = " << (10 == 20) << std::endl;
	std::cout << "10 != 20 = " << (10 != 20) << std::endl;



	/*
	�� ������ : AND(&&) , OR(||), NOT(!),
	��/���� �� ��/���� �����ؼ� ��/���� ����.
	A	B	AND		OR
	0	0	0		0
	1	0	0		1
	0	1	0		1
	1	1	1		1

	*/

	std::cout << "false && false = " << (false && false) << std::endl;
	std::cout << "true && false = " << (true && false) << std::endl;
	std::cout << "true && true = " << (true && true) << std::endl;

	std::cout << "false || false = " << (false || false) << std::endl;
	std::cout << "true || false = " << (true || false) << std::endl;
	std::cout << "true || true = " << (true || true) << std::endl;

	std::cout << "!false =" << !false << std::endl;
	std::cout << "!true =" << !true << std::endl; 
  
	return 0;
}