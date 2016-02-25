#ifndef TEST_H
#define TEST_H

#include<iostream>
#include<string>

using namespace std;

//使用using声明方式1：每一个using声明引入命名空间中的一个成员
//using std::string;//其实string也在全名空间std中
//using std::cin;
//using std::cout;
//using std::endl;
//使用using声明方式2：直接说明使用某命名空间
using namespace std;

void baseDemo();
void inputMultiStr();
void getlineDemo();
void strCharDemo();
string returnStrDemo();
void vectorBaseDemo();
void iteratorBaseDemo();
void searchDemo(int des);
void arrayDemo();
int addNum();//函数在使用之前必须声明，可以声明多次，但只能定义一次。如果一个函数永远不会被用到，那么可以只用声明不用定义

#endif
//一般为了安全性，头文件只负责声明负责不定义，而定义在源文件中实现；可以声明多次，但只能定义一次
//变量、函数的声明应该在头文件中，而在源文件中定义