#include <iostream>
using namespace std;
int main()
{
	int nValue, nSum = 0;
	for (int i=0 ; i < 5; i++)
	{
		cin >> nValue;
		if (nValue <= 40)
			nValue = 40;
		nSum += nValue;
	}
	cout << nSum /5 << endl;
	return 0;
}