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
    if (start == end) {
        if (vec[start] % 2 == 0)
            return tree[node] = 1;
        else
            return tree[node] = 0;
    }

    ll mid = (start + end) / 2;
    return tree[node] = init(tree, node * 2, start, mid) + init(tree, node * 2 + 1, mid + 1, end);
}

void update(vector<ll>& tree, ll node, ll start, ll end, ll index) {
    if (index < start || end < index)
        return;

    if (start == end) {
        if (vec[start] % 2 == 0)
            tree[node] = 1;
        else
            tree[node] = 0;

        return;
    }

    ll mid = (start + end) / 2;
    update(tree, node * 2, start, mid, index);
    update(tree, node * 2 + 1, mid + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(vector<ll>& tree, ll node, ll left, ll right, ll start, ll end) {
    if (right < start || end < left)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return query(tree, node * 2, left, right, start, mid) + query(tree, node * 2 + 1, left, right, mid + 1, end);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n; cin >> n;
    vec.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    vector<ll> seg(4 * n, 0);
    init(seg, 1, 1, n);

    ll queries; cin >> queries;
    ll t1, t2, t3;
    while (queries--) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            vec[t2] = t3;
            update(seg, 1, 1, n, t2);
        }

        else if (t1 == 2)
            cout << query(seg, 1, t2, t3, 1, n) << endl;

        else if (t1 == 3)
            cout << (t3 - t2 + 1) - query(seg, 1, t2, t3, 1, n) << endl;
    }
    return 0;
}
