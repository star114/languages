#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> vna(n, 0);
	for(int &i : vna)
	{
		cin >> i;
	}

	int i, j , t;
	int change;
	for (i =0 ; i < n ; i++)
	{
		change = 0;
		for (j = 0; j < n-i-1; j++)
		{
			if (vna[j] > vna[j+1])
			{
				t = vna[j];
				vna[j] = vna[j+1];
				vna[j+1] = t;
				change = 1;
				//cout << i << endl;
			}
		}
		if (change == 0)
			break;
	}

	// for (int i : vna)
	// {
	// 	cout << i << endl;
	// }
	cout << i + 1 << endl;
	return 0;
}