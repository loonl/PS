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

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll tc, n; cin >> tc;
    while (tc--) {
        cin >> n;
        vector<vector<ll>> dp(n + 1, vector<ll>(10, 0));

        for (ll i = 0; i < 10; i++)
            dp[1][i] = 1;

        for (ll i = 2; i <= n; i++) {
            for (ll j = 0; j < 10; j++) {
                for (ll k = 0; k <= j; k++)
                    dp[i][j] += dp[i - 1][k];
            }
        }

        ll ans = 0;
        for (ll i = 0; i < 10; i++)
            ans += dp[n][i];
        cout << ans << endl;
    }
    return 0;
}
