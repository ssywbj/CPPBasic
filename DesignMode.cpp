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
	void work()
	{
		cout<<"USB work!!"<<endl;
	}
};

class Print : public Computer
{
public:
	void work()
	{
		cout<<"Print work!!"<<endl;
	}
};

class Plugin
{
public:
	static void print(Computer &com)//只接收Computer的子类
	{
		com.work();
	}
};
//抽象类的应用：定义接口标准-->end

//抽象类的应用：代理设计-->start
class Net
{
public:
	virtual void browse() = 0;
};

class MobileNet : public Net
{
public:
	void browse()
	{
		cout<<"mobile net!!"<<endl;
	}
};

class TelecomNet : public Net
{
public:
	void browse()
	{
		cout<<"telecom net!!"<<endl;
	}
};

class Proxy : public Net
{
private:
	Net *mNet;

public:
	//注意两种给mNet指针赋值的方式：start
    Proxy(Net &net)
	{
		mNet = &net;
	}

    Proxy(Net *net)
	{
		mNet = net;
	}
	//注意两种给mNet指针赋值的方式：end

	void browse()
	{	
		check();
		mNet->browse();
	}

	void check()
	{	
		cout<<"proxy check info"<<endl;
	}

};
//抽象类的应用：代理设计-->end

//抽象类的应用：工厂设计-->start
class Friut
{
public:
	virtual void eat() = 0;
};

class Apple : public Friut
{
public:
	void eat()
	{
		cout<<"eat apple"<<endl;
	}
};

class Orange : public Friut
{
public:
	void eat()
	{
		cout<<"eat orange"<<endl;
	}
};

class Factory
{
public:
	static Friut* getInstance(int i)
	{
		Friut *friut;
		if(i >= 0)
		{
			Apple apple;
			friut = &apple;
		}
		else
		{
			Orange orange;
			friut = &orange;
		}
		return friut;
	}
};
//抽象类的应用：工厂设计-->end

int main()
{
	//抽象类的应用：定义接口标准-->start
	cout<<"抽象类的应用：定义接口标准"<<endl;
	Print print;
	Plugin::print(print);
	USB usb;
	Plugin::print(usb);

	//注意抽象类Net被子类实例化的两种方式：start
	cout<<"\n"<<"代理设计"<<endl;
	MobileNet mobileNet;
	Proxy proxyMobile(mobileNet);
    Net &netMobile = proxyMobile;//定义抽象类的引用
	netMobile.browse();

	TelecomNet telecomNet;
	Proxy proxyTelecom(telecomNet);
	Net *netTelecom = &proxyTelecom;//定义抽象类的指针
	netTelecom->browse();
	//注意抽象类Net被子类实例化的两种方式：end

	cout<<"\n"<<"工厂设计"<<endl;
	Friut *friut = Factory::getInstance(0);
	friut->eat();
	friut = Factory::getInstance(-1);
	friut->eat();

	return 0;
}
