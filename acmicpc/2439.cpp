#include <iostream>
using namespace std;
int main()
{
	int nValue;
	cin >> nValue;
	for (int i = nValue - 1; i >= 0 ; i --)
	{
		for (int j = 0 ; j < i ; j++)
		{
			cout << " ";
		}
		for (int j = i; j < nValue; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}