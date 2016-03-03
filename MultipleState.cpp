#include<iostream>

using namespace std;

//赋值兼容规则：在基类对象可以使用的地方都可以用公有派生类(必须是公有派生类)对象来代替。代替有三种：
//1.派生类的对象可以赋值给基类的对象。也就是将派生类对象从基类继承的成员的值分别赋值给基类对象相应的成员。例如：
//     base = child;
//2.派生类对象的地址可以赋值给基类类型的指针。例如：
//     pBase = &child;
//3.派生类对象可以用来初始化基类的引用。例如：
//     Base &b = child;
class Base // 基类Base的声明
{
	public:
	void show()    { cout << "Base::show()" << endl; }      // 公有成员函数show
};

class Child0 : public Base     // 类Base的公有派生类Child0的声明
{
	public:
	void show()    { cout << "Child0::show()" << endl; }    // 公有成员函数show
};

class Child1 : public Child0   // 类Child0的公有派生类Child1的声明
{
	public:
	void show()    { cout << "Child1::show()" << endl; }    // 公有成员函数show
};

void CallShow(Base *pBase)// 一般函数，参数为基类指针
{
	pBase->show();
}

//运算符重载：start
class CTimeSpan
{
public:
	CTimeSpan(){count++;}
	CTimeSpan(int nHours, int nMins);      // 构造函数
	CTimeSpan(int temp){m_temp = temp; count++;}

	CTimeSpan operator +(CTimeSpan ts);// 运算符“+”重载为成员函数，双目运算符
	CTimeSpan& operator ++();// 前置单目运算符重载
	CTimeSpan operator ++(int);//后置单目运算符重载

	//貌似在vc++6.0中不支持重载运算符为类的友元函数，因为编译不过
	//friend CTimeSpan operator -(CTimeSpan ts1, CTimeSpan ts2);//运算符“-”重载为类友元函数

	void SetHours(int Hours) {  m_nHours = Hours; }   
	void SetMins(int Mins) {  m_nMins = Mins; }
	int GetHours()      { return m_nHours; }   // 获取小时数
	int GetMins()       { return m_nMins; }    // 获取分钟数
	void Show();                               // 显示时间值
	void Temp();  

	friend int add(CTimeSpan &a);//友元函数，关键字friend
	friend class B;//友元类，类B是类CTimeSpan的友元类，则类B的所有成员函数都是类CTimeSpan的友元函数，都能访问类CTimeSpan的私有成员和保护成员
	
	static void Count(){cout << "count = " << count << endl;}// 静态成员函数访问静态数据
	static void f(CTimeSpan &a);

private:
	int m_nHours;       // 小时数
	int m_nMins;        // 分钟数
	int m_temp;           // 临时变量，用于演示单目运算符的重载
	static int count;// 静态数据成员的引用性说明
};

int CTimeSpan::count = 0;// 静态数据成员的定义性说明及初始化
void CTimeSpan::f(CTimeSpan &a)//静态函数成员访问非静态数据
{
	cout << "m_temp = " << a.m_temp << endl;//注意格式：对象.非静态数据成员
}

int add(CTimeSpan &a)//通过友元的方式，普通函数或者类的成员函数可以在作用域外访问某个类中的私有数据
{
	return a.m_temp + 10;
}

CTimeSpan::CTimeSpan(int nHours, int nMins)// 构造函数的实现
{
	nHours += nMins/60;
	nMins %= 60;
	m_nHours = nHours;
	m_nMins = nMins;
	count++;
}

CTimeSpan CTimeSpan::operator +(CTimeSpan ts)// 重载运算符函数实现
{
	int nNewHours =  m_nHours + ts.GetHours();
	int nNewMins = m_nMins + ts.GetMins();
	nNewHours += nNewMins/60;
    nNewMins %= 60;
	return CTimeSpan(nNewHours, nNewMins);
}

CTimeSpan& CTimeSpan::operator ++()// 前置单目运算符重载函数
{
	m_temp++;
	return *this;
}

//后置单目运算符重载
CTimeSpan CTimeSpan::operator ++(int)      //注意形参表中的整型参数 
{    
	CTimeSpan old = *this;
	++(*this);
	return old;
}

/*与运算符重载为成员函数时不同的是，重载的友元函数不属于任何类，运算符的操作数都
需要通过函数的形参表传递。操作数在形参表中从左到右出现的顺序就是用运算符写表达式
时操作数的顺序。

如果是双目运算符U，它的其中一个操作数是类A的对象a，那么运算符U就可以重载为类A的友元函数，
此友元函数的两个参数中，一个是类A的对象，另一个是其他对象，也可以是类A的对象。
*/
/*CTimeSpan operator -(CTimeSpan ts1, CTimeSpan ts2)  // 重载运算符函数实现
{
	int nNewHours = ts1.m_nHours  + ts2.m_nHours ;
	int nNewMins = ts1.m_nMins + ts2.m_nMins ;
	nNewHours += nNewMins/60;
	nNewMins %= 60;
	return CTimeSpan(nNewHours, nNewMins);
}
貌似在vc++6.0中不支持重载运算符为类的友元函数，因为编译不过
*/

void CTimeSpan::Show()
{
	cout << m_nHours << "小时" << m_nMins << "分钟" << endl;
}

void CTimeSpan::Temp()
{
	cout << "m_temp = " << m_temp << endl;
}

//运算符重载：end

class B
{   
public:
	void Set(int i);
	void Display();

private:
	CTimeSpan a;
};
/*
友元关系不能传递：如果类B是类CTimeSpan的友元，类C又是类B的友元，类C和类CTimeSpan如果没有声明则没有友元关系：
友元关系是单向的，如果类B是类CTimeSpan的友元，类B的成员函数可以访问类CTimeSpan对象的私有成员和保护成员，
但是类CTimeSpan的成员函数不能访问类B对象的私有成员和保护成员。

友元破坏了类的封装性和类数据的隐藏性，但是又给软件开发提供了很多方便，在实地进行软件
开发的时候可以自己在共享和封装之间平衡一下，决定是否选择使用友元，但原则上尽量少使
用或不使用友元，除非确实很大的提高了开发效率。
*/
void B::Set(int i)
{
	a.m_temp = i; // 因为类B是类CTimeSpan的友元类，所以类B的成员函数可以访问类CTimeSpan对象的私有成员
}
void B::Display()
{
	a.Temp();
}

/*虚函数：在基类中将某个函数声明为虚函数，就可以通过指向派生类对象的基类指针访问派生类中的同名成员了。
这样使用某基类指针指向不同派生类的不同对象时，就可以发生不同的行为，也就实现了运行时的多态。解决了赋值兼容规则中
只能访问到基类中的同名函数的困境。

运行时多态的三个条件:1.类之间要满足赋值兼容规则；2.要声明虚函数；
3.通过类的对象的指针、引用访问虚函数或者通过类的成员函数调用虚函数。

虚函数是动态绑定的基础。记住，虚函数是非静态的成员函数，一定不能是静态（static）的成员函数。
*/
class Basev // 基类Basev的声明
{
public:
	virtual void show()    { cout << "Basev::show()" << endl; } // 基类中的虚成员函数show，关键词virtual
	virtual void show22();
};

/*
如果成员函数的实现在类的声明外给出时，则虚函数的声明只能出现在类的成员函数声明中，而不能在
成员函数实现时出现，简而言之，只能在此成员函数的声明前加virtual修饰，而不能在它的实现前加。
*/
void Basev::show22()
{
	cout << "Basev::show22()" << endl; 
}

class Child0v : public Basev     // 类Basve的公有派生类Child0v的声明
{
public:
	void show()    { cout << "Child0v::show()" << endl; }    // 虚成员函数show
	void show22()    { cout << "Child0v::show22()" << endl; } 
};

class Child1v : public Child0v  // 类Child0的公有派生类Child1的声明
{
public:
	void show()    { cout << "Child1v::show()" << endl; }    // 虚成员函数show
	void show22()    { cout << "Child1v::show22()" << endl; } 
};

void CallShow(Basev *pBase)     // 一般函数，参数为基类指针
{
	pBase->show();
	pBase->show22();
}
//虚函数end

/*抽象类与纯虚函数。抽象类：含有纯虚函数的类, 它不需要定义纯虚函数的实现，而且抽象类不能
实例化，即不能定义抽象类的对象，只能从它继承出非抽象派生类再实例化。(类似于Java中的接口)*/
class CBase// 抽象类CBase的声明
{
public:
	virtual void show() = 0;// 纯虚函数成员show，注意比一般的虚函数多了“ = 0”
	virtual void show44() = 0;
};

/*
注意：抽象类的派生类如果没有实现所有的纯虚函数，只给出了部分纯虚函数的实现，那么这个派生类仍然是抽象类，
仍然不能实例化，只有给出了全部纯虚函数的实现，派生类才不再是抽象类并且才可以实例化。假如类CChild0没有实现
show44()函数，则类CChild0依然是个抽象类，当为它实例时就会出错。
*/
class CChild0 : public CBase// 类CBase的公有派生类Child0的声明
{
public:
	void show()    { cout << "CChild0::show()" << endl; } // 虚成员函数show
	void show44(){};
};

class CChild1 : public CChild0 // 类Child0的公有派生类Child1的声明
{
public:
	void show()    { cout << "CChild1::show()" << endl; }    // 虚成员函数show
};

void CallShow(CBase *pBase)// 一般函数，参数为基类指针
{
	pBase->show();
}
//抽象类与纯虚函数end

int main()
{
	cout<<"==========赋值兼容规则==========="<<endl;
	//虽然公有派生类对象可以代替基类对象使用，但是只能使用它从基类继承的成员，而无法使用它的新添成员。
	//因此将派生类对象的地址赋值给pBase以后，通过pBase只能访问派生类从基类继承的成员，哪怕指针
	//pBase指向的是派生类对象ch0或者ch1，在CallShow中通过pBase也只能调用从基类Base继承的成员函数show
	//，而不会调用Child0类或者Child1类的成员函数show。因此主函数中三次调用CallShow函数，都是访问的基类
	//Base的成员函数show，输出都是Base::show()。 这时我们深切的感受到，即使派生类对象代替了基类对象，
	//它也只能产生基类的功能，自己的新功能无法体现。要想在代替以后同样能够实现自己的功能，就要用到面向
	//对象设计的另一个特性--多态性。
	Base base;       // 声明Base类的对象
	Base *pBase;     // 声明Base类的指针
	Child0 ch0;       // 声明Child0类的对象
	Child1 ch1;      // 声明Child1类的对象
	pBase = &base;   // 将Base类对象base的地址赋值给Base类指针pBase
	CallShow(pBase);
	pBase = &ch0;    // 将Child0类对象ch0的地址赋值给Base类指针pBase
	CallShow(pBase);
	pBase = &ch1;    // 将Child1类对象ch1的地址赋值给Base类指针pBase
	CallShow(pBase);
	cout<<"==========赋值兼容规则==========="<<endl;

	cout<<"==========运算符重载==========="<<endl;
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
    cout<<"==========运算符重载==========="<<endl;

	cout<<"==========静态数据成员与函数==========="<<endl;
	CTimeSpan::f(timeSpan3);
	timeSpan3.Count();
	CTimeSpan::Count();
	cout<<"==========静态数据成员与函数==========="<<endl;

	cout<<"==========友元函数与友元类==========="<<endl;
	cout<<"friend access : "<<add(timeSpan3)<<endl;
	B b;
	b.Set(10000);
	b.Display();
	cout<<"==========友元函数与友元类==========="<<endl;
	/*貌似在vc++6.0中不支持重载运算符为类的友元函数，因为编译不过
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
	1.类之间要满足赋值兼容规则；2.要声明虚函数；3.通过类的对象的指针、引用访问虚函数或者通过类的成员函数调用虚函数。
	*/
	cout<<"==========虚函数==========="<<endl;
	Basev basev;                 // 声明Base类的对象
	Basev *pBasev;             // 声明Base类的指针
	Child0v ch0v;                 // 声明Child0类的对象
	Child1v ch1v;                 // 声明Child1类的对象
	pBasev = &basev;        // 将Base类对象base的地址赋值给Base类指针pBase
	CallShow(pBasev);
	pBasev = &ch0v;            // 将Child0类对象ch0的地址赋值给Base类指针pBase
	CallShow(pBasev);
	pBasev = &ch1v;            // 将Child1类对象ch1的地址赋值给Base类指针pBase
	CallShow(pBasev);
	cout<<"==========虚函数==========="<<endl;

	
	//不能声明抽象类的对象，使用抽象类一般是通过声明抽象类的指针或引用，将指针或引用指向派生类的对象，访问派生类的成员。
	cout<<"==========抽象类与纯虚函数==========="<<endl;
	CBase *cpBase;             // 声明Base类的指针
	CChild0 cch0;                 // 声明Child0类的对象
	CChild1 cch1;                 // 声明Child1类的对象
	cpBase = &cch0;           // 将Child0类对象ch0的地址赋值给Base类指针pBase
	CallShow(cpBase);
	cpBase = &cch1;           // 将Child1类对象ch1的地址赋值给Base类指针pBase
	CallShow(cpBase);
	cout<<"==========抽象类与纯虚函数==========="<<endl;
	return 0;
}