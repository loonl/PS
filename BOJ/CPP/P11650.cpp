#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int>> vec;

bool custom_sort(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

int main()
{
	int n; cin >> n; int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end(), custom_sort);
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i].first << " " << vec[i].second << "\n";
	}
	return 0;
}