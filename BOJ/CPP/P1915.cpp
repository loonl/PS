#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    vector<vector<ll>> vec(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

    char x;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> x;
            vec[i][j] = x - '0';
            if (vec[i][j] == 1)
                dp[i][j] = 1;
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (vec[i][j] == 1) {
                if (dp[i-1][j] != 0 && dp[i-1][j-1] != 0 && dp[i][j-1] != 0) {
                    if (dp[i-1][j] != 1 && dp[i-1][j-1] != 1 && dp[i][j-1] != 1) {
                        ll size = min(dp[i-1][j], dp[i-1][j-1]);
                        size = min(size, dp[i][j-1]);
                        dp[i][j] = size + 1;
                    }
                    else {
                        dp[i][j] = 2;
                    }
                }
                ans = max(ans, dp[i][j]);
            }

        }
    }

    cout << pow(ans, 2) << endl;

    return 0;
}
