#include <iostream>

int main()
{
	int nMax = 0;
	int nData[3];
	for (int i =0 ; i < 3; i++)
	{
		std::cin >> nData[i];
		if (nMax < nData[i])
			nMax = nData[i];
	}
	if (nData[0] == nData[1] && nData[1] == nData[2])
		std::cout << 10000+nData[0]*1000 << std::endl;
	else if (nData[0] == nData[1] || nData[1] == nData[2])
		std::cout << 1000+nData[1]*100 << std::endl;
	else if (nData[0] == nData[2])
		std::cout << 1000+nData[0]*100 << std::endl;
	else
		std::cout <<nMax*100 << std::endl;
	return 0;
}