#include <iostream>
using namespace std;
int main()
{
	int nYear;
	cin >> nYear;

	cout << ((((nYear % 4 == 0) && (nYear % 100 != 0)) || (nYear % 400 == 0)) ? 1 : 0) << endl;

	return 0;
}