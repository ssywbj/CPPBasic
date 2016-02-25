//#include<iostream>
#include "text.h"
void betweenTwoNumbers();
void sumUnlimitNumbers();
void countRepeatNumbers();
void referenceDemo();
void TypeConvert();
//using namespace std;
const int buf_size = 8;//����
typedef double dou;//���ͱ���
typedef double* doup;
//using udou = double*;

void display(int x, int y)//��ͷ�ļ��������ķ�������Դ�ļ���ʵ��
{
	cout<<"x = "<<x<<", y = "<<y<<endl;
}

int main()
{
	//betweenTwoNumbers();
	//sumUnlimitNumbers();
	//countRepeatNumbers();
	referenceDemo();
	//TypeConvert();
	//display(8, 9);
	return 0;
}

/*
 * �����������֮�������
 */
void betweenTwoNumbers(){
	cout<<"input two numbers"<<endl;

	int v1 = 0, v2 = 0;
	cin>>v1>>v2;
	cout<<"v1 = "<<v1<<", v2 = "<<v2<<endl;
	int v = (v1 <= v2) ? v1:v2;

	if(v1 <= v2){
		while(v < v2){		
			std::cout<<v<<" ";
			v++;
		}
	}else{
		while(v < v1){
			v++;
			cout<<v<<" ";
		}
	}
	cout<<endl;
}

/*
 * �������������������֮��
 */
void sumUnlimitNumbers(){
	int sum = 0, value = 0;
	//	value���ڱ��������ÿ������value�Ķ�ȡ������whileѭ������ɣ�һ������Ĳ�����������������Ч����ѭ������
	while(std::cin >> value){
		sum += value;
	}

	cout<<"sum is "<<sum<<endl;
}

/*
 * ͳ�������ظ����ֵĸ���
 */
void countRepeatNumbers(){
	int currVal = 0, val = 0;
	if(std::cin >> currVal){
		int cnt = 1;
		
		while(std::cin >> val){
			if(val == currVal){
				cnt++;
			}else{
				cout<<currVal<<" occurs "<<cnt<<" times "<<endl;
				currVal = val;
				cnt = 1;
			}
		}

		cout<<currVal<<" occurs "<<cnt<<" times "<<endl;
	}
}

void referenceDemo()
{
	int i, &ri = i;
	i = 5; ri = 10;//ͨ�������޸İ󶨶����ֵ
	cout<<i<<", "<<ri<<endl;
	//int m = 30;&ri = m;//���󣺲��ܽ��������°󶨵�����һ������

	int *p = &i;//����һ��ָ��int���͵�ָ��p��Ϊָ�븳ֵ��ʹָ��pָ�����i(ָ��p���i�ĵ�ַ)
	int *p2 = p;//����p2��ʼֵ��Ϊp��Ҳ���Ǳ���i�ĵ�ַ�����������ָ��ָ��ͬһ������
	cout<<"p = "<<p<<", p2 = "<<p2<<", *p2 = "<<*p2<<endl;//*p2���ɽ�ָ�������*�õ�ָ��p2��ָ�Ķ����������ָ�����ֵ
	*p = 45;// �޸�ָ����ָ�Ķ����ֵ
	cout<<"p = "<<p<<", *p = "<<*p<<", i = "<<i<<endl;// i��ֵΪ45
	*p2 = 17;
	cout<<"p2 = "<<p2<<", *p2 = "<<*p2<<", i = "<<i<<endl;// i��ֵΪ17

	int j = 15;
	p = &j;// �޸�ָ���ֵ��ʹָ��pָ�����j
	cout<<p<<", "<<*p<<", "<<i<<endl;// *p��ֵ��Ϊ����j��ֵ

	int v = 12;
	int *pv = &v;
	*pv = *pv * *pv;
	cout<<"pv = "<<pv<<", *pv = "<<*pv<<", v = "<<v<<endl;

    int **ppv = &pv;// ָ��Ҳ�Ƕ���ָ��ָ���ָ�룺ppvָ��ָ��pvָ��(ָ��ppv���ָ��pv�ĵ�ַ)
	cout<<"ppv = "<<ppv<<", *ppv = "<<*ppv<<", **ppv = "<<**ppv<<endl;// ָ���ָ�뼴������"*"��ָ�룬��Ҫ��ָ�����ٴν����ò��ܷ��ʵ���ԭʼ���Ǹ�����

	int t = 42;
	int *pp = 0;// �����ָ��pp
	cout<<pp<<endl;
	int *&rp = pp;// rp��һ����ָ��pp������
	rp = &t;// Ϊrp��ֵ����Ϊָ��pp��ֵ
	cout<<pp<<endl;
	*rp = 0;// �����ã�ʹt��ֵΪ0
	cout<<"t = "<<t<<endl;

	int errNumb = 0;
	int *const curErr= &errNumb ;//curErr��һֱָ��errNumb 
	cout<<"errNumb = "<<errNumb<<endl;
	*curErr = 12;//��ȷ��curErr��һ��ָ����ͨ������ָ��
	cout<<"errNumb = "<<errNumb<<endl;
	const double pi = 3.14;
	const double *const pip= &pi;//pip��һ��ָ��������ĳ���ָ��
	//*pip = 2.72;//����pip��һ��ָ������ָ�룬������ֵ���ܱ��޸�
	
	cout<<"buf_size = "<<::buf_size<<endl;

	dou d1 = 9.9;
	cout<<"d1 = "<<d1<<endl;
	doup pd1 = &d1;
	cout<<"pd1 = "<<pd1<<", *pd1 = "<<*pd1<<endl;
	//udou pd11 = &d1;
	//cout<<"pd11 = "<<pd11<<", *pd11 = "<<*pd11<<endl;

	auto autoi = 7 + 8;
	cout<<"autoi = "<<autoi<<endl;
	auto autoi2 = 7.89L + 8.99L;
	cout<<"autoi2 = "<<autoi2<<endl;
}

void TypeConvert()
{
	unsigned char c = -1;
	int i = c;
	cout<<"c = "<<i<<endl;

	bool flag = -2;//�ѷǲ������͵�����ֵ������������ʱ�������ʼֵΪ0����Ϊfalse������Ϊtrue
	cout<<"flag = "<<flag;//flag��ֵΪ1
	if(flag)//true
	{
		cout<<", true"<<endl;
	}
	else
	{
		cout<<", false"<<endl;
	}
	flag = 0;
	cout<<"flag = "<<flag;//flag��ֵΪ0
	if(flag)//false
	{
		cout<<", true"<<endl;
	}
	else
	{
		cout<<", false"<<endl;
	}
	flag = 3;//flag��ֵΪ1
	cout<<"flag = "<<flag;
	if(flag)//true
	{
		cout<<", true"<<endl;
	}
	else
	{
		cout<<", false"<<endl;
	}

	i = flag;//�Ѳ������͵�ֵ�����ǲ�������ʱ��falseΪ0��trueΪ1��
	cout<<"i = "<<i<<endl;//i��ֵΪ1
	flag = false;
	i = flag;
	cout<<"i = "<<i<<endl;//i��ֵΪ0

	//ʹ���޷������ͱ������10~0֮�������
	unsigned u = 11;//������޷������ͱ����ĳ�ʼֵҪ����������ֵ(����Ϊ10)��1
	while(u > 0)//Ҫʹ��whileѭ��
	{
		u--;
		cout<<u<<'\t';
	}
	cout<<endl;

	cout<<'\x4d'<<'\t'<<'\115'<<endl;
	cout<<'\114'<<'\t'<<'\115'<<'\t'<<"\11567"<<endl;
}

struct Sales{
	int book;
} item, item2;//�������ݽṹSales������������������(��Ҫ���������ӷֺ�)

struct Sales2{
};//��Ҫ���������ӷֺ�
Sales2 item3;//�������ݽṹ�Ͷ�����ı������ֿ���д













