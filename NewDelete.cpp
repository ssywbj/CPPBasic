#include<iostream>

using namespace std;

class CStudent
{
public:
	CStudent()              { cout<<"Default constructor called."<<endl; }          // 无参数的构造函数
	CStudent(int nAge)      { m_nAge = nAge; cout<<"Constructor called."<<endl; }   // 带参数的构造函数
	~CStudent()             { cout<<"Destructor called."<<endl; }                               // 析构函数
	void GetAge(int age)    { m_nAge = age;cout<<"m_nAge = "<<m_nAge<<endl; }       // 内联函数，返回m_nAge

private:
	int m_nAge;        // 私有数据
};

int main()
{
	/*
	动态内存分配：new 类型名(初值列表)，此语句用于申请分配一个内存空间，此内存空间存放由“类型名”表示的类型的数据，
	并用初值列表中列出的值初始化。该语句会返回一个由“类型名”表示的类型的指针，如果分配失败则返回NULL。*/
	CStudent *ptr = new CStudent; // 动态创建对象，没有给出初值列表，所以调用无参数的构造函数

	 /*内存释放：delete 指针名，如果被删除的是普通变量，则会直接释放动态分配的内存。如果被删除的是对象，则该对象
	   的析构函数被调用。这里要注意一下，用new动态分配的内存只能用delete释放一次，如果释放第二次会出现错误。*/
	delete ptr; // 删除对象，自动调用析构函数

	ptr = new CStudent(16); // 动态创建对象，给出了初值，所以调用带参数的构造函数
	delete ptr;// 删除对象，自动调用析构函数

	CStudent *ptrArr = new CStudent[2]; // 动态创建对象数组，为每个对象元素调用无参数的构造函数
	delete []ptrArr;                    // 删除对象数组，自动为每个对象调用析构函数

	return 0;
}
