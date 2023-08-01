
#include "GameManager.h"

///*
//Ŭ������ static �������
//�Ϲ� ��������� Ŭ������ �̿��ؼ� ��ü�� �����ϸ� ������ ��ü���� �޸𸮰� �Ҵ�ǰ�
//�ȴ�. static ��������� Ŭ������ �̿��ؼ� ��ü�� �ƹ��� ���� �����ص� ������ 1����
//������ ��������� �ǰ� �� ��ü���� �̸� �����ؼ� ����ϰ� �ȴ�.
//
//static ��������� Ŭ���� �ܺο� �ش�  static ������ ����ϰڴٴ� ���Ǻκ��� �ݵ��
//�ʿ��ϴ�.
//����Ÿ�� Ŭ�����̸�::�����̸�; ���� ������ �� �ִ�.
//����Ÿ�� Ŭ�����̸�::�����̸� = �ʱⰪ; ���� ������ �� �ִ�.
//*/
//class CStatic
//{
//public:
//    CStatic()
//    {
//    }
//
//    ~CStatic()
//    {
//    }
//
//public:
//    int      mNumber1;
//    static int mNumberStatic;
//    static int mNumberStatic2;
//
//public:
//    void Output()
//    {
//        std::cout << "Output Function" << std::endl;
//        std::cout << "mNumber1 = " << mNumber1 << std::endl;
//        std::cout << "mNumberStatic = " << mNumberStatic << std::endl;
//        std::cout << "mNumberStatic2 = " << mNumberStatic2 << std::endl;
//    }
//
//    static void OutputStatic()
//    {
//        std::cout << "OutputStatic Function" << std::endl;
//
//        // static ����Լ��� this�� ����. �׷��� ������ �Ϲ� ��������� ������ �� ����
//        // static ��������� ����� �����ϴ�.
//        //std::cout << "mNumber1 = " << mNumber1 << std::endl;
//        std::cout << "mNumberStatic = " << mNumberStatic << std::endl;
//        std::cout << "mNumberStatic2 = " << mNumberStatic2 << std::endl;
//    }
//};
//
//int CStatic::mNumberStatic;
//int CStatic::mNumberStatic2;
//
//int main()
//{
//    CStatic   st1, st2;
//
//    st1.mNumber1 = 100;
//    st2.mNumber1 = 200;
//
//    st1.mNumberStatic = 300;
//    st2.mNumberStatic = 400;
//    CStatic::mNumberStatic = 500;
//
//
//    st1.Output();
//    st2.Output();
//
//    st1.OutputStatic();
//    st2.OutputStatic();
//    CStatic::OutputStatic();
//
//    return 0;
//}

int main()
{

	CGameManager	Mgr;

	Mgr.Init();

	Mgr.Run();

	return 0;
}
