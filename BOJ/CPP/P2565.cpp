#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

bool custom_sort(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int max(int a, int b)
{
	if (a < b) return b;
	return a;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n; cin >> n;
	vector<pair<int, int>> graph(n + 1);
	vector<int> dp(n + 1, 1); // dp[a] : a번 전깃줄을 사용할 때

	// input 
	int a, b;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b;
		graph[i] = make_pair(a, b);
	}

	sort(graph.begin(), graph.end(), custom_sort);

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (dp[j] >= dp[i] and graph[j].second < graph[i].second)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	//// debug
	//for (int i = 1; i <= n; i++)
	//{
	//	cout << i << ": " << dp[i] << endl;
	//}

	int maxval = 0;
	for (int i = 1; i <= n; i++)
	{
		if (maxval < dp[i])
			maxval = dp[i];
	}

	cout << n - maxval << endl;
	return 0;
}