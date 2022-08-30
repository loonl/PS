#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

vector<ll> parent;

ll do_find(ll x) {
    if (parent[x] == x)
        return x;

    return parent[x] = do_find(parent[x]);
}

void do_union(ll x, ll y) {
    ll px = do_find(x);
    ll py = do_find(y);

    if (px > py)
        parent[px] = py;
    else if (px < py)
        parent[py] = px;
}

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    parent.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;
    ll x; cin >> x; vector<bool> know(n + 1, false);
    ll t1; know[0] = true;
    for (ll i = 1; i <= x; i++) {
        cin >> t1;
        know[t1] = true;
        do_union(0, t1);
    }

    ll t2;
    vector<vector<ll>> vec;
    ll ans = 0;
    for (ll i = 0; i < m; i++) {
        cin >> t2;

        bool ok = true;
        vector<ll> temp(t2, 0);
        for (ll j = 0; j < t2; j++)
            cin >> temp[j];

        for (ll j = 1; j < t2; j++)
            do_union(temp[j - 1], temp[j]);

        vec.emplace_back(temp);
    }

   for (ll i = 0; i < vec.size(); i++) {
        bool ok = true;
        for (auto& ele: vec[i]) {
            if (know[ele] || know[do_find(ele)]) {
                ok = false;
                break;
            }

        }

        if (ok)
            ans++;
   }

    cout << ans << endl;
    return 0;
}
