#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    ll n, m; cin >> n >> m;
    vector<ll> memory(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> memory[i];
    }
    vector<ll> cost(n + 1, 0); ll hap = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> cost[i];
        hap += cost[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(hap + 1, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= hap; j++) {
            if (j - cost[i] < 0) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }

            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
        }
    }

    ll ans = MAX;
    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= hap; j++) {
            if (dp[i][j] >= m) {
                ans = min(ans, j);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
