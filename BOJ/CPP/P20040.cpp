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
    ll m, n; cin >> n >> m;

    vector<ll> parent(n, 0);

    function<ll(ll)> do_find = [&](ll x) -> ll {
        if (parent[x] == x)
            return x;
        return parent[x] = do_find(parent[x]);
    };

    function<void(ll, ll)> do_union = [&](ll x, ll y) -> void {
        ll px = do_find(x), py = do_find(y);
        if (px < py)
            parent[py] = px;
        else
            parent[px] = py;
    };

    for (ll i = 0; i < n; i++) {
        parent[i] = i;
    }

    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        if (do_find(t1) == do_find(t2)) {
            cout << i + 1 << endl;
            exit(0);
        }

        do_union(t1, t2);
    }

    cout << 0 << endl;
    return 0;
}
