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

    ll n; cin >> n;
    ll x = pow(2, n + 1) - 1, ans = 0;
    vector<ll> vec(x + 1, 0);
    for (ll i = 2; i <= x; i++)
        cin >> vec[i];

    function<ll(ll)> dfs = [&](ll cur) -> ll {
        if (cur * 2 >= x) {
            ans += vec[cur];
            return vec[cur];
        }

        ll right = dfs(cur * 2 + 1), left = dfs(cur * 2);
        ans += vec[cur] + abs(left - right);
        return vec[cur] + max(left, right);
    };

    dfs(1);
    cout << ans << endl;
    return 0;
}