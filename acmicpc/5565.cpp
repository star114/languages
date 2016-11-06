#include <iostream>

int main()
{
	int nTotal;
	int nData;
	std::cin >> nTotal;
	for (int i =0 ; i < 9 ; i++)
	{
		std::cin >> nData;
		nTotal -= nData;
	}
	std::cout << nTotal << std::endl;
	return 0;
}