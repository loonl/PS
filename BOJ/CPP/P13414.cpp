#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int k, l; cin >> k >> l;
	map<string, int> wait;

	string num;
	for (int i = 0; i < l; i++) {
		cin >> num;
		wait[num] = i;
	}

	vector<pair<int, string>> vec;
	for (auto it = wait.begin(); it != wait.end(); it++) {
		vec.push_back(make_pair(it->second, it->first));
	}
	
	sort(vec.begin(), vec.end());

	int finish = (vec.size() > k) ? k : vec.size();
	for (int i = 0; i < finish; i++) {
		cout << vec[i].second << "\n";
	}

	return 0;
}