#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
typedef long long ll;
int dp[100001];
vector<bool> visited;
vector<vector<int>> graph;

void dfs(int node, int parent)
{
	visited[node] = true;
	for (auto next : graph[node])
	{
		if (!visited[next])
			dfs(next, node);
	}
	if (parent != -1)
	{
		dp[parent] += dp[node];
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int n, r, q; cin >> n >> r >> q;
	graph.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);
	int t1, t2;

	for (int i = 0; i <= n; i++)
		dp[i] = 1;

	for (int i = 1; i < n; i++)
	{
		cin >> t1 >> t2;
		graph[t1].push_back(t2);
		graph[t2].push_back(t1);
	}

	dfs(r, -1);
	int t3;
	while (q--)
	{
		cin >> t3;
		cout << dp[t3] << endl;
	}
	return 0;
}