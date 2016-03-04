#include<iostream>
#include<string>

using namespace std;

void reset(int p);
void reset(int *p);
void reset2(int &p);
int findChar(const string &s, char c, int &count);
void printArr(const int arr[], int size);
void printArr(const int *begin, const int *end);
string returnStr();
const string &returnStr(const string &s1, const string &s2);
int* retArray(int &len);

int main()
{
	int i = 2, *p = &i;
	reset(i);
	cout<<"i = "<<i<<endl;//i的值并未改变

	reset(p);
	cout<<"i = "<<i<<endl;//通过指针改变i的值
	reset(&i);
	cout<<"i = "<<i<<endl;//通过指针改变i的值

	//通过引用改变i的值。在C中，常常使用指针类型的形参访问函数外部的对象。
	//在C++中，建议使用引用类型的形参替代指针
	reset2(i);
	cout<<"i = "<<i<<endl;

	//string s("abcdefge");
	//int count = 0;
	//int index = findChar("abcdefge", 'f', count);
	//cout<<"index = "<<index<<", "<<"count = "<<count<<endl;

	//int arr[] = {0, 7, 9, 9,0, 11, 987};
	//reset(arr);
	//cout<<"arr = "<<arr<<endl;

	//int len = sizeof(arr)/sizeof(*arr);
	//printArr(arr, len);
	//printArr(arr, &arr[len]);

	//cout<<returnStr()<<endl;
	//cout<<returnStr("Hello", "hi")<<endl;

    //函数返回指向数组的指针
	int len = 0;
    int *begin = retArray(len); 
	int *end = &begin[len];
	while(begin != end)
	{
		cout<<*begin++<<" ";// 输出数组元素
	}
	cout<<endl;

	char *pCh = "dfkdafd";//用字符串常量初始化字符数组时，会自动添加表示字符结束的空字符
	cout<<pCh<<endl;//直接输出数组
	char *beginCh = pCh;
	char *endCh = beginCh + strlen(pCh);
	while(beginCh < endCh)
	{
		cout<<*beginCh++;
	}
	cout<<endl;

	char temp[5];
	int len2 = 0;
	while(len2 < 4)
	{
		temp[len2] = *pCh;
		len2++;
		pCh++;
	}
	temp[4] = '\0';//最后一个位置存在空字符'\0'用于标识数组的结束，以免报错：字符数组的特殊性
	cout<<temp<<endl;

	char temp2[] = {'a', 'b', 'c'};
	cout<<sizeof(temp2)/sizeof(*temp2)<<"::"<<temp2<<endl;//没有添加'\0'，数组的维度为3，将不会正确输出abc，因为找不到数组的结束符(字串数组的特殊性)
	char temp3[] = {'a', 'b', 'c', '\0'};
	cout<<sizeof(temp3)/sizeof(*temp3)<<"::"<<temp3<<endl;//显示地在数组的最后添加'\0'，数组的维度为4，将会正确输出abc

	return 0;
}

void reset(int p)
{
	p *= p;
}

void reset(int *p)
{
	*p *= *p;
}

//拷贝大的类型对象或者容器对象比较低效，甚至有的类类型(包括IO类型在内)，根本就不支持拷贝操作，此时函数只能通过引用形参访问该类型的对象
void reset2(int &p)
{
	p *= p;
}

//如果函数无须改变引用形参的值，最好将其声明为常量引用
int findChar(const string &s, char c, int &count)
{
	int ret = s.size();
	for(int i = 0;i < s.size();++i)
	{
		if(s[i] == c)
		{
			if(ret == s.size())
			{
				ret = i;
			}

			++count;
		}
	}

	if(ret == s.size())
	{
		ret = -1;
	}
	return ret;
}

void printArr(const int *begin, const int *end)
{
	//int len = sizeof(arr)/sizeof(*arr);函数内无法这样求出数组的长度，因为数组以指针的形式传递给函数，所以一开始函数并不知道数组的确切尺寸
	while(begin != end)
	{
		cout<<*begin++<<" ";
	}
	cout<<endl;
}

void printArr(const int arr[], int size)//因为数组会被转换成指针，所以当我们会函数传递一个数组时，实际上传递的是指向数组的指针
{
	//int len = sizeof(arr)/sizeof(*arr);函数内无法这样求出数组的长度，因为数组以指针的形式传递给函数，所以一开始函数并不知道数组的确切尺寸
	printArr(arr, &arr[size]);
}

string returnStr()
{
	return "Hello World!!!";//直接返回局部变量
}

//返回引用的函数(函数名前多了一个“&”)
inline const string &returnStr(const string &s1, const string &s2)
{
	//错误；原因在返回返回引用的函数里，不能返回局部对象的引用或指针，因为函数调用完成后，它所占的存储空间也会随之释放
	//string ret;
	//return "Hello World!!!";
	return s1.size() >= s2.size() ? s1 : s2;
}
//使用关键字"inline"声明的函数为内联函数。一般来说，内联机制用于优化规模较小、流程直接、频繁调用的函数，
//很多编译器都不支持内联递归函数，而且一个75行的函数也不大可能在调用点内联地展开。内联函数通常在头文件中定义

int* retArray(int &len)//C++中不能返回数组，但可以返回数组的指针或引用
{ 
	int *arr = new int[4];//动态分配内存
	arr[0] = 98;
	arr[1] = 334;
	arr[2] = 5;
	arr[3] = 67;

	len = 4;
	return arr;
}  