#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n; cin >> n;
	vector<int> vec(n + 1, 0);
	vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = true;
	}
	for (int i = 2; i <= n; i++)
	{
		if (vec[i - 1] == vec[i])
			dp[i - 1][i] = true;
	}

	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (vec[j] == vec[j - i] && dp[j - i + 1][j - 1])
				dp[j - i][j] = true;
			else
				dp[j - i][j] = false;
		}
	}

	int q; cin >> q; int t1, t2;
	while (q--)
	{
		cin >> t1 >> t2;
		if (dp[t1][t2])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}