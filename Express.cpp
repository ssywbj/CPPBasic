#include "test.h"

int main()
{
	int mod = 4 % 7;//C++中，参与求余运算的对象必须是整数类型
	cout<<"mod = "<<mod<<endl;

	if(mod != 0)
	{
		int m = -7;
		int temp = m / mod * mod + m % mod;
		cout<<"m % mod = "<<(m % mod)<<endl;

		//如果m、n是整数且n非0，则(m/n*n+m%n)的值与m相等，隐含的意思是如果m%n不等于0，则它的符号与m相同
		if(m == temp)
		{
			cout<<"them equal"<<endl;
		}
		if((7 % -4) == (7 % 4))	//m%-n等于m%n
		{
			cout<<"(m % -n) == (m % n)"<<endl;
		}	
		if((-7 % 4) == -(7 % 4))//-m%n等于-(m%n)
		{
			cout<<"(-m % n) == -(m % n)"<<endl;
		}

	}

	int grade = 100, *g;
	string score = (grade > 90) ? "high" : (grade > 60) ? "pass" : "fail";
	cout<<"score = "<<score<<endl;

	int size = sizeof(grade);
	cout<<"size = "<<size<<endl;
	size = sizeof(short);
	cout<<"size = "<<size<<endl;
	size = sizeof(char);
	cout<<"size = "<<size<<endl;
	size = sizeof(long);
	cout<<"size = "<<size<<endl;
	size = sizeof(long double);
	cout<<"size = "<<size<<endl;
	size = sizeof(double);
	cout<<"size = "<<size<<endl;
	size = sizeof(double*);
	cout<<"size = "<<size<<endl;

	int arr[] = {4, 6, 9, 17, 198}; 
	size = sizeof(arr);//对数组执行sizeof运算得到整个数组所占空间的大小，等价于对数组中所有的元素各执行一次sizeof运算并将所得结果求和
	cout<<"size = "<<size<<endl;

	string s("abc");
	size = sizeof(s);//对string对象或vector对象执行sizeof运算只返回该类型固定部分的大小，不会计算对象中的元素占用了多少空间
	cout<<"size = "<<size<<endl;

	string sarr[] = {"abc", "def", "ghi"};
	size = sizeof(sarr);
	cout<<"size = "<<size<<endl;

	int len = sizeof(arr) / sizeof(*arr);//获取数组中的元素个数
	cout<<"len = "<<len<<endl;

	int count = 0;
	for(;len > 0;len--, count++)//逗号运算符：按照从左向右的顺序依次求值，规定了运算对象的求值顺序，常用于for循环中
	{
		cout<<len<<" ";

		if(count == 3)
		{
			cout<<"\n"<<"count = "<<count<<"\n";
		}
	}
	cout<<endl;

	double slope = static_cast<double>(++len)/(++count);
	cout<<"slope = "<<slope<<"\n"<<endl;

	for(int k = 0, j = 5; k < j; k++, j--)
	{
		cout<<"k = "<<k<<", "<<"j = "<<j<<endl;
	}

    //C++异常处理机制
	int ii = 8, jj = 0;
	try
	{
		//try中是正常处理的程序
		if(jj != 0)
		{
			cout<<"ii / jj = "<<ii / jj;
		}
		else
		{
			throw runtime_error("jj is zero!!");//throw抛出异常
		}
	}
	catch(runtime_error err)//catch捕获异常
	{
		//处理异常
		jj = 2;
		cout<<err.what()<<"\n"<<"ii * jj = "<<ii * jj;//err.what()返回"jj is zero!!"，对于没有初始值的异常类型，what返回的内容由编译器决定
	}
	cout<<endl;

	for(int i = 0;i < 10;i++)
	{
		cout<<addNum()<<"\t";
	}
	cout<<endl;

	return 0;
}


int addNum()
{
	//使用关键字static定义的局部变量count变成局部静态对象。局部静态对象在程序的执行路径第一次经过对象
	//定义语句时初始化，并且直到程序终止时才被销毁，在此期间即使对象所在的函数结束执行也不会对它有影响
	static int count = 0;
	return ++count;
}