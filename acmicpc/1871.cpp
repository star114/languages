#include <iostream>
#include <string>
using namespace std;

long long _abs(long long l)
{
	if (l < 0)
		return 0 - l;
	return l;
}
int convertTo(char c, char cbase)
{
	return c - cbase;
}

int main()
{
	int ncase;
	cin >> ncase;
	for (int i = 0 ; i < ncase ; i ++)
	{
		string strplate;
		cin >> strplate;
		string strdelimiter = "-";
		int ndel = strplate.find(strdelimiter);
		string strletters = strplate.substr(0, ndel);
		string strnumbers = strplate.substr(ndel+1);
		//cout << strplate << endl;

		int nlettervalue = 0;
		int nfactor = 1;
		for (int i = 1 ; i < strletters.size() ; i++)
			nfactor *= 26;
		for(char c : strletters)
		{
			nlettervalue += convertTo(c, 'A') * nfactor;
			nfactor /= 26;
		}
		int nnumbers = 0;
		int nfactor2 = 1;
		for (int i = 1; i < strnumbers.size() ; i++)
			nfactor2 *= 10;
		for (char c : strnumbers)
		{
			nnumbers += convertTo(c, '0') * nfactor2;
			nfactor2 /= 10;
		}
		if (_abs(nlettervalue - nnumbers) <= 100)
			cout << "nice" << endl;
		else
			cout << "not nice" << endl;
	}
	return 0;
}