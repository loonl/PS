#include <string>
#include <map>
#include <iostream>
using namespace std;

int main()
{
	map<string, int> m; int count = 0;
	string str;
	while (getline(cin, str)) {
		auto k = m.find(str);
		if (k == m.end())
			m[str] = 1;
		else
			k->second++;
		count++;
	}

	cout << fixed;
	cout.precision(4);

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << " " << (float)it->second / (float)count * 100.f << "\n";
	}
	return 0;
}