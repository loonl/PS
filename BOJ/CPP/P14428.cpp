#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
vector<ll> arr, seg;

ll init(ll node, ll st, ll ed) {
    if (st == ed)
        return seg[node] = st;

    ll mid = (st + ed) / 2;
    ll x = init(node * 2, st, mid), y = init(node * 2 + 1, mid + 1, ed);
    if (arr[x] <= arr[y])
        return seg[node] = x;
    return seg[node] = y;
}

void update(ll node, ll st, ll ed, ll index, ll val) {

    if (st == ed || index < st || ed < index)
        return;

    ll mid = (st + ed) / 2;
    update(node * 2, st, mid, index, val);
    update(node * 2 + 1, mid + 1, ed, index, val);
    if (arr[seg[node * 2]] <= arr[seg[node * 2 + 1]])
        seg[node] = seg[node * 2];
    else
        seg[node] = seg[node * 2 + 1];
}

ll query(ll node, ll st, ll ed, ll left, ll right) {
    if (ed < left || st > right)
        return -1;

    if (left <= st && ed <= right)
        return seg[node];

    ll mid = (st + ed) / 2;
    ll x = query(node * 2, st, mid, left, right), y = query(node * 2 + 1, mid + 1, ed, left, right);
    if (x != -1 && y != -1) {
        if (arr[x] <= arr[y])
            return x;
        else
            return y;
    }
    else if (x == -1 && y != -1)
        return y;
    else if (x != -1 && y == -1)
        return x;
    else
        return -1;
}


int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE


    ll n; cin >> n;
    arr.assign(n + 1, 0);
    seg.assign(4 * n, 0);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    init(1, 1, n);
    ll m; cin >> m;

    ll t1, t2, t3;
    while (m--) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 1) {
            arr[t2] = t3;
            update(1, 1, n, t2, t3);
        }
        else if (t1 == 2)
            cout << query(1, 1, n, t2, t3) << endl;
    }
    return 0;
}
