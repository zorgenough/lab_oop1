#include "LongLong.h"

using namespace std;

int main()
{
	LongLong a(20, 1, 2);
	LongLong b(10, 1, 1);
	LongLong c;
	c = a + b;
	cout << a.toString() << " " << b.toString() << endl << c.toString() << endl;

	LongLong f;
	f = a * b;
	cout << f.toString() << endl;

	if (b > a)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}