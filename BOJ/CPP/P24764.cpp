#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;

bool notin(size_t index, vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (index == vec[i])
			return false;
	}
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	string ans; string str;
	int n, m; cin >> n >> m;
	vector<string> words(n);
	vector<string> results(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i] >> results[i];
	}
	
	vector<string> challengers(m);
	vector<string> ables;
	for (int i = 0; i < m; i++) {
		cin >> challengers[i];
	}
	bool ok;
	for (int x = 0; x < m; x++) {
		ans = challengers[x];
		ok = true;
		for (int y = 0; y < n; y++) {
			str = words[y];
			vector<int> done;

			string result = "-----";
			for (int i = 0; i < 5; i++) {
				if (str[i] == ans[i]) {
					result[i] = 'G';
					done.push_back(i);
				}
			}

			for (int i = 0; i < 5; i++) {
				char cut = result[i];
				if (cut == '-') {
					// check if y 
					string temp = ans;
					while (temp != "") {
						auto found = temp.find(str[i]);
						if (found != string::npos && result[found + (5 - temp.size())] != 'G' && notin(found, done)) {
							result[i] = 'Y';
							done.push_back(found);
							break;
						}
						if (found != string::npos) {
							temp = temp.substr(found + 1, temp.size() - found - 1);
						}
						else {
							temp = "";
						}
					}
				}
			}

			//cout << "debug : guess :  " << str << ", answer : " << ans << " result : " << result << endl;
			// check
			if (result != results[y]) {
				//cout << "aborting..." << endl;
				ok = false;
				break;
			}
		}
		if (ok)
			ables.emplace_back(ans);
	}

	// print
	for (int i = 0; i < ables.size(); i++) {
		cout << ables[i] << endl;
	}
	return 0;
}
