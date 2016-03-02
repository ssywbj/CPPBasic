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

//��������أ�start
class CTimeSpan
{
public:
	CTimeSpan(){count++;}
	CTimeSpan(int nHours, int nMins);      // ���캯��
	CTimeSpan(int temp){m_temp = temp; count++;}
	CTimeSpan operator +(CTimeSpan ts);// �������+������Ϊ��Ա������˫Ŀ�����
	CTimeSpan& operator ++();// ǰ�õ�Ŀ���������
	CTimeSpan operator ++(int);//���õ�Ŀ���������
	void SetHours(int Hours) {  m_nHours = Hours; }   
	void SetMins(int Mins) {  m_nMins = Mins; }
	int GetHours()      { return m_nHours; }   // ��ȡСʱ��
	int GetMins()       { return m_nMins; }    // ��ȡ������
	void Show();                               // ��ʾʱ��ֵ
	void Temp();  

	friend int add(CTimeSpan &a);//��Ԫ�������ؼ���friend
	friend class B;//��Ԫ�࣬��B����CTimeSpan����Ԫ�࣬����B�����г�Ա����������CTimeSpan����Ԫ���������ܷ�����CTimeSpan��˽�г�Ա�ͱ�����Ա
	
	static void Count(){cout << "count = " << count << endl;}// ��̬��Ա�������ʾ�̬����
	static void f(CTimeSpan &a);

private:
	int m_nHours;       // Сʱ��
	int m_nMins;        // ������
	int m_temp;           // ��ʱ������������ʾ��Ŀ�����������
	static int count;// ��̬���ݳ�Ա��������˵��
};

int CTimeSpan::count = 0;// ��̬���ݳ�Ա�Ķ�����˵������ʼ��
void CTimeSpan::f(CTimeSpan &a)//��̬������Ա���ʷǾ�̬����
{
	cout << "m_temp = " << a.m_temp << endl;//ע���ʽ������.�Ǿ�̬���ݳ�Ա
}

int add(CTimeSpan &a)//ͨ����Ԫ�ķ�ʽ����ͨ����������ĳ�Ա���������������������ĳ�����е�˽������
{
	return a.m_temp + 10;
}

CTimeSpan::CTimeSpan(int nHours, int nMins)// ���캯����ʵ��
{
	nHours += nMins/60;
	nMins %= 60;
	m_nHours = nHours;
	m_nMins = nMins;
	count++;
}

CTimeSpan CTimeSpan::operator +(CTimeSpan ts)// �������������ʵ��
{
	int nNewHours =  m_nHours + ts.GetHours();
	int nNewMins = m_nMins + ts.GetMins();
	nNewHours += nNewMins/60;
    nNewMins %= 60;
	return CTimeSpan(nNewHours, nNewMins);
}

CTimeSpan& CTimeSpan::operator ++()// ǰ�õ�Ŀ��������غ���
{
	m_temp++;
	return *this;
}

//���õ�Ŀ���������
CTimeSpan CTimeSpan::operator ++(int)      //ע���βα��е����Ͳ��� 
{    
	CTimeSpan old = *this;
	++(*this);
	return old;
}

void CTimeSpan::Show()
{
	cout << m_nHours << "Сʱ" << m_nMins << "����" << endl;
}

void CTimeSpan::Temp()
{
	cout << "m_temp = " << m_temp << endl;
}

//��������أ�end

class B
{   
public:
	void Set(int i);
	void Display();

private:
	CTimeSpan a;
};
/*
��Ԫ��ϵ���ܴ��ݣ������B����CTimeSpan����Ԫ����C������B����Ԫ����C����CTimeSpan���û��������û����Ԫ��ϵ��
��Ԫ��ϵ�ǵ���ģ������B����CTimeSpan����Ԫ����B�ĳ�Ա�������Է�����CTimeSpan�����˽�г�Ա�ͱ�����Ա��
������CTimeSpan�ĳ�Ա�������ܷ�����B�����˽�г�Ա�ͱ�����Ա��
*/
void B::Set(int i)
{
	a.m_temp = i; // ��Ϊ��B����CTimeSpan����Ԫ�࣬������B�ĳ�Ա�������Է�����CTimeSpan�����˽�г�Ա
}
void B::Display()
{
	a.Temp();
}

int main()
{
	//��Ȼ���������������Դ���������ʹ�ã�����ֻ��ʹ�����ӻ���̳еĳ�Ա�����޷�ʹ������������Ա��
	//��˽����������ĵ�ַ��ֵ��pBase�Ժ�ͨ��pBaseֻ�ܷ���������ӻ���̳еĳ�Ա������ָ��
	//pBaseָ��������������ch0����ch1����CallShow��ͨ��pBaseҲֻ�ܵ��ôӻ���Base�̳еĳ�Ա����show
	//�����������Child0�����Child1��ĳ�Ա����show����������������ε���CallShow���������Ƿ��ʵĻ���
	//Base�ĳ�Ա����show���������Base::show()�� ��ʱ�������еĸ��ܵ�����ʹ�������������˻������
	//��Ҳֻ�ܲ�������Ĺ��ܣ��Լ����¹����޷����֡�Ҫ���ڴ����Ժ�ͬ���ܹ�ʵ���Լ��Ĺ��ܣ���Ҫ�õ�����
	//������Ƶ���һ������--��̬�ԡ�
	Base base;       // ����Base��Ķ���
	Base *pBase;     // ����Base���ָ��
	Child0 ch0;       // ����Child0��Ķ���
	Child1 ch1;      // ����Child1��Ķ���
	pBase = &base;   // ��Base�����base�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBase);
	pBase = &ch0;    // ��Child0�����ch0�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBase);
	pBase = &ch1;    // ��Child1�����ch1�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBase);

	CTimeSpan timeSpan1(2, 50);
	CTimeSpan timeSpan2(3, 30);
	CTimeSpan timeSum;
	timeSum = timeSpan1 + timeSpan2;
	cout << "timeSpan1: ";
	timeSpan1.Show();
	cout << "timeSpan2: ";
	timeSpan2.Show();
	cout << "timeSum = timeSpan1 + timeSpan2: ";
	timeSum.Show();

	CTimeSpan timeSpan3(100);
	timeSpan3.SetHours(10);
	timeSpan3.SetMins(11);
	(timeSpan3++).Temp();
	CTimeSpan::f(timeSpan3);
	(++timeSpan3).Temp();
	timeSpan3.Show();

	timeSpan3.Count();
	CTimeSpan::Count();

	cout<<"friend access : "<<add(timeSpan3)<<endl;
	B b;
	b.Set(10000);
	b.Display();

	return 0;
}