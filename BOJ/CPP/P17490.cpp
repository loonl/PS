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
vector<ll> cost;

ll find(ll a) {
    if (parent[a] == a)
        return a;

    parent[a] = find(parent[a]);
    cost[a] = min(cost[a], parent[a]);
    return parent[a];
}

void merge(ll a, ll b) {
    a = find(a), b = find(b);
    cost[a] = min(cost[a], cost[b]);
    cost[b] = min(cost[a], cost[b]);
    if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}

void renewCost(ll a) {
    cost[a] = min(cost[a], cost[find(a)]);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m, limit; cin >> n >> m >> limit;
    ll ans = 0;
    parent.assign(n + 1, 0);
    cost.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> cost[i];

    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    vector<bool> ok(n + 1, true);
    ll t1, t2;
    for (ll i = 1; i <= m; i++) {
        cin >> t1 >> t2;
        if (t1 > t2 && (t1 != n && t2 != 1))
            swap(t1, t2);

        ok[t1] = false;
    }

    for (ll i = 1; i <= n; i++) {
        if (ok[i] && i != n)
            merge(i, i + 1);
        else if (ok[i] && i == n)
            merge(i, 1);
    }

    for (ll i = 1; i <= n; i++)
        renewCost(i);

    vector<bool> added(n + 1, false);
    for (ll i = 1; i <= n; i++) {
        if (i != n) {
            if (find(i) != find(i + 1)){
            if (!added[find(i)]) {
                added[find(i)] = true;
                ans += cost[i];
            }
            if (!added[find(i + 1)]) {
                added[find(i + 1)] = true;
                ans += cost[i + 1];
            }
        }
        }
        else if (find(i) != find(1)) {
            if (!added[find(i)]) {
                added[find(i)] = true;
                ans += cost[i];
            }
            if (!added[find(1)]) {
                added[find(1)] = true;
                ans += cost[1];
            }
        }
    }

    if (ans <= limit)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
