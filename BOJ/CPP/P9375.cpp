#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int t; cin >> t;
	int n; string name, kind;
	for (int i = 0; i < t; i++) {
		cin >> n;
		map<string, vector<string>> m;

		// insertion
		for (int j = 0; j < n; j++) {
			cin >> name >> kind;
			int check = m.count(kind);

			// if not in m
			if (check == 0) {
				vector<string> vec;
				vec.push_back(name);
				m[kind] = vec;
			}

			// if already in m
			else if (check == 1) {
				(m.find(kind))->second.push_back(name);
			}
		}

		// calculation
		int len = 1;
		for (auto it = m.begin(); it != m.end(); it++) {
			len *= it->second.size() + 1;
		}

		cout << len - 1 << "\n";
	}
	return 0;
}