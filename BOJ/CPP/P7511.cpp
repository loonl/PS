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
vector<ll> parent;
ll find(ll a) {
    if (parent[a] == a)
        return a;

    parent[a] = find(parent[a]);
    return parent[a];
}

void merge(ll a, ll b) {
    a = find(a), b = find(b);
    if (a == b)
        return;

    else if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll tc; cin >> tc;
    for (ll now = 1; now <= tc; now++) {
        cout << "Scenario " << now << ":" << endl;
        ll n; cin >> n;
        parent.clear();
        parent.assign(n, 0);
        for (ll i = 0; i < n; i++)
            parent[i] = i;

        ll k; cin >> k;
        ll t1, t2;
        while (k--) {
            cin >> t1 >> t2;
            merge(t1, t2);
        }

        ll m; cin >> m;
        while (m--) {
            cin >> t1 >> t2;
            if (find(t1) == find(t2))
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }

        cout << endl;
    }
    return 0;
}