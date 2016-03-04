#ifndef DESIGN_MODE
#define DESIGN_MODE

#include<iostream>

using namespace std;

//抽象类的应用：定义接口标准-->start
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
	static void print(Computer &com);//只接收Computer的子类
};
//抽象类的应用：定义接口标准-->end

//抽象类的应用：工厂设计-->start
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
//抽象类的应用：工厂设计-->end

//抽象类的应用：代理设计-->start
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
	//注意两种给mNet指针赋值的方式：start
    Proxy(Net &net);
    Proxy(Net *net);
	//注意两种给mNet指针赋值的方式：end
	void browse();
	void check();
};
//抽象类的应用：代理设计-->end

#endif