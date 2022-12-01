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

    ll tc = 0;
    while (true) {
        ll t1, t2;
        vector<P> temp;
        set<ll> used;
        tc++;

        while (true) {
            cin >> t1 >> t2;
            if (t1 == 0 && t2 == 0)
                break;
            else if (t1 == -1 && t2 == -1)
                goto fin;

            used.emplace(t1); used.emplace(t2);
            temp.emplace_back(make_pair(t1,t2));
        }
        ll idx = 1;
        vector<vector<ll>> graph(used.size() + 1, vector<ll>());
        map<ll, ll> chihwan;
        for (auto it = used.begin(); it != used.end(); it++) {
            chihwan[*it] = idx;
            idx++;
        }

        for (ll i = 0; i < temp.size(); i++) {
            auto [st, ed] = temp[i];
            graph[chihwan[st]].emplace_back(chihwan[ed]);
        }

        function<bool(ll)> bfs = [&](ll start) -> bool {
            queue<ll> q;
            q.emplace(start);
            vector<bool> visited(graph.size(), false);
            visited[start] = true;

            while (!q.empty()) {
                ll cur = q.front();
                q.pop();
                for (auto next: graph[cur]) {
                    if (!visited[next]) {
                        q.emplace(next);
                        visited[next] = true;
                    }
                    else
                        return false;
                }
            }
            return true;
        };

        ll flag = false;
        vector<ll> In(graph.size(), 0);
        for (ll i = 1; i < In.size(); i++) {
            for (auto num: graph[i])
                In[num]++;
        }
        vector<ll> roots;
        for (ll i = 1; i < In.size(); i++) {
            if (In[i] == 0)
                roots.emplace_back(i);
            else if (In[i] > 1)
                goto print;
        }

        if (roots.size() == 1) {
            if (bfs(roots[0]))
                flag = true;
        }
print:
        if (!flag && used.size() > 0)
            cout << "Case " << tc << " is not a tree." << endl;
        else
            cout << "Case " << tc << " is a tree." << endl;
    }
    fin:
    return 0;
}