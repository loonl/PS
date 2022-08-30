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

    ll n, m, k; cin >> n >> m >> k;
    vector<vector<vector<bool>>> visited(n + 1, vector<vector<bool>>(m + 1, vector<bool>(k + 1 , false)));
    vector<vector<ll>> mp(n + 1, vector<ll>(m + 1, -1));
    char x;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> x;
            mp[i][j] = (ll)x - (ll)'0';
        }
    }

    vector<ll> dr = {-1,1,0,0};
    vector<ll> dc = {0,0,-1,1};

    function <void()> bfs = [&]() -> void {
        queue<tuple<ll, ll, ll, ll>> q;
        q.emplace(make_tuple(1, 1, 0, 0));
        visited[1][1][0] = true;

        while (!q.empty()) {
            auto [curR, curC, curbrokenWall, cur$] = q.front();
            q.pop();

            if (curR == n && curC == m) {
                cout << cur$ + 1 << endl;
                return;
            }

            for (ll i = 0; i < 4; i++) {
                ll nextR = curR + dr[i], nextC = curC + dc[i];

                if (!(nextR < 1 || nextR > n || nextC < 1 || nextC > m)) {
                    if (mp[nextR][nextC] == 1 && curbrokenWall + 1 <= k) {
                        if (!visited[nextR][nextC][curbrokenWall + 1]) {
                            visited[nextR][nextC][curbrokenWall + 1] = true;
                            q.emplace(make_tuple(nextR, nextC, curbrokenWall + 1, cur$ + 1));
                        }
                    }
                    else if (mp[nextR][nextC] == 0 && !visited[nextR][nextC][curbrokenWall]) {
                        visited[nextR][nextC][curbrokenWall] = true;
                        q.emplace(make_tuple(nextR, nextC, curbrokenWall, cur$ +1));
                    }
                }
            }
        }

        cout << -1 << endl;
    };

    bfs();
    return 0;
}
