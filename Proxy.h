#ifndef _PROXY_H
#define _PROXY_H

 ///@brief Abstract Base Class.
 class Subject 
 {
 public:
     Subject() {}
     virtual ~Subject() {}
     virtual void request() = 0;
};

///@brief Real entity class.
class RealSubject: public Subject 
{
public:
    RealSubject();
    virtual ~RealSubject();
    virtual void request();
};

///@brief Proxy class, including a pointer of pointing to the Real-entity class. 
class Proxy: public Subject 
{
public:
    Proxy();
    virtual ~Proxy();
    virtual void request();

private:
    Subject* m_realSubject;
};
#endif