#include <iostream>

int main()
{
	int nKing, nQueen, nLook, nBisop, nKnight, nPon;
	std::cin >> nKing >> nQueen >> nLook >> nBisop >> nKnight >> nPon;
	std::cout 	<< (1-nKing) << " "
				<< (1-nQueen) << " "
				<< (2-nLook) << " "
				<< (2-nBisop) << " " 
				<< (2-nKnight) << " " 
				<< (8-nPon) << std::endl;
	return 0;
}