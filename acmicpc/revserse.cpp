/*
	reverse
	input : 
		#1 - number
		#2 - digits
	output : reverse - by - digit number
 */
int reverse(int n, int ndigits)
{
	int nreverse = 0;

	int nfactor = 1;
	for (int j = 1; j < ndigits; j ++)
		nfactor *= 10;

	while (n != 0)
	{
		nreverse += (n % 10) * nfactor;
		n /= 10;
		nfactor /= 10;
	}
	return nreverse;
}

