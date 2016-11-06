#include <iostream>
#include <string>
using namespace std;
int main()
{
	int nCount =0;
	for(int i = 0 ; i < 8 ; i++)
	{
		string strline;
		cin >> strline;
		int nstart = i % 2;
		for (int j = nstart ; j < 8 ; j += 2)
		{
			if (strline[j] == 'F')
				nCount++;
		}
	}
	cout << nCount << endl;
	return 0;
}