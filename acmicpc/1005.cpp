#include <iostream>
#include <map>
#include <list>

class Builder
{
public:
	Builder();
	~Builder();

	void Clear();
	void Initialize();
	void FindResult();

	int GetTimes();
private:
	int _FindLine(int nBuildNum, int nSum);

	int m_nBuildings;
	int m_nRules;
	int m_nTimes;
	int m_nDestination;
	std::map<int, int> m_buildtime;
	std::map<int, std::list<int> > m_lstRules;
};

Builder::Builder()
{
	Clear();
}

Builder::~Builder()
{

}

void Builder::Clear()
{
	m_nBuildings = 0;
	m_nRules = 0;
	m_nTimes = -1;
	m_nDestination = 0;
	//m_buildtime.clear();
	//m_lstRules.clear();
}

void Builder::Initialize()
{
	std::cin >> m_nBuildings >> m_nRules;
	for (int i = 1 ; i <= m_nBuildings ; i ++)
	{
		std::cin >> m_buildtime[i];
	}
	int nX , nY;
	for (int i =0 ; i < m_nRules ; i++)
	{
		std::cin >> nX >> nY;
		m_lstRules[nY].push_back(nX);
	}
	std::cin >> m_nDestination;
}

int Builder::GetTimes()
{
	return m_nTimes;
}

void Builder::FindResult()
{
	m_nTimes = m_buildtime[m_nDestination];
	_FindLine(m_nDestination, m_nTimes);
}

int Builder::_FindLine(int nBuildNum, int nSum)
{
	for ( std::list<int>::iterator it = m_lstRules[nBuildNum].begin();
			it != m_lstRules[nBuildNum].end() ; ++it)
	{
		int nData = nSum+m_buildtime[*it];
		if (0 == _FindLine(*it , nData))
		{
			if (m_nTimes < nData)
				m_nTimes = nData;
		}
	}
		
	return m_lstRules[nBuildNum].size();
}

int main()
{
	int nCases, nBuildings, nRules, nTimes = 0, nX, nY, nW, nS = 1;
	std::cin >> nCases;

	for (int i = 0; i < nCases ; i++ )
	{
		Builder bd;
		bd.Initialize();
		bd.FindResult();
		std::cout << bd.GetTimes() << std::endl;
	}

	return 0;
}