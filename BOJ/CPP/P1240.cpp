#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    ll t1, t2, t3;
    vector<vector<P>> graph(n + 1, vector<P>());
    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2 >> t3;
        graph[t1].emplace_back(make_pair(t2, t3));
        graph[t2].emplace_back(make_pair(t1, t3));
    }

    vector<bool> visited;

    function<ll(ll, ll)> bfs = [&](ll st, ll ed) -> ll {
        queue<P> q;
        q.emplace(make_pair(st, 0));

        while (!q.empty()) {
            auto [cur, cur$] = q.front();
            q.pop();
            visited[cur] = true;

            if (cur == ed)
                return cur$;

            for (ll i = 0; i < graph[cur].size(); i++) {
                auto [next, next$] = graph[cur][i];
                if (!visited[next]) {
                    q.emplace(make_pair(next, cur$ + next$));
                }
            }
        }
    };

    for (ll i = 0; i < m; i++) {
        visited.clear();
        visited.assign(n + 1, false);
        cin >> t1 >> t2;
        cout << bfs(t1, t2) << endl;
    }
    return 0;
}
