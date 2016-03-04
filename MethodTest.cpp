#include<iostream>
#include<string>

using namespace std;

void reset(int p);
void reset(int *p);
void reset2(int &p);
int findChar(const string &s, char c, int &count);
void printArr(const int arr[], int size);
void printArr(const int *begin, const int *end);
string returnStr();
const string &returnStr(const string &s1, const string &s2);
int* retArray(int &len);

int main()
{
	int i = 2, *p = &i;
	reset(i);
	cout<<"i = "<<i<<endl;//i��ֵ��δ�ı�

	reset(p);
	cout<<"i = "<<i<<endl;//ͨ��ָ��ı�i��ֵ
	reset(&i);
	cout<<"i = "<<i<<endl;//ͨ��ָ��ı�i��ֵ

	//ͨ�����øı�i��ֵ����C�У�����ʹ��ָ�����͵��βη��ʺ����ⲿ�Ķ���
	//��C++�У�����ʹ���������͵��β����ָ��
	reset2(i);
	cout<<"i = "<<i<<endl;

	//string s("abcdefge");
	//int count = 0;
	//int index = findChar("abcdefge", 'f', count);
	//cout<<"index = "<<index<<", "<<"count = "<<count<<endl;

	//int arr[] = {0, 7, 9, 9,0, 11, 987};
	//reset(arr);
	//cout<<"arr = "<<arr<<endl;

	//int len = sizeof(arr)/sizeof(*arr);
	//printArr(arr, len);
	//printArr(arr, &arr[len]);

	//cout<<returnStr()<<endl;
	//cout<<returnStr("Hello", "hi")<<endl;

    //��������ָ�������ָ��
	int len = 0;
    int *begin = retArray(len); 
	int *end = &begin[len];
	while(begin != end)
	{
		cout<<*begin++<<" ";// �������Ԫ��
	}
	cout<<endl;

	char *pCh = "dfkdafd";//���ַ���������ʼ���ַ�����ʱ�����Զ���ӱ�ʾ�ַ������Ŀ��ַ�
	cout<<pCh<<endl;//ֱ���������
	char *beginCh = pCh;
	char *endCh = beginCh + strlen(pCh);
	while(beginCh < endCh)
	{
		cout<<*beginCh++;
	}
	cout<<endl;

	char temp[5];
	int len2 = 0;
	while(len2 < 4)
	{
		temp[len2] = *pCh;
		len2++;
		pCh++;
	}
	temp[4] = '\0';//���һ��λ�ô��ڿ��ַ�'\0'���ڱ�ʶ����Ľ��������ⱨ���ַ������������
	cout<<temp<<endl;

	char temp2[] = {'a', 'b', 'c'};
	cout<<sizeof(temp2)/sizeof(*temp2)<<"::"<<temp2<<endl;//û�����'\0'�������ά��Ϊ3����������ȷ���abc����Ϊ�Ҳ�������Ľ�����(�ִ������������)
	char temp3[] = {'a', 'b', 'c', '\0'};
	cout<<sizeof(temp3)/sizeof(*temp3)<<"::"<<temp3<<endl;//��ʾ���������������'\0'�������ά��Ϊ4��������ȷ���abc

	return 0;
}

void reset(int p)
{
	p *= p;
}

void reset(int *p)
{
	*p *= *p;
}

//����������Ͷ��������������Ƚϵ�Ч�������е�������(����IO��������)�������Ͳ�֧�ֿ�����������ʱ����ֻ��ͨ�������βη��ʸ����͵Ķ���
void reset2(int &p)
{
	p *= p;
}

//�����������ı������βε�ֵ����ý�������Ϊ��������
int findChar(const string &s, char c, int &count)
{
	int ret = s.size();
	for(int i = 0;i < s.size();++i)
	{
		if(s[i] == c)
		{
			if(ret == s.size())
			{
				ret = i;
			}

			++count;
		}
	}

	if(ret == s.size())
	{
		ret = -1;
	}
	return ret;
}

void printArr(const int *begin, const int *end)
{
	//int len = sizeof(arr)/sizeof(*arr);�������޷������������ĳ��ȣ���Ϊ������ָ�����ʽ���ݸ�����������һ��ʼ��������֪�������ȷ�гߴ�
	while(begin != end)
	{
		cout<<*begin++<<" ";
	}
	cout<<endl;
}

void printArr(const int arr[], int size)//��Ϊ����ᱻת����ָ�룬���Ե����ǻắ������һ������ʱ��ʵ���ϴ��ݵ���ָ�������ָ��
{
	//int len = sizeof(arr)/sizeof(*arr);�������޷������������ĳ��ȣ���Ϊ������ָ�����ʽ���ݸ�����������һ��ʼ��������֪�������ȷ�гߴ�
	printArr(arr, &arr[size]);
}

string returnStr()
{
	return "Hello World!!!";//ֱ�ӷ��ؾֲ�����
}

//�������õĺ���(������ǰ����һ����&��)
inline const string &returnStr(const string &s1, const string &s2)
{
	//����ԭ���ڷ��ط������õĺ�������ܷ��ؾֲ���������û�ָ�룬��Ϊ����������ɺ�����ռ�Ĵ洢�ռ�Ҳ����֮�ͷ�
	//string ret;
	//return "Hello World!!!";
	return s1.size() >= s2.size() ? s1 : s2;
}
//ʹ�ùؼ���"inline"�����ĺ���Ϊ����������һ����˵���������������Ż���ģ��С������ֱ�ӡ�Ƶ�����õĺ�����
//�ܶ����������֧�������ݹ麯��������һ��75�еĺ���Ҳ��������ڵ��õ�������չ������������ͨ����ͷ�ļ��ж���

int* retArray(int &len)//C++�в��ܷ������飬�����Է��������ָ�������
{ 
	int *arr = new int[4];//��̬�����ڴ�
	arr[0] = 98;
	arr[1] = 334;
	arr[2] = 5;
	arr[3] = 67;

	len = 4;
	return arr;
}  