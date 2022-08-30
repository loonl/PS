#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false); cout.tie(0)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define PD pair<double, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
bool compare(tuple<ll, ll, ll, ll>& a, tuple<ll, ll, ll, ll>& b) {
    auto [x1, y1, x2, y2] = a;
    auto [x3, y3, x4, y4] = b;

}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    ll n, m;
    cin >> n >> m;
    vector<vector<P>> graph(n + 1, vector<P>());
    vector<bool> visited(n + 1, false);

    ll t1, t2, t3;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        graph[t1].emplace_back(make_pair(t2, t3));
        graph[t2].emplace_back(make_pair(t1, t3));
    }

    set<ll> temp;
    function<ll(ll)> prim = [&](ll start) -> ll {
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.emplace(make_pair(0, start));
        ll ret = 0;

        while (!pq.empty()) {
            auto [dist, cur] = pq.top();
            pq.pop();

            if (visited[cur])
                continue;

            visited[cur] = true;
            ret += dist;
            temp.emplace(dist);

            for (ll i = 0; i < graph[cur].size(); i++) {
                auto [next, nextD] = graph[cur][i];
                if (!visited[next])
                    pq.emplace(make_pair(nextD, next));
            }
        }

        return ret;
    };

    cout << prim(1) - *temp.rbegin() << endl;
    return 0;
}
