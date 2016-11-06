#include <iostream>
using namespace std;
int main()
{
	int nhours, nminutes, nseconds, ntimes;
	cin >> nhours >> nminutes >> nseconds >> ntimes;
	nseconds += ntimes;
	nminutes += nseconds / 60;
	nseconds = nseconds % 60;
	nhours += nminutes / 60;
	nminutes = nminutes % 60;
	nhours = nhours % 24;
	cout << nhours << " " << nminutes << " " << nseconds << endl;
	return 0;
}