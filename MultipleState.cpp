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

int main()
{
	//虽然公有派生类对象可以代替基类对象使用，但是只能使用它从基类继承的成员，而无法使用它的新添成员。
	//因此将派生类对象的地址赋值给pBase以后，通过pBase只能访问派生类从基类继承的成员，哪怕指针
	//pBase指向的是派生类对象ch0或者ch1，在CallShow中通过pBase也只能调用从基类Base继承的成员函数show
	//，而不会调用Child0类或者Child1类的成员函数show。因此主函数中三次调用CallShow函数，都是访问的基类
	//Base的成员函数show，输出都是Base::show()。 这时我们深切的感受到，即使派生类对象代替了基类对象，
	//它也只能产生基类的功能，自己的新功能无法体现。要想在代替以后同样能够实现自己的功能，就要用到面向
	//对象设计的另一个特性--多态性。
	Base base;       // 声明Base类的对象
	Base *pBase;     // 声明Base类的指针
	Child0 ch0       // 声明Child0类的对象
	Child1 ch1;      // 声明Child1类的对象
	pBase = &base;   // 将Base类对象base的地址赋值给Base类指针pBase
	CallShow(pBase);
	pBase = &ch0;    // 将Child0类对象ch0的地址赋值给Base类指针pBase
	CallShow(pBase);
	pBase = &ch1;    // 将Child1类对象ch1的地址赋值给Base类指针pBase
	CallShow(pBase);
	return 0;
}