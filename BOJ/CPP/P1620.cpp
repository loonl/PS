#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	int n, m; cin >> n >> m;
	map<string, int> zukan;
	vector<string> zukan2;
	string poke;
	for (int i = 0; i < n; i++) {
		cin >> poke;
		zukan[poke] = i + 1;
		zukan2.push_back(poke);
	}

	for (int i = 0; i < m; i++) {
		cin >> poke;
		if (isdigit(poke[0])) {
			cout << zukan2[stoi(poke) - 1] << "\n";
		}
		else {
			cout << zukan.find(poke)->second << "\n";
		}
	}
	return 0;

}