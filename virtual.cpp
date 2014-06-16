#include <iostream>
using namespace std;

/**
 * Key point: We can't call pure virtual function in construction or destruction, even if it's implemented.
 * We can call normal virtual function in construction and destruction, but we'd better not!
 * We can call pure and normal virtual function in member function of base and derived class.
 * But remember to implement pure virtual function if we call it in base class.
 */
class A
{
public:
	void g()// g is not virtual
	{
		cout << "A" << endl;
		virF();
	}
	A()
	{
//		virF();// Error!
		virG();// OK, but we'd better not. Item 09.
	}
	~A()
	{
//		virF();// Error!
	}
	virtual void virF() = 0;// pure virtual function
	virtual void virG()// normal virtual function
	{
		cout << "virG from A" << endl;
	}
};
void A::virF()// Even it's implemented
{
	cout << "virF from A" << endl;
}

class B: public A
{
public:
	void g()
	{
		cout << "B" << endl;
		virF();
	}
	virtual void virF()// We must implement pure virtual function in derived class, or B will be an abstract class!
	{
		A::virF();// We can call pure virtual function of base class.
		cout << "virF from B" << endl;
	}
};

int main()
{
	B b;
	b.virF();// first call A::virF(), then B::virF();
	
	A *a = &b;
	a->virF();// the same as above

	a->g();// g() is not virtual, so a->g() will call A::g(), then virF will be B::virF();
	return 0;
}
