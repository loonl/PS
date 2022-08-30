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
    ll n, m, t1, t2;
    ll caseNo = 0;
    while (true) {
        caseNo++;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;

        vector<vector<ll>> graph(n + 1, vector<ll>());
        vector<bool> visited(n + 1, false);
        while (m--) {
            cin >> t1 >> t2;
            graph[t1].emplace_back(t2);
            graph[t2].emplace_back(t1);
        }

        ll trees = 0;
        function<bool(ll)> bfs = [&](ll start) -> bool {
            queue<P> q;
            q.emplace(make_pair(start, -1));
            visited[start] = true;
            bool flag = true;

            while (!q.empty()) {
                auto [cur, last] = q.front();
                q.pop();

                for (ll next : graph[cur]) {
                    if (!visited[next]) {
                        q.emplace(make_pair(next, cur));
                        visited[next] = true;
                        continue;
                    }

                    if (visited[next] && last != next)
                        flag = false;
                }
            }

            return flag;
         };

        for (ll i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (bfs(i))
                    trees++;
            }
        }

        cout << "Case " << caseNo << ": ";
        if (trees == 0)
            cout << "No trees";
        else if (trees == 1)
            cout << "There is one tree";
        else
            cout << "A forest of " << trees << " trees";
        cout << "." << endl;
    }

    return 0;
}
