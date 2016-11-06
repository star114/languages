#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int ncase;
	cin >> ncase;
	vector<int> vnresult(11, -1);
	vnresult[0] = 0;
	vnresult[1] = 1;
	vnresult[2] = 2;
	vnresult[3] = 4;
	for (int i = 4; i < 11 ; i++)
	{
		vnresult[i] = vnresult[i-1] + vnresult[i-2] + vnresult[i-3];
	}

	for (int i= 0; i < ncase ; i++)
	{
		int nvalue;
		cin >> nvalue;
		cout << vnresult[nvalue] << endl;

	}
	return 0;
}