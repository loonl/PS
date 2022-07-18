#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec;
	int n; int m; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m; vec.push_back(m);
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << "\n";
	}
	return 0;
}

