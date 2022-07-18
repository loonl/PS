#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <tuple>
#define endl '\n'
using namespace std;
typedef long long ll;
ll v, e;
ll f1, f2;

ll min(ll a, ll b, ll c)
{
	return min(a, min(b, c));
}

void bfs(vector<vector<pair<ll, ll>>>& graph, ll start, vector<vector<ll>>& nums)
{
	priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
	pq.emplace(make_tuple(nums[start][0], start, 0));

	while (!pq.empty())
	{
		auto [cost, cur, stat] = pq.top();
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			ll next = graph[cur][i].first, next$ = graph[cur][i].second, next_stat = stat;
			if (next_stat == 0 && next == f1)
				next_stat = 1;
			else if (next_stat == 0 && next == f2)
				next_stat = 2;
			else if (next_stat == 1 && next == f2)
				next_stat = 3;
			else if (next_stat == 2 && next == f1)
				next_stat = 3;

			if (next$ + cost < nums[next][next_stat])
			{
				nums[next][next_stat] = next$ + cost;
				pq.emplace(make_tuple(nums[next][next_stat], next, next_stat));
			}
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	cin >> v >> e;
	vector<vector<pair<ll, ll>>> graph(v + 1, vector<pair<ll, ll>>());
	vector<vector<ll>> nums(v + 1, vector<ll>(4, LLONG_MAX));
	nums[1][0] = 0, nums[1][1] = 0, nums[1][2] = 0, nums[1][3] = 0;
	ll t1, t2, t3;
	for (int i = 0; i < e; i++)
	{
		cin >> t1 >> t2 >> t3;
		graph[t1].emplace_back(make_pair(t2, t3));
		graph[t2].emplace_back(make_pair(t1, t3));
	}

	cin >> f1 >> f2;

	bfs(graph, 1, nums);

	if (v >= 4)
	{
		if (nums[v][3] == LLONG_MAX)
			cout << -1 << endl;
		else
			cout << nums[v][3] << endl;
	}
	else if (nums[v][1] != LLONG_MAX || nums[v][2] != LLONG_MAX || nums[v][3] != LLONG_MAX)
		cout << min(nums[v][1], nums[v][2], nums[v][3]) << endl;
	else
		cout << -1 << endl;
	return 0;
}