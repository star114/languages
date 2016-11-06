#include <iostream>
using namespace std;
int main()
{
	int nCounts, nSum = 0;
	cin >> nCounts;
	for (int i =0 ; i < nCounts; i++)
	{
		int nValue;
		cin >> nValue;
		nSum += nValue;
	}
	cout << nSum - nCounts + 1 << endl;
	return 0;
}