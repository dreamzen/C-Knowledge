#include <iostream>
using namespace std;

/**
 *
 * http://blog.csdn.net/haoel/article/details/1948051/
 *
 **/

typedef void(*Func)(void);

class Base
{
public:
    virtual void f()
    {
        cout << "Base::f()" << endl;
    }
    virtual void g()
    {
        cout << "Base::g()" << endl;
    }
private:
    virtual void p()
    {
        cout << "Base::p() private" << endl;
    }
    virtual void q()
    {
        cout << "Base::q() private" << endl;
    }
};

class Derived : public Base
{
public:
    virtual void f()
    {
        cout << "Derived::f()" << endl;
    }
    virtual void g1()
    {
        cout << "Derived::g1()" << endl;
    }
private:
    virtual void p1()
    {
        cout << "Derived::p1() private" << endl;
    }
    virtual void q1()
    {
        cout << "Derived::q1() private" << endl;
    }
};

int main()
{
    Base b;
    // f()--g()--p()--q()
    long *vptr = (long *)*(long *)(&b);//64-bit machine ==> long is 64 bits
    cout << "Base class, The address of virtual table is " << (long*)&b << endl;
    cout << "Base::f() is " << vptr << endl;
    Func func = (Func)vptr[0];
    func();
    cout << "Base::g() is " << vptr + 1 << endl;
    func = (Func)vptr[1];
    func();
    cout << "Base::p() is " << vptr + 2 << endl;
    func = (Func)vptr[2];
    func();
    cout << "Base::q() is " << vptr + 3 << endl;
    func = (Func)vptr[3];
    func();

    cout << "-----------------------" << endl;

    Derived d;
    //d::f()--b::g()--b::p()--b::q()--d::g1()--d::p1()--d::q1()
    vptr = (long *)*(long *)(&d);
    for(int i = 0; i <= 6; i++)
    {
        func = (Func)vptr[i];
        func();
    }
    return 0;
}
