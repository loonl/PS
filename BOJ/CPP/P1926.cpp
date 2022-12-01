#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, m; cin >> n >> m;
    vector<vector<ll>> vec(n, vector<ll>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc = {0, -1, 1, 0};


    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cin >> vec[i][j];
    }

    function<ll(ll, ll)> bfs = [&](ll stR, ll stC) -> ll {
        queue<P> q;
        q.emplace(make_pair(stR, stC));
        visited[stR][stC] = true;
        ll cnt = 0;
        while (!q.empty()) {
            auto [curR, curC] = q.front();
            auto cur = vec[curR][curC];
            q.pop();

            cnt++;

            for (ll i = 0; i < 4; i++) {
                auto nextR = curR + dr[i], nextC = curC + dc[i];

                if (!(nextR < 0 || nextC < 0 || nextR > n - 1 || nextC > m - 1)) {
                    if (!visited[nextR][nextC] && vec[nextR][nextC] == cur) {
                        visited[nextR][nextC] = true;
                        q.emplace(make_pair(nextR, nextC));
                    }
                }
            }
        }

        return cnt;
    };

    ll ans = 0;
    ll e = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (!visited[i][j] && vec[i][j] == 1) {
                e++;
                ans = max(bfs(i, j), ans);
            }
        }
    }

    cout << e << endl;
    cout << ans << endl;
    return 0;
}
