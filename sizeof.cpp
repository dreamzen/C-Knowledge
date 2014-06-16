#include <iostream>
using namespace std;

/**
 * Key point: sizeof() is not a function or unary operator. We can treat
 * it as compile pretreatment, so the contents in () won't be compiled.
 * When we cal the size of union or struct, we should consider about
 * alignment, and when we use double, we'd better put it on top or bottom.
 * Note: the machine is 64bits.
 */

void getSizeOfByName(int a[])
{
	cout << sizeof(a) << endl;//		8, when array is passed as parameter, it turns into a pointer
}

void getSizeOfByPointer(int (*a)[10])//	pay attention to the way of declaration
{
	cout << sizeof(*a) << endl;//		40, a points to array int[10], so *a is array.
}

void getSizeOfByReference(int (&a)[10])
{
	cout << sizeof(a) << endl;//		40, a is a reference
}

int main()
{
/* sizeof() is compile pretreatment */
	int a = 0;
	cout << sizeof(a=3) << endl;// 		4, equal to sizeof(int), (a=3) won't be compiled
	cout << a << endl;// 				0

/* size of internal type */
	cout << sizeof(char) << endl;//		1
	cout << sizeof(short) << endl;// 	2
	cout << sizeof(int) << endl;// 		4, not 8 (maybe for compatibility?)
	cout << sizeof(long) << endl;//		8
	cout << sizeof(long long) << endl;//8
	cout << sizeof(float) << endl;//	4
	cout << sizeof(double) << endl;//	8
	cout << sizeof(char*) << endl;//	8, any pointer is 8 bytes
	cout << sizeof(string***) << endl;//8
	cout << sizeof(string) << endl;//	24
	string str = "hello";
	cout << sizeof(str) << endl;//		24, "string" is a class in C++, no matter what str contains, its size is the same. 24 is associated to machine and compiler	

/* size of array and passing parameter to function */
	int b[10] = {1, 2};
	int *c = b;
	int *d = new int(10);
	cout << sizeof(b) << endl;//		40, 4*10, b is an array
	cout << sizeof(c) << endl;//		8, c is a pointer
	cout << sizeof(d) << endl;//		8, d is a pointer
	getSizeOfByName(b);//				8
	getSizeOfByPointer(&b);//			40
	getSizeOfByReference(b);//			40

/* size of union ==> alignment */
	union u1
	{
		double a;
		int b;
	};
	cout << sizeof(u1) << endl;//		8, double is 8 bytes
	union u2
	{
		char a[13];
		int b;
	};
	cout << sizeof(u2) << endl;//		16, int is 4 bytes, 3*4 < 13 < 4*4
	union u3
	{
		char a[13];
		char b;
	};
	cout << sizeof(u3) << endl;//		13, char is 1 bytes, so 13 is OK

/* size of struct ==> alignment */
	struct s1
	{
		char a;//		-------a, the alignment of char is 1
		double b;//		bbbbbbbb, the alignment of double is 8
		int c;//		---dcccc, the alignment of int is 4
		char d;//				, we should know in pysical memory, it's 1 byte per row. We draw "abcd" here just for convenience.
	};
	cout << sizeof(s1) << endl;//		24, 8*3
	struct s2
	{
		char a;//		cccc--ba
		char b;//		dddddddd
		int c;//
		double d;//
	};
	cout << sizeof(s2) << endl;//		16, 8*2
	struct s3
	{
		s2 s;
		char e;
	};
	cout << sizeof(s3) << endl;//		24, because the alignment of s2 is 8

	return 0;
}
