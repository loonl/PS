#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int N, M; cin >> N >> M;
	vector<int> days(M + 1, 0);
	vector<int> pages(M + 1, 0);
	vector<int> dp(N + 1, 0);
	for (int i = 1; i <= M; i++)
	{
		cin >> days[i] >> pages[i];
	}

	for (int i = 1; i <= M; i++)
	{
		for (int j = N; j >= 1; j--)
		{
			if (j - days[i] >= 0)
				dp[j] = max(dp[j], dp[j - days[i]] + pages[i]);
		}
	}

	cout << dp[N] << endl;
	return 0;
}