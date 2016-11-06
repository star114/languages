#include <iostream>
using namespace std;
int main()
{
	int nA, nB, nMultiple;
	cin >> nA >> nB;
	nMultiple = nA*nB;
	while (nB > 0)
	{
		cout << nA * (nB % 10) << endl;
		nB /= 10;
	}
	cout << nMultiple << endl;
	return 0;
}