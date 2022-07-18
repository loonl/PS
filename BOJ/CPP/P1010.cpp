#include <iostream>
#include <vector>
#define int long long
#define endl '\n'
using namespace std;

int max(int a, int b)
{
	if (a < b) return b;
	return a;
}

signed main()
{
	cin.tie(0)->sync_with_stdio(false);
	int tc; cin >> tc;
	while (tc--)
	{
		int n, m; cin >> n >> m;
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

		for (int i = 1; i <= m - n + 1; i++)
		{
			dp[1][i] = 1;
		}

		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= m - n + i; j++)
			{
				for (int k = 1; k < j; k++)
				{
					dp[i][j] += dp[i - 1][k];
				}
			}
		}

		int hap = 0;
		for (int i = 1; i <= m; i++)
		{
			hap += dp[n][i];
		}
		cout << hap << endl;
	}
	return 0;
}