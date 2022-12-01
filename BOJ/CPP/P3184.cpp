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
    vector<vector<char>> vec(n + 1, vector<char>(m + 1, 'X'));
    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++)
            cin >> vec[i][j];
    }

    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc= {0, -1, 1, 0};
    function<P(ll, ll)> bfs = [&](ll stR, ll stC) -> P {
        queue<P> q;
        q.emplace(make_pair(stR, stC));
        visited[stR][stC] = true;
        ll sheep = 0, wolf = 0;

        while (!q.empty()) {
            auto [curR, curC] = q.front();
            q.pop();

            switch (vec[curR][curC]) {
                case 'v':
                    wolf++;
                    break;
                case 'o':
                    sheep++;
                    break;
            }

            for (ll i = 0; i < 4; i++) {
                ll nextR = curR + dr[i], nextC = curC + dc[i];
                if (!(nextR < 1 || nextC < 1 || nextR > n || nextC > m)) {
                    if (!visited[nextR][nextC] && vec[nextR][nextC] != '#') {
                        q.emplace(make_pair(nextR, nextC));
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }

        if (sheep > wolf)
            wolf = 0;
        else
            sheep = 0;

        return make_pair(sheep, wolf);
    };

    ll sh = 0, wl = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (vec[i][j] != '#' && !visited[i][j]) {
                auto [tmp1, tmp2] = bfs(i, j);
                sh += tmp1, wl += tmp2;
            }
        }
    }

    cout << sh << " " << wl << endl;
    return 0;
}
