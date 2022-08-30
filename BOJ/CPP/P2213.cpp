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
    vector<ll> cost(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    vector<ll> ans;
    for (ll i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    ll t1, t2;
    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
    }

    function<void (ll)> dfs = [&](ll cur) -> void {
        dp[cur][1] = cost[cur];
        visited[cur] = true;
        for (ll i = 0; i < graph[cur].size(); i++) {
            ll next = graph[cur][i];
            if (visited[next])
                continue;

            dfs(next);
            dp[cur][0] += max(dp[next][0], dp[next][1]);
            dp[cur][1] += dp[next][0];
        }
    };

    function<void (ll, ll)> track = [&](ll cur, ll last) -> void {
        if (dp[cur][1] > dp[cur][0] && !visited[last]) {
            ans.emplace_back(cur);
            visited[cur] = true;
        }

        for (ll i = 0; i < graph[cur].size(); i++) {
            ll next = graph[cur][i];
            if (next == last)
                continue;
            track(next, cur);
        }
    };

    dfs(1);
    visited.assign(n + 1, false);
    track(1, 0);

    sort(ans.begin(), ans.end());

    cout << max(dp[1][0], dp[1][1]) << endl;
    for (auto& ele : ans) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
