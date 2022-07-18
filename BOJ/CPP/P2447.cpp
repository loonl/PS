#include <iostream>
#include <string>
using namespace std;

string star(int r, int c, int n) {
	if ((r / n) % 3 == 1 && (c / n) % 3 == 1) { return " "; }
	else {
		if (n / 3 == 0) {
			return "*";
		}
		else { return star(r, c, n / 3); }
	}
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star(i, j, n);
		}
		cout << "\n";
	}
	return 0;
}