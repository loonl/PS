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

    ll n, t, sum = 0; cin >> n >> t;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    for (ll i = 1; i <= n; i++)
        vec[i] += vec[i - 1];

    t %= sum;
    ll ans = 0, ans2 = 0;
    for (ll i = 1; i <= n; i++) {
        if (t >= vec[i - 1] && t < vec[i]) {
            ans = i, ans2 = t - vec[i - 1];
            break;
        }
    }

    cout << ans << " " << ans2 << endl;
    return 0;
}