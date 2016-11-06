#include <iostream>
#include <string>
using namespace std;

string bitwisereverse(const string& strinput)
{
	string strrev;
	for (char c : strinput)
	{
		if (c == '0')
			strrev.push_back('1');
		else if (c == '1')
			strrev.push_back('0');
		else
			strrev.push_back(c);
	}
	return strrev;
}

int main()
{
	int nTimes;
	cin >> nTimes;
	string strInput, strResult;
	cin >> strInput >> strResult;

	string strBitwiseReverseInput = bitwisereverse(strInput);
	//cout << strBitwiseReverseInput << endl;

	if (nTimes % 2 == 0)
	{
		if (strInput == strResult)
			cout << "Deletion succeeded" << endl;
		else
			cout << "Deletion failed" << endl;
	}
	else
	{
		if (strBitwiseReverseInput == strResult)
			cout << "Deletion succeeded" << endl;
		else
			cout << "Deletion failed" << endl;
	
	}

	return 0;
}