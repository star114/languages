#include <iostream>
using namespace std;
int main()
{
	int nN, nM;
	cin >> nN >> nM;
	int nMin = min(nN, nM);
	int nMax = max(nN, nM);
	cout << nMin * (nMax - 1) + (nMin - 1) << endl;
	return 0;
}