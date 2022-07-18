#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> vec;


int main()
{
	vec.assign(10, 0);
	string a; cin >> a;
	for (int i = 0; i < a.length(); i++) {
		string cut = a.substr(i, 1);
		int intcut = stoi(cut);
		vec[intcut]++;
	}

	string output = "";
	for (int i = vec.size() - 1; i >= 0; i--) {
		for (int j = 0; j < vec[i]; j++) {
			output += to_string(i);
		}
	}

	cout << output << endl;
	return 0;
}