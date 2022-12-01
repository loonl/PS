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

    ll tc; cin >> tc;
    while (tc--) {
        ll n; cin >> n;
        vector<ll> picked(n + 1, 0);
        for (ll i = 1; i <= n; i++)
            cin >> picked[i];

        vector<bool> visited(n + 1, false);
        vector<bool> finished(n + 1, false);

        ll ans = n;
        function<void(map<ll, ll>&, ll, ll)> dfs = [&](map<ll, ll>& mp, ll cur, ll idx) -> void {
            visited[cur] = true;
            mp[cur] = idx;

            if (!visited[picked[cur]])
                dfs(mp, picked[cur], idx + 1);
            else {
                if (mp.contains(picked[cur])) 
                    ans -= mp.size() - mp[picked[cur]] + 1;
                return;
            }
        };

        map<ll, ll> temp;
        for (ll i = 1; i <= n; i++) {
            temp.clear();
            if (!visited[i])
                dfs(temp, i, 1);

            finished[i] = true;
        }

        cout << ans << endl;
    }
    return 0;
}