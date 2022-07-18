#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> words;

bool custom_sort(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	return a.length() < b.length();
}

int main()
{
	int n; cin >> n; string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		bool AlreadyIn = false;
		for (int i = 0; i < words.size(); i++) {
			if (temp == words[i]) { AlreadyIn = true; break; }
		}
		if (!AlreadyIn) { words.push_back(temp); }
	}
	
	sort(words.begin(), words.end(), custom_sort);
	for (int i = 0; i < words.size(); i++) {
		cout << words[i] << "\n";
	}
	return 0;
}