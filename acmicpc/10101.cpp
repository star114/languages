#include <iostream>

int main()
{
	int nA, nB, nC;
	std::cin >> nA >> nB >> nC;

	if (180 != nA + nB + nC)
		std::cout << "Error" << std::endl;
	else if(nA == nB && nB == nC)
		std::cout << "Equilateral" << std::endl;
	else if(nA == nB || nB == nC || nC == nA)
		std::cout << "Isosceles" << std::endl;
	else
		std::cout << "Scalene" << std::endl;

	return 0;
}