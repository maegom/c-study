#pragma once
#include <iostream>

//Array Ŭ����
template <typename T>
class CArray
{
public:
	//������
	CArray()
	{
		//�ʱ� ���� 
		mCapacity = 4; //�뷮 4
		mCount = 0;    //���� 0 

		mData = new T[mCapacity]; //�뷮�� �´� �����ͺ��� �����Ҵ�
	}
	//�Ҹ���
	~CArray()
	{
		delete[] mData; //������ �迭 delete
	}

private:
	//T	mData[50];  //�迭 �뷮�� ������ �� ������
	T* mData;		//�ٲٱ� ����
	int mCapacity;	//�迭�� �� ������� ����
	int mCount;		//���� �߰��� ������ ��

public:
	//������ �߰�
	void push_back(const T& data)
	{
		//�迭�� �� á���� �˻��Ѵ�. 
		if (mCapacity == mCount)
		{
			//�뷮 2��� �÷���
			mCapacity *= 2;

			//�þ ������ �Ҵ��Ѵ�. 
			T* Array = new T[mCapacity];

			//������ �迭�� �ִ� �����͸� �þ ������ �����Ѵ�. 
			//Dest : ������ ��ġ
			//Sourse : ������ ��ġ
			//Size : ������ ����Ʈ ��
			//Sourse�� ������ �޸� �ּҷκ��� Size��  ������ ����Ʈ ����ŭ�� 
			//Dest�� ������ �޸𸮿� Size�� ������ ����Ʈ ����ŭ �����Ѵ�. 
			//sizeof(T) : �迭 1���� ũ��
			memcpy(Array, mData, sizeof(T) * mCount);

			//���� �迭�� �����Ѵ�. 
			delete[] mData;

			//������ �þ�� ���Ҵ�� �迭�� ���� �迭�� ����� �� �ְ� �� �ּҸ� �����Ϳ� �־��ش�.
			mData = Array;
		}

		mData[mCount] = data; //�������� ������ �߰�
		++mCount;			  //���� +1
	}

	//������ ������ ����
	void pop_back()
	{
		//������ 0�̸� ����
		if (mCount == 0)
			return;

		--mCount; //�ƴϸ� ������ ���� �ٿ���
	}

	//�߰� ������ �����
	void Remove(int Index)
	{
		//index ���� ó�� 
		if (Index < 0 || Index >= mCount)
			return;

		//���� ������ ���� �ڿ� �ִ� �����͸� �ϳ��� ������
		for (int i = Index; i < mCount - 1; ++i)
		{
			mData[i] = mData[i + 1];
		}

		--mCount; //���� -1
	}

	/*
	�Լ� �ڿ� const�� ���̰� �Ǹ� �Լ������� ��������� ���� ������ �� ����.
	���� �� Ŭ������ �̿��ؼ� ������ ��ü�� const ������ ����ȴٸ� �Լ� �ڿ� const�� �ٿ��� �Լ��� ȣ���� �����ϴ�.
	*/
	//���� ���� ȣ��
	int size() const
	{
		return mCount;
	}
	//�뷮 ȣ��
	int capacity() const
	{
		return mCapacity;
	}
	//����ִ��� ����, ��������� =1(true)
	bool empty() const
	{
		return mCount == 0;
	}
	//�ε����� �ش��ϴ� ������ ȣ��
	T& Get(int Index = 0) const
	{
		return mData[Index];
	}
	//operator�����ε����� ������ ȣ��
	T& operator [] (int Index) const
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

