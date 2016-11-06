#include <iostream>
using namespace std;
int main()
{
	while (true)
	{
		int nA, nB; 
		cin >> nA >> nB;
		if (0 == nA && 0 == nB)
			break;
		else
		{
			if (nA > nB)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}