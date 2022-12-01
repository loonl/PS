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
    if (a > b)
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

    ll n, m; cin >> n >> m;
    parent.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        merge(t1, t2);
    }

    ll ans = 0, curParent;
    for (ll i = 0; i < n; i++) {
        cin >> t1;
        if (i == 0) {
            curParent = find(t1);
            continue;
        }
        else {
            auto temp = find(t1);
            if (curParent != temp) {
                curParent = temp;
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
