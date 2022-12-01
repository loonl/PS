#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n; ll tileR, tileC; cin >> tileC >> tileR;
    ll size = pow(2, n) + 1;
    tileR = size - tileR;
    vector<vector<ll>> vec(size, vector<ll>(size, 0));
    vector<vector<bool>> visited(size, vector<bool>(size, false));


    vector<ll> dr = {-1, 1, 0, 0};
    vector<ll> dc = {0, 0, -1, 1};
    function<void(ll, ll, ll, ll, ll, ll)> dnc = [&](ll r, ll c, ll mark, ll prev_pattern, ll mark_cnt, ll remain_cnt) -> void {
        if (mark_cnt >= 4) {
            mark_cnt = 1;
            mark++;
        }
        
        visited[r][c] = true;
        vec[r][c] = mark;
        remain_cnt--;
        mark_cnt++;

        if (remain_cnt == 0) {
            for (ll i = 1; i < size; i++) {
                for (ll j = 1; j < size; j++)
                    cout << vec[i][j] << " ";
                cout << endl;
            }
            exit(0);
        }

        if (mark_cnt == 2) {
            for (ll i = 0; i < 4; i++) {
                ll nextR = r + dr[i], nextC = c + dc[i];
                if (!(nextR < 1 || nextC < 1 || nextR > size - 1 || nextC > size - 1)) {
                    if (!visited[nextR][nextC]) {
                        if (i < 2)
                            dnc(nextR, nextC, mark, 0, mark_cnt, remain_cnt);
                        else
                            dnc(nextR, nextC, mark, 1, mark_cnt, remain_cnt);
                    }
                }
            }
        }
        else if (mark_cnt == 3) {
            ll st, ed;
            if (prev_pattern == 0)
                st = 2, ed = 4;
            else
                st = 0, ed = 2;

            for (ll i = st; i < ed; i++) {
                ll nextR = r + dr[i], nextC = c + dc[i];
                if (!(nextR < 1 || nextC < 1 || nextR > size - 1 || nextC > size - 1)) {
                    if (!visited[nextR][nextC])
                        dnc(nextR, nextC, mark, -1, mark_cnt, remain_cnt);
                }
            }
        }
        else {
            for (ll i = 0; i < 4; i++) {
                ll nextR = r + dr[i], nextC = c + dc[i];
                if (!(nextR < 1 || nextC < 1 || nextR > size - 1 || nextC > size - 1)) {
                    if (!visited[nextR][nextC])
                        dnc(nextR, nextC, mark, -1, mark_cnt, remain_cnt);
                }
            }
        }

        // back-track
        visited[r][c] = false;
        vec[r][c] = 0;
    };

    visited[tileR][tileC] = true; vec[tileR][tileC] = -1;
    for (ll i = 0; i < 4; i++) {
        ll nearR = tileR + dr[i], nearC = tileC + dc[i];
        if (!(nearR < 1 || nearC < 1 || nearR > size - 1 || nearC > size - 1))
            dnc(nearR, nearC, 1, -1, 1, pow(size - 1, 2) - 1);
    }

    cout << -1 << endl;
    return 0;
}
