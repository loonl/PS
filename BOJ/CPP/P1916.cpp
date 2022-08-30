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
    vector<map<ll, ll>> graph(n + 1, map<ll, ll>());
    vector<ll> val(n + 1, MAX);

    ll t1, t2, t3;
    for (ll i = 1; i <= m; i++) {
        cin >> t1 >> t2 >> t3;
        auto found = graph[t1].find(t2);
        if (found == graph[t1].end())
            graph[t1][t2] = t3;
        else
            graph[t1][t2] = min(graph[t1][t2], t3);
    }

    function<void(ll)> dijk = [&](ll start) -> void {
        priority_queue<P, vector<P>, greater<P>> pq;
        val[start] = 0;
        pq.emplace(make_pair(0, start));

        while (!pq.empty()) {
            auto [cur$, cur] = pq.top();
            pq.pop();

            for (auto it = graph[cur].begin(); it != graph[cur].end(); it++) {
                ll next = it->first, next$ = it->second;
                if (val[next] > next$ + cur$) {
                    pq.emplace(make_pair(next$ + cur$, next));
                    val[next] = next$ + cur$;
                }
            }
        }
    };

    ll st, ed; cin >> st >> ed;
    dijk(st);

    cout << val[ed] << endl;
    return 0;
}
