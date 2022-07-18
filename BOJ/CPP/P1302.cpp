#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool custom_sort(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}

int main() {
	int n; cin >> n; string sold;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		cin >> sold;
		auto it = m.find(sold);
		if (it != m.end()) { it->second++; }
		else { m[sold] = 1; }
	}

	vector<pair<string, int>> vec(m.begin(), m.end());
	sort(vec.begin(), vec.end(), custom_sort);
	
	cout << vec[0].first << endl;
	return 0;
}