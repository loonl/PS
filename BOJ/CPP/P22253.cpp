#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);
ll MOD = 1e9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDG

    ll n, t1, t2; cin >> n;
    vector<ll> nums(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> nums[i];

    vector<vector<ll>> graph(n + 1, vector<ll>());
    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
    }

    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }

    vector<bool> visited(n + 1, false);
    vector<ll> parent(n + 1, -1);

    function<void(ll, ll)> dfs = [&](ll prev, ll cur) -> void {
        visited[cur] = true;
        if (prev != -1)
            parent[cur] = prev;

        for (auto next: graph[cur]) {
            if (!visited[next])
                dfs(cur, next);
        }
    };

    dfs(-1, 1);
    graph.clear();
    graph.assign(n + 1, vector<ll>());
    for (ll i = 2; i <= n; i++)
        graph[parent[i]].emplace_back(i);

    vector<vector<ll>> dp(n + 1, vector<ll>(10, -1));
    function<ll(ll, ll)> dfsdp = [&](ll cur, ll num) -> ll {
        ll& val = dp[cur][num];
        if (val != -1)
            return val;

        val = 0;
        if (nums[cur] == num)
            val++;

        for (auto next: graph[cur]) {
            val += dfsdp(next, num);
            val %= MOD;
            if (nums[cur] == num) {
                for (ll i = num; i < 10; i++) {
                    val += dfsdp(next, i);
                    val %= MOD;
                }
            }
        }

        return val % MOD;
    };

    ll ans = 0;
    for (ll i = 0; i < 10; i++) {
        ans += dfsdp(1, i);
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
