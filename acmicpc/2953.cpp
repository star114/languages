#include <iostream>

int main()
{
	int nScores[5][5];
	for (int i = 0 ; i < 5; i++)
	{
		nScores[i][4] = 0;
	}

	int nMax =0, nWinner= 0;
	for (int i = 0 ; i < 5 ; i++)
	{
		for (int j = 0; j < 4 ; j++)
		{
			std::cin >> nScores[i][j];
			nScores[i][4] += nScores[i][j];
		}
		if (nMax < nScores[i][4])
		{
			nMax = nScores[i][4];
			nWinner = i+1;
		}
	}

	std::cout << nWinner << " " << nMax << std::endl;

	return 0;
}