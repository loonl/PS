#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
	int dut, bo; cin >> dut >> bo;
	map<string, vector<string>> map;
	string input;
	vector<string> answer;
	for (int i = 0 ; i < dut; i++) {
		vector<string> temp; cin >> input;
		temp.push_back("dut");
		map[input] = temp;
	}

	for (int i = 0; i < bo; i++) {
		cin >> input;
		int count = map.count(input);
		if (count == 1) {
			map[input].push_back("bo");
		} else {
			vector<string> temp;
			temp.push_back("bo");
			map[input] = temp;
		}
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second.size() == 2) {
			answer.push_back(it->first);
		}
	}

	int size = answer.size();
	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << answer[i] << "\n";
	}
	
	return 0;
}