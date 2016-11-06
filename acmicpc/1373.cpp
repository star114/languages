#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <sstream>
using namespace std;

int main()
{
	string strValue;
	cin >> strValue;
	int nValue = 0;
	int nCount = (strValue.size() % 3 == 0) ? 3 : strValue.size() % 3;
	for (string::iterator it = strValue.begin() ; it != strValue.end() ; ++it)
	{
		char c = *it;
		nValue += (atoi(&c) * pow(2, --nCount));
		
		if (nCount == 0)
		{
			cout << nValue;
			nCount = 3;
			nValue = 0;
		}
	}
	cout << endl;
}