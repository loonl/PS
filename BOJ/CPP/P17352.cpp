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
    vector<ll> parent(n + 1, 0);
    for (ll i = 0; i <= n; i++)
        parent[i] = i;

    function<ll(ll)> do_find = [&](ll a) -> ll {
        if (parent[a] == a)
            return a;

        parent[a] = do_find(parent[a]);
        return parent[a];
    };

    function<void(ll, ll)> merge = [&](ll a, ll b) -> void {
        a = do_find(a), b = do_find(b);
        if (a == b)
            return;

        parent[a] = b;
    };

    ll t1, t2;
    for (ll i = 0; i < n - 2; i++) {
        cin >> t1 >> t2;
        merge(t1, t2);
    }

    ll ans = 0, other = 0;
    for (ll i = 1; i <= n; i++) {
        if (parent[i] == i && ans == 0)
            ans = i;
        else if (parent[i] == i && ans != 0)
            other = i;
    }


    cout << other << " " << ans << endl;
    return 0;
}
