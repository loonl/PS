#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

void bfs(vector<vector<ll>>& graph, vector<bool>& visited, ll start) {
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll tc; cin >> tc;
    ll v, e, part;
    vector<vector<ll>> graph;
    vector<bool> visited;
    vector<bool> isred;

    function<void(ll)> bfs = [&](ll start) -> void {
        queue<ll> q;
        visited[start] = true;
        q.emplace(start);
        isred[start] = true;

        while (!q.empty()) {
            ll cur = q.front();
            q.pop();
            for (auto nxt: graph[cur]) {
                if (!visited[nxt]) {
                    q.emplace(nxt);
                    isred[nxt] = !isred[cur];
                    visited[nxt] = true;
                }
            }
        }
    };

    function<bool(ll)> yes = [&](ll start) -> bool {
        queue<ll> q;
        visited[start] = true;
        q.emplace(start);

        while (!q.empty()) {
            ll cur = q.front();
            q.pop();
            for (auto next : graph[cur]) {
                if (isred[next] == isred[cur])
                    return false;
                if (!visited[next]) {
                    q.emplace(next);
                    visited[next] = true;
                }
            }
        }

        return true;
    };

    while (tc--) {
        part = 0;
        cin >> v >> e;
        graph.clear(); visited.clear();
        graph.assign(v + 1, vector<ll>());
        visited.assign(v + 1, false);
        isred.assign(v + 1, false);

        ll t1, t2;
        for (ll i = 0; i < e; i++) {
            cin >> t1 >> t2;
            graph[t1].emplace_back(t2);
            graph[t2].emplace_back(t1);
        }

        for (ll i = 1; i <= v; i++) {
            if (!visited[i]) {
                bfs(i);
            }
        }

        visited.clear();
        visited.assign(v + 1, false);

        bool ok = true;

        for (ll i = 1; i <= v; i++) {
            if (!visited[i]) {
                bool check = yes(i);
                if (!check) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
