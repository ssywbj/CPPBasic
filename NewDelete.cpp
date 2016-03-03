#include<iostream>

using namespace std;

class CStudent
{
public:
	CStudent()              { cout<<"Default constructor called."<<endl; }          // �޲����Ĺ��캯��
	CStudent(int nAge)      { m_nAge = nAge; cout<<"Constructor called."<<endl; }   // �������Ĺ��캯��
	~CStudent()             { cout<<"Destructor called."<<endl; }                               // ��������
	void GetAge(int age)    { m_nAge = age;cout<<"m_nAge = "<<m_nAge<<endl; }       // ��������������m_nAge

private:
	int m_nAge;        // ˽������
};

int main()
{
	/*
	��̬�ڴ���䣺new ������(��ֵ�б�)������������������һ���ڴ�ռ䣬���ڴ�ռ����ɡ�����������ʾ�����͵����ݣ�
	���ó�ֵ�б����г���ֵ��ʼ���������᷵��һ���ɡ�����������ʾ�����͵�ָ�룬�������ʧ���򷵻�NULL��*/
	CStudent *ptr = new CStudent; // ��̬��������û�и�����ֵ�б����Ե����޲����Ĺ��캯��

	 /*�ڴ��ͷţ�delete ָ�����������ɾ��������ͨ���������ֱ���ͷŶ�̬������ڴ档�����ɾ�����Ƕ�����ö���
	   ���������������á�����Ҫע��һ�£���new��̬������ڴ�ֻ����delete�ͷ�һ�Σ�����ͷŵڶ��λ���ִ���*/
	delete ptr; // ɾ�������Զ�������������

	ptr = new CStudent(16); // ��̬�������󣬸����˳�ֵ�����Ե��ô������Ĺ��캯��
	delete ptr;// ɾ�������Զ�������������

	CStudent *ptrArr = new CStudent[2]; // ��̬�����������飬Ϊÿ������Ԫ�ص����޲����Ĺ��캯��
	delete []ptrArr;                    // ɾ���������飬�Զ�Ϊÿ�����������������

	return 0;
}
