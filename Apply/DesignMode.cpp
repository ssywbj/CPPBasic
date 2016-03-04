#include "DesignMode.h"

//�������Ӧ�ã�����ӿڱ�׼-->start
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
//�������Ӧ�ã�����ӿڱ�׼-->end

//�������Ӧ�ã��������-->start
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
//�������Ӧ�ã��������-->end

//�������Ӧ�ã��������-->start
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
//�������Ӧ�ã��������-->end

int main()
{
	cout<<"�������Ӧ�ã�����ӿڱ�׼"<<endl;
	Print print;
	Plugin::print(print);
	USB usb;
	Plugin::print(usb);

	cout<<"\n"<<"�������"<<endl;
	Friut *friut = Factory::getInstance(0);
	friut->eat();
	friut = Factory::getInstance(-1);
	friut->eat();

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

	Net *netProxy = new Proxy(new TelecomNet());//��̬�ڴ����
	netProxy->browse();
	delete netProxy;
	netProxy = NULL;
	//ע�������Net������ʵ���������ַ�ʽ��end

	return 0;
}