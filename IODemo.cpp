//#include<iostream>
#include "text.h"
void betweenTwoNumbers();
void sumUnlimitNumbers();
void countRepeatNumbers();
void referenceDemo();
void TypeConvert();
//using namespace std;
const int buf_size = 8;//常量
typedef double dou;//类型别名
typedef double* doup;
//using udou = double*;

void display(int x, int y)//在头文件中声明的方法，在源文件中实现
{
	cout<<"x = "<<x<<", y = "<<y<<endl;
}

int main()
{
	//betweenTwoNumbers();
	//sumUnlimitNumbers();
	//countRepeatNumbers();
	referenceDemo();
	//TypeConvert();
	//display(8, 9);
	return 0;
}

/*
 * 输出两个整数之间的整数
 */
void betweenTwoNumbers(){
	cout<<"input two numbers"<<endl;

	int v1 = 0, v2 = 0;
	cin>>v1>>v2;
	cout<<"v1 = "<<v1<<", v2 = "<<v2<<endl;
	int v = (v1 <= v2) ? v1:v2;

	if(v1 <= v2){
		while(v < v2){		
			std::cout<<v<<" ";
			v++;
		}
	}else{
		while(v < v1){
			v++;
			cout<<v<<" ";
		}
	}
	cout<<endl;
}

/*
 * 求任意输入个数的数字之和
 */
void sumUnlimitNumbers(){
	int sum = 0, value = 0;
	//	value用于保存输入的每个数，value的读取操作在while循环中完成；一旦输入的不是整数，输入流无效，即循环结束
	while(std::cin >> value){
		sum += value;
	}

	cout<<"sum is "<<sum<<endl;
}

/*
 * 统计输入重复数字的个数
 */
void countRepeatNumbers(){
	int currVal = 0, val = 0;
	if(std::cin >> currVal){
		int cnt = 1;
		
		while(std::cin >> val){
			if(val == currVal){
				cnt++;
			}else{
				cout<<currVal<<" occurs "<<cnt<<" times "<<endl;
				currVal = val;
				cnt = 1;
			}
		}

		cout<<currVal<<" occurs "<<cnt<<" times "<<endl;
	}
}

void referenceDemo()
{
	int i, &ri = i;
	i = 5; ri = 10;//通过引用修改绑定对象的值
	cout<<i<<", "<<ri<<endl;
	//int m = 30;&ri = m;//错误：不能将引用重新绑定到另外一个对象

	int *p = &i;//定义一个指向int类型的指针p并为指针赋值，使指针p指向变量i(指针p存放i的地址)
	int *p2 = p;//定义p2初始值是为p，也就是变量i的地址，因此这两个指针指向同一个对象
	cout<<"p = "<<p<<", p2 = "<<p2<<", *p2 = "<<*p2<<endl;//*p2：由解指针操作符*得到指针p2所指的对象，输出它所指对象的值
	*p = 45;// 修改指针所指的对象的值
	cout<<"p = "<<p<<", *p = "<<*p<<", i = "<<i<<endl;// i的值为45
	*p2 = 17;
	cout<<"p2 = "<<p2<<", *p2 = "<<*p2<<", i = "<<i<<endl;// i的值为17

	int j = 15;
	p = &j;// 修改指针的值，使指针p指向变量j
	cout<<p<<", "<<*p<<", "<<i<<endl;// *p的值即为变量j的值

	int v = 12;
	int *pv = &v;
	*pv = *pv * *pv;
	cout<<"pv = "<<pv<<", *pv = "<<*pv<<", v = "<<v<<endl;

    int **ppv = &pv;// 指针也是对象。指向指针的指针：ppv指针指向pv指针(指针ppv存放指针pv的地址)
	cout<<"ppv = "<<ppv<<", *ppv = "<<*ppv<<", **ppv = "<<**ppv<<endl;// 指针的指针即有两个"*"的指针，需要对指针做再次解引用才能访问到最原始的那个对象

	int t = 42;
	int *pp = 0;// 定义空指针pp
	cout<<pp<<endl;
	int *&rp = pp;// rp是一个对指针pp的引用
	rp = &t;// 为rp赋值就是为指针pp赋值
	cout<<pp<<endl;
	*rp = 0;// 解引用，使t的值为0
	cout<<"t = "<<t<<endl;

	int errNumb = 0;
	int *const curErr= &errNumb ;//curErr将一直指向errNumb 
	cout<<"errNumb = "<<errNumb<<endl;
	*curErr = 12;//正确：curErr是一个指向普通变量的指针
	cout<<"errNumb = "<<errNumb<<endl;
	const double pi = 3.14;
	const double *const pip= &pi;//pip是一个指向常量对象的常量指针
	//*pip = 2.72;//错误：pip是一个指向常量的指针，常量的值不能被修改
	
	cout<<"buf_size = "<<::buf_size<<endl;

	dou d1 = 9.9;
	cout<<"d1 = "<<d1<<endl;
	doup pd1 = &d1;
	cout<<"pd1 = "<<pd1<<", *pd1 = "<<*pd1<<endl;
	//udou pd11 = &d1;
	//cout<<"pd11 = "<<pd11<<", *pd11 = "<<*pd11<<endl;

	auto autoi = 7 + 8;
	cout<<"autoi = "<<autoi<<endl;
	auto autoi2 = 7.89L + 8.99L;
	cout<<"autoi2 = "<<autoi2<<endl;
}

void TypeConvert()
{
	unsigned char c = -1;
	int i = c;
	cout<<"c = "<<i<<endl;

	bool flag = -2;//把非布尔类型的算术值赋给布尔类型时，如果初始值为0则结果为false，否则为true
	cout<<"flag = "<<flag;//flag的值为1
	if(flag)//true
	{
		cout<<", true"<<endl;
	}
	else
	{
		cout<<", false"<<endl;
	}
	flag = 0;
	cout<<"flag = "<<flag;//flag的值为0
	if(flag)//false
	{
		cout<<", true"<<endl;
	}
	else
	{
		cout<<", false"<<endl;
	}
	flag = 3;//flag的值为1
	cout<<"flag = "<<flag;
	if(flag)//true
	{
		cout<<", true"<<endl;
	}
	else
	{
		cout<<", false"<<endl;
	}

	i = flag;//把布尔类型的值赋给非布尔类型时，false为0，true为1，
	cout<<"i = "<<i<<endl;//i的值为1
	flag = false;
	i = flag;
	cout<<"i = "<<i<<endl;//i的值为0

	//使用无符号类型变量输出10~0之间的整数
	unsigned u = 11;//定义的无符号类型变量的初始值要比输出的最大值(这里为10)大1
	while(u > 0)//要使用while循环
	{
		u--;
		cout<<u<<'\t';
	}
	cout<<endl;

	cout<<'\x4d'<<'\t'<<'\115'<<endl;
	cout<<'\114'<<'\t'<<'\115'<<'\t'<<"\11567"<<endl;
}

struct Sales{
	int book;
} item, item2;//定义数据结构Sales并在类体后紧跟变量名(不要忘记在最后加分号)

struct Sales2{
};//不要忘记在最后加分号
Sales2 item3;//定义数据结构和定义类的变量名分开书写













