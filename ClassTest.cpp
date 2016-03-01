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
	Clock(int NewH, int NewM)//声明并定义构造函数
	{
		Hour=NewH;
		Minute=NewM;
		Second = NewM;
	}

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

//类的组合1：start
class Point
{ 
public:
	Point(int xx,int yy) { X=xx; Y=yy; } //构造函数
	Point(Point &p);
	int GetX(void) { return X; } //取X坐标
	int GetY(void) { return Y; } //取Y坐标

private:
	int X,Y; //点的坐标
};

Point::Point(Point &p)
{
	X = p.X;
	Y = p.Y;
	cout << "Point拷贝构造函数被调用" << endl;
}

class Distance
{
public:
	Distance(Point a,Point b); //构造函数
	double GetDis()   { return dist; }

private:
	Point  p1, p2;
	double dist;// 距离
};

Distance::Distance(Point a,Point b):p1(a), p2(b)
{
	cout<< "Distance构造函数被调用" <<endl;
	double x = double(p1.GetX() - p2.GetX());
	double y = double(p1.GetY() - p2.GetY());
	dist = x*x + y*y;
}
//类的组合1：end


//类的组合2：start
/*
两个类可能相互包含，即类A中有类B类型的内嵌对象，类B中也有A类型的内嵌对象。在C++中，要使用一个类必须在
使用前已经声明了该类，但是两个类互相包含时就肯定有一个类在定义之前就被引用了，这时候怎么办呢？就要用到前向引用
声明了。前向引用声明是在引用没有定义的类之前对该类进行声明，这只是为程序声明一个代表该类的标识符，类的具体定义
可以在程序的其他地方，简单说，就是声明下这个标识符是个类，它的定义可以在别的地方找到。
*/
class B;//前向引用声明
class A
{  
public:
	void f(B b);
};

/*
void A::f(B b)//貌似在这里还不能找到B类的对象，why?
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

//类的组合2：end


//类模板：start
// 定义结构体Student
struct Student
{
	int id;//学号
	float average;//平均分
};

template <class T>
class Store
{
public:
	Store(void);//默认形式（无形参）的构造函数
	T GetElem(void);//获取数据
	void PutElem(T x);//存入数据
private:
	T item; // item用来存放任意类型的数据
	int haveValue;//标识item是否被存入数据
};

// 以下是成员函数的实现，注意，类模板的成员函数都是函数模板
// 构造函数的实现
template <class T>//函数模板
Store<T>::Store(void):haveValue(0)//注意“Store<T>::”的写法；haveValue(0)：为变量haveValue赋值为0
{
}

// 获取数据的函数的实现
template <class T>
T Store<T>::GetElem(void)
{
	// 若item没有存入数据，则终止程序
	if (haveValue == 0)
	{
		cout << "item没有存入数据!" << endl;
		exit(1);
	}
	return item;
}

// 存入数据的函数的实现
template <class T>
void Store<T>::PutElem(T x)
{
	haveValue = 1; //将其置为1，表示item已经存入数据
	item = x;// 将x的值存入item
}
//类模板：end

//类的继承与派生：start
class employee// 雇员类
{
public:
	employee();//构造函数
	~employee();//析构函数
	void promote(int);//升级函数
	void getSalary();//计算工资

protected:
	char *m_szName;//雇员姓名
	int   m_nGrade;//级别
	float m_fSalary;//工资
};
//salesman类继承employee类，将除了基类的构造函数和析构函数外的所有其他成员全部接收
/*
派生类的继承方式为public，即公有继承时，对基类中的公有成员和保护成员的访问属性都不变，而对基类的私有成员则不能访问
。具体说，就是基类的公有成员和保护成员被继承到派生类中以后同样成为派生类的公有成员和保护成员，派生类中新增成员对他
们可以直接访问，派生类的对象只能访问继承的基类公有成员。但是派生类的新增成员和派生类的对象都不能访问基类的私有成员;

派生类的继承方式为protected，即保护继承方式时，基类的公有成员和保护成员被派生类继承后变成派生类的保护成员，
而基类的私有成员在派生类中不能访问。因为基类的公有成员和保护成员在派生类中都成了保护成员，所以派生类的新增成员
可以直接访问基类的公有成员和保护成员，而派生类的对象不能访问它们。千万要记住类的对象也是处于类外的，
不能访问类的保护成员。对基类的私有成员，派生类的新增成员函数和派生类对象都不能访问

 派生类的继承方式为private，即私有继承方式时，基类的公有成员和保护成员被派生类继承后变成派生类的私有成员，
 而基类的私有成员在派生类中不能访问。 派生类的新增成员可以直接访问基类的公有成员和保护成员，但是在类的外
 部通过派生类的对象不能访问它们，而派生类的成员和派生类的对象都不能访问基类的私有成员。(私有继承使得基类的成员在
 其派生类后续的派生中不能再被访问，中止了基类成员继续向下派生，这对代码的复用性没有好处，所以一般很少使用私有继承方式。)
*/
class salesman : public employee
{
public:
	salesman();
	~salesman();
	//派生类修改基类成员的方式之一：通过在派生类中声明和基类中数据或函数同名的成员，覆盖基类的相应数据或函数。
	//一旦我们在派生类中声明了一个和基类某个成员同名的成员，那么派生类这个成员就会覆盖外层的同名成员。
	//这叫做同名覆盖。需要注意的是，要实现函数覆盖不只要函数同名，函数形参表也要相同
	void getSalary();//计算工资，

private:
	float m_fProportion;//提成比例
	float m_fSalesSum;//当月总销售额
};

class Base// 基类Base的声明
{
public:// 公有成员函数
	void SetTwo(int a, int b) { x=a; y=b; }
	int GetX(){ return x; }
	int GetY(){ return y; }

private:// 私有数据成员
	int x;
	int y;
};

class Child : private Base //派生类的声明，继承方式为私有继承
{
public://新增公有成员函数
	void SetThree(int a, int b, int c) { SetTwo(a, b); z=c; }
	int GetX() { return Base::GetX(); }//在派生类内部访问基类的同名方法或变量，注意访问格式
	int GetY() { return Base::GetY(); }
	int GetZ() { return z; }

private: // 新增私有数据成员
	int z;
};

class Base1// 基类Base1，只有默认构造函数
{
public:
	Base1(){ cout<<"Base1 construct"<<endl; }
	 ~Base1(){ cout<<"Base1 destruct"<<endl; }//Base1的析构函数
};

class Base2// 基类Base2，只有带参数的构造函数
{
public:
	Base2(int x){ cout<<"Base2 construct "<<x<<endl; }
	~Base2(){ cout<<"Base2 destruct"<<endl; }//Base2的析构函数
};

class Base3// 基类Base3，只有带参数的构造函数
{
public:
	Base3(int y){ cout<<"Base3 construct "<<y<<endl; }
	~Base3(){ cout<<"Base3 destruct"<<endl;}//Base3的析构函数
};

class Child2 : public Base2, public Base1, public Base3// 派生类Child
{
public:
	/*
    基类的构造函数若有参数，则派生类必须定义构造函数，将传入的参数再传递给基类的构造函数，对基类进行初始化。

	构造派生类的对象调用构造函数时的处理顺序是：1.首先调用基类的构造函数，若有多个基类，调用顺序按照它们在派
	生类声明时从左到右出现的顺序；2.如果有内嵌对象成员，则调用内嵌对象成员的构造函数，若为多个内嵌对象，
	则按照它们在派生类中声明的顺序调用，如果无内嵌对象则跳过这一步；3.调用派生类构造函数中的语句。

    若定义有析构函数，则派生类的析构函数一般只需要在其函数体中清理新增成员就可以了，对于继承的基类成员和派生类内嵌对象成员的清理
	，一般由系统自动调用基类和对象成员的析构函数来完成。这个执行过程的顺序正好和派生类构造函数相反：1.执行析构
	函数语句清理派生类的新增成员；2.调用内嵌对象成员所属类的析构函数清理派生类内嵌对象成员，各个对象成员的清理顺
	序与其在构造函数中的构造顺序相反；3.调用基类的析构函数清理继承的基类成员，如果是多继承则各个基类的清理顺序也
	与其在构造函数中的构造顺序相反。总起来一句话，析构函数执行时所有成员或对象的清理顺序与构造函数的构造顺序刚好完全相反。
	*/
	Child2(int i,int j,int k,int m):Base2(i),b3(j),b2(k),Base3(m){}//带有基类的构造函数和内嵌对象；声明并定义
	Child2(int p,int m,int n);//只声明

private: // 派生类的内嵌对象成员
	Base1 b1;
	Base2 b2;
	Base3 b3;
};

Child2::Child2(int p,int m,int n):Base2(p),b3(m),b2(n),Base3(p)//定义
{
}

class Base11 // 基类Base1的声明
{
	public:
	int x;
	void show(){ cout<<"x of Base11: "<<x<<endl; } 
};

class Base22// 基类Base2的声明
{
	public:
	int x;
	void show(){ cout<<"x of Base22: "<<x<<endl; } 
};
/*多继承：如果多个基类之间没有继承关系也没有共同基类，基类中含有具有同名成员，派生类也新增
了同名成员，则派生类成员会覆盖所有基类中的同名成员。通过成员名只能访问到派生类的成员，
要访问各基类的同名成员就需要使用作用域分辨符；哪怕派生类中不存在同名成员，访问多个
基类的同名成员也需要使用作用域分辨符，因为从不同基类继承过来的同名成员具有相同的作用域，
通过成员名无法唯一标识成员。*/
class Child33 : public Base11, public Base22// 派生类Child的声明
{
	public:
	int x;
	void show(){ cout<<"x of Child33: "<<x<<endl; } 
};

/*多继承：如果派生类的全部或者部分基类有共同的基类，也就是说派生类的这些基类是从同一个
基类派生出来的，那么派生类的这些直接基类从上一级基类继承的成员都具有相同的名称，
即都是同名成员，定义了派生类的对象后，同名数据成员就会在内存中有多份拷贝
，同名函数也会有多个映射, 要访问它们就必须通过直接基类限定，使用作用域分辨符访问。*/
class Base44// 基类Base44的声明
{
	public:
	int x;
	void show() { cout<<"x of Base44: "<<x<<endl; }
};

class Base441 : public Base44 // 由Base44派生的类Base441的声明
{
};

class Base442 : public Base44 // 由Base44派生的类Base442的声明
{
};

class Child44 : public Base441, public Base442
{
};

/*虚基类技术：派生类直接基类的共同基类声明为虚基类后，派生类从不同的直接基类继承
来的同名数据成员在内存中就会只有一份拷贝，同名函数也会只有一个映射，这样不仅实现了
唯一标识同名成员，而且也节省了内存空间，可见比起使用作用域分辨符访问，虚基类技术是很实用。*/
class Base0v // 基类Base0的声明，虚基类没有定义构造函数的情况
{
	public:
	int x;
	void show()      { cout<<"x of Base0v: "<<x<<endl; }
};
//声明虚基类只需要在它的派生类声明时使用关键字virtual修饰
class Base1v : virtual public Base0v// Base0v为虚基类，公有派生Base1v类
{
};
class Base2v : virtual public Base0v// Base0v为虚基类，公有派生Base2v类
{
};
class Childv : public Base1v, public Base2v
{
};

/*如果虚基类定义了带参数表的非默认构造函数，没有定义默认形式的构造函数，
那么由虚基类直接或间接继承的所有派生类，都必须在构
造函数的成员初始化列表中给出对虚基类成员的初始化。*/
class Base0vc// 基类Base0的声明，虚基灶定义了构造函数的情况
{
	public:
	Base0vc(int y)     { x=y; }
	int x;
	void show()      { cout<<"x of Base0vc: "<<x<<endl; }
};
class Base1vc : virtual public Base0vc     // Base0为虚基类，公有派生Base1类
{
	public:
	Base1vc(int y):Base0vc(y)    { }//对虚基类成员的初始化
};
class Base2vc : virtual public Base0vc     // Base0为虚基类，公有派生Base2类
{
	public:
	Base2vc(int y):Base0vc(y)    { } //对虚基类成员的初始化 
};
class Childvc : public Base1vc, public Base2vc
{
	public:
	Childvc(int y):Base0vc(y),Base1vc(y),Base2vc(y)   { }//也需要对虚基类成员的初始化
	//void show(){ cout<<"x of Childvc: "<<x<<endl; }
};

//类的继承与派生：end

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

	cout<<"================================="<<endl; 

	Point myp1(1,1), myp2(4,5);
	/*
	类的内嵌调用顺序：按照内嵌对象在组合类的声明中出现的次序，依次调用内嵌对象的构造函数，然后再执行本类的构造函数的函数体：
	先调用p1的构造函数，再调用p2的构造函数，最后执行Distance构造函数的函数体。析构函数的执行顺序与构造函数正好相反。
	*/
	Distance myd(myp1, myp2);//Point类的拷贝构造函数被调用了4次，而且都是在Distance类构造函数执行之前进行的，在Distance构造函数进行实参和形参的结合时，也就是传入myp1和myp2的值时调用了两次，在用传入的值初始化内嵌对象p1和p2时又调用了两次。
	cout<< "The distance is:"<<myd.GetDis() << endl;

	// 声明Student结构体类型变量，并赋初值
	Student g = { 103, 93 };
	// 声明两个Store类的对象，数据成员item为int类型
	Store<int> S1, S2;
	// 声明Store类对象S3，数据成员item为Student结构体类型
	Store<Student> S3;
	S1.PutElem(7);// 向对象S1中存入数值7
	S2.PutElem(-1);// 向对象S2中存入数值-1
	// 输出S1和S2的数据成员的值
	cout << S1.GetElem() << "  " << S2.GetElem() << endl;
	S3.PutElem(g); // 向对象S3中存入Student结构体类型变量g
	// 输出对象S3的数据成员
	cout << "The student id is " << S3.GetElem().id << endl;//注意结构体访问其数据成员的方式

	Child child;//声明Child类的对象
	child.SetThree(1, 2, 3);//设置派生类的数据
	cout << "The data of child: "<< child.GetX() << ", " << child.GetY() << ", " << child.GetZ() << endl; 

	Child2 child2(3,4,5,6);

	Child33 child33;
	child33.x = 5;          // 访问派生类数据成员
	child33.show();         // 调用派生类函数成员
	child33.Base11::x = 7;   // 使用作用域分辨符访问基类Base1的数据成员
	child33.Base11::show();  // 使用作用域分辨符调用基类Base1的函数成员
	child33.Base22::x = 8;   // 使用作用域分辨符访问基类Base2的数据成员
    child33.Base22::show();  // 使用作用域分辨符访问基类Base2的函数成员

	Child44 child44;
	child44.Base441::x = 3;      // 通过直接基类Base1限定成员
	child44.Base441::show();
	child44.Base442::x = 5;      // 通过直接基类Base2限定成员
	child44.Base442::show();

	Childv childv;
	childv.x = 5;
	childv.show();

	/*定义派生类Childvc的对象childvc，在构造对象chilvcd时调用了Childvc的构造函数
	，其初始化列表中不只调用了虚基类Base0vc的构造函数对从它继承的成员x进行初始化，而
	且还调用了基类Base1vc和Base2vc的构造函数Base1vc()和Base2vc()，而Base1vc()和Base2vc()
	的初始化列表中又有对虚基类Base0vc成员x的初始化。这么说，从虚基类Base0vc继承来的成员
	x初始化了三次，其实不然，因为编译器在遇到这种情况时会进行特殊处理：如果构造的对象中
	有从虚基类继承来的成员，那么虚基类成员的初始化由而且只由最远派生类的构造函数调
	用虚基类的构造函数来完成。最远派生类就是声明对象时指定的类，上面例子中构造对象
	child时，类Child就是最远派生类。除了最远派生类，它的其他基类对虚基类构造函数的
	调用会被忽略。上例中就只会由Childvc类的构造函数调用虚基类Base0vc的构造函数完成成员
	x的初始化，而Childvc类的基类Base1vc和Base2vc对虚基类Base0vc构造函数的调用会被忽略。*/
	Childvc childvc(3);
	childvc.show();
	//childvc.Base1vc::x = 99;      // 通过直接基类Base1限定成员
	//childvc.Base1vc::show();
	//childvc.Base2vc::x = 100;      // 通过直接基类Base1限定成员
	//childvc.Base2vc::show();
	return 0;
}