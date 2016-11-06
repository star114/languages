#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int _bsort(vector<int> vnvalue)
{
	int nret = 0;
	for (int i = 0 ; i < vnvalue.size() ; i++)
	{
		int nindex = i;
		for (int j = i+1; j < vnvalue.size() ; j++)
		{
			if (vnvalue[nindex] > vnvalue[j])
			{
				nindex = j;
			}
				
		}
		if (nindex != i)
		{
			nret += vnvalue[nindex] + vnvalue[i];

			int ntmp = vnvalue[i];
			vnvalue[i] = vnvalue[nindex];
			vnvalue[nindex] = ntmp;

			cout << vnvalue[i] << " " << vnvalue[nindex] << endl;
		}
			
	}
	return nret;
}

int main(){
	int nnumbers;
	cin >> nnumbers;
	vector<int> vnvalue(nnumbers, 0);

	for (int& i : vnvalue)
	{
		cin >> i;
	}

	cout << _bsort(vnvalue) << endl;

	reverse(vnvalue.begin(), vnvalue.end());
	cout << _bsort(vnvalue) << endl;
	return 0;
}