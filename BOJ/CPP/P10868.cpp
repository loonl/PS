#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;
vector<ll> vec;

ll init(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = vec[start];

    ll mid = (start + end) / 2;
    return tree[node] = min(init(tree, node * 2, start, mid), init(tree, node * 2 + 1, mid + 1, end));
}

ll query(vector<ll>& tree, ll node, ll left, ll right, ll start, ll end) {
    if (end < left || start > right)
        return MAX;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return min(query(tree, node * 2, left, right, start, mid), query(tree, node * 2 + 1, left, right, mid + 1, end));
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n, queries; cin >> n >> queries;
    vec.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    vector<ll> seg(4 * n, 0);
    init(seg, 1, 1, n);

    ll t1, t2, t3;
    while (queries--) {
        cin >> t2 >> t3;
        cout << query(seg, 1, t2, t3, 1, n) << endl;
    }
    return 0;
}
