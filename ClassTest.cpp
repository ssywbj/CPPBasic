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
	Clock(int NewH, int NewM){Hour=NewH; Minute=NewM;Second = NewM;}//���������幹�캯��

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

	return 0;
}