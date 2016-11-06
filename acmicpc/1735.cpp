#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0) return b;
	return gcd(b, a % b);
}
int main()
{
	int nA1, nA2, nB1, nB2;
	cin >> nA1 >> nA2 >> nB1 >> nB2;
	
	int nDivisior = nA2 * nB2;
	int nDividend = nA1 * nB2 + nB1 * nA2;
	int ngcd = nDividend > nDivisior ? gcd(nDividend, nDivisior): gcd(nDivisior, nDividend);
	cout << nDividend / ngcd << " " << nDivisior / ngcd << endl;
	
	return 0;
}
