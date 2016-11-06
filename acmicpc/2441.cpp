#include <iostream>
using namespace std;
int main()
{
	int nValue;
	cin >> nValue;
	for (int i = 0; i < nValue ; i ++)
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