#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <sstream>
using namespace std;

vector<string>::iterator in(vector<string>& vec, string what) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == what) {
			return vec.begin() + i;
		}
	}
	return vec.end();
}

int main()
{
	cin.tie(0);
	int t; cin >> t;
	cin.ignore();

	for (int i = 0; i < t; i++) {
		set<string> growls;
		vector<string> heard;
		while (true) {
			string str;
			getline(cin, str);

			if (str == "what does the fox say?")
				break;

			int idx = str.find("goes");
			// xxxx goes xxxx
			if (idx != -1) {
				idx = idx + ((string)"goes ").length();
				string sound = str.substr(idx, str.length() - idx);
				growls.insert(sound);
			}
			// toot ow ow toot 
			else if (idx == -1) {
				// split and insert sounds into vector
				istringstream ss(str);
				string token;
				while (getline(ss, token, ' ')) {
					heard.push_back(token);
				}
			}
		}

		vector<string> ans(heard);

		// 들은 것들 중에 정의된 울음소리 제거
		for (int j = 0; j < heard.size(); j++) {
			string single = heard[j];
			auto find = growls.find(single);
			if (find != growls.end()) { ans.erase(in(ans, single)); }
		}

		// 여우 울음소리 출력
		for (int j = 0; j < ans.size(); j++) {
			cout << ans[j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}