#include <iostream>

class CSingleton
{
private:
    CSingleton()
    {
    }

    ~CSingleton()
    {
    }

    // �̱��� ��ü�� �����ǰ� �ش� �޸� �ּҸ� �����ϱ� ���� ������ �����Ѵ�.
private:
    static CSingleton* mInst;

public:
    static CSingleton* GetInst()
    {
        // mInst�� nullptr�̶�� ���� �����Ҵ�� ��ü�� �޸� �ּҰ� ���� ���ٴ� ���̴�.
        // �׷��Ƿ� CSingleton Ŭ������ �ϳ� �����Ҵ��ϰ� �� �޸� �ּҸ� mInst������
        // �����صд�.
        // ������ mInst�� nullptr�� �ƴ϶�� �̹� �����Ҵ�� �޸� �ּҸ� ������ �����Ƿ�
        // �׳� �� �ּҸ� ���ϸ� ���ش�.
        if (nullptr == mInst)
            mInst = new CSingleton;

        return mInst;
    }

    static void DestroyInst()
    {
        if (nullptr != mInst)
        {
            delete mInst;
            mInst = nullptr;
        }
    }
};

CSingleton* CSingleton::mInst = nullptr;


int main()
{
    //CSingleton   single;
    for (int i = 0; i < 10; ++i)
    {
        std::cout << CSingleton::GetInst() << std::endl;
    }

    CSingleton::DestroyInst();

    return 0;

     
}