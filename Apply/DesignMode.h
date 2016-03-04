#ifndef DESIGN_MODE
#define DESIGN_MODE

#include<iostream>

using namespace std;

//�������Ӧ�ã�����ӿڱ�׼-->start
class Computer
{
public:
	virtual void work() = 0;
};

class USB : public Computer
{
public:
	void work();
};

class Print : public Computer
{
public:
	void work();
};

class Plugin
{
public:
	static void print(Computer &com);//ֻ����Computer������
};
//�������Ӧ�ã�����ӿڱ�׼-->end

//�������Ӧ�ã��������-->start
class Friut
{
public:
	virtual void eat() = 0;
};

class Apple : public Friut
{
public:
	void eat();
};

class Orange : public Friut
{
public:
	void eat();
};

class Factory
{
public:
	static Friut* getInstance(int i);
};
//�������Ӧ�ã��������-->end

//�������Ӧ�ã��������-->start
class Net
{
public:
	virtual void browse() = 0;
};

class MobileNet : public Net
{
public:
	void browse();
};

class TelecomNet : public Net
{
public:
	void browse();
};

class Proxy : public Net
{
private:
	Net *mNet;

public:
	//ע�����ָ�mNetָ�븳ֵ�ķ�ʽ��start
    Proxy(Net &net);
    Proxy(Net *net);
	//ע�����ָ�mNetָ�븳ֵ�ķ�ʽ��end
	void browse();
	void check();
};
//�������Ӧ�ã��������-->end

#endif