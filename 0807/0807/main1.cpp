
#include <iostream>

/*
��Ӱ��迡�� ������, �Ҹ��� ȣ�����
������ : �θ� -> �ڽ�
�Ҹ��� : �ڽ� -> �θ�

�Լ� ������ : �θ�Ŭ������ �ִ� �Լ��� �ڽ�Ŭ������ �Ȱ��� ���·� �����Ǹ�
�� �� �ִ� ����̴�.
�Լ��� �����ǵǾ� �ִٸ� CParentŸ������ ȣ���� ��� CParent�� �����Ǿ� �ִ�
�Լ��� ȣ��ǰ� CChildŸ������ ȣ���� ��� CChild�� �����Ǿ� �ִ� �Լ���
ȣ��ȴ�.
�θ�Ŭ������ ������ �Լ��� �ڽ�Ŭ������ ������ �Լ��� ���� �ٸ� �ּҰ� ������
�ٸ��Լ��� �ν��� �ȴ�.

�����Լ� : Ŭ������ ����Լ� �տ� virtual �� ������ �ش� �Լ��� �����Լ��� �ȴ�.
�����Լ��� ������ �ִ� Ŭ������ ��ü�� �����ϰ� �Ǹ� �����Լ� ���̺��� �����Եȴ�.
�����Լ� ���̺��� Ŭ�������� 1���� �����ϸ� ���� Ÿ���� ��ü�� �ƹ��� ���� ����
�ϴ��� 1���� �����Ѵ�.
�׷��� �����Լ��� ������ �ִ� Ŭ������ �̿��ؼ� ��ü�� �����ϸ� �ش� �����Լ����̺���
�ּҰ� �ش� ��ü�� __vfptr �̶�� ���� ����(���α׷��Ӱ� �����ϸ� �ȵǴ�)�� �ش�
�����Լ����̺��� �ּҸ� �����صΰ� �����Լ� ȣ��� ����ϰ� �ȴ�.

�����Լ� ���̺��� �ش� Ŭ�������� �����Լ��� ������ �Լ����� �޸� �ּҸ�
�����ϴ� �迭�̴�.

�Ϲ��Լ��� ȣ���ϸ� �ش� �Լ��� �ּҷ� �ٷ� ȣ���� �õ��Ѵ�.
������ �����Լ��� ȣ���� �ϸ� �ϴ� �����Լ� ���̺��� �ش� �Լ��� �ּҰ�
� �ּҷ� ����Ǿ� �ִ����� �Ǵ��ϰ� �� �ּҸ� �̿��Ͽ� �Լ��� ȣ���Ѵ�.
��,

Ŭ������ ��������� ���� ��� sizeof�� �ϰ� �Ǹ� �ּ� ����Ʈ�� 1����Ʈ�� ������
�ȴ�.
��, �����Լ��� ������ �ִ� Ŭ������ ��� x64������ 8����Ʈ, x86������ 4����Ʈ��
������ �ȴ�.
*/

// CParent�� 2���� �����Լ��� �ִ�.
// 1. �Ҹ���    2. Output
class CParent
{
public:
    CParent()
    {
        std::cout << "CParent ������" << std::endl;
    }

    virtual ~CParent()
    {
        std::cout << "CParent �Ҹ���" << std::endl;
    }

public:
    virtual void Output()
    {
        std::cout << "CParent Output Function" << std::endl;
    }
};

// CChild�� 2���� �����Լ��� �ִ�.
// 1. �Ҹ���    2. Output
// �θ� Ŭ�������� �Ҹ��ڿ� Output �Լ��� virtual �� �����Ǿ� �����Ƿ�
// CChild Ŭ������ �����Լ� ���̺� �����Լ� 2��, �Ҹ��ڿ� Output�Լ����ּҸ�
// CChild�� �������� �Ҹ��ڿ� Output�Լ��� �ּҷ� �����Լ� ���̺��� ä���ش�.
class CChild : public CParent
{
public:
    CChild()
    {
        std::cout << "CChild ������" << std::endl;
    }

    virtual ~CChild()
    {
        std::cout << "CChild �Ҹ���" << std::endl;
    }

public:
    virtual void Output()
    {
        std::cout << "CChild Output Function" << std::endl;
    }
};

// CChild1�� 1���� �����Լ��� �ִ�.
// 1. �Ҹ���
// �θ� Ŭ�������� �Ҹ��ڿ� Output �Լ��� virtual �� �����Ǿ� �����Ƿ�
// CChild1 Ŭ������ �����Լ� ���̺� �Ҹ��ڴ� �����ǵ� CChild1 Ŭ������ �Ҹ��ڰ�
// �����Լ����̺� ����ǰ� Output�Լ��� �����ǰ� ���� ������  CParent Ŭ������
// ������ �Լ��� �޸� �ּҰ� �����Լ� ���̺� ����ȴ�.
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
};

class CChildChild : public CChild
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