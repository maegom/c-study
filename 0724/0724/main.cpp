#include <iostream>
/*
	����ü : �������� ������ �ϳ��� ��� ����� �� �ְ� ���ִ� �����̴�.

	����
	struct ����ü�̸�
	{
		���ϴ� ���� ����
	};

	��������� ���� Ÿ���� ������ش�.
	����ü�̸��� ���� Ÿ���� �ȴ�.


	*/

//	#define :   ��ó���� , ������ ���� NAME_SIZE�̸��� ��� 32�� ��� ��ü
#define NAME_SIZE	32
#define TEST	std::cout<< "Test" << std::endl; //������ �Ⱦ���. 

enum class CharcterType
{
	Type1,
	Type2,
	Type3
};

struct TestSturct
{
	int test1;
	int test2;
	int test3;
};

struct Playar
{
	char	Name[NAME_SIZE];
	CharcterType Type12;
	int Option;
	TestSturct TestStr;
};

int main() {

	TEST

	Playar player = {}; //��� ������� 0���� �ʱ�ȭ 
	Playar player1 = {"aa0b" , CharcterType::Type1}; //�̷��� �� ��� ���� 

	//����ü�� .�� �̿��Ͽ� ����� �����Ѵ�. 
	//Name�� char �迭�̴�. 
	std::cout << player1.Name << std::endl; // char �迭�� ��繮�� ���
	std::cout << player1.Name[0] << std::endl; 
	//std::cout << player.Type12 << std::endl;
	//���ڿ��� ���� �ν��ϱ� ���Ͽ� �ݵ�� �������� �ι���(0)�� �־��־�� �Ѵ�. 
	//�׷��� ���� �迭�� 32�������� ���� ���ڸ� ������ �� �ִ� ������ 31�� �̴�. 

	return 0;
}