#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int main()
{
	int nCases, nA, nB;
	cin >> nCases;
	for (int i = 0 ; i < nCases ; i++)
	{
		cin >> nA >> nB;
		cout << ((nA * nB) / (nA > nB ? gcd(nA, nB) : gcd(nB, nA))) << endl;
	}
	return 0;
}
