#include <iostream>
#include <string>
using namespace std;
int main()
{
	string strinput;
	cin >> strinput;
	int nheight = 0;
	char cprev = ' ';
	for (char c : strinput)
	{
		if (cprev != c)
			nheight += 10;
		else if (cprev == c)
			nheight += 5;
		cprev = c;
	}
	cout << nheight << endl;

	return 0;
}