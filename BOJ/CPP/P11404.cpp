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
    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, MAX));
    ll t1, t2, t3;

    for (ll i = 1; i <= n; i++) {
        dist[i][i] = 0;
    }

    for (ll i = 1; i <= m; i++) {
        cin >> t1 >> t2 >> t3;
        dist[t1][t2] = min(dist[t1][t2], t3);
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll k = 1; k <= n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (dist[i][j] == MAX)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
