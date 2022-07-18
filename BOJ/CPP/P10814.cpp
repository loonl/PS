#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;
vector<tuple<int, string, int>> vec;

bool custom_sort(tuple<int, string, int> a, tuple<int, string, int> b) {
	if (get<0>(a) == get<0>(b)) {
		return get<2>(a) < get<2>(b);
	}
	return get<0>(a) < get<0>(b);
}

int main()
{
	int n; cin >> n; int a; string b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		vec.push_back(make_tuple(a, b, i));
	}

	sort(vec.begin(), vec.end(), custom_sort);
	for (int i = 0; i < vec.size(); i++) {
		cout << get<0>(vec[i]) << " " << get<1>(vec[i]) << "\n";
	}
	return 0;
}