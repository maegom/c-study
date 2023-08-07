
#include <iostream>

/*
상속관계에서 생성자, 소멸자 호출순서
생성자 : 부모 -> 자식
소멸자 : 자식 -> 부모

함수 재정의 : 부모클래스에 있는 함수를 자식클래스에 똑같은 형태로 재정의를
할 수 있는 기능이다.
함수가 재정의되어 있다면 CParent타입으로 호출할 경우 CParent에 구현되어 있는
함수가 호출되고 CChild타입으로 호출할 경우 CChild에 구현되어 있는 함수가
호출된다.
부모클래스에 구현된 함수와 자식클래스에 구현된 함수는 서로 다른 주소가 나오며
다른함수로 인식이 된다.

가상함수 : 클래스의 멤버함수 앞에 virtual 이 붙으면 해당 함수는 가상함수가 된다.
가상함수를 가지고 있는 클래스는 객체를 생성하게 되면 가상함수 테이블을 가지게된다.
가상함수 테이블은 클래스마다 1개씩 존재하며 같은 타입의 객체를 아무리 많이 생성
하더라도 1개만 존재한다.
그래서 가상함수를 가지고 있는 클래스를 이용해서 객체를 생성하면 해당 가상함수테이블의
주소가 해당 객체의 __vfptr 이라는 내부 변수(프로그래머가 접근하면 안되는)에 해당
가상함수테이블의 주소를 저장해두고 가상함수 호출시 사용하게 된다.

가상함수 테이블은 해당 클래스에서 가상함수로 구현된 함수들의 메모리 주소를
저장하는 배열이다.

일반함수는 호출하면 해당 함수의 주소로 바로 호출을 시도한다.
하지만 가상함수는 호출을 하면 일단 가상함수 테이블에서 해당 함수의 주소가
어떤 주소로 저장되어 있는지를 판단하고 그 주소를 이용하여 함수를 호출한다.
즉,

클래스도 멤버변수가 없을 경우 sizeof를 하게 되면 최소 바이트인 1바이트가 나오게
된다.
단, 가상함수를 가지고 있는 클래스일 경우 x64에서는 8바이트, x86에서는 4바이트가
나오게 된다.
*/

// CParent에 2개의 가상함수가 있다.
// 1. 소멸자    2. Output
class CParent
{
public:
    CParent()
    {
        std::cout << "CParent 생성자" << std::endl;
    }

    virtual ~CParent()
    {
        std::cout << "CParent 소멸자" << std::endl;
    }

public:
    virtual void Output()
    {
        std::cout << "CParent Output Function" << std::endl;
    }
};

// CChild에 2개의 가상함수가 있다.
// 1. 소멸자    2. Output
// 부모 클래스에도 소멸자와 Output 함수가 virtual 로 구성되어 있으므로
// CChild 클래스는 가상함수 테이블에 가상함수 2개, 소멸자와 Output함수의주소를
// CChild에 재정의한 소멸자와 Output함수의 주소로 가상함수 테이블을 채워준다.
class CChild : public CParent
{
public:
    CChild()
    {
        std::cout << "CChild 생성자" << std::endl;
    }

    virtual ~CChild()
    {
        std::cout << "CChild 소멸자" << std::endl;
    }

public:
    virtual void Output()
    {
        std::cout << "CChild Output Function" << std::endl;
    }
};

// CChild1에 1개의 가상함수가 있다.
// 1. 소멸자
// 부모 클래스에는 소멸자와 Output 함수가 virtual 로 구성되어 있으므로
// CChild1 클래스는 가상함수 테이블에 소멸자는 재정의된 CChild1 클래스의 소멸자가
// 가상함수테이블에 저장되고 Output함수는 재정의가 없기 때문에  CParent 클래스에
// 구현된 함수의 메모리 주소가 가상함수 테이블에 저장된다.
class CChild1 : public CParent
{
public:
    CChild1()
    {
        std::cout << "CChild1 생성자" << std::endl;
    }

    ~CChild1()
    {
        std::cout << "CChild1 소멸자" << std::endl;
    }
};

class CChildChild : public CChild
{
public:
    CChildChild()
    {
        std::cout << "CChildChild 생성자" << std::endl;
    }

    ~CChildChild()
    {
        std::cout << "CChildChild 소멸자" << std::endl;
    }

public:
    void Output()
    {
        std::cout << "CChildChild Output Function" << std::endl;
    }
};

int main()
{
    //CChild   child;

    std::cout << "CParent : " << sizeof(CParent) << std::endl;
    std::cout << "CChild : " << sizeof(CChild) << std::endl;
    std::cout << "CChild1 : " << sizeof(CChild1) << std::endl;
    /*CParent* Child = new CChild;

    Child->Output();

    delete   Child;*/
    CParent* ChildArr[3] = {};
    ChildArr[0] = new CChild;
    ChildArr[1] = new CChild1;
    ChildArr[2] = new CChildChild;
    for (int i = 0; i < 3; ++i)
    {
        ChildArr[i]->Output();
    }

    return 0;
}