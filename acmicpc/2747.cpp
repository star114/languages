#include <iostream>
using namespace std;
#define MAX_VALUE 45
int anfibo[MAX_VALUE +1];
int fibo (int n)
{
	if (anfibo[n] == -1)
		anfibo[n] = fibo(n-1) + fibo(n-2);
	return anfibo[n];
}

int main()
{
	int nvalue;
	cin >> nvalue;

	anfibo[0] = 0;
	anfibo[1] = 1;
	for (int i= 2 ; i < MAX_VALUE +1 ; i++)
		anfibo[i] = -1;
	
	cout << fibo(nvalue) << endl;
	return 0;
}