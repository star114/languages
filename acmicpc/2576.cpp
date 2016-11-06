#include <iostream>
using namespace std;
int main()
{
	int nMin = 100, nSum = 0;
	for (int i =0 ; i < 7 ; i++)
	{
		int nValue;
		cin >> nValue;
		if (nValue % 2 == 1)
		{
			nSum += nValue;
			if (nMin > nValue)
				nMin = nValue;
		}
	}
	if (nSum == 0)
		cout << -1 << endl;
	else
	{
		cout << nSum << endl;
		cout << nMin << endl;
	}
	return 0;
}