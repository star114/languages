#include <iostream>
using namespace std;
int main()
{
	int ncase;
	cin >> ncase;
	for (int i = 0 ; i < ncase ; i++)
	{
		int nA, nB;
		cin >> nA >> nB;
		int nTmp = 1;
		int nMultiple = nA % 10;
		for (int j = 0 ; j < nB ; j++)
			nTmp = (nTmp * nMultiple) % 10;
		
		if (nTmp == 0)
			cout << 10 << endl;
		else
			cout << nTmp << endl;
	}
	return 0;
}