#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int> vec;
int n, m;
bool isin(vector<int>& s, int num)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (num == s[i])
			return true;
	}
	return false;
}

void BF(int x, int nums, string print, vector<int> used)
{
	print += to_string(vec[x]) + " ";
	used.push_back(x);
	nums++;

	if (nums == m)
	{
		cout << print << endl;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!isin(used, i))
		{
			BF(i, nums, print, used);
		}
	}
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
		vector<int> temp; temp.clear();
		BF(i, 0, "", temp);
	}
	return 0;
}