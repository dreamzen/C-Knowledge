#include <iostream>
#include <vector>
using namespace std;

/**
 * Key point: x.size() return an unsigned value.
 *            x.length()
 * 			  ...
 */

int main()
{
	vector<int> vec(1, 0);
	string str = "1";
	char chr[2] = "1";//including '\0' at the end
	cout << vec.size() << endl;// 1 
	cout << vec.size() - 2 << endl;// 184467440..(64-bits), NOT "-1" 
	cout << str.length() << endl;// 1
	cout << str.length() - 2 << endl;// 184467440..
	cout << strlen(chr) << endl;// 1
	cout << strlen(chr) - 2 << endl;// 184467440.. 
	cout << sizeof(chr) << endl;// 2
	cout << sizeof(chr) - 3 << endl;// 184467440..

	cout << sizeof(str) << endl;// no matter what str contains, sizeof(str) is always 24(according to compiler)

	// So, never do this!
	int i = 1;
	while(i < vec.size() - 1)
	{
		i++;
		// Forever if vec.empty()!
	}
	// Instead
	int j = 1;
	while(j + 1 < vec.size())
	{
		j++;
		// This is all right
	}
	return 0;
}
