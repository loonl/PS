#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    vector<vector<char>> vec(n + 1, vector<char>(m + 1));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    for (ll i = 1; i <=n; i++) {
        for (ll j = 1; j<=m; j++) {
            cin >> vec[i][j];
            if (vec[i][j] == 'x')
                visited[i][j] = true;
        }
    }

    ll cnt = 0;
    vector<ll> dr = {-1, 0, 1};
    vector<ll> dc = {1, 1, 1};
    function<bool(ll, ll)> dfs = [&](ll curR, ll curC) -> bool {
        if (curC == m) {
            cnt++;
            return true;
        }

        visited[curR][curC] = true;

        for (ll i = 0; i < 3; i++) {
            ll nextR = curR + dr[i], nextC = curC + dc[i];
            if (!(nextR < 1 || nextR > n)) {
               if (!visited[nextR][nextC]) {
                   if (dfs(nextR, nextC))
                       return true;
               }
            }
        }

        return false;
    };

    for (ll i = 1; i <= n; i++) {
        if (!visited[i][1])
            dfs(i, 1);
    }

    cout << cnt << endl;
    return 0;
}
