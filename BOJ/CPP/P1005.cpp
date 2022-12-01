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
        ll n, k; cin >> n >> k;
        vector<ll> time(n + 1, 0);
        vector<ll> entry(n + 1, 0);
        vector<vector<ll>> graph(n + 1, vector<ll>());
        for (ll i = 1; i <= n; i++)
            cin >> time[i];

        ll t1, t2;
        for (ll i = 0; i < k; i++) {
            cin >> t1 >> t2;
            graph[t1].emplace_back(t2);
            entry[t2]++;
        }

        vector<ll> dp(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            dp[i] = time[i];

        ll aim; cin >> aim;

        function<void(ll)> bfs = [&](ll start) -> void {
            queue<ll> q;
            for (ll i = 1; i <= n; i++) {
                if (entry[i] == 0)
                    q.emplace(i);
            }

            while (!q.empty()) {
                auto cur = q.front();
                q.pop();

                if (cur == aim)
                    return;

                for (auto next: graph[cur]) {
                    entry[next]--;
                    dp[next] = max(dp[next], dp[cur] + time[next]);

                    if (entry[next] == 0)
                        q.emplace(next);
                }
            }
        };

        bfs(1);
        cout << dp[aim] << endl;
    }
    return 0;
}
