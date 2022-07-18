#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	string temp;
	set<string> s;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.insert(temp);
	}

	int len = 0;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		auto found = s.find(temp);
		if (found != s.end()) {
			len++;
		}
	}

	cout << len << endl;
	return 0;
}