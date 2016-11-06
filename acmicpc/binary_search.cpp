#include <iostream>
using namespace std;
int midpoint(int a, int b)
{
	return (a + b) >> 1;
}

#define KEY_NOT_FOUND -1;
int binary_search(int A[], int key, int imin, int imax)
{
  	// continue searching while [imin,imax] is not empty
	while (imax >= imin)
    {
      	// calculate the midpoint for roughly equal partition
    	int imid = midpoint(imin, imax);
      	if(A[imid] == key)
        	// key found at index imid
        	return imid; 
      	// determine which subarray to search
      	else if (A[imid] < key)
        	// change min index to search upper subarray
        	imin = imid + 1;
      	else         
        	// change max index to search lower subarray
        	imax = imid - 1;
    }

  	// key was not found
  	return KEY_NOT_FOUND;
}

int binary_search_equality(int A[], int key, int imin, int imax)
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
	int A[8] = {0, 1, 3, 4, 5, 5, 6, 7};
	cout << binary_search(A, 5, 0, 7) << endl;
	cout << binary_search_equality(A, 5, 0, 7) << endl;
	return 0;
}