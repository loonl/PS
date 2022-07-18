#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<pair<string, bool>> checked;
bool check(string val) {
	for (auto it = checked.begin(); it != checked.end(); it++) {
		if (it->first == val) {
			return it->second;
		}
	}
	return false;
}

int find_(string val) {
	for (int i = 0; i < checked.size(); i++) {
		if (val == checked[i].first)
			return i;
	}
	return -1;
}

int main()
{
	int n; cin >> n;
	vector<string> in, out;
	string car;
	for (int i = 0; i < n; i++) {
		cin >> car;
		in.push_back(car);
		checked.push_back(make_pair(car, false));
	}

	for (int i = 0; i < n; i++) {
		cin >> car;
		out.push_back(car);
	}
	
	int count = 0;
	auto in_it = in.begin();
	auto out_it = out.begin();
	while (in_it != in.end() && out_it != out.end()) {
		if (!check(*in_it)) {
			// 똑같으면 두 iterator 모두 ++ & 나간 애들 true로
			if (*in_it == *out_it) {
				checked[find_(*out_it)].second = true;
				in_it++;
				out_it++;
			}

			// 다르다면 추월한 것이므로 count++ 후 out iterator만 ++ & 나간 애들 true로
			else if (*in_it != *out_it) {
				checked[find_(*out_it)].second = true;
				count++;
				out_it++;
			}
		}
		else {
			in_it++;
		}
	}

	cout << count << endl;
	return 0;
}