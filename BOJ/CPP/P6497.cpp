#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    ll n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        vector<ll> num(n, 0);
        vector<vector<P>> graph(n, vector<P>());
        ll t1, t2, t3;
        ll total = 0;
        for (ll i = 1; i <= m; i++) {
            cin >> t1 >> t2 >> t3;
            total += t3;
            graph[t1].emplace_back(make_pair(t2, t3));
            graph[t2].emplace_back(make_pair(t1, t3));
        }

        vector<bool> visited(n, false);
        ll cost = 0;

        function<void()> prim = [&]() -> void {
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.emplace(make_pair(0, 0));

            while (!pq.empty()) {
                auto [cur$, cur] = pq.top();
                pq.pop();

                if (visited[cur])
                    continue;

                visited[cur] = true;
                cost += cur$;

                for (ll i = 0; i < graph[cur].size(); i++) {
                    auto [next, next$] = graph[cur][i];
                    if (!visited[next])
                        pq.emplace(make_pair(next$, next));
                }
            }
        };

        prim();
        cout << total - cost << endl;
    }
    return 0;
}
