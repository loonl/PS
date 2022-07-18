#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define PD pair<double, ll>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
vector<ll> arr;
ll n;

ll initSegment(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = arr[start];

    ll mid = (start + end) / 2;
    return tree[node] = initSegment(tree, node * 2, start, mid) + initSegment(tree, node * 2 + 1, mid + 1, end);
}

ll sum(vector<ll>& tree, ll node, ll start, ll end, ll left, ll right) {
    if (left > end || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<ll>& tree, ll node, ll start, ll end, ll index, ll diff) {
    if (index < start || index > end)
        return;

    tree[node] += diff;

    if (start != end) {
        ll mid = (start + end) / 2;
        update(tree, node * 2, start, mid, index, diff);
        update(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ll n, m; cin >> n >> m;
    arr.assign(n + 1, 0);
    vector<ll> tree(4 * n, 0);
    initSegment(tree, 1, 1, n);

    ll t1, t2, t3;
    while (m--) {
        cin >> t1 >> t2 >> t3;
        if (t1 == 0)
            cout << sum(tree, 1, 1, n, min(t2, t3), max(t2, t3)) << endl;
        else {
            ll diff = t3 - arr[t2];
            arr[t2] = t3;
            update(tree, 1, 1, n, t2, diff);
        }
    }

    return 0;
}
