#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
using namespace std;
int main()
{
	int nCase;
	cin >> nCase;
	double dMax = 0;
	double dValue = 0;
	vector<double> vdInputs(nCase, 0);
	for (int i = 0 ; i < nCase ; i ++)
		cin >> vdInputs[i];
	
	for (int i = 0; i < nCase; i++)
	{
		double dValue = vdInputs[i];
		if (dMax < dValue)
			dMax = dValue;
		for (int j = i+1 ; j < nCase; j++)
		{
			dValue *= vdInputs[j];
			if (dMax < dValue)
				dMax = dValue;
		}
	}
	
	// 출력 주의 a * e^20 이런식으로 출력될 수 있음. 
    printf("%.3lf\n", dMax);
	
	return 0;
}