#include<vector>

#include "test.h"

int main()
{
	//baseDemo();
	//inputMultiStr();
	//getlineDemo();
	//strCharDemo();
	//cout<<"return string is "<<returnStrDemo()<<endl;
	//vectorBaseDemo();
	//iteratorBaseDemo();
	//searchDemo(5);
	//arrayDemo();

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

void arrayDemo(void)//为了与C语言兼容，可以使用关键字void表示函数没有形参
{
	int arr[10];
	int i = 1;
	//int arr2[i];错误：数组中的维度必须是一个常量表达式且大于0，不允许用auto关键字定义数组
	int arr2[] = {9,0,9};
	//int arr3[] = arr2;错误：不允许将数组的内容赋值给其他数组
	int *ptrs[10];//ptrs是含有10个整型类型的数组
    //int &refs[10];错误：不存在引用的数组
	int (*parray)[10] = &arr;//parray指向一个含有10个整数的数组
	int (&arrRef)[10] = arr;//arrRef引用一个含有10个整数的数组

	string nums[] = {"advbd", "agfagd", "fffaaa"};
	string *p = &nums[0];//指向num的第一个元素
	cout<<"*p = "<<*p<<endl;
	string *str = nums;//直接指向数组名，等价于指向数组第一个元素：string *p = &nums[0];
	cout<<"*str = "<<*str<<endl;
	//auto ia2(nums);ia2是一个指针，指向nums的第一个元素，等价于auto ia2(&nums[0])，在一些情况下数组的操作就是指针的操作
	//而"decltype(nums) nums3 = {"a", "b", "c"};返回的是由三个元素组成的字符串数组，注意与"auto ia2(nums)"的区别。

	const int len = 10;
	int array[len] = {45, 9, 12, 67, 34, 98, 6};
	int *end = &array[len];//获取指向数组最后一个元素的下一个元素的指针，实际上这个元素并不存在，这个指针的作用类似于尾后迭代器
	cout<<"*end = "<<*end<<endl;//int *beg = begin(array);int *end = end(array);C++11标准
	for(int *begin = array;begin != end;++begin)
	{
		cout<<*begin<<" ";
	}
	cout<<endl;

	int arr4 = *(array +4);//解引用与指针运算的交互
	cout<<"*arr4 = "<<arr4<<endl;//输出array[4]的值
	arr4 = *array +4;
	cout<<"*arr4 = "<<arr4<<endl;//输出(array[0] + 4)的值

	int array2 = array[2];
	cout<<"*array2 = "<<array2<<endl;
	array2 = *(array+2);//array[2]等价于*(array+2)：在很多情况下，使用数组的名字其实就是在使用一个指向数组首元素的指针
	cout<<"*array2 = "<<array2<<endl;
	int *array4 = (array +4);//下标与指针的运算
	array2 = array4[1];//等价于*(array4 + 1);
	cout<<"*array2 = "<<array2<<endl;
	array2 = array4[-1];//等价于*(array4 - 1);
	cout<<"*array2 = "<<array2<<endl;

	//现代的C++程序应当尽量使用vector和迭代器，以免使用内置数组和指针；应该尽量使用string，避免使用C风格的基于数组的字符串

	const int len3 = 4;
	int ia[3][len3] = {{1, 2, 3, 99}, {456, 190}, {89}};
	int (&row)[len3] = ia[1];//row是一个含有四个整数的数组的引用，它绑定到ia的第二行
	for(int j = 0;j < len3;j++)
	{
		cout<<row[j]<<" ";
	}
	cout<<endl;
	int (*ppp)[len3] = ia;//指向含有四个整数的数组
	for(int jj = 0;jj < len3;jj++)
	{
		cout<<*(ppp[jj])<<" ";
	}
	cout<<endl;
}

void iteratorBaseDemo()
{
	string addInfo = "na4e g7fg";
	if(addInfo.begin() != addInfo.end())//判断非空：如果两个返回的迭代器不一样，即不是尾后迭代器
	{
		char* ch = addInfo.begin();//获取指向第一个元素的指针
		cout<<"*ch = "<<*ch<<endl;//解指针取值
		*ch = toupper(*ch);
		cout<<"*ch = "<<*ch<<endl;
		ch++;//指示容器的下一个元素；ch--是指示容器的上一个元素
		cout<<"*ch = "<<*ch<<endl;

		for(char *c = addInfo.begin();c != addInfo.end();c++)//迭代string对象中的元素
		{
			cout<<*c<<"  ";
		}
		cout<<endl;

		string *p_addInfo = &addInfo;
		if(!p_addInfo->empty())//先对p_addInfo解引用，再调用empty函数，等价：!(*p_addInfo).empty()
		{
			cout<<"================="<<endl;
		}
		else
		{
			cout<<"!!!!!!!!!!!!!!!!!"<<endl;
		}	
	}	
}

/*
 *二分查找功能
 */
void searchDemo(int des)
{
	cout<<"5 / 2 = "<< (5 / 2)<<endl;
	cout<<"5 / 3 = "<< (5 / 3)<<endl;
	cout<<"5 / 4 = "<< (5 / 4)<<endl;

	vector<int> ints;//要完成二分查找功能，ints看元素必须是有序的
	for(int i = 0; i < 11;i++)
	{
		ints.push_back(i * 2 - 1);
	}

	if(ints.begin() != ints.end())
	{
		for(int *i = ints.begin(); i != ints.end();i++)
		{
			//ints.push_back(63);注意：在迭代器中不能改变vector的容量，因为任何一种改变vector对象容量的操作都会使迭代器失效
			cout<<*i<<"  ";
		}
		cout<<endl;

		int *beg = ints.begin();//获取指向第一个元素的迭代器(指针)
		int *end = ints.end();//获取指向最后一个元素的下一个元素的迭代器(也被称为尾后迭代器(指针)，它没有什么含义，仅是个标记，表示我们已经处理完成容器中的所有元素)
		int *mid = beg + (end - beg)/2;
		cout<<"*beg = "<< *beg <<", *mid = "<< *mid <<", *(end - 1) = "<< *(end - 1)<<endl;

		if(des > *(end - 1))//尾后迭代器减1(指针左移一位)即会得到指向最后一个元素的指针
		{
			cout<<"source is so big"<<endl;
			return;
		}
		else if(des == *(end - 1))
		{
			cout<<des <<" on last position"<<endl;
			return;
		}
		else if(des == *beg)
		{
			cout<<des <<" on first position"<<endl;
			return;
		}

		while(mid != end && *mid != des)
		{
			if(des < *mid)
			{
				end = mid;
			}
			else
			{
				beg = mid + 1;
			}

			mid = beg + (end - beg)/2;
			cout<<"*mid = "<< *mid <<endl;	
		}

		if(des == *mid)
		{
			cout<<des <<" in of list"<<endl;
		}
		else 
		{
			cout<<des <<" out of list"<<endl;
		}
	}
	
}

void vectorBaseDemo()
{
	//初始化vector对象的几个特殊方法
	//vector<T> v3(n, val);v3包含n个重复的元素，每个元素的值都是val
	//vector<T> v4(n);v4包含n个重复地执行了值初始化的对象
	//vector<T> v5{a, b, c, d};v5包含初始值个数的元素，每个元素被赋予相应的初始值
	//vector<T> v6 = {a, b, c, d};等价于v5{a, b, c, d}
	string baseInfo = "info";
	string addInfo = "1a4eg7fg";
	int addInfoLen = 0;
	if(!addInfo.empty())
	{
		addInfoLen = addInfo.size();
	}
	vector<string> infos;
	for(int i = 0;i < 10;i++)//不能在范围for循环中向vector对象添加元素
	{
		if(i < addInfoLen)
		{
			infos.push_back(baseInfo + addInfo[i]);
		}
		else
		{
			infos.push_back(baseInfo);
		}	
	}

	if(!infos.empty())
	{
		auto len = infos.size();
		for(auto i = 0;i < len;i++)
		{
			cout<<infos[i]<<"  ";
		}
		cout<<endl;
	}
	
}

void strCharDemo()
{
	string s2(",Ff/a,C'''fad!!!!!!!");
	string upperStr;
	auto len = s2.size();
	int pnt = 0;

	//decltype(s2.size()) count = 0;decltype关键字：C++11标准
	//for(auto c:s2)//范围for：C++11标准
	//{
	//}

	if(!s2.empty())//如果对string对象使用了下标，都要确认在那个位置上确实有值；如果s2为空，则s2[i]的结果将是未定义的
	{	
		for(auto i = 0; i<len; i++)
		{
			//cout<<"s2["<<i<<"] = "<<s2[i]<<"  ";
			cout<<s2[i]<<"  ";
			if(ispunct(s2[i]))//判断是否是标点符号
			{
				pnt++;//统计标点符号的个数
			}
			else
			{
				if(isalpha(s2[i]))//抽取s2中的字母
				{
					upperStr += toupper(s2[i]);//如果是小写，则转换成大写；否则原样输出
				}	
			}
			
			//把s2中字母全部变成小写字母：如果是大写，则转换成小写；否则原样输出
			//char &ch = s2[i];ch = tolower(ch);//方法一：利用引用间接修改值
			s2[i] = tolower(s2[i]);//方法二：直接修改值
		}
		cout<<endl;
		cout<<"pnt = "<<pnt<<", upperStr = "<<upperStr;
		cout<<endl;
		cout<<"s2 = "<<s2<<endl;
	}
}
void baseDemo()
{
	//要使用string标准类型，先#include<string>并使用命名空间std
	string s;//初始化方式1，s为空串
	string s2("dfad  fad");//初始化方式2，s2被直接初始化为"dfad  fad"
	string s3 = "dfadfad";//初始化方式3，s3被拷贝初始化为"dfadfad"
	string s4(10, 'c');//初始化方式4，s4为10个c
	s2 = "s2";//修改s2的值
	cout<<"s = "<<s<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;

	cin >> s;//从键盘输入流中给s赋值
	cout<<"s = "<<s<<endl;//如果输入"  dfadfa fffff   "(注意空格)，则只会输出dfadfa，即输出的的结果中是没有任何空格的

	//size()返回的是一个string::size_type类型的值，size_type是一个无符号类型的值而且能足够存放下任何string对象的大小
	//如果在表达式中滥用了带符号数和无符号数，就会有意想不到的效果，因此混用需谨慎，最好不混用。
	cout<<"s.size() = "<<s.size()<<endl;//获取字符串长度size()
	//auto len = s.size();通过auto或decltype来推断变量len的类型

	if(s.empty())//判断字符串是否为空
	{
		cout<<"s is null"<<endl;
	}
	else
	{
		cout<<"s isn't null"<<endl;
	}

	//字符串比较规则：对应位置上的字符按ASCII码值逐个比较，第一个不一样的字符的值哪个比较大，那个字符串就比较大；
	string str1 = "hello";
    string str2 = "hel";
	string str3 = "Hel";
	string str4 = "hil";
	string str5 = "Bil";
	string str6 = "hel";
	if(str1 == str2)//str1与str2相等
	{
		cout<< "str1与str2相等" <<endl;
	}
	else//不等
	{
		cout<< "str1与str2不等" <<endl;
	}
	cout<< (str6 == str2) <<endl;//相等结果为1，不等结果为0

	if(str1 > str2)
	{
		cout<< str1<<"大于"<<str2 <<endl;
	}
	else//
	{
		cout<< str1<< "小于" <<str2<<endl;
	}
	if(str2 > str3)
	{
		cout<<str2<< "大于"<<str3 <<endl;
	}
	else//
	{
		cout<<str2<< "小于" <<str3<<endl;
	}
	if(str1 > str4)
	{
		cout<<str1<< "大于"<< str4<<endl;
	}
	else//
	{
		cout<<str1<< "小于" << str4<<endl;
	}
	if(str1 > str5)
	{
		cout<< str1<< "大于"<< str5 <<endl;
	}
	else//
	{
		cout<< str1<< "小于" << str5<<endl;
	}

	string addStr = str5 + str6;//两个string对象相加，等价于string addStr = (str5 += str6);
	cout<< "addStr = " << addStr<<endl;

	//字面值常量(切记：字符串字面值与string是不同的类型)和string对象相加:确保运算符(+)的两则的运算对象至少有一个是string
	addStr = ", "  + addStr;
	cout<< "addStr = " << addStr<<endl;
	//addStr = ", "  + ";;;;;";//无法相加，因为运算符(+)的两则没有一个是string对象
	//addStr = ", "  + ";;;;;" + addStr;//错误：无法相加，因为是从右往左运算，而第一个运算符(+)的两则没有一个是string对象
	addStr = addStr + ", " + ";;;;;";// 正确：运用连续输入输出原理(cin >> s1 >> s2)，等价于:string temp = addStr + ", ";addStr = temp + ";;;;;";
	cout<< "addStr = " << addStr<<endl;
}

void inputMultiStr()
{
	string s1, s2;
	cin >> s1 >> s2;//从键盘输入流中给s1和s2赋值
	cout<< s1 << s2 <<endl;//如果输入"  dfadfa fffff   "(注意空格)，则只会输出dfadfafffff，即输出的的结果中是没有任何空格的
}

void getlineDemo()
{
	string line;
	//getline(cin, line)遇到换行符才会执行结束(注意：换行符也会被读进来)，但变量line不存储换行符
	while(getline(cin, line))//如果流有效(没遇到文件结束标记或非法输入)，则不断从输入流中读取一行数据
	{
		cout<< "line = " << line <<endl;
	}
}

string returnStrDemo()
{
	string content(" H o  ld! !  ");

	string str("abcd efg");
	for(char* it = str.begin(); it != str.end() && !isspace(*it); ++it)//到达字符串末尾或遇到空格时结束循环
	{
		*it = toupper(*it);//把字符串中的元素转换成大写字母，
	}
	cout<<str<<endl;

	string returnStr;
	if(!content.empty())
	{
		auto len = content.size();
		for(auto i = 0;i < len; i++)
		{
			char &ch = content[i];
			if(!isspace(ch))
			{
				returnStr += ch;
			}

			/*if(isalpha(ch))
			{
				returnStr += ch;
			}*/
		}
	}
	return returnStr;
	//return "Hello World!!!";
}




