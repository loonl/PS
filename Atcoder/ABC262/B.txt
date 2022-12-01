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
    ll n, m; cin >> n >> m;
    vector<set<ll>> graph(n + 1, set<ll>());

    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace(t2);
        graph[t2].emplace(t1);
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = i + 1; j <= n; j++) {
            for (ll k = j + 1; k <= n; k++) {
                auto found1 = graph[i].find(j);
                auto found2 = graph[j].find(k);
                auto found3 = graph[k].find(i);
                if (found1 != graph[i].end() && found2 != graph[j].end() && found3 != graph[k].end())
                    ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
