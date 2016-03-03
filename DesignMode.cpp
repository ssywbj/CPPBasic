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
	static void print(Computer &com)//ֻ����Computer������
	{
		com.work();
	}
};
//�������Ӧ�ã�����ӿڱ�׼-->end

//�������Ӧ�ã��������-->start
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
	//ע�����ָ�mNetָ�븳ֵ�ķ�ʽ��start
    Proxy(Net &net)
	{
		mNet = &net;
	}

    Proxy(Net *net)
	{
		mNet = net;
	}
	//ע�����ָ�mNetָ�븳ֵ�ķ�ʽ��end

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
//�������Ӧ�ã��������-->end

//�������Ӧ�ã��������-->start
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
//�������Ӧ�ã��������-->end

int main()
{
	//�������Ӧ�ã�����ӿڱ�׼-->start
	cout<<"�������Ӧ�ã�����ӿڱ�׼"<<endl;
	Print print;
	Plugin::print(print);
	USB usb;
	Plugin::print(usb);

	//ע�������Net������ʵ���������ַ�ʽ��start
	cout<<"\n"<<"�������"<<endl;
	MobileNet mobileNet;
	Proxy proxyMobile(mobileNet);
    Net &netMobile = proxyMobile;//��������������
	netMobile.browse();

	TelecomNet telecomNet;
	Proxy proxyTelecom(telecomNet);
	Net *netTelecom = &proxyTelecom;//����������ָ��
	netTelecom->browse();
	//ע�������Net������ʵ���������ַ�ʽ��end

	cout<<"\n"<<"�������"<<endl;
	Friut *friut = Factory::getInstance(0);
	friut->eat();
	friut = Factory::getInstance(-1);
	friut->eat();

	return 0;
}
