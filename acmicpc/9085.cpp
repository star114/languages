#include <iostream>
using namespace std;

int main()
{
	int ncase;
	cin >> ncase;
	for (int i = 0 ; i < ncase ; i ++)
	{
		int nnumbers;
		cin >> nnumbers;
		int nsum = 0;
		for (int j = 0 ; j < nnumbers ; j++)
		{
			int nvalue;
			cin >> nvalue;
			nsum += nvalue;
		}
		cout << nsum << endl;
	}
	return 0;
}