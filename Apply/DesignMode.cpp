#include "DesignMode.h"

//抽象类的应用：定义接口标准-->start
void USB::work()
{
	cout<<"USB work!!"<<endl;
}

void Print::work()
{
	cout<<"Print work!!"<<endl;
}

void Plugin::print(Computer &com)
{
	com.work();
}
//抽象类的应用：定义接口标准-->end

//抽象类的应用：工厂设计-->start
void Apple::eat()
{
	cout<<"eat apple"<<endl;
}

void Orange::eat()
{
	cout<<"eat orange"<<endl;
}

Friut* Factory::getInstance(int i)
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
//抽象类的应用：工厂设计-->end

//抽象类的应用：代理设计-->start
void MobileNet::browse()
{
	cout<<"mobile net!!"<<endl;
}

void TelecomNet::browse()
{
	cout<<"telecom net!!"<<endl;
}

Proxy::Proxy(Net &net)
{
	mNet = &net;
}

Proxy::Proxy(Net *net)
{
	mNet = net;
}

void Proxy::browse()
{	
	check();
	mNet->browse();
}

void Proxy::check()
{	
	cout<<"proxy check info"<<endl;
}
//抽象类的应用：代理设计-->end

int main()
{
	cout<<"抽象类的应用：定义接口标准"<<endl;
	Print print;
	Plugin::print(print);
	USB usb;
	Plugin::print(usb);

	cout<<"\n"<<"工厂设计"<<endl;
	Friut *friut = Factory::getInstance(0);
	friut->eat();
	friut = Factory::getInstance(-1);
	friut->eat();

	//注意抽象类Net被子类实例化的三种方式：start
	cout<<"\n"<<"代理设计"<<endl;
	MobileNet mobileNet;
	Proxy proxyMobile(mobileNet);
    Net &netMobile = proxyMobile;//定义抽象类的引用
	netMobile.browse();

	TelecomNet telecomNet;
	Proxy proxyTelecom(telecomNet);
	Net *netTelecom = &proxyTelecom;//定义抽象类的指针
	netTelecom->browse();

	Net *netProxy = new Proxy(new TelecomNet());//动态内存分配
	netProxy->browse();
	delete netProxy;
	netProxy = NULL;
	//注意抽象类Net被子类实例化的两种方式：end

	return 0;
}