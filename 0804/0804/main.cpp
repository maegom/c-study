#include <iostream>
#include "LinkedList.h"

/*
linked list
�����͸� �߰��Ҷ� �׶� �׶� ������ �����.  

single linked list : ���ʹ��������� ��ũ�� ������ ���� ���
double linked list : ������� , ������� �Ѵ� ����

���� : ��� �߰��ص� ������ �ӵ�

�迭 �� ���ؼ� 
������� �߰��� �Ҷ��� �迭�� ����
�߰��� �߰��� linked list�� ����
(��, �뷮�� �þ���� �迭�� ����)
������ �迭�� ���� 

*/
int main()
{
	CLinkedList<int>	IntList;

	for (int i = 0; i < 10; ++i)
	{
		IntList.push_back(i);
	}

	IntList.erase(5);

	CLinkedList<int>::iterator	iter;
	CLinkedList<int>::iterator	iterEnd = IntList.end();

	for (iter = IntList.begin(); iter != iterEnd; ++iter)
	{
		std::cout << *iter << std::endl;
	}

	return 0;
}
