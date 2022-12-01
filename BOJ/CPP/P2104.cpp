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
ll n;

ll initSumSeg(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = arr[start];

    ll mid = (start + end) / 2;
    return tree[node] = initSumSeg(tree, node * 2, start, mid) + initSumSeg(tree, node * 2 + 1, mid + 1, end);
}

ll initMinSeg(vector<ll>& tree, ll node, ll start, ll end) {
    if (start == end)
        return tree[node] = start;

    ll mid = (start + end) / 2;
    ll first = initMinSeg(tree, node * 2, start, mid), second = initMinSeg(tree, node * 2 + 1, mid + 1, end);
    if (arr[first] > arr[second])
        return tree[node] = second;
    else
        return tree[node] = first;
}

ll querySum(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right) {
    if (end < left || right < start)
        return 0;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2;
    return querySum(tree, node * 2, start, mid, left, right) + querySum(tree, node * 2 + 1, mid + 1, end, left, right);
}

ll queryMin(vector<ll>& tree, ll node, ll start, ll end, ll& left, ll& right) {
    if (end < left || right < start)
        return -1;

    if (left <= start && end <= right)
        return tree[node];

    ll mid = (start + end) / 2, ret = -1;
    ll first = queryMin(tree, node * 2, start, mid, left, right), second = queryMin(tree, node * 2 + 1, mid + 1, end, left, right);

    if (first != -1)
        ret = first;

    if (second != -1) {
        if (ret == -1)
            ret = second;
        else if (arr[first] > arr[second])
            ret = second;
    }

    return ret;
}

ll dnc(vector<ll>& treeSum, vector<ll>& treeMin, ll st, ll ed) {
    if (st == ed)
        return arr[st] * arr[st];

    ll divide = queryMin(treeMin, 1, 1, n, st, ed);

    ll ret = -1;
    if (divide != -1)
        ret = querySum(treeSum, 1, 1, n, st, ed) * arr[divide];

    if (st < divide)
        ret = max(ret, dnc(treeSum, treeMin, st, divide - 1));

    if (divide < ed)
        ret = max(ret, dnc(treeSum, treeMin, divide + 1, ed));

    return ret;
}



int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> n;
    arr.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> arr[i];

    vector<ll> segSum(4 * n, 0), segMin(4 * n, 0);
    initSumSeg(segSum, 1, 1, n);
    initMinSeg(segMin, 1, 1, n);
    cout << dnc(segSum, segMin, 1, n) << endl;
    return 0;
}
