#include <iostream>
using namespace std;
int main()
{
	int nMax = 0;
	int nNow = 0;
	for (int i= 0 ; i <4 ; i++)
	{
		int nout, nin;
		cin >> nout >> nin;
		nNow += nin;
		nNow -= nout;
		if(nMax < nNow)
			nMax = nNow;
	}
	cout << nMax << endl;
	return 0;
}