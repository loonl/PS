#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    ll t1, t2;
    vector<bool> visited(n + 1, false);
    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    for (ll i = 1; i <= n; i++)
        dp[i][1] = 1;

    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
    }

    function<void(ll)> dfsdp = [&](ll cur) -> void {
        visited[cur] = true;

        for (auto next : graph[cur]) {
            if (!visited[next]) {
                dfsdp(next);
                dp[cur][0] += dp[next][1];
                dp[cur][1] += min(dp[next][0], dp[next][1]);
            }
        }
    };

    dfsdp(1);
    cout << min(dp[1][0], dp[1][1]) << endl;

    return 0;
}
