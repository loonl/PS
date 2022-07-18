#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;
ll answer = 0;

void prim(vector<vector<pair<ll, ll>>>& graph, vector<bool>& visited)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push(make_pair(0, 1));

	while (!pq.empty())
	{
		auto [cur$, cur] = pq.top();
		pq.pop();

		if (visited[cur])
			continue;
		visited[cur] = true;
		answer += cur$;

		for (int i = 0; i < graph[cur].size(); i++)
		{
			auto [nxt, nxt$] = graph[cur][i];
			if (!visited[nxt])
				pq.emplace(make_pair(nxt$, nxt));
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	int v, e; cin >> v >> e;
	vector<vector<pair<ll, ll>>> graph(v + 1, vector<pair<ll, ll>>());
	ll t1, t2, t3;
	for (int i = 0; i < e; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1].emplace_back(make_pair(t2, t3));
		graph[t2].emplace_back(make_pair(t1, t3));
	}
	vector<bool> visited(v + 1, false);
	prim(graph, visited);
	cout << answer << endl;
	return 0;
}