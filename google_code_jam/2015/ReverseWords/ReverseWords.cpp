#include <iostream>
#include <vector>
#include <string>

int main()
{
	using namespace std;
	int nCases;
	string strInput;
	vector<string> tokens;

	cin >> nCases;
	getline(cin, strInput);
	//cout << nCases << endl;
	for (int i =1 ; i <= nCases ; i ++)
	{
		tokens.clear();
		getline(cin , strInput);

/*
while (token != mystring)
으로 조건 잡으면, 마지막에 같은 token 이 두개 연속으로 나타나는 아래와 같은 입력에 대해 오류가 발생할 수 있다.
all foo a base the this would than write five class than with word bar foo this base a bar long than way than snow alpha way a too way set with chars this along the along class entry word than bar long base alpha would along only alpha like chars per this this
 */
		string token, mystring(strInput);

		int nindex = -1;
		do
		{
			nindex = mystring.find_first_of(" ");
			token = mystring.substr(0, nindex);
			mystring = mystring.substr(nindex + 1);
		  	tokens.push_back(token);
		} while(-1 != nindex);
		
		cout << "Case #" << i << ":";
		for (vector<string>::reverse_iterator it = tokens.rbegin(); it != tokens.rend() ; ++it)
		{
			//if (it != tokens.rbegin())
			//	cout << " ";
			cout << " " << *it;
		}
		cout << endl;
	}
	
	return 0;
}