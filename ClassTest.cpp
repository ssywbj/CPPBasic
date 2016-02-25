#include<iostream>

using namespace std;

//struct Sales_data
//{
//	string bookNo;//ISBN编号
//	int units_sold = 0;//销量
//	double revenue = 0;//收入

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
	Clock(int NewH, int NewM, int NewS);//声明构造函数
	Clock(int NewH, int NewM){Hour=NewH; Minute=NewM;Second = NewM;}//声明并定义构造函数

	Clock(Clock &clock);//声明拷贝构造函数，它的形参是本类的对象的引用

	//类的析构函数和构造函数不同的是它不能有任何形参。如果没有定义析构函数系统也会自动生成一个默认析构函数，默认析构函数也不会做任何工作
	//~Clock();//声明类的析构函数，析构函数会在对象被删除之前做一些清理工作， 由系统自动调用的，它执行完后对象就消失了，分配的内存空间也释放了

	//在类中声明函数，可以在类外定义函数，也可以写在类中定义，在类中定义的函数为隐式的内联函数。
	void SetTime(int NewH, int NewM, int NewS);
	void ShowTime();

	//比较简单的成员函数可以声明为内联函数，内联函数的声明有两种方式：隐式声明和显式声明，两种声明的效果一样
	void ShowTime2()//在类中声明并定义了ShowTime2函数：隐式的内联函数
	{ cout<<Hour<<":"<<Minute<<":"<<Second<<endl; }  
	void ShowTime3();

	int GetSecond(){return Second;}

private:// 私有类型成员，如果没有标明访问控制属性则默认为private
	int Hour, Minute, Second; //不可以在这里直接赋值
};

/*作用域运算符“::”表示我们定义了一个名为SetTime的函数并且该函数被声明在类Clock的作用域内
一旦编译器看到这个函数名，就能理解剩余的代码是位于类的作用域内，所以当SetTime使用到Hour、
Minute、Second时，实际上是隐式地使用了类Clock的成员*/
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
//通过方法SetTime和ShowTime等函数来访问私有的Hour、Minute、Second等类成员，因此实际上这些方法就是Clock类的外部接口

inline void Clock::ShowTime3()//使用关键字"inline"定义的为显示的内联函数
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

Clock::Clock(int NewH, int NewM, int NewS)
{
   Hour = NewH;
   Minute = NewM;
   Second = NewS;
}

//定义拷贝构造函数
Clock::Clock(Clock &clock)
{
   Hour = clock.Hour;
   Minute = clock.Minute;
   Second = clock.Second + 17;
   cout<<"\n"<<"调用拷贝构造函数, Second = "<<Second<<endl;
}

/*Clock::~Clock()//定义类的析构函数
{
	cout<<"======调用析构函数====="<<endl;
}*/

//非类的成员函数
void fun1(Clock clock)
{ 
	cout<<"Second = "<<clock.GetSecond()<<endl; 
}
Clock fun2()
{    
	Clock A(10, 20, 16); //
	return A; //调用拷贝构造函数
}

int main()
{
	//Clock myClock;//如果没有为类定义构造函数，则编译器会为类生成默认的构造函数Clock()
	//myClock.SetTime(8, 30, 30);
	//myClock.ShowTime();

	//myClock.ShowTime2();

	Clock myClock2(23, 45, 78);//如果为类定义了构造函数，则编译器就就不会再为它生成默认的构造函数Clock()了
	myClock2.ShowTime3();
	myClock2.SetTime(8, 37, 59);
	myClock2.ShowTime();

	Clock myClock3(17, 25);
	myClock3.ShowTime2();

	Clock myClock4(myClock3);//拷贝构造函数被调用形式一，如果没有定义的类的拷贝构造函数，则编译器会调用默认的拷贝构造函数
	myClock4.ShowTime3();

	fun1(myClock4);//拷贝构造函数被调用形式二

	/*
	 拷贝构造函数被调用形式三，但这里拷贝构造函数被调用了两次，为什么呢？
	 因为编译器在执行B=fun2()时会创建一个临时的无名对象，在执行return A时实际上是调用了拷贝
	 构造函数将A的值拷贝到了临时对象中(第一次)，A就释放了，然后将临时对象的值再拷贝到对象B中(第二次)。
	 (注：因为对象A是局部对象，所以在fun2函数执行完就会被释放了！！)
	*/
	Clock myClock5 = fun2();
	cout<<"Second = "<<myClock5.GetSecond()<<endl; 

	return 0;
}