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
struct info {
    ll cost;
    ll x;
    ll y;
};

vector<info> edges;


ll find(ll a) {
    if (parent[a] == a)
        return a;

    parent[a] = find(parent[a]);
    return parent[a];
}

void merge(ll a, ll b) {
    a = find(a), b = find(b);
    if (a > b)
        parent[b] = a;
    else
        parent[a] = b;
}

bool custom_sort(info a, info b) {
    return a.cost < b.cost;
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    ll t1, t2, t3;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        edges.push_back({t3, t1, t2});
    }

    parent.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    sort(edges.begin(), edges.end(), custom_sort);

    ll ans = 0;
    for (ll i = 0; i < m; i++) {
        if (find(edges[i].x) != find(edges[i].y)) {
            merge(edges[i].x, edges[i].y);
            ans += edges[i].cost;
        }
    }

    cout << ans << endl;
    return 0;
}
