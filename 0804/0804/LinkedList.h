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
	friend CLinkedList;

private:
	//생성자 
	CLinkedListNode() :
		mnext(nullptr), //노드 초기화
		mprev(nullptr),
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
	//typedef : 타입을 재정의 한다. (CLinkedListNode<T> 타음을 CNode라는 이름으로 대체 가능)
	typedef CLinkedListNode<T> CNode;

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
};