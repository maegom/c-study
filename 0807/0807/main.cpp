
#include <iostream>

/*
상속 : 클래스와 클래스 사이에 부모와 자식의 관계를 형성하여
부모의 멤버를 자식이 상속받는 기능이다.

class CParent
{
public:
   int   mA;

private:
   int   mB;

public:
   int GetB()
   {
      return mB;
   }
};

class CChild : public CParent
{
pulbic:
   int   mC;
};

public : 자기자신, 외부, 자식 내부에서 모두 접근이 가능하다.

private : 자기자신에서는 접근이 가능하지만 외부, 자식 내부에서는
접근이 불가능하다.

protected : 자기자신, 자식 내부에서는 접근이 가능하지만 외부에서는
접근이 불가능하다.

다형성 : 상속관계에 있는 클래스 사이에 서로 형변환이 가능한 성질을
말한다.

업캐스팅 : 자식타입을 부모타입으로 형변환 하는것을 말한다.

다운캐스팅 : 부모타입을 자식타입으로 형변환 하는것을 말한다.

*/

class CParent
{
public:
    CParent()
    {
        std::cout << "CParent 생성자" << std::endl;
    }

    ~CParent()
    {
        std::cout << "CParent 소멸자" << std::endl;
    }

public:
    int   mA;

private:
    int   mB;

protected:
    int   mD;

public:
    int GetB()
    {
        return mB;
    }

public:
    void Output()
    {
        std::cout << "CParent Output Function" << std::endl;
    }
};

class CParent1
{
public:
    CParent1()
    {
        std::cout << "CParent1 생성자" << std::endl;
    }

    ~CParent1()
    {
        std::cout << "CParent1 소멸자" << std::endl;
    }

public:
    int   mA11;
};

class CChild : public CParent, private CParent1
{
public:
    int   mC;

public:
    CChild()
    {
        std::cout << "CChild 생성자" << std::endl;
    }

    ~CChild()
    {
        std::cout << "CChild 소멸자" << std::endl;
    }
};

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

public:
    int   mD;

public:
    void OutputChild1()
    {
        std::cout << "CChild1 OutputChild1 Function" << std::endl;
    }

};

class CChild2 : public CParent
{
public:
    CChild2()
    {
        std::cout << "CChild2 생성자" << std::endl;
    }

    ~CChild2()
    {
        std::cout << "CChild2 소멸자" << std::endl;
    }

public:
    int   mF;
    int   mG;

public:
    void OutputChild2()
    {
        std::cout << "CChild2 OutputChild2 Function" << std::endl;
    }
};

class CChild3 : public CParent
{
public:
    CChild3()
    {
        std::cout << "CChild3 생성자" << std::endl;
    }

    ~CChild3()
    {
        std::cout << "CChild3 소멸자" << std::endl;
    }

};

class CChildChild : public CChild3
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

};

int main()
{
    CParent* ChildArray[10] = {};

    ChildArray[0] = new CChild1;
    ChildArray[1] = new CChild2;
    ChildArray[2] = new CChild3;
    ChildArray[3] = new CChildChild;

    ((CChild1*)ChildArray[2])->OutputChild1();

    for (int i = 0; i < 3; ++i)
    {
        ChildArray[i]->Output();
    }


    // 아래는 CChild 클래스를 이용해서 객체를 생성하고 그 주소를
    // CParent 포인터 타입 변수에 저장해두었다.
    // 이렇게 하면 자식클래스 타입을 부모인 CParent클래스 타입으로
    // 형변환해서 저장한다.
    CParent* Child = new CChild;

    // CChild1 객체를 생성하고 그 주소를 CParent 포인터 타입에 저장했다.
    // 업캐스팅이 일어났다.
    CParent* Child1 = new CChild1;

    //CChild2* Child22 = new CChild1;
    //CChild1* Child11 = new CChild1;

    // CChild2 객체를 생성하고 그 주소를 CParent 포인터 타입에 저장했다.
    // 업캐스팅이 일어났다.
    CParent* Child2 = new CChild2;

    // Child1 포인터 변수는 CParent 타입의 포인터 변수이다. 그렇기 때문에
    // 자식객체의 메모리 주소를 가지고 있다고 하더라도 타입 자체가 CParent의
    // 포인터 타입이므로 CParent의 멤버만 접근이 가능하다.
    // 만약 CChild1 에 구현되어 있는 내용에 대해 접근하고자 한다면 CChild1 타입
    // 으로 다운캐스팅하여 사용해야 한다.
    Child1->Output();
    //Child1->OutputChild1();
    ((CChild1*)Child1)->OutputChild1();

    // Child1 포인터 변수는 CChild1 객체를 생성하고 그 주소를 업캐스팅
    // 하여 저장해두었다. 그러므로 아래와 같이 다시 CChild1 타입의 포인터
    // 타입 변수에 주소를 저장할 수 있다.
    CChild1* Child1Ptr = (CChild1*)Child1;

    // Child2 포인터 변수는 CChild2 객체를 생성하고 그 주소를 업캐스팅
    // 하여 저장해두었다. 그러므로 아래와 같이 다시 CChild2 타입의 포인터
    // 타입 변수에 주소를 저장할 수 있다.
    CChild2* Child2Ptr = (CChild2*)Child2;

    // Child2 포인터 변수는 CChild2 객체를 생성하고 그 주소를 업캐스팅
    // 하여 저장해두었다. 그런데 아래에서는 CChild1 포인터 타입으로
    // 형변환하여 CChild1 포인터 타입 변수에 주소를 저장하고 있다.
    // 에러는 아니다. Child2 는 CParent 포인터 타입 변수이므로 이 변수가
    // 어떤 객체의 주소를 저장하고 있더라도 일단 CParent 포인터 타입이므로
    // CParent를 상속받고 있는 타입의 메모리 주소로 형변환하여 저장하는
    // 것이 가능하다.(상속만 받으면 다운캐스팅 가능)
    CChild1* Child1Patr1 = (CChild1*)Child2;

    CChild2* Child2Patr2 = (CChild2*)Child1;

    //CChild   child;

    //child.mA = 100;
    //child.mD = 500;
    //child.mA11 = 500;

    /*CParent1   parent1;

    parent1.mA11 = 500;

    CChild   ChildArr[100];
    CChild1   ChildArr1[100];
    CChild2   ChildArr2[100];
    CChild3   ChildArr3[100];*/


    return 0;
}