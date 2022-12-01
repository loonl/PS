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
vector<ll> parent;
ll do_find(ll a) {
    if (parent[a] == a)
        return a;

    return parent[a] = do_find(parent[a]);
}

void do_merge(ll a, ll b) {
    a = do_find(a), b = do_find(b);
    if (a == b)
        return;
    
    parent[a] = b;
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n, m; cin >> n >> m;
    ll t1, t2;
    vector<set<ll>> graph(n + 1, set<ll>());
    vector<bool> visited(n + 1, false);
    parent.assign(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        parent[i] = i;

    for (ll i = 1; i <= m; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace(t2);
        graph[t2].emplace(t1);
        do_merge(t1, t2);
    }
    vector<ll> starts;
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (parent[i] == i)
            starts.emplace_back(i);
    }

    function<void(ll, ll)> dfs = [&](ll cur, ll prev) -> void {
       visited[cur] = true;

       for (auto next: graph[cur]) {
           if (!visited[next])
               dfs(next, cur);

           else {
               if (prev != -1 && next != prev) {
                   ans++;
                   //graph[cur].erase(graph[cur].find(next));
                   graph[next].erase(graph[next].find(cur));
               }
           }
       }
    };

    for (ll i = 0; i < starts.size(); i++)
        dfs(starts[i], -1);

    ans += starts.size() - 1;
    cout << ans << endl;
    return 0;
}