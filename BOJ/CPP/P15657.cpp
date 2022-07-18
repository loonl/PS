#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int> vec;
int n, m;

void BF(int idx, int nums, string& print)
{
	nums++;
	print += to_string(vec[idx]) + " ";
	if (nums == m)
	{
		cout << print << endl;
		print = print.substr(0, print.length() - to_string(vec[idx]).length() - 1);
		return;
	}

	for (int i = idx; i < n; i++)
	{
		BF(i, nums, print);
	}
	print = print.substr(0, print.length() - to_string(vec[idx]).length() - 1);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> n >> m;
	vec.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		string tmp = "";
		BF(i, 0, tmp);
	}
	return 0;
}