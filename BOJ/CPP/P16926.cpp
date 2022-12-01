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
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    ll n, m, r; cin >> n >> m >> r;
    vector<vector<ll>> vec(n, vector<ll>(m, 0)), temp(n, vector<ll>(m, 0));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cin >> vec[i][j];
    }

    ll leftClimit, rightClimit, upRlimit, downRlimit, startR, startC;
    function<void(ll, ll, ll, ll, bool)> rotate = [&](ll r, ll c, ll num, ll dir, bool second) -> void {
        if (startR == r && startC == c && second)
            return;

        if (!second)
            second = true;

        ll next = vec[r][c];
        vec[r][c] = num;

        if (r == downRlimit && c == leftClimit)
            dir = 2;
        else if (r == downRlimit && c == rightClimit)
            dir = 3;
        else if (r == upRlimit && c == rightClimit)
            dir = 4;

        ll nextR, nextC;
        if (dir == 1)
            nextR = r + 1, nextC = c;
        else if (dir == 2)
            nextR = r, nextC = c + 1;
        else if (dir == 3)
            nextR = r - 1, nextC = c;
        else if (dir == 4)
            nextR = r, nextC = c - 1;

        rotate(nextR, nextC, next, dir, second);
    };

    while (r--) {
        for (ll i = 0; i < min(n, m) / 2; i++) {
            upRlimit = i;
            downRlimit = n - 1 - i;
            leftClimit = i;
            rightClimit = m - 1 - i;
            startR = i, startC = i;
            rotate(i, i, vec[i][i + 1], 1, false);
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    return 0;
}