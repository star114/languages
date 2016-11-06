#include <iostream>
#include <string>
using namespace std;

int GetNumericValue(char c)
{
	return (int)(c - '0');
}

bool IsUpper(char c)
{
	bool f = false;
	if ('A' <= c && c <='Z')
		f = true;
	return f;
}

bool IsLower(char c)
{
	bool f = false;
	if ('a' <= c && c <= 'z')
		f = true;
	return f;
}

bool IsLetter(char c)
{
	bool f = false;
	if (IsUpper(c) || IsLower(c))
		f = true;
	return f;
}
bool IsDigit(char c)
{
	bool f = false;
	if ('0' <= c && c <= '9')
		f = true;
	return f;
}

bool IsLetterOrDigit(char c)
{
	return (IsLetter(c) || IsDigit(c));
}

int ToInt32(char c, int nFromBase)
{
	int nValue = 0;
	if (IsDigit(c))
	{
		nValue = GetNumericValue(c);
	}
	else if (IsLetter(c))
	{
		nValue = IsUpper(c) ? (int)(c-'A') + 10 : (int)(c-'a') + 10;
	}
	else
		nValue = -1;
	return nValue;
}

int ToInt32(string& strValue, int nFromBase)
{
	int nValue = 0;
	for (string::iterator it = strValue.begin(); it != strValue.end() ; it++ )
	{
		char c = *it;
		if (IsLetterOrDigit(c))
		{
			int nTemp = ToInt32(c, nFromBase);

			if (-1 != nTemp)
			{
				nValue = nValue * nFromBase;
				nValue += nTemp;
			}
			else
			{
				nValue = -1;
				break;
			}
		}
		else 
		{
			nValue = -1;
			break;
		}
	}
	return nValue;
}

int main()
{
	string strX;
	cin >> strX;
	cout << ToInt32(strX, 16) << endl;
	return 0;
}
