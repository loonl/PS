#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
vector<ll> arr;

ll init(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = start;

    ll mid = (start + end) / 2;
    ll x = init(tree, 2 * node, start, mid);
    ll y = init(tree, 2 * node + 1, mid + 1, end);
    if (arr[x] > arr[y])
        return tree[node] = y;
    else
        return tree[node] = x;
}

ll get(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    ll mid = (start + end) / 2;
    ll _left = get(tree, 2 * node, start, mid, left, right);
    ll _right = get(tree, 2 * node + 1, mid + 1, end, left, right);

    if (_left == -1 || _right == -1)
        return _left == -1 ? _right : _left;

    return arr[_left] < arr[_right] ? _left : _right;
}

ll getmax(vector<ll>& tree, ll start, ll end) {
    ll minidx = get(tree, 1, 1, arr.size() - 1, start, end);

    ll ret = (end - start + 1) * arr[minidx];

    if (minidx > start)
        ret = max(ret, getmax(tree, start, minidx - 1));

    if (minidx < end)
        ret = max(ret, getmax(tree, minidx + 1, end));

    return ret;
}

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n;
    while (1) {
        cin >> n;
        if (n == 0)
            exit(0);

        arr.clear(); arr.assign(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            cin >> arr[i];

        vector<ll> seg(4 * n, 0);
        init(seg, 1, 1, n);
        cout << getmax(seg, 1, n) << endl;
    }
    return 0;
}
