#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<P> vec;
    vec.emplace_back(make_pair(0, 0));
    ll t1, t2;
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        vec.emplace_back(make_pair(t1, t2));
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, pow(10, 18)));
    for (ll i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (ll i = 1; i < n; i++) {
        for (ll j = 1; i + j <= n; j++) {
            for (ll k = 0; k <= i; k++) {
                if (j + k + 1 <= n)
                    dp[j][j + i] = min(dp[j][j + i], dp[j][j + k] + dp[j + k + 1][j + i] + vec[j].first * vec[j + k].second * vec[j + i].second);
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
