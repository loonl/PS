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
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n, m, cost, st; cin >> n >> m >> cost >> st;
    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<bool> visited(n + 1, false);
    vector<ll> dist(n + 1, MAX);

    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
    }

    function<void()> bfs = [&]() -> void {
        queue<P> q;
        q.emplace(make_pair(st, 0));
        visited[st] = true;
        while (!q.empty()) {
            auto [cur, moved] = q.front();
            q.pop();

            dist[cur] = moved;

            for (auto next: graph[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.emplace(make_pair(next, moved + 1));
                }
            }
        }
    };

    bfs();
    vector<ll> ans;
    for (ll i = 1; i <= n; i++) {
        if (dist[i] == cost)
            ans.emplace_back(i);
    }

    if (ans.empty())
        cout << -1 << endl;
    else {
        for (auto ele: ans)
            cout << ele << endl;
    }
    return 0;
}