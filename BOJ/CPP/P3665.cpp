#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
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

    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        vector<ll> vec(n + 1, 0);
        map<ll, ll> ranks;
        for (ll i = 1; i <= n; i++) {
            cin >> vec[i];
            ranks[vec[i]] = i;
        }

        vector<ll> entry(n + 1, 0);
        vector<vector<ll>> graph(n + 1, vector<ll>());
        for (ll i = 1; i < n; i++) {
            for (ll j = i + 1; j <= n; j++) {
                graph[vec[i]].emplace_back(vec[j]);
                entry[vec[j]]++;
            }
        }

        ll m; cin >> m;
        ll t1, t2;
        for (ll i = 0; i < m; i++) {
            cin >> t1 >> t2;
            if (ranks[t1] > ranks[t2]) {
                graph[t2].erase(find(graph[t2].begin(), graph[t2].end(), t1));
                entry[t1]--;
                graph[t1].emplace_back(t2);
                entry[t2]++;
            }
            else {
                graph[t1].erase(find(graph[t1].begin(), graph[t1].end(), t2));
                entry[t2]--;
                graph[t2].emplace_back(t1);
                entry[t1]++;
            }
        }

        function <vector<ll>()> bfs = [&]() -> vector<ll> {
            queue<ll> q;
            for (ll i = 1; i <= n; i++) {
                if (entry[i] == 0)
                    q.emplace(i);
            }

            vector<ll> vec;

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                vec.emplace_back(cur);

                for (auto next : graph[cur]) {
                    entry[next]--;

                    if (entry[next] == 0)
                        q.emplace(next);
                }
            }

            return vec;
        };

        auto ans = bfs();
        if (ans.size() < n)
            cout << "IMPOSSIBLE" << endl;
        else {
            for (auto& ele: ans) {
                cout << ele << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
