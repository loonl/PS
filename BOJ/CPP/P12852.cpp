#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

ll min(ll a, ll b) {
    if (a >b)
        return b;
    return a;
}

ll min(ll a, ll b, ll c) {
    return min(a, min(b, c));
}

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<ll> dp(3 * n, MAX);
    dp[n] = 0;

    for (ll i = n - 1; i >= 1; i--)
        dp[i] = min(dp[3 * i], dp[2 * i], dp[i + 1]) + 1;

    cout << dp[1] << endl;

    ll pivot = 1;
    vector<ll> ans;
    while (pivot <= n) {
        ll piv = dp[pivot];
        ans.emplace_back(pivot);

        if (pivot == n)
            break;

        if (piv - 1 == dp[3 * pivot])
            pivot *= 3;
        else if (piv - 1 == dp[2 * pivot])
            pivot *= 2;
        else
            pivot++;
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++)
        cout << *it << " ";
    return 0;
}
