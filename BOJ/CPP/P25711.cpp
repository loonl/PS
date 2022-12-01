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
ll dp[1001][1001];

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    cout << fixed;
    cout.precision(10);
    ll n, q; cin >> n >> q;
    vector<ld> x(n, 0), y(n, 0);
    vector<ld> pSum1(n, 0), pSum2(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> x[i];

    for (ll i = 0; i < n; i++)
        cin >> y[i];

    for (ll i = 1; i < n; i++) {
        ld dist = sqrt((x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]));
        if (y[i] > y[i - 1])
            pSum1[i] = pSum1[i - 1] + 3 * dist;
        else if (y[i] == y[i - 1])
            pSum1[i] = pSum1[i - 1] + 2 * dist;
        else
            pSum1[i] = pSum1[i - 1] + dist;
    }

    for (ll i = n - 2; i >= 0; i--) {
        ld dist = sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
        if (y[i + 1] < y[i])
            pSum2[i] = pSum2[i + 1] + 3 * dist;
        else if (y[i + 1] == y[i])
            pSum2[i] = pSum2[i + 1] + 2 * dist;
        else
            pSum2[i] = pSum2[i + 1] + dist;
    }

    ll t1, t2;
    while (q--) {
        cin >> t1 >> t2;
        if (t1 < t2)
            cout << pSum1[t2 - 1] - pSum1[t1 - 1] << endl;
        else
            cout << pSum2[t2 - 1] - pSum2[t1 - 1] << endl;
    }
    return 0;
}