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

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    vector<ll> parent(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    function<ll(ll)> do_find = [&](ll a) -> ll {
        if (parent[a] == a)
            return a;

        return do_find(parent[a]);
    };

    function<void(ll, ll)> merge = [&](ll a, ll b) -> void {
        a = do_find(a), b = do_find(b);

        if (a == b)
            return;

        if (vec[a] > vec[b])
            parent[a] = b;
        else
            parent[b] = a;
    };

    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        merge(t1, t2);
    }

    vector<bool> isFriend(n + 1, false);
    ll payed = 0;
    for (ll i = 1; i <= n; i++) {
        ll cheapest = do_find(i);
        if (!isFriend[cheapest]) {
            payed += vec[cheapest];
            isFriend[cheapest] = true;
        }

        isFriend[i] = true;
    }

    if (payed > k)
        cout << "Oh no" << endl;
    else
        cout << payed << endl;
    return 0;
}