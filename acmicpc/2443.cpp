#include <iostream>
using namespace std;
int main()
{
	int nValue;
	cin >> nValue;
	for (int i = nValue; i > 0 ; i --)
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