#pragma once

#include <iostream>

template <typename T>
class CArray
{
public:
	CArray()
	{
		mCapacity = 4;
		mCount = 0;

		mData = new T[mCapacity];
	}

	~CArray()
	{
		delete[] mData;
	}

private:
	T* mData;
	int	mCapacity;	// 배열이 총 몇개인지를 저장.
	int	mCount;		// 실제 추가된 데이터 수

public:
	void push_back(const T& data)
	{
		// 배열이 꽉 찼는지 검사한다.
		if (mCapacity == mCount)
		{
			// 배열 용량을 2배만큼 늘린다.
			mCapacity *= 2;

			// 늘어난 공간을 할당한다.
			T* Array = new T[mCapacity];

			// 원래의 배열에 있던 데이터를 늘어난 공간에 복사한다.
			// Dest : 복사할 위치
			// Source : 복사대상 위치
			// Size : 복사할 바이트 수
			// Source에 지정된 메모리 주소로부터 Size에 지정된 바이트 수만큼을
			// Dest에 지정된 메모리에 Size에 지정된 바이트 수만큼 복사한다.
			// sizeof(T) : 배열 1개의 크기
			memcpy(Array, mData, sizeof(T) * mCount);

			// 원본 배열을 제거한다.
			delete[] mData;

			// 공간이 늘어나서 재할당된 배열을 실제 배열로 사용할 수 있게 그 주소를
			// 포인터에 넣어둔다.
			mData = Array;
		}

		mData[mCount] = data;
		++mCount;
	}

	void pop_back()
	{
		if (mCount == 0)
			return;

		--mCount;
	}

	void Remove(int Index)
	{
		if (Index < 0 || Index >= mCount)
			return;

		for (int i = Index; i < mCount - 1; ++i)
		{
			mData[i] = mData[i + 1];
		}

		--mCount;
	}

	/*
	함수 뒤에 const를 붙이게 되면 이 함수에서는 멤버변수의 값을 변경할 수 없다.
	만약 이 클래스를 이용해서 생성된 객체가 const 변수에 저장된다면 함수 뒤에
	const 를 붙여준 함수만 호출이 가능하다.
	*/
	int size()	const
	{
		return mCount;
	}

	int capacity()	const
	{
		return mCapacity;
	}

	bool empty()	const
	{
		return mCount == 0;
	}

	T& Get(int Index = 0)	const
	{
		return mData[Index];
	}

	T& operator [] (int Index)	const
	{
		return mData[Index];
	}

	/*void* operator new (size_t Size)
	{
		std::cout << "CArray Operator new" << std::endl;
		return nullptr;
	}

	void operator delete (void* Addr)
	{
		std::cout << "CArray Operator delete" << std::endl;
	}*/
};

