#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;
vector<int> vec;

int average(int n) {
	int sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += (vec[i] * (i - 4000));
	}
	float ans = sum / (float) n;
	return round(ans);
}

int middle(int n) {
	if (n == 1) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] != 0) { return i - 4000; }
		}
	}
	int members = 0;
	for (int i = 0; i < vec.size(); i++) {
		members += vec[i];
		if (members > n / 2) { return i - 4000; }
	}
}

int common() {
	int common = 0; vector<int> temp;
	for (int i = 0; i < vec.size(); i++) {
		if (common < vec[i]) { common = vec[i]; temp.clear(); temp.push_back(i - 4000); }
		else if (common != 0 && common == vec[i]) { temp.push_back(i - 4000); }
	}
	int ans;
	if (temp.size() == 1) { ans = temp[0]; }
	else if (temp.size() > 1) { ans = temp[1]; }
	return ans;
}

int range() {
	int max = INT_MIN; int min = INT_MAX; int now;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != 0) {
			now = i - 4000;
			if (now > max) { max = now; }
			if (now < min) { min = now; }
		}
	}
	return max - min;
}

int main() {
	vec.assign(8001, 0); int n; cin >> n; int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp; vec[temp + 4000]++; 
	}
	cout << average(n) << endl;
	cout << middle(n) << endl;
	cout << common() << endl;
	cout << range() << endl;

	return 0;
}

