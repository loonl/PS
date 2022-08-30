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

    ll n, centre;
    while (cin >> n >> centre) {
        vector<bool> visited(n + 1, false);
        vector<vector<P>> graph(n + 1, vector<P>());
        vector<ll> dp(n + 1, 0);
        ll t1, t2, t3;
        for (ll i = 0; i < n - 1; i++) {
            cin >> t1 >> t2 >> t3;
            graph[t1].emplace_back(make_pair(t2, t3));
            graph[t2].emplace_back(make_pair(t1, t3));
        }

        function<void(ll)> dfsdp = [&](ll cur) -> void {
            visited[cur] = true;

            for (ll i = 0; i < graph[cur].size(); i++) {
                ll next = graph[cur][i].first, next$ = graph[cur][i].second;

                if (!visited[next]) {
                    dfsdp(next);

                    if (dp[next] != 0)
                        dp[cur] += min(next$, dp[next]);
                    else
                        dp[cur] += next$;
                }
            }
        };

        dfsdp(centre);
        cout << dp[centre] << endl;
    }

    return 0;
}
