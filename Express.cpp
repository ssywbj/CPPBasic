#include "test.h"

int main()
{
	int mod = 4 % 7;//C++�У�������������Ķ����������������
	cout<<"mod = "<<mod<<endl;

	if(mod != 0)
	{
		int m = -7;
		int temp = m / mod * mod + m % mod;
		cout<<"m % mod = "<<(m % mod)<<endl;

		//���m��n��������n��0����(m/n*n+m%n)��ֵ��m��ȣ���������˼�����m%n������0�������ķ�����m��ͬ
		if(m == temp)
		{
			cout<<"them equal"<<endl;
		}
		if((7 % -4) == (7 % 4))	//m%-n����m%n
		{
			cout<<"(m % -n) == (m % n)"<<endl;
		}	
		if((-7 % 4) == -(7 % 4))//-m%n����-(m%n)
		{
			cout<<"(-m % n) == -(m % n)"<<endl;
		}

	}

	int grade = 100, *g;
	string score = (grade > 90) ? "high" : (grade > 60) ? "pass" : "fail";
	cout<<"score = "<<score<<endl;

	int size = sizeof(grade);
	cout<<"size = "<<size<<endl;
	size = sizeof(short);
	cout<<"size = "<<size<<endl;
	size = sizeof(char);
	cout<<"size = "<<size<<endl;
	size = sizeof(long);
	cout<<"size = "<<size<<endl;
	size = sizeof(long double);
	cout<<"size = "<<size<<endl;
	size = sizeof(double);
	cout<<"size = "<<size<<endl;
	size = sizeof(double*);
	cout<<"size = "<<size<<endl;

	int arr[] = {4, 6, 9, 17, 198}; 
	size = sizeof(arr);//������ִ��sizeof����õ�����������ռ�ռ�Ĵ�С���ȼ��ڶ����������е�Ԫ�ظ�ִ��һ��sizeof���㲢�����ý�����
	cout<<"size = "<<size<<endl;

	string s("abc");
	size = sizeof(s);//��string�����vector����ִ��sizeof����ֻ���ظ����͹̶����ֵĴ�С�������������е�Ԫ��ռ���˶��ٿռ�
	cout<<"size = "<<size<<endl;

	string sarr[] = {"abc", "def", "ghi"};
	size = sizeof(sarr);
	cout<<"size = "<<size<<endl;

	int len = sizeof(arr) / sizeof(*arr);//��ȡ�����е�Ԫ�ظ���
	cout<<"len = "<<len<<endl;

	int count = 0;
	for(;len > 0;len--, count++)//��������������մ������ҵ�˳��������ֵ���涨������������ֵ˳�򣬳�����forѭ����
	{
		cout<<len<<" ";

		if(count == 3)
		{
			cout<<"\n"<<"count = "<<count<<"\n";
		}
	}
	cout<<endl;

	double slope = static_cast<double>(++len)/(++count);
	cout<<"slope = "<<slope<<"\n"<<endl;

	for(int k = 0, j = 5; k < j; k++, j--)
	{
		cout<<"k = "<<k<<", "<<"j = "<<j<<endl;
	}

    //C++�쳣�������
	int ii = 8, jj = 0;
	try
	{
		//try������������ĳ���
		if(jj != 0)
		{
			cout<<"ii / jj = "<<ii / jj;
		}
		else
		{
			throw runtime_error("jj is zero!!");//throw�׳��쳣
		}
	}
	catch(runtime_error err)//catch�����쳣
	{
		//�����쳣
		jj = 2;
		cout<<err.what()<<"\n"<<"ii * jj = "<<ii * jj;//err.what()����"jj is zero!!"������û�г�ʼֵ���쳣���ͣ�what���ص������ɱ���������
	}
	cout<<endl;

	for(int i = 0;i < 10;i++)
	{
		cout<<addNum()<<"\t";
	}
	cout<<endl;

	return 0;
}


int addNum()
{
	//ʹ�ùؼ���static����ľֲ�����count��ɾֲ���̬���󡣾ֲ���̬�����ڳ����ִ��·����һ�ξ�������
	//�������ʱ��ʼ��������ֱ��������ֹʱ�ű����٣��ڴ��ڼ伴ʹ�������ڵĺ�������ִ��Ҳ���������Ӱ��
	static int count = 0;
	return ++count;
}