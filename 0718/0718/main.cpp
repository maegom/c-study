#include <iostream>

int main()
{
	/*	����

	2���� : 0~1 ���̷� ������ ���� ����
	0b1110111  : 0b �� 2����
	10���� : 0~9 ���̷� ������ ���� ����
	16���� : 0~ 15���̷� ������ ���� ���� 10~15�� a~ f�� ǥ��
	0x  : 16����

	216 �� 2����, 16������ ��ȯ
	216/2 108 -0
	   /2 54  -0
	   /2 27  -0
	   /2 13  -1
	   /2  6  -1
	   /2  3  -0
	   /2  1  -1

	   0b11011000

	�ٽ� 10����
	1   1  0  1  1 0 0 0
	128 64 32 16 8 4 2 1

	128+64+16+8

	16������ 2���� 4�ڸ��� �����ȴ�.
	1101  1000
	13		8
	0xd8

	��Ʈ���� �������� : 2���� ������ ������ �����Ѵ�.
	���� ���� �����Ͽ� ����� ���� ���´�.
	AND(&), OR(|), NOT(~), XOR(^)
	��Ʈ���� �������ڸ� ����ϸ� �ǿ����ڴ��� ���� 2������ ��ȯ�Ѵ�.

	216 & 357
	011011000
	101100101

	001000000

	216 | 357
	011011000
	101100101

	111111101

	~216
	11011000

	00000000 00000000 00000000 11011000
	11111111 11111111 11111111 00100111
	��Ī �Ǵ� -217


	216 ^ 357
	011011000
	101100101

	110111101

	*/

	std::cout << "216 & 35 = " << (216 & 357) << std::endl;
	std::cout << "216 | 35 = " << (216 | 357) << std::endl;
	std::cout << "~216  = " << (~216) << std::endl;
	std::cout << "216 ^ 357 = " << (216 ^ 357) << std::endl;


	const int State1 = 0x1;		//1
	const int State2 = 0x2;		//10
	const int State3 = 0x4;		//100
	const int State4 = 0x8;		//1000
	const int State5 = 0x10;	//10000
	const int State6 = 0x20;	//100000
	const int State7 = 0x40;	//1000000

	int State = 0;
	/*
	OR �� �̿��Ͽ� �߰��ϰ� AND�� �̿��ؼ� ���°� �ִ��� �˻��Ѵ�.
	XOR�� �̿��ؼ� ���°� �������� ��� �����ϰ� ���°� ���� ��� ���ش�
	*/


	State = State | State3;  // 000 | 100 = 100
	State = State | State5;  // 00100 | 10000 = 10100
	State = State | State7;

	State = State ^ State7; //1010100 ^ 1000000 = 0010100

	std::cout << "State1 = " << (State & State1) << std::endl;
	std::cout << "State2 = " << (State & State2) << std::endl;
	std::cout << "State3 = " << (State & State3) << std::endl;
	std::cout << "State4 = " << (State & State4) << std::endl;
	std::cout << "State5 = " << (State & State5) << std::endl;
	std::cout << "State6 = " << (State & State6) << std::endl;
	std::cout << "State7 = " << (State & State7) << std::endl;

	/*
	����Ʈ ������ :  << , >> 2���� �ִ�.
	216 << 2   /2^2��
	: 11011000 �������� 2ĭ�̵��ض�
	   00000000 00000000 00000011 01100000 ���� �ΰ� ���� > ������ �ΰ�0 ����
	   :864

	   216 >> 2 /2^2����
	: 11011000 ���������� 2ĭ�̵��ض�
	  00110110 ������ �ΰ� ���� > ���� �ΰ�0 ����
	   :864
	*/

	unsigned char r = 201;
	unsigned char g = 157;
	unsigned char b = 182;
	unsigned char a = 240;

	unsigned int Color = 0;

	Color = a;
	//00000000 00000000 00000000 aaaaaaaaa

	Color = Color << 8;
	//00000000 00000000 aaaaaaaaa 00000000

	Color = Color | r;
	//00000000 00000000 aaaaaaaaa rrrrrrrr

	Color = Color << 8;
	//00000000 aaaaaaaaa rrrrrrrr 00000000

	Color = Color | g;
	//00000000 aaaaaaaaa rrrrrrrr gggggggg

	Color = Color << 8;
	//aaaaaaaaa rrrrrrrr gggggggg 00000000

	Color = Color | b;
	//aaaaaaaaa rrrrrrrr gggggggg bbbbbbbb

	std::cout << Color << std::endl;

	std::cout << "b = " << (Color & 0x000000ff) << std::endl;
	std::cout << "g = " << (Color >> 8 & 0x000000ff) << std::endl;
	std::cout << "r = " << (Color >> 16 & 0x000000ff) << std::endl;
	std::cout << "a = " << (Color >> 24 & 0x000000ff) << std::endl;

	const int test1 = 0b11111111111;		//1
	std::cout << "test1 = " << test1 << std::endl;

	/*
	���������� : ++, --
	++:������ �� 1���� 
	--:������ �� 1����
	���� : ��ġ����
	������ : ��ġ����

	*/

	int Number = 100;
	std::cout << ++Number << std::endl;
	std::cout <<  Number++ << std::endl;
	std::cout <<  Number << std::endl;

	std::cout << --Number << std::endl;
	std::cout << Number-- << std::endl;
	std::cout << Number << std::endl;

	/*
	������ ����� : +=, -=, &=, |=
	*/

	Number = 10;
	Number += 20;

	std::cout << Number << std::endl;



	return 0;
}