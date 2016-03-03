#include "Proxy.h"
#include <iostream>

using namespace std;

RealSubject::RealSubject()
{
    cout << "RealSubject constructor" << endl;
}

RealSubject::~RealSubject()
{
   cout << "RealSubject destructor" << endl;
}

///@brief Real-entity's request method.
void RealSubject::request()
{
    cout << "RealSubject request" << endl;
}

Proxy::Proxy(): m_realSubject(NULL)
{
    cout << "Proxy constructor" << endl;
}

Proxy::~Proxy()
{
    cout << "Proxy destructor" << endl;
    delete m_realSubject;
    m_realSubject = NULL;
}

///@brief Proxy's request method.
void Proxy::request()
{
    cout << "Proxy request" << endl;

    ///@brief Construct it when necessary.
    if (!m_realSubject) {
        m_realSubject = new RealSubject();
    }

    m_realSubject->request();
}

int main()
{
   Subject* proxy = new Proxy();    
   proxy->request();

   delete proxy;
   proxy = NULL;

   return 0;
}