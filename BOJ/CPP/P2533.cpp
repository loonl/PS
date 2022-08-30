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

    ll n; cin >> n;
    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<bool> visited(n + 1, false);
    vector<vector<ll>> dp(n + 1, vector<ll>(2)); // 0 = 일반, 1 = E.A
    for (ll i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }

    ll t1, t2;
    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
    }

    function<void(ll)> dfs = [&](ll cur) -> void {
        visited[cur] = true;

        for (auto& next : graph[cur]) {
            if (!visited[next]) {
                dfs(next);
                dp[cur][0] += dp[next][1];
                dp[cur][1] += min(dp[next][0], dp[next][1]);
            }
        }
    };

    dfs(1);

    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}
