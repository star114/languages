#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Convert(char c)
{
	return (int)(c - '0');
}

int main()
{
	int nT, nSmax;
	cin >> nT;

	for (int i =1 ; i <= nT ; i++)
	{
		cin >> nSmax;
		string strSmember;
		cin >> strSmember;
		vector<int> vnSmember(nSmax+1, 0);
		int nNeeds = 0;
		int nAudience = 0;
		for (int j = 0; j <= nSmax ; j++)
		{
			vnSmember[j] = Convert(strSmember[j]);
			if (nAudience < j && vnSmember[j] > 0)
			{
				nNeeds += (j - nAudience);
				nAudience += (j - nAudience);
			}
			nAudience += vnSmember[j];
		}
		cout << "Case #" << i << ": " << nNeeds << endl;
	}

	return 0;
}