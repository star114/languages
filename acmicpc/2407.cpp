#include <iostream>
using namespace std;
int main()
{
	unsigned long long ulN, ulM;
	cin >> ulN >> ulM;

	// unsigned long long is not enough size.
	unsigned long long ulCombination = 1;
	unsigned long long uli = ulN;
	unsigned long long ulj = 2;
	while(ulj <= ulM)
	{
		//cout << "ulCombination: " << ulCombination << " ulj: " << ulj << " uli: " << uli << endl;
		if (ulCombination % ulj == 0)
		{
			ulCombination /= ulj++;
		}
		else
		{
			ulCombination *= uli--;
		}
	}
	for (unsigned long long ulindex = uli; uli > ulN-ulM; uli--)
		ulCombination *= uli;

	cout << ulCombination << endl;
	
	return 0;
}