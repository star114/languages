#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main()
{
	int na, nb;
	cin >> na >> nb;
	int ngcd = gcd(na, nb);
	cout << ngcd << endl;
	cout << na * nb / ngcd << endl;
	return 0;
}