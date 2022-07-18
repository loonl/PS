#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

bool custom_sort(long a, long b) {
	string str_a = to_string(a); string str_b = to_string(b);
	unsigned long long casea = stoull(str_a + str_b);
	unsigned long long caseb = stoull(str_b + str_a);
	return casea > caseb;
}

int main()
{
	int k, n; cin >> k >> n;
	vector<long> vec;
	vector<long> answers;

	string str; long max = LONG_MIN;
	for (int i = 0; i < k; i++) {
		cin >> str;
		int idx = str.length() - 1;
		long num = stol(str);
		vec.push_back(num);
		if (num > max) {
			max = num;
		}
	}

	for (auto it = vec.begin(); it != vec.end(); it++) {
		if (*it == max) {
			vec.erase(it);
			break;
		}
	}

	// 1 ~ n - (k-1) 번째 까진 max 값 선택해주기
	for (int i = 1; i <= n - k + 1; i++) {
		answers.push_back(max);
	}

	// 나머지 친구들 한번씩 넣어줘서 조건 만족시키기
	for (int i = 0; i < vec.size(); i++) {
		answers.push_back(vec[i]);
	}

	// custom sort
	sort(answers.begin(), answers.end(), custom_sort);

	for (int i = 0; i < answers.size(); i++) {
		cout << to_string(answers[i]);
	}

	return 0;
}