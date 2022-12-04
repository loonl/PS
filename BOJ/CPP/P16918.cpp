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

    ll r, c, t; cin >> r >> c >> t;
    vector<vector<ll>> vec(r + 1, vector<ll>(c + 1, 0));
    char t1;
    for (ll i = 1; i <= r; i++) {
        for (ll j = 1; j <= c; j++) {
            cin >> t1;
            if (t1 == '.')
                vec[i][j] = 0;
            else if (t1 == 'O')
                vec[i][j] = 3;
        }
    }

    if (t <= 1) {
        for (ll i = 1; i <= r; i++) {
            for (ll j = 1; j <= c; j++) {
                if (vec[i][j] == 0)
                    cout << '.';
                else
                    cout << 'O';
            }
            cout << endl;
        }

        exit(0);
    }
    for (ll i = 1; i <= r; i++) {
        for (ll j = 1; j <= c; j++) {
            if (vec[i][j] != 0)
                vec[i][j]--;
        }
    }

    vector<ll> dr = {-1, 0, 0, 1};
    vector<ll> dc = {0, -1, 1, 0};
    for (ll now = 2; now <= t; now++) {
        auto temp = vec;
        queue<P> q;
        for (ll i = 1; i <= r; i++) {
            for (ll j = 1; j <= c; j++) {
                if ((vec[i][j] != 0 && temp[i][j] != 0) || vec[i][j] == 1) {
                    temp[i][j] = vec[i][j] - 1;
                    if (temp[i][j] == 0) {
                        for (ll k = 0; k < 4; k++) {
                            ll nextR = i + dr[k], nextC = j + dc[k];
                            if (nextR >= 1 && nextC >= 1 && nextR <= r && nextC <= c) {
                                temp[nextR][nextC] = 0;
                            }
                        }
                    }
                }
                else if (vec[i][j] != 0 && temp[i][j] == 0)
                    continue;
                else if (vec[i][j] == 0) {
                    if (now % 2 == 0)
                        q.emplace(make_pair(i, j));
                }

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
                    temp[r][c] = 3;
                }
            }
        }
        vec = temp;
    }

    for (ll i = 1; i <= r; i++) {
        for (ll j = 1; j <= c; j++) {
            if (vec[i][j] == 0)
                cout << '.';
            else
                cout << 'O';
        }
        cout << endl;
    }
    return 0;
}