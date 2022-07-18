#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
	int n; cin >> n;
	vector<long long> movie_title;

	// brute force
	for (long long i = 666; i < LLONG_MAX; i++) {
		if (movie_title.size() == n) { cout << i - 1 << endl; break; }
		long long num = i;
		while (true) {
			if (num % 1000 == 666) { movie_title.push_back(i); break; }
			num /= 10;
			if (num == 0) { break; }
		}
	}

	return 0;
}

