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

    ll v, e; cin >> v >> e;
    vector<vector<ll>> dp(v + 1, vector<ll>(v + 1, MAX));

    ll t1, t2, t3;
    for (ll i = 0; i < e; i++) {
        cin >> t1 >> t2 >> t3;
        dp[t1][t2] = t3;
    }

    for (ll i = 1; i <= v; i++) {
        for (ll j = 1; j <= v; j++) {
            for (ll k = 1; k <= v; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }

    vector<ll> vec;
    for (ll i = 1; i <= v; i++) {
        vec.emplace_back(dp[i][i]);
    }

    ll ans = *min_element(vec.begin(), vec.end());
    if (ans == MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}
