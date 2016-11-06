#include <iostream>
using namespace std;

int main()
{
	for (int i = 0 ; i < 3 ; i++)
	{
		int nzeros = 0;
		for (int j = 0 ; j < 4 ; j++)
		{
			int nnum;
			cin >> nnum;
			if (0 == nnum)
				nzeros++;
		}
		switch (nzeros)
		{
			case 0 :
				cout << 'E' << endl;
			break;
			case 1 :
				cout << 'A' << endl;
			break;
			case 2 :
				cout << 'B' << endl;
			break;
			case 3 :
				cout << 'C' << endl;
			break;
			case 4 :
				cout << 'D' << endl;
			break;
			default:
				//Error
			break;
		}
		
	}
	return 0;
}