#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vndata(3, 0);
	for (int i = 0 ; i < 3 ; i++)
	{
		cin >> vndata[i];
 	}
 	sort(vndata.begin(), vndata.end());
 	for (int i = 0 ; i < 3; i ++)
 	{
 		cout << vndata[i];
 		if (i != 2)
 			cout << " ";
 	}
 	cout << endl;
	return 0;
}