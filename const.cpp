#include <iostream>
#include <vector>
using namespace std;

bool cmp(int a, int b)// normal function
{
	return a < b;
}

class Solution
{
public:
	string str;
	Solution(string ss)
	{
		str = ss;
	}
	const char& operator[](int index) const
	{
		cout << "const []" << endl;
		return str[index];
	}
	char& operator[](int index)
	{
		cout << "normal []" << endl;
		return const_cast<char&>(static_cast<const Solution&>(*this)[index]);// Call const operator[]
	}
	void func(vector<int> &v)
	{
		sort(v.begin(), v.end(), myCmp);// myCmp can be 1. normal non-member function; 2. static member function
	}
	static bool myCmp(int a, int b)// myCmp must be static
	{
		return a < b;
	}
};

int main()
{
	vector<int> v(3);
	v[0] = 2;
	v[1] = 1;
	v[2] = 3;
	Solution s("Hello world");
	cout << s[1] << endl;// Call normal operator[]
	return 0;
}
