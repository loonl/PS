#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <sstream>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	bool U = false, C1 = false, P = false, C2= false;
	string str;
	getline(cin, str);
	istringstream ss(str);
	vector<string> strs;
	string buffer;
	while (getline(ss, buffer, ' '))
	{
		strs.push_back(buffer);
	}

	for (string str : strs)
	{
		for (int i = 0; i < str.length(); i++)
		{
			char x = str[i];
			if (!U && x == 'U')
			{
				U = true;
				continue;
			}
			else if (!C1 && x == 'C' && U)
			{
				C1 = true;
				continue;
			}
			else if (!P && x == 'P' && C1)
			{
				P = true;
				continue;
			}
			else if (!C2 && x == 'C' && P)
			{
				C2 = true;
				if (U && C1 && P && C2)
					goto fin;
			}
		}
	}

fin:
	if (U && C1 && P && C2)
		cout << "I love UCPC" << endl;
	else
		cout << "I hate UCPC" << endl;
	return 0;
}