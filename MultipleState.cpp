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

	//ò����vc++6.0�в�֧�����������Ϊ�����Ԫ��������Ϊ���벻��
	//friend CTimeSpan operator -(CTimeSpan ts1, CTimeSpan ts2);//�������-������Ϊ����Ԫ����

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

/*�����������Ϊ��Ա����ʱ��ͬ���ǣ����ص���Ԫ�����������κ��࣬������Ĳ�������
��Ҫͨ���������βα��ݡ����������βα��д����ҳ��ֵ�˳������������д���ʽ
ʱ��������˳��

�����˫Ŀ�����U����������һ������������A�Ķ���a����ô�����U�Ϳ�������Ϊ��A����Ԫ������
����Ԫ���������������У�һ������A�Ķ�����һ������������Ҳ��������A�Ķ���
*/
/*CTimeSpan operator -(CTimeSpan ts1, CTimeSpan ts2)  // �������������ʵ��
{
	int nNewHours = ts1.m_nHours  + ts2.m_nHours ;
	int nNewMins = ts1.m_nMins + ts2.m_nMins ;
	nNewHours += nNewMins/60;
	nNewMins %= 60;
	return CTimeSpan(nNewHours, nNewMins);
}
ò����vc++6.0�в�֧�����������Ϊ�����Ԫ��������Ϊ���벻��
*/

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

��Ԫ�ƻ�����ķ�װ�Ժ������ݵ������ԣ������ָ���������ṩ�˺ܶ෽�㣬��ʵ�ؽ������
������ʱ������Լ��ڹ���ͷ�װ֮��ƽ��һ�£������Ƿ�ѡ��ʹ����Ԫ����ԭ���Ͼ�����ʹ
�û�ʹ����Ԫ������ȷʵ�ܴ������˿���Ч�ʡ�
*/
void B::Set(int i)
{
	a.m_temp = i; // ��Ϊ��B����CTimeSpan����Ԫ�࣬������B�ĳ�Ա�������Է�����CTimeSpan�����˽�г�Ա
}
void B::Display()
{
	a.Temp();
}

/*�麯�����ڻ����н�ĳ����������Ϊ�麯�����Ϳ���ͨ��ָ�����������Ļ���ָ������������е�ͬ����Ա�ˡ�
����ʹ��ĳ����ָ��ָ��ͬ������Ĳ�ͬ����ʱ���Ϳ��Է�����ͬ����Ϊ��Ҳ��ʵ��������ʱ�Ķ�̬������˸�ֵ���ݹ�����
ֻ�ܷ��ʵ������е�ͬ��������������

����ʱ��̬����������:1.��֮��Ҫ���㸳ֵ���ݹ���2.Ҫ�����麯����
3.ͨ����Ķ����ָ�롢���÷����麯������ͨ����ĳ�Ա���������麯����

�麯���Ƕ�̬�󶨵Ļ�������ס���麯���ǷǾ�̬�ĳ�Ա������һ�������Ǿ�̬��static���ĳ�Ա������
*/
class Basev // ����Basev������
{
public:
	virtual void show()    { cout << "Basev::show()" << endl; } // �����е����Ա����show���ؼ���virtual
	virtual void show22();
};

/*
�����Ա������ʵ����������������ʱ�����麯��������ֻ�ܳ�������ĳ�Ա���������У���������
��Ա����ʵ��ʱ���֣������֮��ֻ���ڴ˳�Ա����������ǰ��virtual���Σ�������������ʵ��ǰ�ӡ�
*/
void Basev::show22()
{
	cout << "Basev::show22()" << endl; 
}

class Child0v : public Basev     // ��Basve�Ĺ���������Child0v������
{
public:
	void show()    { cout << "Child0v::show()" << endl; }    // ���Ա����show
	void show22()    { cout << "Child0v::show22()" << endl; } 
};

class Child1v : public Child0v  // ��Child0�Ĺ���������Child1������
{
public:
	void show()    { cout << "Child1v::show()" << endl; }    // ���Ա����show
	void show22()    { cout << "Child1v::show22()" << endl; } 
};

void CallShow(Basev *pBase)     // һ�㺯��������Ϊ����ָ��
{
	pBase->show();
	pBase->show22();
}
//�麯��end

/*�������봿�麯���������ࣺ���д��麯������, ������Ҫ���崿�麯����ʵ�֣����ҳ����಻��
ʵ�����������ܶ��������Ķ���ֻ�ܴ����̳г��ǳ�����������ʵ������(������Java�еĽӿ�)*/
class CBase// ������CBase������
{
public:
	virtual void show() = 0;// ���麯����Աshow��ע���һ����麯�����ˡ� = 0��
	virtual void show44() = 0;
};

/*
ע�⣺����������������û��ʵ�����еĴ��麯����ֻ�����˲��ִ��麯����ʵ�֣���ô�����������Ȼ�ǳ����࣬
��Ȼ����ʵ������ֻ�и�����ȫ�����麯����ʵ�֣�������Ų����ǳ����ಢ�Ҳſ���ʵ������������CChild0û��ʵ��
show44()����������CChild0��Ȼ�Ǹ������࣬��Ϊ��ʵ��ʱ�ͻ����
*/
class CChild0 : public CBase// ��CBase�Ĺ���������Child0������
{
public:
	void show()    { cout << "CChild0::show()" << endl; } // ���Ա����show
	void show44(){};
};

class CChild1 : public CChild0 // ��Child0�Ĺ���������Child1������
{
public:
	void show()    { cout << "CChild1::show()" << endl; }    // ���Ա����show
};

void CallShow(CBase *pBase)// һ�㺯��������Ϊ����ָ��
{
	pBase->show();
}
//�������봿�麯��end

int main()
{
	cout<<"==========��ֵ���ݹ���==========="<<endl;
	//��Ȼ���������������Դ���������ʹ�ã�����ֻ��ʹ�����ӻ���̳еĳ�Ա�����޷�ʹ�����������Ա��
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
	cout<<"==========��ֵ���ݹ���==========="<<endl;

	cout<<"==========���������==========="<<endl;
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
	(++timeSpan3).Temp();
	timeSpan3.Show();
    cout<<"==========���������==========="<<endl;

	cout<<"==========��̬���ݳ�Ա�뺯��==========="<<endl;
	CTimeSpan::f(timeSpan3);
	timeSpan3.Count();
	CTimeSpan::Count();
	cout<<"==========��̬���ݳ�Ա�뺯��==========="<<endl;

	cout<<"==========��Ԫ��������Ԫ��==========="<<endl;
	cout<<"friend access : "<<add(timeSpan3)<<endl;
	B b;
	b.Set(10000);
	b.Display();
	cout<<"==========��Ԫ��������Ԫ��==========="<<endl;
	/*ò����vc++6.0�в�֧�����������Ϊ�����Ԫ��������Ϊ���벻��
	CTimeSpan timeSpan11(2, 50);
	CTimeSpan timeSpan21(3, 30);
	cout << "timeSpan11: ";
	timeSpan11.Show();
	cout << "timeSpan21: ";
	timeSpan21.Show();
	CTimeSpan timeSum1;
	timeSum1 = timeSpan11 - timeSpan21;
	cout << "timeSum1 = timeSpan11 - timeSpan21: ";
	timeSum1.Show();
    */

	/*
	1.��֮��Ҫ���㸳ֵ���ݹ���2.Ҫ�����麯����3.ͨ����Ķ����ָ�롢���÷����麯������ͨ����ĳ�Ա���������麯����
	*/
	cout<<"==========�麯��==========="<<endl;
	Basev basev;                 // ����Base��Ķ���
	Basev *pBasev;             // ����Base���ָ��
	Child0v ch0v;                 // ����Child0��Ķ���
	Child1v ch1v;                 // ����Child1��Ķ���
	pBasev = &basev;        // ��Base�����base�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBasev);
	pBasev = &ch0v;            // ��Child0�����ch0�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBasev);
	pBasev = &ch1v;            // ��Child1�����ch1�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(pBasev);
	cout<<"==========�麯��==========="<<endl;

	
	//��������������Ķ���ʹ�ó�����һ����ͨ�������������ָ������ã���ָ�������ָ��������Ķ��󣬷���������ĳ�Ա��
	cout<<"==========�������봿�麯��==========="<<endl;
	CBase *cpBase;             // ����Base���ָ��
	CChild0 cch0;                 // ����Child0��Ķ���
	CChild1 cch1;                 // ����Child1��Ķ���
	cpBase = &cch0;           // ��Child0�����ch0�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(cpBase);
	cpBase = &cch1;           // ��Child1�����ch1�ĵ�ַ��ֵ��Base��ָ��pBase
	CallShow(cpBase);
	cout<<"==========�������봿�麯��==========="<<endl;
	return 0;
}