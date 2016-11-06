#include <iostream>
using namespace std;
int main()
{
	int nValue;
	cin >> nValue;
	for (int i = 1; i <= nValue ; i ++)
	{
		for (int j = 0 ; j < nValue - i ; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2*(i-1)+1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = nValue - 1; i > 0 ; i --)
	{
		for (int j = 0 ; j < nValue - i ; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2*(i-1)+1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}