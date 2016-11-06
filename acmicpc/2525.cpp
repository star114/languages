#include <iostream>
using namespace std;

int main()
{
	int nHours, nMiniutes, nNeed;
	cin >> nHours >> nMiniutes >> nNeed;
	nMiniutes += nNeed;
	nHours += (nMiniutes / 60);
	nMiniutes = nMiniutes % 60;
	nHours = nHours % 24;
	cout << nHours << " " << nMiniutes << endl;
	return 0;
}