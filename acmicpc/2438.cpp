#include <iostream>

int main()
{
	int nN;
	std::cin >> nN;

	for (int i =1 ; i <= nN ; i++)
	{
		for (int j = 0 ; j < i ; j++)
			std::cout << '*';
		std::cout << std::endl;
	}
	return 0;
}