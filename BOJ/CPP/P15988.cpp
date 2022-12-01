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
ll MOD = 1000000009;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll tc; cin >> tc;
    vector<ll> dp(1000001, 0);
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for (ll i = 4; i <= 1000000; i++)
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % MOD;

    while (tc--) {
        ll n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}