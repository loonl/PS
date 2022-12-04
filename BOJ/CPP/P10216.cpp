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
vector<T> vec;
vector<ll> parent;

bool isgroup(ll idx1, ll idx2) {
    auto& [x1, y1, dist1] = vec[idx1];
    auto& [x2, y2, dist2] = vec[idx2];
    double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if (dist <= dist1 + dist2)
        return true;
    return false;
}

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

    if (a > b)
        parent[a] = b;
    else
        parent[b] = a;
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll tc; cin >> tc;
    while (tc--) {
        vec.clear(); parent.clear();

        ll n; cin >> n;
        vec.assign(n + 1, {0, 0, 0});
        parent.assign(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            parent[i] = i;

        ll t1, t2, t3;
        for (ll i = 1; i <= n; i++) {
            cin >> t1 >> t2 >> t3;
            vec[i] = make_tuple(t1, t2, t3);
        }

        for (ll i = 1; i <= n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                if (isgroup(i, j))
                    merge(i, j);
            }
        }

        set<ll> ans;
        for (ll i = 1; i <= n; i++)
            ans.emplace(find(i));

        cout << ans.size() << endl;
    }
    return 0;
}