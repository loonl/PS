#include <iostream>
#include <vector>
#define endl '\n'
#define ull long long
using namespace std;
//typedef unsigned long long ull;
vector<ull> a;

ull init(vector<ull>& tree, ull node, ull start, ull end)
{
	if (start == end)
		return tree[node] = a[start];

	ull mid = (start + end) / 2;
	return tree[node] = (init(tree, node * 2, start, mid) * init(tree, node * 2 + 1, mid + 1, end)) % 1000000007;
}

ull gop(vector<ull>& tree, ull node, ull start, ull end, ull& left, ull& right)
{
	if (left > end || right < start)
		return 1;
	if (left <= start && end <= right)
		return tree[node];
	return (gop(tree, node * 2, start, (start + end) / 2, left, right) * gop(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right)) % 1000000007;
}

void update(vector<ull>& tree, ull node, ull start, ull end, ull& index, ull& val)
{
	if (index < start || end < index)
		return;

	if (start == end)
	{
		tree[node] = val % 1000000007;
		return;
	}

	update(tree, 2 * node, start, (start + end) / 2, index, val);
	update(tree, 2 * node + 1, (start + end) / 2 + 1, end, index, val);
	tree[node] = tree[2 * node] * tree[2 * node + 1] % 1000000007;
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ull n, m, k; cin >> n >> m >> k;
	a.assign(n + 1, 0);
	for (ull i = 1; i <= n; i++)
		cin >> a[i];

	vector<ull> seg(4 * n, 0);
	init(seg, 1, 1, n);

	ull cmd, tmp1, tmp2;
	for (ull i = n + 2; i <= n + m + k + 1; i++)
	{
		cin >> cmd >> tmp1 >> tmp2;
		if (cmd == 1)
		{
			a[tmp1] = tmp2;
			update(seg, 1, 1, n, tmp1, tmp2);
		}
		else
			cout << gop(seg, 1, 1, n, tmp1, tmp2) << endl;
	}
	return 0;
}