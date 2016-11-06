#include <iostream>
using namespace std;
int main()
{
	int nValue;
	cin >> nValue;
	for (int i = 1; i <= nValue ; i ++)
	{
		for (int j = 1 ; j <= nValue ; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}