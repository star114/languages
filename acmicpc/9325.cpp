#include <iostream>
using namespace std;
int main()
{
	int nCases;
	cin >> nCases; 

	for (int i =0 ; i < nCases ; i++)
	{
		int nPrices;
		cin >> nPrices;
		int nOptions;
		cin >> nOptions;
		for (int j =0 ; j < nOptions ; j++)
		{
			int nCounts, nOptionValue;
			cin >> nCounts >> nOptionValue;
			nPrices += nCounts*nOptionValue;
		}
		cout << nPrices << endl;
	}

	return 0;
}