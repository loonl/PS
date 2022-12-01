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

    ll n; cin >> n;
    vector<ll> vec(n + 1, 0);
    vector<ll> dp(n + 1, 1);

    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    for (ll i = n - 1; i >= 1; i--) {
        ll b4 = i + vec[i] + 1;
        if (b4 <= n)
            dp[i] += dp[b4];
    }

    for (ll i = 1; i <= n; i++)
        cout << dp[i] << " ";
    return 0;
}
