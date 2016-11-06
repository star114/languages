#include <iostream>

int main()
{
	int nMinBurger = 2000, nMinDrinks = 2000;

	int nBurger, nDrinks;
	for (int i = 0 ; i < 3 ; i ++) 
	{
		std::cin >> nBurger;
		if (nMinBurger > nBurger)
			nMinBurger = nBurger;
	}
	for (int i = 0 ; i < 2 ; i++)
	{
		std::cin >> nDrinks;
		if (nMinDrinks > nDrinks)
			nMinDrinks = nDrinks;
	}

	std::cout << nMinDrinks + nMinBurger - 50<< std::endl;

}