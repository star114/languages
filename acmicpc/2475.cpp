#include <iostream>

int main()
{
	int nData;
	int nSquareSum = 0;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> nData;
		nSquareSum += nData * nData;
	}

	std::cout << (nSquareSum % 10) << std::endl;
		
	return 0;
}