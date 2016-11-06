#include <iostream>
int main()
{
	while (true)
	{
		int nM, nF;
		std::cin >> nM >> nF;
		if (0 == nM && 0 == nF)
			break;
		std::cout << nM+nF << std::endl;
	}
	
	return 0;
}