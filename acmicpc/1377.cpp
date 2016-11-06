#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define KEY_NOT_FOUND -1;
int midpoint(int a, int b)
{
	return (a + b) >> 1;
}
int binary_search_equality(vector<int> A, int key, int imin, int imax)
{
  	// continually narrow search until just one element remains
  	while (imin < imax)
    {
     	int imid = midpoint(imin, imax);
 
      	// code must guarantee the interval is reduced at each iteration
      	//assert(imid < imax);
      	// note: 0 <= imin < imax implies imid will always be less than imax
 
      	// reduce the search
      	if (A[imid] < key)
        	imin = imid + 1;
      	else
        	imax = imid;
    }
  	// At exit of while:
  	//   if A[] is empty, then imax < imin
  	//   otherwise imax == imin
 
  	// deferred test for equality
  	if ((imax == imin) && (A[imin] == key))
    	return imin;
  	else
    	return KEY_NOT_FOUND;
}
int main()
{
	int n;
	cin >> n;
	vector<int> vna;
	vector<int> vna_sorted;
	for(int i = 0; i < n ; i++)
	{
		int value;
		cin >> value;
		vna.push_back(value);
		vna_sorted.push_back(value);
	}

	sort(vna_sorted.begin(), vna_sorted.end());


	int nIndex = -1;
	for (int i = 0  ; i < n; i++)
	{
		int nDiffIndex = binary_search_equality(vna_sorted, vna[i], 0, n-1);

		cout << "nDiffIndex : " << nDiffIndex << " i : " << i << endl;
		if (nDiffIndex - i > 0 && nIndex < i)
			nIndex = i;
	}

	cout << ((nIndex == -1) ? 1 : nIndex + 1) << endl;

	return 0;
}