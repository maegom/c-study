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

    // 싱글톤 객체가 생성되고 해당 메모리 주소를 저장하기 위한 변수를 생성한다.
private:
    static CSingleton* mInst;

public:
    static CSingleton* GetInst()
    {
        // mInst가 nullptr이라는 것은 동적할당된 객체의 메모리 주소가 아직 없다는 것이다.
        // 그러므로 CSingleton 클래스를 하나 동적할당하고 그 메모리 주소를 mInst변수에
        // 저장해둔다.
        // 하지만 mInst가 nullptr이 아니라면 이미 동적할당된 메모리 주소를 가지고 있으므로
        // 그냥 그 주소를 리턴만 해준다.
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