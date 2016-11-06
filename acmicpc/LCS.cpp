// The MIT License (MIT)

// Copyright (c) 2015-2015 Heesik Shin.

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

/* code */
/*
	Longest Common Sequence (LCS)

	pseudo code

	function LCSLength(X[1..m], Y[1..n])
    C = array(0..m, 0..n)
    for i := 0..m
       C[i,0] = 0
    for j := 0..n
       C[0,j] = 0
    for i := 1..m
        for j := 1..n
            if X[i] = Y[j]
                C[i,j] := C[i-1,j-1] + 1
            else
                C[i,j] := max(C[i,j-1], C[i-1,j])
    return C[m,n]

    function backtrack(C[0..m,0..n], X[1..m], Y[1..n], i, j)
    if i = 0 or j = 0
        return ""
    else if  X[i] = Y[j]
        return backtrack(C, X, Y, i-1, j-1) + X[i]
    else
        if C[i,j-1] > C[i-1,j]
            return backtrack(C, X, Y, i, j-1)
        else
            return backtrack(C, X, Y, i-1, j)
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

class Builder
{
public:
	Builder(int nCount);
	~Builder();
	void Initialize();

	int size();
	int operator[] (int nIndex);
	int back();
private:
	std::vector<int> m_vnData;
	int m_nCount;
};

Builder::Builder(int nCount)
{
	m_nCount = nCount;
	m_vnData.clear();
}
Builder::~Builder()
{
}
void Builder::Initialize()
{
	int nData;
	for (int i = 0 ; i < m_nCount ; i++)
	{
		std::cin >> nData;
		m_vnData.push_back(nData);
	}
}
int Builder::size()
{
	return m_nCount;
}

int Builder::operator[] (int nIndex)
{
	if (m_vnData.size() <= nIndex)
		throw;
	return m_vnData[nIndex];
}

int Builder::back()
{
	return m_vnData.back();
}

class LCS
{
public:
	LCS(int nN, int nM);
	~LCS();

	int Getdata(int nN, int nM);
	void Setdata(int nN, int nM, int nData);

	void print();
private:
	int* m_pLCSLength;
	int m_nN;
	int m_nM;
};

LCS::LCS(int nN, int nM)
{
	m_nN = nN;
	m_nM = nM;
	m_pLCSLength = (int*)malloc((m_nN) *(m_nM) * sizeof(int));
}
LCS::~LCS()
{
	if (m_pLCSLength != NULL)
		free(m_pLCSLength);
}

int LCS::Getdata(int nN, int nM)
{
	return m_pLCSLength[nN*m_nM + nM];
}
void LCS::Setdata(int nN, int nM, int nData)
{
	m_pLCSLength[nN*m_nM + nM] = nData;
}
void LCS::print()
{
	for (int i =0 ; i < m_nN ; i++)
	{
		for (int j = 0 ; j < m_nM; j++)
		{
			std::cout << Getdata(i, j);
		}
		std::cout << std::endl;
	}
}

std::string IntToString (int number)
{
	std::ostringstream convStream;
	
	convStream << number;
	
	return convStream.str ();
}

std::string backtrack(LCS& lcs, Builder& b1, Builder& b2, int i, int j, bool fFirst)
{
	//std::cout << i << ", " << j << std::endl;
	if (0 == i || 0 == j)
		return "";
	else if (b1[i-1] == b2[j-1])
		return backtrack(lcs, b1, b2, i-1, j-1, false) + IntToString(b1[i-1]) + (fFirst ? "" : " ");
	else
	{
		if (lcs.Getdata(i, j-1) > lcs.Getdata(i-1, j))
			return backtrack(lcs, b1, b2, i, j-1, fFirst);
		else
			return backtrack(lcs, b1, b2, i-1, j, fFirst);
	}
}

int main()
{
	// Input
	int nN, nM;
	std::cin >> nN;
	Builder b1(nN);
	b1.Initialize();
	std::cin >> nM;
	Builder b2(nM);
	b2.Initialize();

	LCS lcs(nN+1, nM+1);
	/*
	Calculate Dynamic Array.
	 */
	for (int i = 0 ; i < nN+1 ; i ++)
		lcs.Setdata(i,0,0);
	for (int j = 0 ; j < nM+1 ; j ++)
		lcs.Setdata(0,j,0);
	for (int i = 1 ; i < nN+1 ; i ++)
	{
		for (int j = 1 ; j < nM+1 ; j ++)
		{
			//std::cout << i << ", " << j <<std::endl;
			if (b1[i-1] == b2[j-1])
				lcs.Setdata(i,j,lcs.Getdata(i-1, j-1) + 1);
			else
				lcs.Setdata(i,j, std::max(lcs.Getdata(i-1,j) , lcs.Getdata(i,j-1)));
			//std::cout << lcs.Getdata(i,j) << std::endl;
		}
	}

	//lcs.print();

	// Output
	std::cout << lcs.Getdata(nN, nM) << std::endl;

	std::cout << backtrack(lcs, b1, b2, nN, nM, true) << std::endl;


	return 0;
}