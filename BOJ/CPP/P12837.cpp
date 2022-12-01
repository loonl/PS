#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e9+7;
vector<ll> vec;

void update(vector<ll>& tree, ll node, ll start, ll end, ll& index) {
    if (index < start || end < index)
        return;

    if (start == end) {
        tree[node] = vec[start];
        return;
    }

    ll mid = (start + end) / 2;
    update(tree, node * 2, start, mid, index);
    update(tree, node * 2 + 1, mid + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right) {
    if (right < start || end < left)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return query(tree, node * 2, start, mid, left, right) + query(tree, node * 2 + 1, mid + 1, end, left, right);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, q; cin >> n >> q;
    vec.assign(n + 1, 0);
    vector<ll> tree(4 * n, 0);

    ll t1, t2, t3;
    while (q--) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            vec[t2] += t3;
            update(tree, 1, 1, n, t2);
        }
        else if (t1 == 2)
            cout << query(tree, 1, 1, n, t2, t3) << endl;
    }
    return 0;
}
