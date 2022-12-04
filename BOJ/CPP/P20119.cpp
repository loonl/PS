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

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m, temp, ed; cin >> n >> m;
    vector<vector<P>> graph(n + 1, vector<P>());
    vector<vector<ll>> entry(n + 1);
    for (ll i = 0; i < m; i++) {
        cin >> temp;

        vector<ll> ingr(temp, 0);

        for (ll j = 0; j < temp; j++)
            cin >> ingr[j];

        cin >> ed;
        for (ll j = 0; j < temp; j++)
            graph[ingr[j]].emplace_back(make_pair(ed, entry[ed].size()));
        entry[ed].emplace_back(temp);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> ok(n + 1, false);

    function<void(ll)> bfs = [&](ll st) -> void {
        if (visited[st])
            return;

        queue<ll> q;
        q.emplace(st);
        visited[st] = true;

        while (!q.empty()) {
            ll cur = q.front();
            q.pop();

            ok[cur] = true;

            for (auto [next, index]: graph[cur]) {
                entry[next][index]--;
                if (entry[next][index] == 0 && !visited[next]) {
                    q.emplace(next);
                    visited[next] = true;
                }
            }
        }
    };

    ll x, t1; cin >> x;
    for (ll i = 0; i < x; i++) {
        cin >> t1;
        for (ll j = 0; j < entry[t1].size(); j++)
            entry[t1][j] = 0;
        bfs(t1);
    }

    vector<ll> ans;
    for (ll i = 1; i <= n; i++) {
        if (ok[i])
            ans.emplace_back(i);
    }

    cout << ans.size() << endl;
    if (!ans.empty()) {
        for (auto ele: ans)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}