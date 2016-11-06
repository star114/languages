#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int nM, nF;
	std::cin >> nM >> nF;
	std::vector<int> vnMCharacter (nM, 0);
	std::vector<int> vnFCharacter (nF, 0);
	for (int i = 0 ; i < nM ; i ++)
		std::cin >> vnMCharacter[i];
	for (int j = 0 ; j < nF ; j ++)
		std::cin >> vnFCharacter[j];
	
	int nSum = 0;
	int nMin = 1000000;
	bool fSelected = false;
	std::vector<int> vnSelectedIndex (nF, 0);
	for (int i = 0 ; i < nM ; i ++ )
	{
		for (int j = 0 ; j < nF ; j++)
		{
			if (vnSelectedIndex[j] == 1)
				continue;
			
			int nSub = abs(vnMCharacter[i] - vnFCharacter[j]);
			if (nMin > nSub)
			{
				nMin = nSub;
				vnSelectedIndex[j] = 1;
			}
		}
		if (nMin != 1000000)
			nSum += nMin;
	}
	
	
	std::cout << nSum << std::endl;
	return 0;
}