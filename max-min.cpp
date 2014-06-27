#include <iostream>
using namespace std;

int main()
{
	int MAX_INT = 0x7FFFFFFF;
	int MIN_INT = 0x80000000;
	cout << MAX_INT << endl;
	cout << MIN_INT << endl;
	cout << (MAX_INT + 1) << endl;//	MIN_INT
	cout << (MIN_INT - 1) << endl;//	MAX_INT
	cout << (-MIN_INT) << endl;//		MIN_INT ATTENTION!
	cout << (unsigned int)(-MIN_INT) << endl;//	abs(MIN_INT)
}
