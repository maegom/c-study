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
	int	mCapacity;	// �迭�� �� ������� ����.
	int	mCount;		// ���� �߰��� ������ ��

public:
	void push_back(const T& data)
	{
		// �迭�� �� á���� �˻��Ѵ�.
		if (mCapacity == mCount)
		{
			// �迭 �뷮�� 2�踸ŭ �ø���.
			mCapacity *= 2;

			// �þ ������ �Ҵ��Ѵ�.
			T* Array = new T[mCapacity];

			// ������ �迭�� �ִ� �����͸� �þ ������ �����Ѵ�.
			// Dest : ������ ��ġ
			// Source : ������ ��ġ
			// Size : ������ ����Ʈ ��
			// Source�� ������ �޸� �ּҷκ��� Size�� ������ ����Ʈ ����ŭ��
			// Dest�� ������ �޸𸮿� Size�� ������ ����Ʈ ����ŭ �����Ѵ�.
			// sizeof(T) : �迭 1���� ũ��
			memcpy(Array, mData, sizeof(T) * mCount);

			// ���� �迭�� �����Ѵ�.
			delete[] mData;

			// ������ �þ�� ���Ҵ�� �迭�� ���� �迭�� ����� �� �ְ� �� �ּҸ�
			// �����Ϳ� �־�д�.
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
	�Լ� �ڿ� const�� ���̰� �Ǹ� �� �Լ������� ��������� ���� ������ �� ����.
	���� �� Ŭ������ �̿��ؼ� ������ ��ü�� const ������ ����ȴٸ� �Լ� �ڿ�
	const �� �ٿ��� �Լ��� ȣ���� �����ϴ�.
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

