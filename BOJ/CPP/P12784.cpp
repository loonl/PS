#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> P;

int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    ll tc; cin >> tc;
    while (tc--) {
        ll n, m; cin >> n >> m; ll t1, t2, t3;
        vector<vector<P>> graph(n + 1, vector<P>());
        vector<ll> dp(n + 1, 0);
        for (ll i = 0; i < m; i++) {
            cin >> t1 >> t2 >> t3;
            graph[t1].emplace_back(make_pair(t2, t3));
            graph[t2].emplace_back(make_pair(t1, t3));
        }
        
        vector<bool> visited(n + 1, false);
        function<void(ll)> dfsdp = [&](ll cur) -> void {
            visited[cur] = true;
            
            for (ll i = 0; i < graph[cur].size(); i++) {
                auto [next, next$] = graph[cur][i];
                if (!visited[next]) {
                    dfsdp(next);
                    if (dp[next] != 0)
                        dp[cur] += min(next$, dp[next]);
                    else
                        dp[cur] += next$;
                }
            }
        };
        
        dfsdp(1);
        cout << dp[1] << endl;
    }
    return 0;
}