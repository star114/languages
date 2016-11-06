#include <iostream>
#include <math.h>

int _FindDivisor(int N)
{
	bool fFind = false;
	int divisor;
	for (divisor = 2 ; divisor <= sqrt(N) ; divisor ++)
	{
		if (N % divisor == 0) 
		{
			fFind = true;
			break;	
		}
	}
		
	if (!fFind)
		divisor = 1;
	return divisor;
}

int main()
{
		
	int N, counter = 0;
	std::cin >> N;
	int divisor = _FindDivisor(N);
	
	counter = (divisor == 1) ? N-1 : (N - N / _FindDivisor(N));
	std::cout << counter << std::endl;
	
	return 0;
}