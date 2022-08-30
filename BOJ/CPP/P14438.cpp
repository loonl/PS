#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define endl '\n'
using namespace std;
typedef long long ll;
vector<ll> a;

ll init(vector<ll>& tree, ll node, ll start, ll end)
{
	if (start == end)
		return tree[node] = a[start];

	ll mid = (start + end) / 2;
	return tree[node] = min(init(tree, node * 2, start, mid), init(tree, node * 2 + 1, mid + 1, end));
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

void update(vector<ll>& tree, ll node, ll start, ll end, ll& index, ll& val)
{
	if (index < start || end < index)
		return;

	if (start == end)
	{
		tree[node] = val;
		return;
	}

	ll mid = (start + end) / 2;

	update(tree, 2 * node, start, mid, index, val);
	update(tree, 2 * node + 1, mid + 1, end, index, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll n; cin >> n;
	a.assign(n + 1, 0);
	vector<ll> seg(4 * n, 0);
	for (ll i = 1; i <= n; i++)
        cin >> a[i];

	init(seg, 1, 1, n);

	ll m, t1, t2, t3; cin >> m;
	for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1)
            update(seg, 1, 1, n, t2, t3);
        else
            cout << MIN(seg, 1, 1, n, t2, t3) << endl;
	}
	return 0;
}
