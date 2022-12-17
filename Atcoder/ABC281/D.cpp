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

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, k, d; cin >> n >> k >> d;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(d, -1)));
    for (ll i = 1; i <= n; i++)
        dp[i][0][0] = 0;

    for (ll i = 1; i <= n; i++) {
        dp[i][1][vec[i] % d] = max(vec[i], dp[i][1][vec[i] % d]);

        ll rem = vec[i] % d;
        if (i == 1)
            continue;

        for (ll j = 1; j <= min(i, k); j++) {
            for (ll x = 0; x < d; x++) {
                if (dp[i - 1][j - 1][(x + d - rem) % d] != -1)
                    dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j - 1][(x + d - rem) % d] + vec[i]);

                if (dp[i - 1][j][x] != -1)
                    dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][x]);
            }
        }
    }

    cout << dp[n][k][0] << endl;
    return 0;
}