#include<iostream>

using namespace std;

//struct Sales_data
//{
//	string bookNo;//ISBN���
//	int units_sold = 0;//����
//	double revenue = 0;//����

//	string isbn() const {return bookNo;}
//	Sales_data& combine(const Sales_data&);
//	double avg_price() const;
//};
//Sales_data item1;

//Sales_data add(const Sales_data&, const Sales_data&);
//ostream &print(ostream&, Sales_data&);
//istream &read(istream&, Sales_data&);

//double Sales_data::avg_price() const
//{
//	if(units_sold)
//	{
//		return revenue / units_sold;
//	}
//	else
//	{
//		return 0;
//	}
//}

//Sales_data& Sales_data::combine(const Sales_data &rhs)
//{
//	units_sold += rhs.units_sold;
//	revenue += rhs.revenue;
//	return *this;
//}

class Clock
{
public:
	Clock(int NewH, int NewM, int NewS);//�������캯��
	Clock(int NewH, int NewM)//���������幹�캯��
	{
		Hour=NewH;
		Minute=NewM;
		Second = NewM;
	}

	Clock(Clock &clock);//�����������캯���������β��Ǳ���Ķ��������

	//������������͹��캯����ͬ�������������κ��βΡ����û�ж�����������ϵͳҲ���Զ�����һ��Ĭ������������Ĭ����������Ҳ�������κι���
	//~Clock();//����������������������������ڶ���ɾ��֮ǰ��һЩ�������� ��ϵͳ�Զ����õģ���ִ�����������ʧ�ˣ�������ڴ�ռ�Ҳ�ͷ���

	//�������������������������ⶨ�庯����Ҳ����д�����ж��壬�����ж���ĺ���Ϊ��ʽ������������
	void SetTime(int NewH, int NewM, int NewS);
	void ShowTime();

	//�Ƚϼ򵥵ĳ�Ա������������Ϊ�����������������������������ַ�ʽ����ʽ��������ʽ����������������Ч��һ��
	void ShowTime2()//������������������ShowTime2��������ʽ����������
	{ cout<<Hour<<":"<<Minute<<":"<<Second<<endl; }  
	void ShowTime3();

	int GetSecond(){return Second;}

private:// ˽�����ͳ�Ա�����û�б������ʿ���������Ĭ��Ϊprivate
	int Hour, Minute, Second; //������������ֱ�Ӹ�ֵ
};

/*�������������::����ʾ���Ƕ�����һ����ΪSetTime�ĺ������Ҹú�������������Clock����������
һ������������������������������ʣ��Ĵ�����λ������������ڣ����Ե�SetTimeʹ�õ�Hour��
Minute��Secondʱ��ʵ��������ʽ��ʹ������Clock�ĳ�Ա*/
void Clock::SetTime(int NewH, int NewM, int NewS)
{
   Hour = NewH;
   Minute = NewM;
   Second = NewS;
}

void Clock::ShowTime()
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}
//ͨ������SetTime��ShowTime�Ⱥ���������˽�е�Hour��Minute��Second�����Ա�����ʵ������Щ��������Clock����ⲿ�ӿ�

inline void Clock::ShowTime3()//ʹ�ùؼ���"inline"�����Ϊ��ʾ����������
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

Clock::Clock(int NewH, int NewM, int NewS)
{
   Hour = NewH;
   Minute = NewM;
   Second = NewS;
}

//���忽�����캯��
Clock::Clock(Clock &clock)
{
   Hour = clock.Hour;
   Minute = clock.Minute;
   Second = clock.Second + 17;
   cout<<"\n"<<"���ÿ������캯��, Second = "<<Second<<endl;
}

/*Clock::~Clock()//���������������
{
	cout<<"======������������====="<<endl;
}*/

//����ĳ�Ա����
void fun1(Clock clock)
{ 
	cout<<"Second = "<<clock.GetSecond()<<endl; 
}
Clock fun2()
{    
	Clock A(10, 20, 16); //
	return A; //���ÿ������캯��
}

//������1��start
class Point
{ 
public:
	Point(int xx,int yy) { X=xx; Y=yy; } //���캯��
	Point(Point &p);
	int GetX(void) { return X; } //ȡX����
	int GetY(void) { return Y; } //ȡY����

private:
	int X,Y; //�������
};

Point::Point(Point &p)
{
	X = p.X;
	Y = p.Y;
	cout << "Point�������캯��������" << endl;
}

class Distance
{
public:
	Distance(Point a,Point b); //���캯��
	double GetDis()   { return dist; }

private:
	Point  p1, p2;
	double dist;// ����
};

Distance::Distance(Point a,Point b):p1(a), p2(b)
{
	cout<< "Distance���캯��������" <<endl;
	double x = double(p1.GetX() - p2.GetX());
	double y = double(p1.GetY() - p2.GetY());
	dist = x*x + y*y;
}
//������1��end


//������2��start
/*
����������໥����������A������B���͵���Ƕ������B��Ҳ��A���͵���Ƕ������C++�У�Ҫʹ��һ���������
ʹ��ǰ�Ѿ������˸��࣬���������໥�����ʱ�Ϳ϶���һ�����ڶ���֮ǰ�ͱ������ˣ���ʱ����ô���أ���Ҫ�õ�ǰ������
�����ˡ�ǰ������������������û�ж������֮ǰ�Ը��������������ֻ��Ϊ��������һ���������ı�ʶ������ľ��嶨��
�����ڳ���������ط�����˵�����������������ʶ���Ǹ��࣬���Ķ�������ڱ�ĵط��ҵ���
*/
class B;//ǰ����������
class A
{  
public:
	void f(B b);
};

/*
void A::f(B b)//ò�������ﻹ�����ҵ�B��Ķ���why?
{
	cout<<"temp = "<<b.getTemp()<<endl;
}
*/

class B
{  
public:
	void g(A a);
	int getTemp(){return temp;}
private:
	int temp;
};

//������2��end


//��ģ�壺start
// ����ṹ��Student
struct Student
{
	int id;//ѧ��
	float average;//ƽ����
};

template <class T>
class Store
{
public:
	Store(void);//Ĭ����ʽ�����βΣ��Ĺ��캯��
	T GetElem(void);//��ȡ����
	void PutElem(T x);//��������
private:
	T item; // item��������������͵�����
	int haveValue;//��ʶitem�Ƿ񱻴�������
};

// �����ǳ�Ա������ʵ�֣�ע�⣬��ģ��ĳ�Ա�������Ǻ���ģ��
// ���캯����ʵ��
template <class T>//����ģ��
Store<T>::Store(void):haveValue(0)//ע�⡰Store<T>::����д����haveValue(0)��Ϊ����haveValue��ֵΪ0
{
}

// ��ȡ���ݵĺ�����ʵ��
template <class T>
T Store<T>::GetElem(void)
{
	// ��itemû�д������ݣ�����ֹ����
	if (haveValue == 0)
	{
		cout << "itemû�д�������!" << endl;
		exit(1);
	}
	return item;
}

// �������ݵĺ�����ʵ��
template <class T>
void Store<T>::PutElem(T x)
{
	haveValue = 1; //������Ϊ1����ʾitem�Ѿ���������
	item = x;// ��x��ֵ����item
}
//��ģ�壺end

//��ļ̳���������start
class employee// ��Ա��
{
public:
	employee();//���캯��
	~employee();//��������
	void promote(int);//��������
	void getSalary();//���㹤��

protected:
	char *m_szName;//��Ա����
	int   m_nGrade;//����
	float m_fSalary;//����
};
//salesman��̳�employee�࣬�����˻���Ĺ��캯�������������������������Աȫ������
/*
������ļ̳з�ʽΪpublic�������м̳�ʱ���Ի����еĹ��г�Ա�ͱ�����Ա�ķ������Զ����䣬���Ի����˽�г�Ա���ܷ���
������˵�����ǻ���Ĺ��г�Ա�ͱ�����Ա���̳е����������Ժ�ͬ����Ϊ������Ĺ��г�Ա�ͱ�����Ա����������������Ա����
�ǿ���ֱ�ӷ��ʣ�������Ķ���ֻ�ܷ��ʼ̳еĻ��๫�г�Ա�������������������Ա��������Ķ��󶼲��ܷ��ʻ����˽�г�Ա;

������ļ̳з�ʽΪprotected���������̳з�ʽʱ������Ĺ��г�Ա�ͱ�����Ա��������̳к���������ı�����Ա��
�������˽�г�Ա���������в��ܷ��ʡ���Ϊ����Ĺ��г�Ա�ͱ�����Ա���������ж����˱�����Ա�������������������Ա
����ֱ�ӷ��ʻ���Ĺ��г�Ա�ͱ�����Ա����������Ķ����ܷ������ǡ�ǧ��Ҫ��ס��Ķ���Ҳ�Ǵ�������ģ�
���ܷ�����ı�����Ա���Ի����˽�г�Ա���������������Ա��������������󶼲��ܷ���

 ������ļ̳з�ʽΪprivate����˽�м̳з�ʽʱ������Ĺ��г�Ա�ͱ�����Ա��������̳к����������˽�г�Ա��
 �������˽�г�Ա���������в��ܷ��ʡ� �������������Ա����ֱ�ӷ��ʻ���Ĺ��г�Ա�ͱ�����Ա�������������
 ��ͨ��������Ķ����ܷ������ǣ���������ĳ�Ա��������Ķ��󶼲��ܷ��ʻ����˽�г�Ա��(˽�м̳�ʹ�û���ĳ�Ա��
 ������������������в����ٱ����ʣ���ֹ�˻����Ա����������������Դ���ĸ�����û�кô�������һ�����ʹ��˽�м̳з�ʽ��)
*/
class salesman : public employee
{
public:
	salesman();
	~salesman();
	//�������޸Ļ����Ա�ķ�ʽ֮һ��ͨ�����������������ͻ��������ݻ���ͬ���ĳ�Ա�����ǻ������Ӧ���ݻ�����
	//һ����������������������һ���ͻ���ĳ����Աͬ���ĳ�Ա����ô�����������Ա�ͻḲ������ͬ����Ա��
	//�����ͬ�����ǡ���Ҫע����ǣ�Ҫʵ�ֺ������ǲ�ֻҪ����ͬ���������βα�ҲҪ��ͬ
	void getSalary();//���㹤�ʣ�

private:
	float m_fProportion;//��ɱ���
	float m_fSalesSum;//���������۶�
};

class Base// ����Base������
{
public:// ���г�Ա����
	void SetTwo(int a, int b) { x=a; y=b; }
	int GetX(){ return x; }
	int GetY(){ return y; }

private:// ˽�����ݳ�Ա
	int x;
	int y;
};

class Child : private Base //��������������̳з�ʽΪ˽�м̳�
{
public://�������г�Ա����
	void SetThree(int a, int b, int c) { SetTwo(a, b); z=c; }
	int GetX() { return Base::GetX(); }//���������ڲ����ʻ����ͬ�������������ע����ʸ�ʽ
	int GetY() { return Base::GetY(); }
	int GetZ() { return z; }

private: // ����˽�����ݳ�Ա
	int z;
};

class Base1// ����Base1��ֻ��Ĭ�Ϲ��캯��
{
public:
	Base1(){ cout<<"Base1 construct"<<endl; }
	 ~Base1(){ cout<<"Base1 destruct"<<endl; }//Base1����������
};

class Base2// ����Base2��ֻ�д������Ĺ��캯��
{
public:
	Base2(int x){ cout<<"Base2 construct "<<x<<endl; }
	~Base2(){ cout<<"Base2 destruct"<<endl; }//Base2����������
};

class Base3// ����Base3��ֻ�д������Ĺ��캯��
{
public:
	Base3(int y){ cout<<"Base3 construct "<<y<<endl; }
	~Base3(){ cout<<"Base3 destruct"<<endl;}//Base3����������
};

class Child2 : public Base2, public Base1, public Base3// ������Child
{
public:
	/*
    ����Ĺ��캯�����в���������������붨�幹�캯����������Ĳ����ٴ��ݸ�����Ĺ��캯�����Ի�����г�ʼ����

	����������Ķ�����ù��캯��ʱ�Ĵ���˳���ǣ�1.���ȵ��û���Ĺ��캯�������ж�����࣬����˳������������
	��������ʱ�����ҳ��ֵ�˳��2.�������Ƕ�����Ա���������Ƕ�����Ա�Ĺ��캯������Ϊ�����Ƕ����
	������������������������˳����ã��������Ƕ������������һ����3.���������๹�캯���е���䡣

    �����������������������������������һ��ֻ��Ҫ���亯����������������Ա�Ϳ����ˣ����ڼ̳еĻ����Ա����������Ƕ�����Ա������
	��һ����ϵͳ�Զ����û���Ͷ����Ա��������������ɡ����ִ�й��̵�˳�����ú������๹�캯���෴��1.ִ������
	������������������������Ա��2.������Ƕ�����Ա���������������������������Ƕ�����Ա�����������Ա������˳
	�������ڹ��캯���еĹ���˳���෴��3.���û����������������̳еĻ����Ա������Ƕ�̳���������������˳��Ҳ
	�����ڹ��캯���еĹ���˳���෴��������һ�仰����������ִ��ʱ���г�Ա����������˳���빹�캯���Ĺ���˳��պ���ȫ�෴��
	*/
	Child2(int i,int j,int k,int m):Base2(i),b3(j),b2(k),Base3(m){}//���л���Ĺ��캯������Ƕ��������������
	Child2(int p,int m,int n);//ֻ����

private: // ���������Ƕ�����Ա
	Base1 b1;
	Base2 b2;
	Base3 b3;
};

Child2::Child2(int p,int m,int n):Base2(p),b3(m),b2(n),Base3(p)//����
{
}

class Base11 // ����Base1������
{
	public:
	int x;
	void show(){ cout<<"x of Base11: "<<x<<endl; } 
};

class Base22// ����Base2������
{
	public:
	int x;
	void show(){ cout<<"x of Base22: "<<x<<endl; } 
};
/*��̳У�����������֮��û�м̳й�ϵҲû�й�ͬ���࣬�����к��о���ͬ����Ա��������Ҳ����
��ͬ����Ա�����������Ա�Ḳ�����л����е�ͬ����Ա��ͨ����Ա��ֻ�ܷ��ʵ�������ĳ�Ա��
Ҫ���ʸ������ͬ����Ա����Ҫʹ��������ֱ���������������в�����ͬ����Ա�����ʶ��
�����ͬ����ԱҲ��Ҫʹ��������ֱ������Ϊ�Ӳ�ͬ����̳й�����ͬ����Ա������ͬ��������
ͨ����Ա���޷�Ψһ��ʶ��Ա��*/
class Child33 : public Base11, public Base22// ������Child������
{
	public:
	int x;
	void show(){ cout<<"x of Child33: "<<x<<endl; } 
};

/*��̳У�����������ȫ�����߲��ֻ����й�ͬ�Ļ��࣬Ҳ����˵���������Щ�����Ǵ�ͬһ��
�������������ģ���ô���������Щֱ�ӻ������һ������̳еĳ�Ա��������ͬ�����ƣ�
������ͬ����Ա��������������Ķ����ͬ�����ݳ�Ա�ͻ����ڴ����ж�ݿ���
��ͬ������Ҳ���ж��ӳ��, Ҫ�������Ǿͱ���ͨ��ֱ�ӻ����޶���ʹ��������ֱ�����ʡ�*/
class Base44// ����Base44������
{
	public:
	int x;
	void show() { cout<<"x of Base44: "<<x<<endl; }
};

class Base441 : public Base44 // ��Base44��������Base441������
{
};

class Base442 : public Base44 // ��Base44��������Base442������
{
};

class Child44 : public Base441, public Base442
{
};

/*����༼����������ֱ�ӻ���Ĺ�ͬ��������Ϊ������������Ӳ�ͬ��ֱ�ӻ���̳�
����ͬ�����ݳ�Ա���ڴ��оͻ�ֻ��һ�ݿ�����ͬ������Ҳ��ֻ��һ��ӳ�䣬��������ʵ����
Ψһ��ʶͬ����Ա������Ҳ��ʡ���ڴ�ռ䣬�ɼ�����ʹ��������ֱ�����ʣ�����༼���Ǻ�ʵ�á�*/
class Base0v // ����Base0�������������û�ж��幹�캯�������
{
	public:
	int x;
	void show()      { cout<<"x of Base0v: "<<x<<endl; }
};
//���������ֻ��Ҫ����������������ʱʹ�ùؼ���virtual����
class Base1v : virtual public Base0v// Base0vΪ����࣬��������Base1v��
{
};
class Base2v : virtual public Base0v// Base0vΪ����࣬��������Base2v��
{
};
class Childv : public Base1v, public Base2v
{
};

/*�������ඨ���˴�������ķ�Ĭ�Ϲ��캯����û�ж���Ĭ����ʽ�Ĺ��캯����
��ô�������ֱ�ӻ��Ӽ̳е����������࣬�������ڹ�
�캯���ĳ�Ա��ʼ���б��и�����������Ա�ĳ�ʼ����*/
class Base0vc// ����Base0���������������˹��캯�������
{
	public:
	Base0vc(int y)     { x=y; }
	int x;
	void show()      { cout<<"x of Base0vc: "<<x<<endl; }
};
class Base1vc : virtual public Base0vc     // Base0Ϊ����࣬��������Base1��
{
	public:
	Base1vc(int y):Base0vc(y)    { }//��������Ա�ĳ�ʼ��
};
class Base2vc : virtual public Base0vc     // Base0Ϊ����࣬��������Base2��
{
	public:
	Base2vc(int y):Base0vc(y)    { } //��������Ա�ĳ�ʼ�� 
};
class Childvc : public Base1vc, public Base2vc
{
	public:
	Childvc(int y):Base0vc(y),Base1vc(y),Base2vc(y)   { }//Ҳ��Ҫ��������Ա�ĳ�ʼ��
	//void show(){ cout<<"x of Childvc: "<<x<<endl; }
};

//��ļ̳���������end

int main()
{
	//Clock myClock;//���û��Ϊ�ඨ�幹�캯�������������Ϊ������Ĭ�ϵĹ��캯��Clock()
	//myClock.SetTime(8, 30, 30);
	//myClock.ShowTime();

	//myClock.ShowTime2();

	Clock myClock2(23, 45, 78);//���Ϊ�ඨ���˹��캯������������;Ͳ�����Ϊ������Ĭ�ϵĹ��캯��Clock()��
	myClock2.ShowTime3();
	myClock2.SetTime(8, 37, 59);
	myClock2.ShowTime();

	Clock myClock3(17, 25);
	myClock3.ShowTime2();

	Clock myClock4(myClock3);//�������캯����������ʽһ�����û�ж������Ŀ������캯����������������Ĭ�ϵĿ������캯��
	myClock4.ShowTime3();

	fun1(myClock4);//�������캯����������ʽ��

	/*
	 �������캯����������ʽ���������������캯�������������Σ�Ϊʲô�أ�
	 ��Ϊ��������ִ��B=fun2()ʱ�ᴴ��һ����ʱ������������ִ��return Aʱʵ�����ǵ����˿���
	 ���캯����A��ֵ����������ʱ������(��һ��)��A���ͷ��ˣ�Ȼ����ʱ�����ֵ�ٿ���������B��(�ڶ���)��
	 (ע����Ϊ����A�Ǿֲ�����������fun2����ִ����ͻᱻ�ͷ��ˣ���)
	*/
	Clock myClock5 = fun2();
	cout<<"Second = "<<myClock5.GetSecond()<<endl; 

	cout<<"================================="<<endl; 

	Point myp1(1,1), myp2(4,5);
	/*
	�����Ƕ����˳�򣺰�����Ƕ�����������������г��ֵĴ������ε�����Ƕ����Ĺ��캯����Ȼ����ִ�б���Ĺ��캯���ĺ����壺
	�ȵ���p1�Ĺ��캯�����ٵ���p2�Ĺ��캯�������ִ��Distance���캯���ĺ����塣����������ִ��˳���빹�캯�������෴��
	*/
	Distance myd(myp1, myp2);//Point��Ŀ������캯����������4�Σ����Ҷ�����Distance�๹�캯��ִ��֮ǰ���еģ���Distance���캯������ʵ�κ��βεĽ��ʱ��Ҳ���Ǵ���myp1��myp2��ֵʱ���������Σ����ô����ֵ��ʼ����Ƕ����p1��p2ʱ�ֵ��������Ρ�
	cout<< "The distance is:"<<myd.GetDis() << endl;

	// ����Student�ṹ�����ͱ�����������ֵ
	Student g = { 103, 93 };
	// ��������Store��Ķ������ݳ�ԱitemΪint����
	Store<int> S1, S2;
	// ����Store�����S3�����ݳ�ԱitemΪStudent�ṹ������
	Store<Student> S3;
	S1.PutElem(7);// �����S1�д�����ֵ7
	S2.PutElem(-1);// �����S2�д�����ֵ-1
	// ���S1��S2�����ݳ�Ա��ֵ
	cout << S1.GetElem() << "  " << S2.GetElem() << endl;
	S3.PutElem(g); // �����S3�д���Student�ṹ�����ͱ���g
	// �������S3�����ݳ�Ա
	cout << "The student id is " << S3.GetElem().id << endl;//ע��ṹ����������ݳ�Ա�ķ�ʽ

	Child child;//����Child��Ķ���
	child.SetThree(1, 2, 3);//���������������
	cout << "The data of child: "<< child.GetX() << ", " << child.GetY() << ", " << child.GetZ() << endl; 

	Child2 child2(3,4,5,6);

	Child33 child33;
	child33.x = 5;          // �������������ݳ�Ա
	child33.show();         // ���������ຯ����Ա
	child33.Base11::x = 7;   // ʹ��������ֱ�����ʻ���Base1�����ݳ�Ա
	child33.Base11::show();  // ʹ��������ֱ�����û���Base1�ĺ�����Ա
	child33.Base22::x = 8;   // ʹ��������ֱ�����ʻ���Base2�����ݳ�Ա
    child33.Base22::show();  // ʹ��������ֱ�����ʻ���Base2�ĺ�����Ա

	Child44 child44;
	child44.Base441::x = 3;      // ͨ��ֱ�ӻ���Base1�޶���Ա
	child44.Base441::show();
	child44.Base442::x = 5;      // ͨ��ֱ�ӻ���Base2�޶���Ա
	child44.Base442::show();

	Childv childv;
	childv.x = 5;
	childv.show();

	/*����������Childvc�Ķ���childvc���ڹ������chilvcdʱ������Childvc�Ĺ��캯��
	�����ʼ���б��в�ֻ�����������Base0vc�Ĺ��캯���Դ����̳еĳ�Աx���г�ʼ������
	�һ������˻���Base1vc��Base2vc�Ĺ��캯��Base1vc()��Base2vc()����Base1vc()��Base2vc()
	�ĳ�ʼ���б������ж������Base0vc��Աx�ĳ�ʼ������ô˵���������Base0vc�̳����ĳ�Ա
	x��ʼ�������Σ���ʵ��Ȼ����Ϊ�������������������ʱ��������⴦���������Ķ�����
	�д������̳����ĳ�Ա����ô������Ա�ĳ�ʼ���ɶ���ֻ����Զ������Ĺ��캯����
	�������Ĺ��캯������ɡ���Զ�����������������ʱָ�����࣬���������й������
	childʱ����Child������Զ�����ࡣ������Զ�����࣬�����������������๹�캯����
	���ûᱻ���ԡ������о�ֻ����Childvc��Ĺ��캯�����������Base0vc�Ĺ��캯����ɳ�Ա
	x�ĳ�ʼ������Childvc��Ļ���Base1vc��Base2vc�������Base0vc���캯���ĵ��ûᱻ���ԡ�*/
	Childvc childvc(3);
	childvc.show();
	//childvc.Base1vc::x = 99;      // ͨ��ֱ�ӻ���Base1�޶���Ա
	//childvc.Base1vc::show();
	//childvc.Base2vc::x = 100;      // ͨ��ֱ�ӻ���Base1�޶���Ա
	//childvc.Base2vc::show();
	return 0;
}