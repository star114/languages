#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long long uN;
	cin >> uN;
	
	long long i = sqrt(uN)/2 -1;
	long long uSum = 0;
	while(i++ < uN)
	{
		uSum = i*(i+1)/2;
		if (uSum + i + 1 > uN && uN >= uSum) break;
	}
	cout << i << endl; 
}