#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct my_data {
	int m_ndata;
	int m_nplace;
};

bool mycompareless (my_data a,my_data b) { return (a.m_ndata<b.m_ndata);}
bool mycomparegreater (my_data a,my_data b) { return (a.m_ndata>b.m_ndata);}

int main()
{
	int nSize;
	
	cin >> nSize;
	vector<my_data> vec_nA(nSize);
	vector<my_data> vec_nB(nSize);

	for (int i = 0; i < nSize ; i++)
	{
		cin >> vec_nA[i].m_ndata;
		vec_nA[i].m_nplace = i;
	}
	for (int i = 0 ; i < nSize ; i++)
	{
		cin >> vec_nB[i].m_ndata;
		vec_nB[i].m_nplace = i;
	}

	sort(vec_nA.begin(), vec_nA.end(), mycompareless);
	sort(vec_nB.begin(), vec_nB.end(), mycomparegreater);

	int nSum = 0;
	for (int i = 0; i < nSize ; i ++)
	{
		nSum += vec_nA[i].m_ndata * vec_nB[i].m_ndata;
	}
	cout << nSum << endl;

	// vector<int> vec_output(nSize);
	// for (int i = 0 ; i < nSize; i ++)
	// {
	// 	vec_output[vec_nB[i].m_nplace] = vec_nA[i].m_ndata;
	// }

	// for (int i = 0; i < nSize ; i++)
	// 	cout << vec_output[i] << " ";

	// cout << endl;
	return 0;
}