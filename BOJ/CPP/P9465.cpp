#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        vector<vector<ll>> num(3, vector<ll>(n + 1, -1));
        for (ll i = 1; i <= 2; i++) {
            for (ll j = 1; j <= n; j++)
                cin >> num[i][j];
        }

        vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
        if (n == 1) {
            cout << max(num[1][1], num[2][1]) << endl;
            continue;
        }
        else if (n == 2) {
            cout << max(num[1][1] + num[2][2], num[2][1] + num[1][2]) << endl;
            continue;
        }

        dp[1][1] = num[2][1]; dp[1][0] = num[1][1];
        dp[2][1] = num[1][1] + num[2][2]; dp[2][0] = num[1][2] + num[2][1];
        for (ll i = 3; i <= n; i++) {
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1] + num[1][i]), max(dp[i - 2][0], dp[i - 2][1]) + num[1][i]);
            dp[i][1] = max(dp[i - 1][0] + num[2][i], max(dp[i - 2][0], dp[i - 2][1]) + num[2][i]);
        }

        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}
