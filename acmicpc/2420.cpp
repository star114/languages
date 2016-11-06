#include <iostream>
using namespace std;
long long _abs(long long l)
{
	if (l < 0)
		return 0 - l;
	return l;
}
int main()
{
	long long la, lb;
	cin >> la >> lb;
	cout << _abs((long long)(la-lb)) << endl;
	return 0;
}