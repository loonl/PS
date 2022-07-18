#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

vector<tuple<long, int, int>> vec;

vector<tuple<long, int, int>>::iterator find(long value) {
	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (get<0>(*it) == value)
			return it;
	}
	return vec.end();
}

bool custom_sort(tuple<long, int, int> a, tuple<long, int, int> b) {
	int numa = get<1>(a); int numb = get<1>(b);
	int idxa = get<2>(a); int idxb = get<2>(b);
	if (numa == numb)
		return idxa < idxb;
	return numa > numb;
}

int main()
{
	int n; long c;
	cin >> n >> c;

	long val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		auto found = find(val);

		// if found
		if (found != vec.end()) {
			get<1>(*found)++;
		}

		// if not found
		else if (found == vec.end()) {
			vec.push_back(make_tuple(val, 1, i));
		}
	}

	sort(vec.begin(), vec.end(), custom_sort);

	for (int i = 0; i < vec.size(); i++) {
		int repeat = get<1>(vec[i]);
		long value = get<0>(vec[i]);
		for (int j = 0; j < repeat; j++) {
			cout << value << " ";
		}
	}

	return 0;
}