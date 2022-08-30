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
    string str; cin >> str;
    vector<vector<ll>> graph(n, vector<ll>());
    ll t1, t2;
    for (ll i = 0; i < n - 1; i++) {
        cin >> t1 >> t2;
        t1--; t2--;
        graph[t1].emplace_back(t2);
        graph[t2].emplace_back(t1);
    }

    string ans = "";

    function<void(ll, ll, ll)> dfs = [&](ll cur, ll prev, ll idx) -> void {
        if (ans.length() == idx)
            ans.push_back(str[cur]);
        else
            ans[idx] = str[cur];


        for (auto next : graph[cur]) {
            if (next == prev)
                continue;

            if (ans.length() == idx || ans[idx + 1] <= str[next]) {
                if (ans[idx + 1] < str[next])
                    ans.resize(idx + 1);
                dfs(next, cur, idx + 1);
            }
        }
    };

    dfs(0, -1, 0);
    cout << ans << endl;
    return 0;
}
