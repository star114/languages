#include <iostream>
using namespace std;
int main()
{
	int nRows, nCols, nMax = 0;


	for (int i = 1 ; i < 10 ; i++)
	{
		for (int j = 1 ; j < 10 ; j++)
		{
			int nValue;
			cin >> nValue;
			if (nMax < nValue)
			{
				nMax = nValue;
				nRows = i;
				nCols = j;
			}	
		}
	}
	cout << nMax << endl;
	cout << nRows << " " << nCols << endl;
	return 0;
}