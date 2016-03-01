#include<iostream>

using namespace std;

//��ֵ���ݹ����ڻ���������ʹ�õĵط��������ù���������(�����ǹ���������)���������档���������֣�
//1.������Ķ�����Ը�ֵ������Ķ���Ҳ���ǽ����������ӻ���̳еĳ�Ա��ֵ�ֱ�ֵ�����������Ӧ�ĳ�Ա�����磺
//     base = child;
//2.���������ĵ�ַ���Ը�ֵ���������͵�ָ�롣���磺
//     pBase = &child;
//3.������������������ʼ����������á����磺
//     Base &b = child;
class Base // ����Base������
{
	public:
	void show()    { cout << "Base::show()" << endl; }      // ���г�Ա����show
};

class Child0 : public Base     // ��Base�Ĺ���������Child0������
{
	public:
	void show()    { cout << "Child0::show()" << endl; }    // ���г�Ա����show
};

class Child1 : public Child0   // ��Child0�Ĺ���������Child1������
{
	public:
	void show()    { cout << "Child1::show()" << endl; }    // ���г�Ա����show
};

void CallShow(Base *pBase)// һ�㺯��������Ϊ����ָ��
{
	pBase->show();
}

int main()
{
	//��Ȼ���������������Դ���������ʹ�ã�����ֻ��ʹ�����ӻ���̳еĳ�Ա�����޷�ʹ�����������Ա��
	//��˽����������ĵ�ַ��ֵ��pBase�Ժ�ͨ��pBaseֻ�ܷ���������ӻ���̳еĳ�Ա������ָ��
	//pBaseָ��������������ch0����ch1����CallShow��ͨ��pBaseҲֻ�ܵ��ôӻ���Base�̳еĳ�Ա����show
	//�����������Child0�����Child1��ĳ�Ա����show����������������ε���CallShow���������Ƿ��ʵĻ���
	//Base�ĳ�Ա����show���������Base::show()�� ��ʱ�������еĸ��ܵ�����ʹ�������������˻������
	//��Ҳֻ�ܲ�������Ĺ��ܣ��Լ����¹����޷����֡�Ҫ���ڴ����Ժ�ͬ���ܹ�ʵ���Լ��Ĺ��ܣ���Ҫ�õ�����
	//������Ƶ���һ������--��̬�ԡ�
	Base base;       // ����Base��Ķ���
	Base *pBase;     // ����Base���ָ��
	Child0 ch0       // ����Child0��Ķ���
	Child1 ch1;      // ����Child1��Ķ���
	pBase = &base;   // ��Base�����base�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBase);
	pBase = &ch0;    // ��Child0�����ch0�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBase);
	pBase = &ch1;    // ��Child1�����ch1�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBase);
	return 0;
}