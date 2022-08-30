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

    ll n, m; cin >> n >> m;
    vector<ll> dp(n + 1, 0);
    vector<vector<ll>> graph(n + 1, vector<ll>());
    vector<bool> visited(n + 1, false);
    ll t1, t2;
    for (ll i = 1; i <= n; i++) {
        cin >> t1;
        if (t1 == -1)
            continue;

        graph[t1].emplace_back(i);
    }

    for (ll i = 0; i < m; i++) {
        cin >> t1 >> t2;
        dp[t1] += t2;
    }

    function<void(ll)> dfsdp = [&](ll cur) -> void {
        visited[cur] = true;

        for (auto next: graph[cur]) {
            if (!visited[next]) {
                dp[next] += dp[cur];
                dfsdp(next);
            }
        }
    };

    dfsdp(1);

    for (ll i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << endl;

    return 0;
}
