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
    vector<vector<ll>> vec(n + 1, vector<ll>(m + 1, 0));
    vector<vector<ll>> groups(n + 1, vector<ll>(m + 1, 0));
    vector<ll> groupNum(1, -1);
    vector<vector<ll>> ans(n + 1, vector<ll> (m + 1, 0));
    char x;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            cin >> x;
            vec[i][j] = x - '0';
        }
    }

    vector<vector<bool>> visited(n + 1, vector<bool>(m + 1, false));
    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc = {0, -1,1, 0};
    function<ll(ll, ll, ll)> bfs = [&](ll r, ll c, ll numbering) -> ll {
        visited[r][c] = true;
        queue<P> q;
        q.emplace(make_pair(r, c));
        ll value = 0;
        while (!q.empty()) {
            auto [curR, curC] = q.front();
            assert(vec[curR][curC] == 0);
            q.pop();

            value++;
            groups[curR][curC] = numbering;

            for (ll i = 0; i < 4; i++) {
                ll nextR = curR + dr[i], nextC = curC + dc[i];
                if (!(nextR < 1 || nextC < 1 || nextR > n || nextC > m)) {
                    if (vec[nextR][nextC] == 0 && !visited[nextR][nextC]) {
                        visited[nextR][nextC] = true;
                        q.emplace(make_pair(nextR, nextC));
                    }
                }
            }
        }

        return value;
    };

    ll number = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (vec[i][j] == 0 && !visited[i][j]) {
                number++;
                ll temp = bfs(i, j, number);
                groupNum.emplace_back(temp);
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            if (vec[i][j] == 1) {
                set<ll> temp;
                for (ll k = 0; k < 4; k++) {
                    ll nextR = i + dr[k], nextC = j + dc[k];
                    if (!(nextR < 1 || nextC < 1 || nextR > n || nextC > m)) {
                        if (vec[nextR][nextC] == 0)
                            temp.emplace(groups[nextR][nextC]);
                    }
                }

                ll counts = 1;
                for (auto it = temp.begin(); it != temp.end(); it++)
                    counts += groupNum[*it];
                counts %= 10;
                ans[i][j] = counts;
            }
        }
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}
