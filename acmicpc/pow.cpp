#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int find_pow_number(int n, int nBase)
{
	int nPowNumber = 0;
	while (n >= nBase)
	{
		n /= nBase;
		nPowNumber++;
	}
	return nPowNumber;
}

int find_geometric_seq_sum(int r, int n)
{
	return ((1-pow(r, n)) / (1-r));
}

int main()
{
	int nn, nm;
	cin >> nn >> nm;
	// nn ! / nm! (nn-nm)!
	// 
	int nTwoPowNumbernn = find_pow_number(nn, 2);
	int nFivePowNumbernn = find_pow_number(nn, 5);
	int nTwoPowNumbermn = find_pow_number(nm, 2);
	int nFivePowNumbermn = find_pow_number(nm, 5);
	
	cout << nTwoPowNumbernn << " "<< find_geometric_seq_sum(2, nTwoPowNumbernn+1) << endl;
	cout << nFivePowNumbernn << " "<<  find_geometric_seq_sum(5, nFivePowNumbernn+1) << endl;
	cout << nTwoPowNumbermn << " "<< find_geometric_seq_sum(2, nTwoPowNumbermn+1) << endl;
	cout << nFivePowNumbermn << " "<<  find_geometric_seq_sum(5, nFivePowNumbermn+1) << endl;
	
	return 0;
}