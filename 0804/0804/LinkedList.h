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
	friend class CLinkedList;

	template <typename T>
	friend class CLinkedListIterator;

private:
	//������ 
	CLinkedListNode() :
		mNext(nullptr), //��� �ʱ�ȭ
		mPrev(nullptr)
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

template <typename T>
class CLinkedListIterator
{
	template <typename T>
	friend class CLinkedList;

public:
	CLinkedListIterator() :
		mNode(nullptr)
	{
	}

	~CLinkedListIterator()
	{
	}
private :
	CLinkedListNode<T>* mNode;

public : 
	bool operator == (const CLinkedListIterator<T>& iter) const
	{
		return mNode == iter.mNode;
	}

	bool operator != (const CLinkedListIterator<T>& iter) const
	{
		return mNode != iter.mNode;
	}
	// ��������
	void operator ++ ()
	{
		mNode = mNode->mNext;
	}

	// ��������
	void operator ++ (int)
	{
		mNode = mNode->mNext;
	}

	// ��������
	void operator -- ()
	{
		mNode = mNode->mPrev;
	}

	// ��������
	void operator -- (int)
	{
		mNode = mNode->mPrev;
	}

	T& operator * ()
	{
		return mNode->mData;
	}
private:
	void operator = (CLinkedListNode<T>* Node)
	{
		mNode = Node;
	}

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

public:
	// public���� typedef �� �صθ� Ŭ���� �ܺο����� �� Ÿ���� ����Ͽ�
	// ������ ������ �� �ִ�.
	typedef CLinkedListIterator<T>	iterator;

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

	void clear()
	{
		// Begin�� End�� ������ ���� �����͸� �߰��ϱ� ���� ������ ���
		// �� �����Ѵ�.
		CNode* Node = mBegin->mNext;

		while (mEnd != Node)
		{
			// ���� ��带 �̸� �޾Ƶд�. ���� ��带 �����ϰ� �Ǹ�
			// ���� ����� �ּҸ� �� �� ���� ������ ���� ��带 �̸�
			// �޾Ƶΰ� ���� ��带 �����Ѵ�.
			CNode* Next = Node->mNext;

			delete	Node;

			Node = Next;
		}

		// Begin�� End�� �����Ѵ�.
		mBegin->mNext = mEnd;
		mEnd->mPrev = mBegin;

		mCount = 0;
	}

	iterator begin()	const
	{
		iterator	iter;
		iter.mNode = mBegin->mNext;
		return iter;
	}

	iterator end()	const
	{
		iterator	iter;
		iter.mNode = mEnd;
		return iter;
	}

	// erase �Լ��� ��带 �����ϰ� ������ ����� ���� ��带
	// iterator�� �����Ͽ� ��ȯ�Ѵ�.
	iterator erase(const T& Data)
	{
		CNode* Node = mBegin->mNext;

		while (mEnd != Node)
		{
			if (Node->mData == Data)
			{
				iterator	iter;
				iter = Node;

				return erase(iter);
			}

			Node = Node->mNext;
		}

		// �����Ͱ� ���� ��� end�� �����Ѵ�.
		return end();
	}

	iterator erase(const iterator& iter)
	{
		if (iter == end())
			return end();

		CNode* Prev = iter.mNode->mPrev;
		CNode* Next = iter.mNode->mNext;

		// �������� �������� ������带 ���� �����Ѵ�.
		Prev->mNext = Next;
		Next->mPrev = Prev;

		// ���� ��带 �����Ѵ�.
		delete iter.mNode;

		// ������ ����� �������� iterator�� �����Ͽ� ��ȯ�Ѵ�.
		iterator	result;
		result.mNode = Next;

		return result;
	}
};