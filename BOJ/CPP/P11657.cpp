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
    ll t1, t2, t3;
    vector<vector<P>> graph(n + 1, vector<P>());
    for (ll i = 1; i <= m; i++) {
        cin >> t1 >> t2 >> t3;
        graph[t1].emplace_back(make_pair(t2, t3));
    }

    vector<ll> dist(n + 1, MAX);
    dist[1] = 0;
    bool cycle = false;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 0; k < graph[j].size(); k++) {
                if (dist[j] == MAX)
                    break;

                auto [nextL, cost] = graph[j][k];
                if (dist[nextL] > dist[j] + cost) {
                    dist[nextL] = dist[j] + cost;
                    if (i == n) {
                        cycle = true;
                        goto print;
                    }
                }
            }
        }
    }

print:
    if (cycle) {
        cout << -1 << endl;
        exit(0);
    }

    for (ll i = 2; i <= n; i++) {
        if (dist[i] != MAX)
            cout << dist[i] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
