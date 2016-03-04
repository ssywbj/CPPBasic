#ifndef IO_H
#define IO_H

#include<string>
#include<fstream>

using namespace std;

class File
{
private:
	static char* mBasePath;

public:
	static void save(const char* absolutePath, const string &content);
	static void save(const string &fileName, const string &content);
	static void save(const string &folder, const string &fileName, const string &content);
};

#endif