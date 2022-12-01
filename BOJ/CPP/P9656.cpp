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

    ll n; cin >> n;
    vector<ll> dp(n + 3, 0);
    dp[1] = 0, dp[3] = 0, dp[2] = 1;
    for (ll i = 4; i <= n; i++) {
        if (dp[i - 3] == 0 || dp[i - 1] == 0)
            dp[i] = 1;
        else
            dp[i] = 0;
    }

    if (dp[n] == 1)
        cout << "SK" << endl;
    else
        cout << "CY" << endl;
    return 0;
}
