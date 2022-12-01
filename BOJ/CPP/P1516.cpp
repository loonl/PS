#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
ll MOD = pow(10, 9) + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, t1; cin >> n;
    vector<ll> entry(n + 1, 0);
    vector<ll> time(n + 1, 0);
    vector<ll> ans(n + 1, 0);
    vector<vector<ll>> graph(n + 1, vector<ll>());
    ll pivot = 1; bool first = true;
    while (cin >> t1) {
        if (t1 == -1) {
            pivot++;
            first = true;
            continue;
        }
        if (first) {
            time[pivot] = t1;
            first = false;
        }
        else {
            graph[t1].emplace_back(pivot);
            entry[pivot]++;
        }
    }

    function<void()> bfs = [&]() -> void {
        queue<ll> q;
        for (ll i = 1; i <= n; i++) {
            if (entry[i] == 0)
                q.emplace(i);
        }

        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            ans[cur] += time[cur];

            for (auto next: graph[cur]) {
                entry[next]--;

                ans[next] = max(ans[next], ans[cur]);

                if (entry[next] == 0)
                    q.emplace (next);
            }
        }
    };

    bfs();

    for (ll i = 1; i <= n; i++)
        cout << ans[i] << endl;
    return 0;
}
