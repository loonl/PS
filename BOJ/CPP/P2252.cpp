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

    ll n, m;
    cin >> n >> m;
    vector<ll> entry(n + 1, 0);
    vector<vector<ll>> graph(n + 1, vector<ll>());
    ll t1, t2;
    for (ll i = 1; i <= m; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        entry[t2]++;
    }

    function <void()> bfs = [&]() -> void {
        queue<ll> q;
        for (ll i = 1; i <= n; i++) {
            if (entry[i] == 0)
                q.emplace(i);
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            cout << cur << " ";

            for (auto next : graph[cur]) {
                entry[next]--;

                if (entry[next] == 0)
                    q.emplace(next);
            }
        }
        cout << endl;
    };

    bfs();

    return 0;
}
