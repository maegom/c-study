#pragma once

/*
friend : �ٸ� Ŭ�������� �� Ŭ������ private�� ������ �� �ְ� ���ִ� ����̴�.

*/

//��� Ŭ���� 
template <typename T>
class CLinkedListNode
{
	//friend : �ٸ� Ŭ�������� �� Ŭ������ private�� ������ �� �ְ� ���ִ� ����̴�.
	template <typename T>
	friend CLinkedList;

private:
	//������ 
	CLinkedListNode() :
		mnext(nullptr), //��� �ʱ�ȭ
		mprev(nullptr),
	{
	}
	~CLinkedListNode()
	{
	}
private :
	T					mData; // ������
	CLinkedListNode<T>* mNext; // ������� �ּ�
	CLinkedListNode<T>* mPrev; // ������� �ּ�
};

//���� Linked List Ŭ����
template <typename T>
class CLinkedList
{

public:
	//������
	CLinkedList()
	{
		mBegin = new CNode; //��ó�� ��� �����Ҵ� (�ڷ����� ���۵� �ճ��)
		mEnd = new CNode;   //������ ���

		//�ʱ� ���� 
		mBegin->mNext = mEnd;   // �� �ճ�� ���� ��� �ּҸ� �ǵ� ���� ����
		mEnd->mPrev = mBegin;   // �� �ڳ�� �� ����ַθ� �Ǿ� ���� ����

		mCount = 0;
	}
	//�Ҹ���
	~CLinkedList()
	{
		//��� �Ǿպ��� delete
		CNode* Node = mBegin;

		//��尡 ���� ���� ����
		while (nullptr != Node)
		{
			CNode* Next = Node->mNext; // ������ ���� ��� Next �� �޾ƿ���
			delete Node;               // ���� ��� ���� 
			Node = Next;               // ���� ��带 ���� ���� ����
			// �̷��� �ϴ� ���� : ��带 ���� ����� ���� ��带 �� �� ����. 
		}
	}

private :
	//typedef : Ÿ���� ������ �Ѵ�. (CLinkedListNode<T> Ÿ���� CNode��� �̸����� ��ü ����)
	typedef CLinkedListNode<T> CNode;

private :
	//���� ��� (ó���� ��) �� ���� ������ �� ���ϴ�.
	CNode* mBegin;
	CNode* mEnd;
	int mCount; //��� ����

public : 
	//�ڿ� �߰�
	void push_back(const T& Data)
	{	// �ڿ� �߰��� End���� End����� ������� ���̿� �߰�

		//��� �����Ҵ� 
		CNode* Node = new CNode;

		//��忡 ������ ����
		Node->mData = Data;

		//���� ��� ����� (��)���̳���� ����� ����
		CNode* Prev = mEnd->mPrev;

		//��������� ������忡 �߰��� ��� ����, �߰��ҳ�忡 ������忡 ������� ����
		Prev->mNext = Node;
		Node->mPrev = Prev;

		//(��) ���̳���� �� ��忡 �߰��� ��� ����, �߰��� ��� ������ (��) ���̳�� ����
		mEnd->mPrev = Node;
		Node->mNext = mEnd;

		//��� ���� �߰�
		++mCount;
	}
	//�տ� �߰�
	void  push_front(const T& Data)
	{	// �տ� �߰��� Begin���� Begin����� ������� ���̿� �߰�
	
		//��� �����Ҵ�
		CNode* Node = new CNode;

		//��忡 ������ ����
		Node->mData = Data;
		
		//���� ��� ����� (ó��)���̳���� ������� ����
		CNode* Next = mBegin->mNext;

		//��������� ������忡 �߰��� ��� ����, �߰��� ����� ������忡 ������� ����
		Next->mPrev = Node;
		Node->mNext = Next;

		//(ó��) ���̳���� ���� ��忡 �߰��� ��� ����, �߰��� ��� ������ (ó��)���̳�� ����
		mBegin->mNext = Node;
		Node->mPrev = mBegin;

		//��� ���� ����
		++mCount;
	}
	// �� ��� ����
	void pop_back()
	{	//�ǳ� ���(����)�� ����� ����

		// ������� ��� ����
		if (empty())
			return;

		//������ ��忡 ������ �� ��� ����
		CNode* DeleteNode = mEnd->mPrev;
		//���� ��忡 ������ ����� �� ��� ����
		CNode* Prev = DeleteNode->mPrev;

		// ���� ����� �������� End��带 �����Ѵ�.
		Prev->mNext = mEnd; //��������� ������忡 (��)���̳�� ����
		mEnd->mPrev = Prev; //(��)���̳���� ������忡 ������� ����

		//������ ��� delete
		delete   DeleteNode;

		//��� ���� ����
		--mCount;
	}
	//�� ��� ���� 
	void pop_front()
	{	//�� �� ���(����)�� ������� ����

		// ������� ��� ����
		if (empty())
			return;

		//������ ��忡 ��ó�� ���� ��� ����
		CNode* DeleteNode = mBegin->mNext;
		//������忡 �����ҳ���� ������� ����
		CNode* Next = DeleteNode->mNext;

		// ���� ����� �������� End��带 �����Ѵ�.
		Next->mPrev = mBegin; //��������� ������忡 (ó��)���̳�� ����
		mBegin->mNext = Next; //(ó��)���̳���� ������忡 ������� ����

		//������ ��� delete
		delete   DeleteNode;

		//��� ���� ����
		--mCount;
	}

	//���� ��尳�� ȣ��
	int size()   const
	{
		return mCount;
	}

	//����ִ��� �Ǵ� ��������� = 1(true)
	bool empty()   const
	{
		return mCount == 0;
	}
};