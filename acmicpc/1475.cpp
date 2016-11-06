#include <iostream>

int main()
{
	int nData[10]; // 0 - 8 , 9는 6에 입력한다. 하나로 취급하므로.
	for (int i = 0 ; i < 10; i++)
		nData[i] = 0;
	int nN, nValue;
	std::cin >> nN;
	while (nN > 0)
	{
		nValue = nN % 10;
		nN = nN / 10;
		nData[nValue]++;
	}

	int nMax = 0;
	int nNum = 0;
	for (int i =0 ; i < 9 ; i++)
	{
		if (i == 6)
			nNum = ((nData[6]+nData[9])%2 == 0) ? (nData[6]+nData[9])/2 : (nData[6]+nData[9])/2+1;
		else
			nNum = nData[i];

		if (nMax < nNum)
			nMax = nNum;
	}

	std::cout << nMax << std::endl;
}