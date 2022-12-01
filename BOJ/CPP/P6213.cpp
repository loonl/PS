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

ll initMax(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = vec[start];


    ll mid = (start + end) / 2;
    return tree[node] = max(initMax(tree, node * 2, start, mid), initMax(tree, node * 2 + 1, mid + 1, end));
}

ll initMin(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = vec[start];

    ll mid = (start + end) / 2;
    return tree[node] = min(initMin(tree, node * 2, start, mid), initMin(tree, node * 2 + 1, mid + 1, end));
}

ll queryMax(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right) {
    if (end < left || right < start)
        return -1;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return max(queryMax(tree, 2 * node, start, mid, left, right), queryMax(tree, 2 * node + 1, mid + 1, end, left, right));
}

ll queryMin(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right) {
    if (end < left || right < start)
        return MAX;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return min(queryMin(tree, node * 2, start, mid, left, right), queryMin(tree, node * 2 + 1, mid + 1, end, left, right));
}


int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, q; cin >> n >> q;
    vec.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    vector<ll> treeMax(4 * n, 0), treeMin(4 * n, 0);
    initMax(treeMax, 1, 1, n);
    initMin(treeMin, 1, 1, n);

    ll t1, t2;
    while (q--) {
        cin >> t1 >> t2;
        cout << queryMax(treeMax, 1, 1, n, t1, t2) - queryMin(treeMin, 1, 1, n, t1, t2) << endl;
    }

    return 0;
}
