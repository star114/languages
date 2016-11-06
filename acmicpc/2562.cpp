#include <iostream>
using namespace std;
int main()
{
	int nmax = 0;
	int nwhere = 0;
	for (int i = 1 ; i < 10 ; i++)
	{
		int nvalue;
		cin >> nvalue;
		if (nmax < nvalue)
		{
			nmax = nvalue;
			nwhere = i;
		}
	}
	cout << nmax << endl;
	cout << nwhere << endl;
	return 0;
}