#include <iostream>

int main()
{
	int nCases, nX1, nX2, nY1, nY2, nR1, nR2, nR_A, nR_S, nLength , nReturn;
	std::cin >> nCases;
	for (int i = 0; i < nCases ; i++)
	{
		std::cin >> nX1 >> nY1 >> nR1 >> nX2 >> nY2 >> nR2;
		nR_A = (nR1 + nR2) * (nR1 + nR2);
		nR_S = (nR2 - nR1) * (nR2 - nR1);
		nLength = (nX2 - nX1) * (nX2 - nX1) + (nY2 - nY1) * (nY2 - nY1);

		if (nLength == 0)
		{
			if (nR1 == nR2)	
				nReturn = -1;
			else 
				nReturn = 0;
		}
		else 
		{
			if (nLength == nR_A)
				nReturn = 1;
			else if (nLength > nR_A)
				nReturn = 0;
			else if (nLength < nR_A)
			// 두 점 사이의 거리가 두 반지름의 합보다 작은 경우에 한해 두 반지름의 차를 계산할 수 있다.
			{
				if (nLength == nR_S)
					nReturn = 1;
				else if (nLength < nR_S)
					nReturn = 0;
				else if (nLength > nR_S)
					nReturn = 2;
			}
		}

		std::cout << nReturn << std::endl;
	}
	return 0;
}