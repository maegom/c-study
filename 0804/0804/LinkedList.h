#pragma once

/*
friend : 다른 클래스에서 이 클래스의 private에 접근할 수 있게 해주는 기능이다.

*/

//노드 클래스 
template <typename T>
class CLinkedListNode
{
	//friend : 다른 클래스에서 이 클래스의 private에 접근할 수 있게 해주는 기능이다.
	template <typename T>
	friend class CLinkedList;

	template <typename T>
	friend class CLinkedListIterator;

private:
	//생성자 
	CLinkedListNode() :
		mNext(nullptr), //노드 초기화
		mPrev(nullptr)
	{
	}
	~CLinkedListNode()
	{
	}
private :
	T					mData; // 데이터
	CLinkedListNode<T>* mNext; // 다음노드 주소
	CLinkedListNode<T>* mPrev; // 이전노드 주소
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
	// 전위연산
	void operator ++ ()
	{
		mNode = mNode->mNext;
	}

	// 후위연산
	void operator ++ (int)
	{
		mNode = mNode->mNext;
	}

	// 전위연산
	void operator -- ()
	{
		mNode = mNode->mPrev;
	}

	// 후위연산
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

//실제 Linked List 클래스
template <typename T>
class CLinkedList
{

public:
	//생성자
	CLinkedList()
	{
		mBegin = new CNode; //맨처음 노드 동적할당 (자료저장 시작될 앞노드)
		mEnd = new CNode;   //마지막 노드

		//초기 설정 
		mBegin->mNext = mEnd;   // 맨 앞노드 다음 노드 주소를 맨뒤 노드로 설정
		mEnd->mPrev = mBegin;   // 맨 뒤노드 전 노드주로를 맨앞 노드로 설정

		mCount = 0;
	}
	//소멸자
	~CLinkedList()
	{
		//노드 맨앞부터 delete
		CNode* Node = mBegin;

		//노드가 없을 까지 제거
		while (nullptr != Node)
		{
			CNode* Next = Node->mNext; // 제거전 다음 노드 Next 로 받아오기
			delete Node;               // 현재 노드 삭제 
			Node = Next;               // 다음 노드를 현재 노드로 설정
			// 이렇게 하는 이유 : 노드를 먼저 지우면 다음 노드를 알 수 없다. 
		}
	}

private :
	//typedef : 타입을 재정의 한다. (CLinkedListNode<T> 타입을 CNode라는 이름으로 대체 가능)
	typedef CLinkedListNode<T> CNode;

public:
	// public으로 typedef 을 해두면 클래스 외부에서도 이 타입을 사용하여
	// 변수를 선언할 수 있다.
	typedef CLinkedListIterator<T>	iterator;

private :
	//더미 노드 (처음과 끝) 를 쓰면 접근이 더 편하다.
	CNode* mBegin;
	CNode* mEnd;
	int mCount; //노드 개수

public : 
	//뒤에 추가
	void push_back(const T& Data)
	{	// 뒤에 추가는 End노드와 End노드의 이전노드 사이에 추가

		//노드 동적할당 
		CNode* Node = new CNode;

		//노드에 데이터 저장
		Node->mData = Data;

		//이전 노드 만들어 (끝)더미노드의 전노드 저장
		CNode* Prev = mEnd->mPrev;

		//이전노드의 다음노드에 추가할 노드 저장, 추가할노드에 이전노드에 이전노드 저장
		Prev->mNext = Node;
		Node->mPrev = Prev;

		//(끝) 더미노드의 전 노드에 추가할 노드 저장, 추가할 노드 다음에 (끝) 더미노드 저장
		mEnd->mPrev = Node;
		Node->mNext = mEnd;

		//노드 개수 추가
		++mCount;
	}
	//앞에 추가
	void  push_front(const T& Data)
	{	// 앞에 추가는 Begin노드와 Begin노드의 다음노드 사이에 추가
	
		//노드 동적할당
		CNode* Node = new CNode;

		//노드에 데이터 저장
		Node->mData = Data;
		
		//다음 노드 만들어 (처음)더미노드의 다음노드 저장
		CNode* Next = mBegin->mNext;

		//다음노드의 이전노드에 추가할 노드 저장, 추가할 노드의 다음노드에 다음노드 저장
		Next->mPrev = Node;
		Node->mNext = Next;

		//(처음) 더미노드의 다음 노드에 추가할 노드 저장, 추가할 노드 이전에 (처음)더미노드 저장
		mBegin->mNext = Node;
		Node->mPrev = mBegin;

		//노드 숫자 증가
		++mCount;
	}
	// 뒤 노드 삭제
	void pop_back()
	{	//맨끝 노드(더미)의 전노드 삭제

		// 비어있을 경우 제외
		if (empty())
			return;

		//제거할 노드에 마지막 전 노드 저장
		CNode* DeleteNode = mEnd->mPrev;
		//이전 노드에 제거할 노드의 전 노드 저장
		CNode* Prev = DeleteNode->mPrev;

		// 지울 노드의 이전노드와 End노드를 연결한다.
		Prev->mNext = mEnd; //이전노드의 다음노드에 (끝)더미노드 저장
		mEnd->mPrev = Prev; //(끝)더미노드의 이전노드에 이전노드 저장

		//제거할 노드 delete
		delete   DeleteNode;

		//노드 개수 줄임
		--mCount;
	}
	//앞 노드 삭제 
	void pop_front()
	{	//맨 앞 노드(더미)의 다음노드 삭제

		// 비어있을 경우 제외
		if (empty())
			return;

		//제거할 노드에 맨처음 다음 노드 저장
		CNode* DeleteNode = mBegin->mNext;
		//다음노드에 제거할노드의 다음노드 저장
		CNode* Next = DeleteNode->mNext;

		// 지울 노드의 이전노드와 End노드를 연결한다.
		Next->mPrev = mBegin; //다음노드의 이전노드에 (처음)더미노드 저장
		mBegin->mNext = Next; //(처음)더미노드의 다음노드에 다음노드 저장

		//제거할 노드 delete
		delete   DeleteNode;

		//노드 개수 줄임
		--mCount;
	}

	//현재 노드개수 호출
	int size()   const
	{
		return mCount;
	}

	//비어있는지 판단 비어있으면 = 1(true)
	bool empty()   const
	{
		return mCount == 0;
	}

	void clear()
	{
		// Begin과 End를 제외한 실제 데이터를 추가하기 위해 생성한 노드
		// 를 제거한다.
		CNode* Node = mBegin->mNext;

		while (mEnd != Node)
		{
			// 다음 노드를 미리 받아둔다. 현재 노드를 제거하게 되면
			// 다음 노드의 주소를 알 수 없기 때문에 다음 노드를 미리
			// 받아두고 현재 노드를 제거한다.
			CNode* Next = Node->mNext;

			delete	Node;

			Node = Next;
		}

		// Begin과 End를 연결한다.
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

	// erase 함수는 노드를 제거하고 제거한 노드의 다음 노드를
	// iterator로 구성하여 반환한다.
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

		// 데이터가 없을 경우 end를 리턴한다.
		return end();
	}

	iterator erase(const iterator& iter)
	{
		if (iter == end())
			return end();

		CNode* Prev = iter.mNode->mPrev;
		CNode* Next = iter.mNode->mNext;

		// 지울노드의 이전노드와 다음노드를 서로 연결한다.
		Prev->mNext = Next;
		Next->mPrev = Prev;

		// 현재 노드를 제거한다.
		delete iter.mNode;

		// 제거한 노드의 다음노드로 iterator를 구성하여 반환한다.
		iterator	result;
		result.mNode = Next;

		return result;
	}
};