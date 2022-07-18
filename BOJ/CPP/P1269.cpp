#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	set<long> set_a;
	int len = 0;
	long temp;
	for (int i = 0; i < a; i++) {
		cin >> temp;
		set_a.insert(temp);
		len++;
	}

	for (int i = 0; i < b; i++) {
		cin >> temp;
		auto found = set_a.find(temp);
		if (found == set_a.end())
			len++;
		else if (found != set_a.end())
			len--;
	}

	cout << len << endl;
	return 0;
}