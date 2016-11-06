#include <iostream>

int a_nFib[41];
int fibonacci(int n)
{
	if (0 == n)
		return 0;
	else if (1 == n)
		return 1;
	else
	{
		if (-1 == a_nFib[n-1])
			a_nFib[n-1] = fibonacci(n-1);
		if (-1 == a_nFib[n-2])
			a_nFib[n-2] = fibonacci(n-2);
		return a_nFib[n-1] + a_nFib[n-2];
	}
		
}

int main()
{
	//Initialize
	a_nFib[0] = 0;
	a_nFib[1] = 1;
	for(int n = 2 ; n < 41; n ++)
		a_nFib[n] = -1;

	int nCases,N;
	std::cin >> nCases;
	for (int i =0; i < nCases; i++)
	{
		std::cin >> N;
		if (0 == N)
			std::cout << "1 0" << std::endl;
		else if (1 == N)
			std::cout << "0 1" << std::endl;
		else 
			std::cout << fibonacci(N-1) << " " << fibonacci(N) << std::endl;
	}
	return 0;
}