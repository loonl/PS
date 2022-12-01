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
vector<ll> arr;

ll init(vector<ll>& tree, ll node, ll st, ll ed) {
    if (st == ed)
        return tree[node] = arr[st];

    ll mid = (st + ed) / 2;
    return tree[node] = init(tree, node * 2, st, mid) + init(tree, node * 2 + 1, mid + 1, ed);
}

void update(vector<ll>& tree, ll node, ll st, ll ed, ll idx) {
    if (idx < st || ed < idx)
        return;

    if (st == ed) {
        tree[node] = arr[st];
        return;
    }

    ll mid = (st + ed) / 2;
    update(tree, node * 2, st, mid, idx);
    update(tree, node * 2 + 1, mid + 1, ed, idx);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(vector<ll>& tree, ll node, ll st, ll ed, ll left, ll right) {
    if (st > right || ed < left)
        return 0;

    if (left <= st && ed <= right)
        return tree[node];

    ll mid = (st + ed) / 2;
    return query(tree, node * 2, st, mid, left, right) + query(tree, node * 2 + 1, mid + 1, ed, left, right);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, q; cin >> n >> q;
    arr.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    vector<ll> tree(4 * n, 0);
    init(tree, 1, 1, n);
    ll t1, t2, t3, t4;
    while (q--) {
        cin >> t1 >> t2 >> t3 >> t4;
        if (t1 > t2)
            swap(t1, t2);
        cout << query(tree, 1, 1, n, t1, t2) << endl;

        arr[t3] = t4;
        update(tree, 1, 1, n, t3);
    }
    return 0;
}
