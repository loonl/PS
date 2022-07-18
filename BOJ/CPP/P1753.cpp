#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;
ll v, e;

void bfs(vector<vector<pair<ll, ll>>>& graph, vector<bool>& visited, ll& start, vector<ll>& nums)
{
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	nums[start] = 0;
	pq.emplace(make_pair(nums[start], start));

	while (!pq.empty())
	{
		ll cost = pq.top().first, cur = pq.top().second;
		pq.pop();

		// TODO
		for (int i = 0; i < graph[cur].size(); i++)
		{
			ll next = graph[cur][i].first, next$ = graph[cur][i].second;
			if (next$ + cost < nums[next])
			{
				nums[next] = next$ + cost;
				pq.emplace(make_pair(nums[next], next));
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> v >> e;
	vector<vector<pair<ll, ll>>> graph(v + 1, vector<pair<ll, ll>>());
	vector<ll> nums(v + 1, LLONG_MAX);
	vector<bool> visited(v + 1, false);
	ll start; cin >> start;
	ll t1, t2, t3;
	for (int i = 0; i < e; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1].emplace_back(make_pair(t2, t3));
	}

	bfs(graph, visited, start, nums);

	for (int i = 1; i <= v; i++)
	{
		if (i == start)
			cout << 0 << endl;
		else if (nums[i] == LLONG_MAX)
			cout << "INF" << endl;
		else
			cout << nums[i] << endl;
	}
	return 0;
}