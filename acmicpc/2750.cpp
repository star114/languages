#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int nnumbers;
	cin >> nnumbers;

	vector<int> vndata(nnumbers, 0);
	for (int& i : vndata)
	{
		int nvalue;
		cin >> nvalue;
		i = nvalue;
	}

 	sort(vndata.begin(), vndata.end());

 	for (int i : vndata)
 	{
 		cout << i << endl;
 	}
	return 0;
}