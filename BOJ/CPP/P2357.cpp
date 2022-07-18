#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<ll> a;

ll init_M(vector<ll>& tree, ll node, ll start, ll end)
{
	if (start == end)
		return tree[node] = a[start];

	ll mid = (start + end) / 2;
	return tree[node] = max(init_M(tree, node * 2, start, mid), init_M(tree, node * 2 + 1, mid + 1, end));
}

ll MAX(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right)
{
	if (right < start || end < left)
		return -1;
	if (left <= start && end <= right)
		return tree[node];
	ll mid = (start + end) / 2;
	return max(MAX(tree, 2 * node, start, mid, left, right), MAX(tree, 2 * node + 1, mid + 1, end, left, right));
}

void update_M(vector<ll>& tree, ll node, ll start, ll end, ll& index, ll& val)
{
	if (index < start || end < index)
		return;

	if (start == end)
	{
		tree[node] = val;
		return;
	}

	ll mid = (start + end) / 2;
	update_M(tree, 2 * node, start, mid, index, val);
	update_M(tree, 2 * node + 1, mid + 1, end, index, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

ll init_m(vector<ll>& tree, ll node, ll start, ll end)
{
	if (start == end)
		return tree[node] = a[start];

	ll mid = (start + end) / 2;
	return tree[node] = min(init_m(tree, node * 2, start, mid), init_m(tree, node * 2 + 1, mid + 1, end));
}

ll MIN(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right)
{
	if (right < start || end < left)
		return LLONG_MAX;
	if (left <= start && end <= right)
		return tree[node];
	ll mid = (start + end) / 2;
	return min(MIN(tree, 2 * node, start, mid, left, right), MIN(tree, 2 * node + 1, mid + 1, end, left, right));
}

void update_m(vector<ll>& tree, ll node, ll start, ll end, ll& index, ll& val)
{
	if (index < start || end < index)
		return;

	if (start == end)
	{
		tree[node] = val;
		return;
	}

	ll mid = (start + end) / 2;

	update_m(tree, 2 * node, start, mid, index, val);
	update_m(tree, 2 * node + 1, mid + 1, end, index, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll n, m; cin >> n >> m;
	a.assign(n + 1, 0);
	for (ll i = 1; i <= n; i++)
		cin >> a[i];

	vector<ll> seg_M(4 * n, 0);
	vector<ll> seg_m(4 * n, 0);
	init_M(seg_M, 1, 1, n);
	init_m(seg_m, 1, 1, n);

	ll t1, t2;
	while (m--)
	{
		cin >> t1 >> t2;
		cout << MIN(seg_m, 1, 1, n, t1, t2) << " " << MAX(seg_M, 1, 1, n, t1, t2) << endl;
	}
	return 0;
}