#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> s; string str; cin >> str;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		for (int j = 1; j <= len - i; j++) {
			s.insert(str.substr(i,j));
		}
	}

	cout << s.size() << endl;
	return 0;
}