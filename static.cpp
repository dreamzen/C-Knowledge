#include <iostream>
using namespace std;

/**
 * Key point: Only const static data member can be initialized in line.
 * Static data member must be defined before being used, or there will be an LD Error.
 * Sizeof() will ignore static data member.
 * As with empty struct or class, sizeof() = 1.
 * Note: the machine is 64bits.
 */
class MyClass
{
public:
	char c;
	static int s1;// Declaration. The compiler must see its definition before using it.
	static const int s2 = 2;// ONLY const static data member can do this!
	//int ab = 1;//Error or Warning!
	//static int s1 = 1; //Error!
	MyClass(int a)
	{
		s1 = a;// If there is no definition, it will get an LD Error.
	}
	static void print()
	{
		cout << s1 << " " << s2 << endl;
	}
	virtual void v1()
	{
	}
	virtual void v2()
	{
	}
	virtual void v3()
	{
	}
};

struct s1
{
};

int MyClass::s1;// Definition. We can also give it a value(=1).

int main()
{
	MyClass mc(10);
	mc.print();
	cout << sizeof(MyClass) << endl;//	16, a char(1) and a pointer to virtual function table(8), alignment ==> 8 * 2 = 16
	cout << sizeof(s1) << endl;//		1, empty struct or class, size is 1
	return 0;
}
