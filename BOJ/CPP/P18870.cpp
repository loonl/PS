#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool custom_sort(pair<long, int> a, pair<long, int> b) {
	return a.first < b.first;
}

int main() {
	vector<pair<long, int>> vec;  // first = 값, second = 원래 index
	int n; cin >> n; long temp;
	vector<int> ans; ans.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		vec.push_back(make_pair(temp, i));
	}

	sort(vec.begin(), vec.end(), custom_sort);
	
	int count = 0; // 해당 원소보다 작은 숫자의 개수를 기록해주기 위한 변수
	for (int i = 1; i < vec.size(); i++) {
		int now = vec[i].first;
		if (now != vec[i-1].first) // 뒤에 거와 같다면 count는 + 해주지 않아야 한다.
			count++;
		ans[vec[i].second] = count;
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
