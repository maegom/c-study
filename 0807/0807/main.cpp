
#include <iostream>

/*
��� : Ŭ������ Ŭ���� ���̿� �θ�� �ڽ��� ���踦 �����Ͽ�
�θ��� ����� �ڽ��� ��ӹ޴� ����̴�.

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

public : �ڱ��ڽ�, �ܺ�, �ڽ� ���ο��� ��� ������ �����ϴ�.

private : �ڱ��ڽſ����� ������ ���������� �ܺ�, �ڽ� ���ο�����
������ �Ұ����ϴ�.

protected : �ڱ��ڽ�, �ڽ� ���ο����� ������ ���������� �ܺο�����
������ �Ұ����ϴ�.

������ : ��Ӱ��迡 �ִ� Ŭ���� ���̿� ���� ����ȯ�� ������ ������
���Ѵ�.

��ĳ���� : �ڽ�Ÿ���� �θ�Ÿ������ ����ȯ �ϴ°��� ���Ѵ�.

�ٿ�ĳ���� : �θ�Ÿ���� �ڽ�Ÿ������ ����ȯ �ϴ°��� ���Ѵ�.

*/

class CParent
{
public:
    CParent()
    {
        std::cout << "CParent ������" << std::endl;
    }

    ~CParent()
    {
        std::cout << "CParent �Ҹ���" << std::endl;
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
        std::cout << "CParent1 ������" << std::endl;
    }

    ~CParent1()
    {
        std::cout << "CParent1 �Ҹ���" << std::endl;
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
        std::cout << "CChild ������" << std::endl;
    }

    ~CChild()
    {
        std::cout << "CChild �Ҹ���" << std::endl;
    }
};

class CChild1 : public CParent
{
public:
    CChild1()
    {
        std::cout << "CChild1 ������" << std::endl;
    }

    ~CChild1()
    {
        std::cout << "CChild1 �Ҹ���" << std::endl;
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
        std::cout << "CChild2 ������" << std::endl;
    }

    ~CChild2()
    {
        std::cout << "CChild2 �Ҹ���" << std::endl;
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
        std::cout << "CChild3 ������" << std::endl;
    }

    ~CChild3()
    {
        std::cout << "CChild3 �Ҹ���" << std::endl;
    }

};

class CChildChild : public CChild3
{
public:
    CChildChild()
    {
        std::cout << "CChildChild ������" << std::endl;
    }

    ~CChildChild()
    {
        std::cout << "CChildChild �Ҹ���" << std::endl;
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


    // �Ʒ��� CChild Ŭ������ �̿��ؼ� ��ü�� �����ϰ� �� �ּҸ�
    // CParent ������ Ÿ�� ������ �����صξ���.
    // �̷��� �ϸ� �ڽ�Ŭ���� Ÿ���� �θ��� CParentŬ���� Ÿ������
    // ����ȯ�ؼ� �����Ѵ�.
    CParent* Child = new CChild;

    // CChild1 ��ü�� �����ϰ� �� �ּҸ� CParent ������ Ÿ�Կ� �����ߴ�.
    // ��ĳ������ �Ͼ��.
    CParent* Child1 = new CChild1;

    //CChild2* Child22 = new CChild1;
    //CChild1* Child11 = new CChild1;

    // CChild2 ��ü�� �����ϰ� �� �ּҸ� CParent ������ Ÿ�Կ� �����ߴ�.
    // ��ĳ������ �Ͼ��.
    CParent* Child2 = new CChild2;

    // Child1 ������ ������ CParent Ÿ���� ������ �����̴�. �׷��� ������
    // �ڽİ�ü�� �޸� �ּҸ� ������ �ִٰ� �ϴ��� Ÿ�� ��ü�� CParent��
    // ������ Ÿ���̹Ƿ� CParent�� ����� ������ �����ϴ�.
    // ���� CChild1 �� �����Ǿ� �ִ� ���뿡 ���� �����ϰ��� �Ѵٸ� CChild1 Ÿ��
    // ���� �ٿ�ĳ�����Ͽ� ����ؾ� �Ѵ�.
    Child1->Output();
    //Child1->OutputChild1();
    ((CChild1*)Child1)->OutputChild1();

    // Child1 ������ ������ CChild1 ��ü�� �����ϰ� �� �ּҸ� ��ĳ����
    // �Ͽ� �����صξ���. �׷��Ƿ� �Ʒ��� ���� �ٽ� CChild1 Ÿ���� ������
    // Ÿ�� ������ �ּҸ� ������ �� �ִ�.
    CChild1* Child1Ptr = (CChild1*)Child1;

    // Child2 ������ ������ CChild2 ��ü�� �����ϰ� �� �ּҸ� ��ĳ����
    // �Ͽ� �����صξ���. �׷��Ƿ� �Ʒ��� ���� �ٽ� CChild2 Ÿ���� ������
    // Ÿ�� ������ �ּҸ� ������ �� �ִ�.
    CChild2* Child2Ptr = (CChild2*)Child2;

    // Child2 ������ ������ CChild2 ��ü�� �����ϰ� �� �ּҸ� ��ĳ����
    // �Ͽ� �����صξ���. �׷��� �Ʒ������� CChild1 ������ Ÿ������
    // ����ȯ�Ͽ� CChild1 ������ Ÿ�� ������ �ּҸ� �����ϰ� �ִ�.
    // ������ �ƴϴ�. Child2 �� CParent ������ Ÿ�� �����̹Ƿ� �� ������
    // � ��ü�� �ּҸ� �����ϰ� �ִ��� �ϴ� CParent ������ Ÿ���̹Ƿ�
    // CParent�� ��ӹް� �ִ� Ÿ���� �޸� �ּҷ� ����ȯ�Ͽ� �����ϴ�
    // ���� �����ϴ�.(��Ӹ� ������ �ٿ�ĳ���� ����)
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