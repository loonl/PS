#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n; vector<vector<int>> info; vector<int> ranking;
	cin >> n; int weight, height;

	// input
	for (int i = 0; i < n; i++) {
		cin >> weight >> height;
		vector<int> vec = { weight , height };
		info.push_back(vec);
	}

	// brute-force
	for (int i = 0; i < n; i++) {
		int rank = 1;
		int now_weight = info[i][0]; int now_height = info[i][1];
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (now_weight < info[j][0] && now_height < info[j][1])
			rank++;
		}
		ranking.push_back(rank);
	}

	// print
	for (int i = 0; i < ranking.size(); i++) {
		cout << ranking[i] << " ";
	}

	return 0;
}

