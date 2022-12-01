#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

struct compare {
    bool operator()(T _a, T _b) const {
        auto [a, no, a$] = _a; auto [b, use, b$] = _b;
        if (a$ == b$)
            return a > b;
        return a$ > b$;
    }
};

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n, m, k; cin >> n >> m >> k;

    if (k == 1) {
        cout << 1 << endl;
        exit(0);
    }

    vector<vector<ll>> graph(k + 1, vector<ll>());
    vector<bool> visited(k + 1, false);
    vector<bool> added(k + 1, false);
    vector<vector<ll>> mp(n + 1, vector<ll>(m + 1, -1));
    vector<P> vec; vec.emplace_back(make_pair(0, 0));
    vector<ll> dp(k + 1, 1);
    vector<ll> parent(k + 1, -1);

    ll t1, t2;
    for (ll i = 1; i <= k; i++) {
        cin >> t1 >> t2;
        vec.emplace_back(make_pair(t1, t2));
        mp[t1][t2] = i;
    }

    vector<ll> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<ll> dc = {-1, 0,  1, -1, 1,-1, 0, 1};
    function<void(ll)> check_adj = [&](ll cur) -> void {
        auto [curR, curC] = vec[cur];
        for (ll i = 0; i < 8; i++) {
            ll nextR = curR + dr[i], nextC = curC + dc[i];
            if (!(nextR < 0 || nextR > n || nextC < 0 || nextC > m)) {
                ll next = mp[nextR][nextC];
                if (next != -1) {
                    graph[next].emplace_back(cur);
                    graph[cur].emplace_back(next);
                }
            }
        }
    };

    for (ll i = 1; i <= k; i++)
        check_adj(i);

    function<void(ll)> bfs = [&](ll start) -> void {
        priority_queue<T, vector<T>, compare> pq;
        pq.emplace(make_tuple(start, -1, 0));
        visited[start] = true;

        while (!pq.empty()) {
            auto [cur, prev, cur$] = pq.top();
            pq.pop();

            if (prev != -1)
                parent[cur] = prev;

            for (auto it = graph[cur].begin(); it != graph[cur].end(); it++) {
                auto next = *it;
                if (!visited[next]) {
                    visited[next] = true;
                    pq.emplace(make_tuple(next, cur, cur$ + 1));
                }
            }
        }
    };

    ll start; cin >> start;
    bfs(start);

    for (ll i = 1; i <= k; i++) {
        if (!visited[i]) {
            cout << -1 << endl;
            exit(0);
        }
    }

    for (ll i = 1; i <= k; i++)
        graph[i].clear();

    for (ll i = 1; i <= k; i++) {
        if (i == start)
            continue;

        graph[parent[i]].emplace_back(i);
    }

    function<void(ll)> dfsdp = [&](ll cur) -> void {
        for (auto it = graph[cur].begin(); it != graph[cur].end(); it++) {
            auto next = *it;
            dfsdp(next);
            dp[cur] += dp[next];
        }
    };

    dfsdp(start);
    for (ll i = 1; i <= k; i++)
        cout << dp[i] << " ";
    cout << endl;
    return 0;
}
