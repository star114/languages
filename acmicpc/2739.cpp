#include <iostream>
using namespace std;
int main()
{
	int nval;
	cin >> nval;
	for (int i = 1 ; i < 10 ; i++)
	{
		cout << nval << " * " << i << " = " << nval * i << endl;
	}
	return 0;
}