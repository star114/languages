#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long find_pow_number(unsigned long long n, unsigned long long nBase)
{
	unsigned long long nPowNumber = nBase;
	unsigned long long nSum = 0;
	while (n >= nPowNumber)
	{
		nSum += (n/nPowNumber);
		nPowNumber *= nBase;
	}
	return nSum;
}

int main()
{
	unsigned long long nn, nm;
	cin >> nn >> nm;
	// nn ! / nm! (nn-nm)!
	// 

	unsigned long long nTwoNumbers = find_pow_number(nn, 2) - find_pow_number(nm, 2) - find_pow_number(nn-nm, 2);
	unsigned long long nFiveNumbers = find_pow_number(nn, 5) - find_pow_number(nm, 5) - find_pow_number(nn-nm, 5);

	unsigned long long nCount = min(nTwoNumbers, nFiveNumbers);

	cout << nCount << endl;
	
	return 0;
}