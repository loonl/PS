#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<vector<int>> map;
vector<vector<int>> dp;
int r, c;
vector<int> rows = { -1, 1, 0, 0 };
vector<int> cols = { 0, 0, -1, 1 };

int dfs(int curR, int curC)
{
	if (curR == r - 1 && curC == c - 1)
	{
		return 1;
	}
	if (dp[curR][curC] != -1)
		return dp[curR][curC];

	if (dp[curR][curC] == -1)
	{
		dp[curR][curC] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nxtR = curR + rows[i], nxtC = curC + cols[i];
			if (!(nxtR < 0 || nxtR > r - 1 || nxtC < 0 || nxtC > c - 1))
			{
				if (map[curR][curC] > map[nxtR][nxtC] && map[nxtR][nxtC] != 0)
				{
					dp[curR][curC] += dfs(nxtR, nxtC);
				}
			}
		}
	}

	return dp[curR][curC];
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> r >> c;
	map.assign(r, vector<int>(c, 0));
	dp.assign(r, vector<int>(c, -1));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << dfs(0, 0) << endl;
	return 0;
}