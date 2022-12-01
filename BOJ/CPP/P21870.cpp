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

    ll n; cin >> n; vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    function<ll(ll, ll)> gcd = [&](ll a, ll b) -> ll {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    };

    function<ll(ll, ll)> calc_GCD = [&](ll lo, ll hi) -> ll {
        ll num = vec[hi];
        for (int i = lo; i < hi; i++)
            num = gcd(num, vec[i]);
        return num;
    };

    function<ll(ll, ll)> GCD = [&](ll lo, ll hi) -> ll {
        if (lo >= hi)
            return vec[hi];

        ll md = (lo + hi - 1) / 2;
        return max(GCD(lo, md) + calc_GCD(md + 1, hi),
                   calc_GCD(lo, md) + GCD(md + 1, hi));
    };

    cout << GCD(1, n) << endl;
    return 0;
}
