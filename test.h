#ifndef TEST_H
#define TEST_H

#include<iostream>
#include<string>

using namespace std;

//ʹ��using������ʽ1��ÿһ��using�������������ռ��е�һ����Ա
//using std::string;//��ʵstringҲ��ȫ���ռ�std��
//using std::cin;
//using std::cout;
//using std::endl;
//ʹ��using������ʽ2��ֱ��˵��ʹ��ĳ�����ռ�
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
int addNum();//������ʹ��֮ǰ��������������������Σ���ֻ�ܶ���һ�Ρ����һ��������Զ���ᱻ�õ�����ô����ֻ���������ö���

#endif
//һ��Ϊ�˰�ȫ�ԣ�ͷ�ļ�ֻ�����������𲻶��壬��������Դ�ļ���ʵ�֣�����������Σ���ֻ�ܶ���һ��
//����������������Ӧ����ͷ�ļ��У�����Դ�ļ��ж���