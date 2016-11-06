#include <iostream>
using namespace std;
int main()
{
	int nValue;
	cin >> nValue;
	for (int i = 1; i <= nValue ; i ++)
	{
		for (int j = 0 ; j < i ; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = nValue - 1; i > 0 ; i --)
	{
		for (int j = 0 ; j < i ; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}