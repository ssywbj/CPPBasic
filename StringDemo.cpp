#include<vector>

#include "test.h"

int main()
{
	//baseDemo();
	//inputMultiStr();
	//getlineDemo();
	//strCharDemo();
	//cout<<"return string is "<<returnStrDemo()<<endl;
	//vectorBaseDemo();
	//iteratorBaseDemo();
	//searchDemo(5);
	//arrayDemo();

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

void arrayDemo(void)//Ϊ����C���Լ��ݣ�����ʹ�ùؼ���void��ʾ����û���β�
{
	int arr[10];
	int i = 1;
	//int arr2[i];���������е�ά�ȱ�����һ���������ʽ�Ҵ���0����������auto�ؼ��ֶ�������
	int arr2[] = {9,0,9};
	//int arr3[] = arr2;���󣺲�������������ݸ�ֵ����������
	int *ptrs[10];//ptrs�Ǻ���10���������͵�����
    //int &refs[10];���󣺲��������õ�����
	int (*parray)[10] = &arr;//parrayָ��һ������10������������
	int (&arrRef)[10] = arr;//arrRef����һ������10������������

	string nums[] = {"advbd", "agfagd", "fffaaa"};
	string *p = &nums[0];//ָ��num�ĵ�һ��Ԫ��
	cout<<"*p = "<<*p<<endl;
	string *str = nums;//ֱ��ָ�����������ȼ���ָ�������һ��Ԫ�أ�string *p = &nums[0];
	cout<<"*str = "<<*str<<endl;
	//auto ia2(nums);ia2��һ��ָ�룬ָ��nums�ĵ�һ��Ԫ�أ��ȼ���auto ia2(&nums[0])����һЩ���������Ĳ�������ָ��Ĳ���
	//��"decltype(nums) nums3 = {"a", "b", "c"};���ص���������Ԫ����ɵ��ַ������飬ע����"auto ia2(nums)"������

	const int len = 10;
	int array[len] = {45, 9, 12, 67, 34, 98, 6};
	int *end = &array[len];//��ȡָ���������һ��Ԫ�ص���һ��Ԫ�ص�ָ�룬ʵ�������Ԫ�ز������ڣ����ָ�������������β�������
	cout<<"*end = "<<*end<<endl;//int *beg = begin(array);int *end = end(array);C++11��׼
	for(int *begin = array;begin != end;++begin)
	{
		cout<<*begin<<" ";
	}
	cout<<endl;

	int arr4 = *(array +4);//��������ָ������Ľ���
	cout<<"*arr4 = "<<arr4<<endl;//���array[4]��ֵ
	arr4 = *array +4;
	cout<<"*arr4 = "<<arr4<<endl;//���(array[0] + 4)��ֵ

	int array2 = array[2];
	cout<<"*array2 = "<<array2<<endl;
	array2 = *(array+2);//array[2]�ȼ���*(array+2)���ںܶ�����£�ʹ�������������ʵ������ʹ��һ��ָ��������Ԫ�ص�ָ��
	cout<<"*array2 = "<<array2<<endl;
	int *array4 = (array +4);//�±���ָ�������
	array2 = array4[1];//�ȼ���*(array4 + 1);
	cout<<"*array2 = "<<array2<<endl;
	array2 = array4[-1];//�ȼ���*(array4 - 1);
	cout<<"*array2 = "<<array2<<endl;

	//�ִ���C++����Ӧ������ʹ��vector�͵�����������ʹ�����������ָ�룻Ӧ�þ���ʹ��string������ʹ��C���Ļ���������ַ���

	const int len3 = 4;
	int ia[3][len3] = {{1, 2, 3, 99}, {456, 190}, {89}};
	int (&row)[len3] = ia[1];//row��һ�������ĸ���������������ã����󶨵�ia�ĵڶ���
	for(int j = 0;j < len3;j++)
	{
		cout<<row[j]<<" ";
	}
	cout<<endl;
	int (*ppp)[len3] = ia;//ָ�����ĸ�����������
	for(int jj = 0;jj < len3;jj++)
	{
		cout<<*(ppp[jj])<<" ";
	}
	cout<<endl;
}

void iteratorBaseDemo()
{
	string addInfo = "na4e g7fg";
	if(addInfo.begin() != addInfo.end())//�жϷǿգ�����������صĵ�������һ����������β�������
	{
		char* ch = addInfo.begin();//��ȡָ���һ��Ԫ�ص�ָ��
		cout<<"*ch = "<<*ch<<endl;//��ָ��ȡֵ
		*ch = toupper(*ch);
		cout<<"*ch = "<<*ch<<endl;
		ch++;//ָʾ��������һ��Ԫ�أ�ch--��ָʾ��������һ��Ԫ��
		cout<<"*ch = "<<*ch<<endl;

		for(char *c = addInfo.begin();c != addInfo.end();c++)//����string�����е�Ԫ��
		{
			cout<<*c<<"  ";
		}
		cout<<endl;

		string *p_addInfo = &addInfo;
		if(!p_addInfo->empty())//�ȶ�p_addInfo�����ã��ٵ���empty�������ȼۣ�!(*p_addInfo).empty()
		{
			cout<<"================="<<endl;
		}
		else
		{
			cout<<"!!!!!!!!!!!!!!!!!"<<endl;
		}	
	}	
}

/*
 *���ֲ��ҹ���
 */
void searchDemo(int des)
{
	cout<<"5 / 2 = "<< (5 / 2)<<endl;
	cout<<"5 / 3 = "<< (5 / 3)<<endl;
	cout<<"5 / 4 = "<< (5 / 4)<<endl;

	vector<int> ints;//Ҫ��ɶ��ֲ��ҹ��ܣ�ints��Ԫ�ر����������
	for(int i = 0; i < 11;i++)
	{
		ints.push_back(i * 2 - 1);
	}

	if(ints.begin() != ints.end())
	{
		for(int *i = ints.begin(); i != ints.end();i++)
		{
			//ints.push_back(63);ע�⣺�ڵ������в��ܸı�vector����������Ϊ�κ�һ�ָı�vector���������Ĳ�������ʹ������ʧЧ
			cout<<*i<<"  ";
		}
		cout<<endl;

		int *beg = ints.begin();//��ȡָ���һ��Ԫ�صĵ�����(ָ��)
		int *end = ints.end();//��ȡָ�����һ��Ԫ�ص���һ��Ԫ�صĵ�����(Ҳ����Ϊβ�������(ָ��)����û��ʲô���壬���Ǹ���ǣ���ʾ�����Ѿ�������������е�����Ԫ��)
		int *mid = beg + (end - beg)/2;
		cout<<"*beg = "<< *beg <<", *mid = "<< *mid <<", *(end - 1) = "<< *(end - 1)<<endl;

		if(des > *(end - 1))//β���������1(ָ������һλ)����õ�ָ�����һ��Ԫ�ص�ָ��
		{
			cout<<"source is so big"<<endl;
			return;
		}
		else if(des == *(end - 1))
		{
			cout<<des <<" on last position"<<endl;
			return;
		}
		else if(des == *beg)
		{
			cout<<des <<" on first position"<<endl;
			return;
		}

		while(mid != end && *mid != des)
		{
			if(des < *mid)
			{
				end = mid;
			}
			else
			{
				beg = mid + 1;
			}

			mid = beg + (end - beg)/2;
			cout<<"*mid = "<< *mid <<endl;	
		}

		if(des == *mid)
		{
			cout<<des <<" in of list"<<endl;
		}
		else 
		{
			cout<<des <<" out of list"<<endl;
		}
	}
	
}

void vectorBaseDemo()
{
	//��ʼ��vector����ļ������ⷽ��
	//vector<T> v3(n, val);v3����n���ظ���Ԫ�أ�ÿ��Ԫ�ص�ֵ����val
	//vector<T> v4(n);v4����n���ظ���ִ����ֵ��ʼ���Ķ���
	//vector<T> v5{a, b, c, d};v5������ʼֵ������Ԫ�أ�ÿ��Ԫ�ر�������Ӧ�ĳ�ʼֵ
	//vector<T> v6 = {a, b, c, d};�ȼ���v5{a, b, c, d}
	string baseInfo = "info";
	string addInfo = "1a4eg7fg";
	int addInfoLen = 0;
	if(!addInfo.empty())
	{
		addInfoLen = addInfo.size();
	}
	vector<string> infos;
	for(int i = 0;i < 10;i++)//�����ڷ�Χforѭ������vector�������Ԫ��
	{
		if(i < addInfoLen)
		{
			infos.push_back(baseInfo + addInfo[i]);
		}
		else
		{
			infos.push_back(baseInfo);
		}	
	}

	if(!infos.empty())
	{
		auto len = infos.size();
		for(auto i = 0;i < len;i++)
		{
			cout<<infos[i]<<"  ";
		}
		cout<<endl;
	}
	
}

void strCharDemo()
{
	string s2(",Ff/a,C'''fad!!!!!!!");
	string upperStr;
	auto len = s2.size();
	int pnt = 0;

	//decltype(s2.size()) count = 0;decltype�ؼ��֣�C++11��׼
	//for(auto c:s2)//��Χfor��C++11��׼
	//{
	//}

	if(!s2.empty())//�����string����ʹ�����±꣬��Ҫȷ�����Ǹ�λ����ȷʵ��ֵ�����s2Ϊ�գ���s2[i]�Ľ������δ�����
	{	
		for(auto i = 0; i<len; i++)
		{
			//cout<<"s2["<<i<<"] = "<<s2[i]<<"  ";
			cout<<s2[i]<<"  ";
			if(ispunct(s2[i]))//�ж��Ƿ��Ǳ�����
			{
				pnt++;//ͳ�Ʊ����ŵĸ���
			}
			else
			{
				if(isalpha(s2[i]))//��ȡs2�е���ĸ
				{
					upperStr += toupper(s2[i]);//�����Сд����ת���ɴ�д������ԭ�����
				}	
			}
			
			//��s2����ĸȫ�����Сд��ĸ������Ǵ�д����ת����Сд������ԭ�����
			//char &ch = s2[i];ch = tolower(ch);//����һ���������ü���޸�ֵ
			s2[i] = tolower(s2[i]);//��������ֱ���޸�ֵ
		}
		cout<<endl;
		cout<<"pnt = "<<pnt<<", upperStr = "<<upperStr;
		cout<<endl;
		cout<<"s2 = "<<s2<<endl;
	}
}
void baseDemo()
{
	//Ҫʹ��string��׼���ͣ���#include<string>��ʹ�������ռ�std
	string s;//��ʼ����ʽ1��sΪ�մ�
	string s2("dfad  fad");//��ʼ����ʽ2��s2��ֱ�ӳ�ʼ��Ϊ"dfad  fad"
	string s3 = "dfadfad";//��ʼ����ʽ3��s3��������ʼ��Ϊ"dfadfad"
	string s4(10, 'c');//��ʼ����ʽ4��s4Ϊ10��c
	s2 = "s2";//�޸�s2��ֵ
	cout<<"s = "<<s<<endl;
	cout<<"s2 = "<<s2<<endl;
	cout<<"s3 = "<<s3<<endl;
	cout<<"s4 = "<<s4<<endl;

	cin >> s;//�Ӽ����������и�s��ֵ
	cout<<"s = "<<s<<endl;//�������"  dfadfa fffff   "(ע��ո�)����ֻ�����dfadfa��������ĵĽ������û���κοո��

	//size()���ص���һ��string::size_type���͵�ֵ��size_type��һ���޷������͵�ֵ�������㹻������κ�string����Ĵ�С
	//����ڱ��ʽ�������˴����������޷��������ͻ������벻����Ч������˻������������ò����á�
	cout<<"s.size() = "<<s.size()<<endl;//��ȡ�ַ�������size()
	//auto len = s.size();ͨ��auto��decltype���ƶϱ���len������

	if(s.empty())//�ж��ַ����Ƿ�Ϊ��
	{
		cout<<"s is null"<<endl;
	}
	else
	{
		cout<<"s isn't null"<<endl;
	}

	//�ַ����ȽϹ��򣺶�Ӧλ���ϵ��ַ���ASCII��ֵ����Ƚϣ���һ����һ�����ַ���ֵ�ĸ��Ƚϴ��Ǹ��ַ����ͱȽϴ�
	string str1 = "hello";
    string str2 = "hel";
	string str3 = "Hel";
	string str4 = "hil";
	string str5 = "Bil";
	string str6 = "hel";
	if(str1 == str2)//str1��str2���
	{
		cout<< "str1��str2���" <<endl;
	}
	else//����
	{
		cout<< "str1��str2����" <<endl;
	}
	cout<< (str6 == str2) <<endl;//��Ƚ��Ϊ1�����Ƚ��Ϊ0

	if(str1 > str2)
	{
		cout<< str1<<"����"<<str2 <<endl;
	}
	else//
	{
		cout<< str1<< "С��" <<str2<<endl;
	}
	if(str2 > str3)
	{
		cout<<str2<< "����"<<str3 <<endl;
	}
	else//
	{
		cout<<str2<< "С��" <<str3<<endl;
	}
	if(str1 > str4)
	{
		cout<<str1<< "����"<< str4<<endl;
	}
	else//
	{
		cout<<str1<< "С��" << str4<<endl;
	}
	if(str1 > str5)
	{
		cout<< str1<< "����"<< str5 <<endl;
	}
	else//
	{
		cout<< str1<< "С��" << str5<<endl;
	}

	string addStr = str5 + str6;//����string������ӣ��ȼ���string addStr = (str5 += str6);
	cout<< "addStr = " << addStr<<endl;

	//����ֵ����(�мǣ��ַ�������ֵ��string�ǲ�ͬ������)��string�������:ȷ�������(+)��������������������һ����string
	addStr = ", "  + addStr;
	cout<< "addStr = " << addStr<<endl;
	//addStr = ", "  + ";;;;;";//�޷���ӣ���Ϊ�����(+)������û��һ����string����
	//addStr = ", "  + ";;;;;" + addStr;//�����޷���ӣ���Ϊ�Ǵ����������㣬����һ�������(+)������û��һ����string����
	addStr = addStr + ", " + ";;;;;";// ��ȷ�����������������ԭ��(cin >> s1 >> s2)���ȼ���:string temp = addStr + ", ";addStr = temp + ";;;;;";
	cout<< "addStr = " << addStr<<endl;
}

void inputMultiStr()
{
	string s1, s2;
	cin >> s1 >> s2;//�Ӽ����������и�s1��s2��ֵ
	cout<< s1 << s2 <<endl;//�������"  dfadfa fffff   "(ע��ո�)����ֻ�����dfadfafffff��������ĵĽ������û���κοո��
}

void getlineDemo()
{
	string line;
	//getline(cin, line)�������з��Ż�ִ�н���(ע�⣺���з�Ҳ�ᱻ������)��������line���洢���з�
	while(getline(cin, line))//�������Ч(û�����ļ�������ǻ�Ƿ�����)���򲻶ϴ��������ж�ȡһ������
	{
		cout<< "line = " << line <<endl;
	}
}

string returnStrDemo()
{
	string content(" H o  ld! !  ");

	string str("abcd efg");
	for(char* it = str.begin(); it != str.end() && !isspace(*it); ++it)//�����ַ���ĩβ�������ո�ʱ����ѭ��
	{
		*it = toupper(*it);//���ַ����е�Ԫ��ת���ɴ�д��ĸ��
	}
	cout<<str<<endl;

	string returnStr;
	if(!content.empty())
	{
		auto len = content.size();
		for(auto i = 0;i < len; i++)
		{
			char &ch = content[i];
			if(!isspace(ch))
			{
				returnStr += ch;
			}

			/*if(isalpha(ch))
			{
				returnStr += ch;
			}*/
		}
	}
	return returnStr;
	//return "Hello World!!!";
}




