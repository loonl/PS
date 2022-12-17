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
ll MOD = 1e9+7;


int main() {
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<ll> parent(n + 1, -1);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    function<ll(ll)> find = [&](ll a) -> ll {
        if (parent[a] == a)
            return a;

        parent[a] = find(parent[a]);
        return parent[a];
    };

    function<void(ll, ll)> merge = [&](ll a, ll b) -> void {
        a = find(a), b = find(b);
        if (a == b)
            return;

        if (a > b)
            parent[b] = a;
        else
            parent[a] = b;
    };

    ll t1, t2;
    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
        merge(t1, t2);
    }

    vector<ll> starts;
    for (ll i = 1; i <= n; i++) {
        if (find(i) == i)
            starts.emplace_back(i);
    }

    vector<ll> numCon(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        numCon[i] = graph[i].size();

    vector<bool> visited(n + 1, false);
    vector<ll> type(n + 1, -1);
    ll num0 = 0, num1 = 0, others = 0;

    vector<ll> groups, tempo;
    function<bool(ll st)> isBipartite = [&](ll st) -> bool {
        queue<P> q;
        q.emplace(make_pair(st, 0));
        visited[st] = true;

        if (graph[st].size() == 0) {
            others++;
            return true;
        }

        ll size = 0;
        while (!q.empty()) {
            auto [cur, color] = q.front();
            q.pop();

            // TODO
            tempo.emplace_back(cur);

            type[cur] = color;
            if (color == 1)
                num1++;
            else
                num0++;

            size++;

            for (auto next: graph[cur]) {
                if (!visited[next]) {
                    visited[next] = true;
                    if (color == 1)
                        q.emplace(make_pair(next, 0));
                    else
                        q.emplace(make_pair(next, 1));
                }
                else {
                    if (color == type[next])
                        return false;
                }
            }
        }

        groups.emplace_back(size);
        return true;
    };

    ll ans = 0;

    // inside one graph
    for (auto start: starts) {
        num0 = 0, num1 = 0;
        tempo.clear();

        if (!isBipartite(start)) {
            cout << 0 << endl;
            exit(0);
        }

        ll val = 0;
        for (auto ele: tempo) {
            if (type[ele] == 0)
                val += num1 - numCon[ele];
            else
                val += num0 - numCon[ele];
        }

        val /= 2;
        ans += val;
    }

    // with different groups of graphs
    for (ll i = 0; i < groups.size(); i++) {
        for (ll j = i + 1; j < groups.size(); j++)
            ans += groups[i] * groups[j];
    }

    // with lonely only-one vertexes
    ll remain_other = others;
    while (remain_other--)
        ans += remain_other + (n - others);

    cout << ans << endl;
    return 0;
}