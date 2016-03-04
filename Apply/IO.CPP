#include<iostream>
#include "IO.h"
#include <direct.h>

char* File::mBasePath = "D:\\CppFile\\";

void File::save(const char *absolutePath, const string &content)
{
	cout<<absolutePath<<endl;

	ofstream ofile;
	ofile.open(absolutePath, ios::app);//ios::app����׷�ӵķ�ʽ���ļ�
	if(ofile)
	{
		ofile<<content<<endl;
	}
	else
	{
		cout<<"open fail"<<endl;
	}
	ofile.close();
}

void File::save(const string &fileName, const string &content)
{
	//while(*m_path != '\0')//�ַ�������ֵ�Կ��ַ�'\0'��β
	//{
	//	cout<<*m_path;
	//	m_path++;
	//}

	int len = 0 ;
	char *pBasePath = mBasePath;
	int srtLen = strlen(pBasePath) + fileName.size();
	char *absolutePath = new char[srtLen + 1];//�ַ�����������ԣ���1��Ϊ��Ԥ����������һ��λ���������ַ���'\0'

	char *end = pBasePath + strlen(pBasePath);
	while(pBasePath < end)
	{
		absolutePath[len]= *pBasePath++;
		len++;
	}

	for(int i = 0; i < fileName.size(); i++)
	{
		absolutePath[len] = fileName[i];
		len++;
	}

	//����������һλ����'\0'��ʾ����Ľ�β�������������鷵�ص����ݲ���ȷ����Ϊ�������Ҳ��������������
	absolutePath[srtLen] = '\0';

	save(absolutePath, content);

	delete absolutePath;
	absolutePath = NULL;
}

void File::save(const string &folder, const string &fileName, const string &content)
{
	int len = 0 ;
	string fileSeparator("\\");
	int srtLen = strlen(mBasePath) + folder.size() + fileSeparator.size();
	char *absolutePath = new char[srtLen + 1];

	char *end = mBasePath + strlen(mBasePath);
	while(mBasePath < end)
	{
		absolutePath[len]= *mBasePath++;
		len++;
	}

	for(int m = 0; m < folder.size(); m++)
	{
		absolutePath[len] = folder[m];
		len++;
	}



	for(int i = 0; i < fileSeparator.size(); i++)
	{
		absolutePath[len] = fileSeparator[i];
		len++;
	}

	absolutePath[srtLen] = '\0';

	_mkdir(absolutePath);

	//for(int j = 0; j < fileName.size(); j++)
	//{
	//	absolutePath[len] = fileName[j];
	//	len++;
	//}

	//absolutePath[srtLen] = '\0';

	//save(absolutePath, content);

	delete absolutePath;
	absolutePath = NULL;
}

int main()
{
	//char *absolutePath = "D:\\CppFile\\CPP_LOG.txt";
	//File::save(absolutePath/*"D:\\CppFile\\CPP_LOG.txt"*/, "Ssy Love Wbj, forever!!\nSsy Love Wbj, forever!!");

	string fileName("Ssywbj.txt");
	//File::save(fileName, "Ssy Love Wbj, forever!!\n��ʱӱ!!");

	File::save("Auto", fileName, "Ssy Love Wbj, forever!!\n��ʱӱ!!");

	return 0;
}