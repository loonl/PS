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
    ll t1;
    vector<vector<ll>> vec(20, vector<ll>(20, 0));
    for (ll i = 1; i <= 19; i++) {
        for (ll j = 1; j <= 19; j++) {
            cin >> t1;
            if (t1 == 1)
                vec[i][j] = t1;
            else if (t1 == 2)
                vec[i][j] = -t1;
            else
                vec[i][j] = 0;
        }
    }

    ll val = 0, ansR, ansC;
    function<void(ll, ll, ll, bool, bool)> check = [&](ll curR, ll curC, ll dir, bool isWhite, bool isFirst) -> void {
        if (curR < 1 || curC < 1 || curR > 19 || curC > 19 || val > 6)
            return;

        auto cur = vec[curR][curC];

        if (isWhite) {
            if (cur == -2)
                val++;
            else
                return;
        }
        else {
            if (cur == 1)
                val++;
            else
                return;
        }

        ll nextR = curR, nextC = curC;
        switch (dir) {
            case 1:
                nextR--, nextC--;
                break;
            case 2:
                nextR--;
                break;
            case 3:
                nextR--, nextC++;
                break;
            case 4:
                nextC--;
                break;
            case 5:
                nextC++;
                break;
            case 6:
                nextR++, nextC--;
                break;
            case 7:
                nextR++;
                break;
            case 8:
                nextR++, nextC++;
                break;
        }

        if (val == 5) {
            switch (dir) {
                case 1:
                case 2:
                    ansR = curR, ansC = curC;
                    break;
                case 3:
                    ansR = curR + 4, ansC = curC - 4;
                    break;
                case 4:
                    ansR = curR, ansC = curC;
                    break;
                case 5:
                    ansR = curR, ansC = curC - 4;
                    break;
                case 6:
                    ansR = curR, ansC = curC;
                    break;
                case 7:
                    ansR = curR - 4, ansC = curC;
                    break;
                case 8:
                    ansR = curR - 4, ansC = curC - 4;
                    break;
            }
        }

        check(nextR, nextC, dir, isWhite, false);
        if (isFirst) {
            if (dir == 5)
                check(curR, curC - 1, 4, isWhite, false);
            else if (dir == 6)
                check(curR - 1, curC + 1, 3, isWhite, false);
            else if (dir == 7)
                check(curR - 1, curC, 2, isWhite, false);
            else if (dir == 8)
                check(curR - 1, curC - 1, 1, isWhite, false);
        }
    };

    for (ll i = 1; i <= 19; i++) {
        for (ll j = 1; j <= 19; j++) {
            if (vec[i][j] == 1) { // black
                for (ll k = 5; k <= 8; k++) {
                    val = 0;
                    check(i, j, k, false, true);
                    if (val == 5) {
                        cout << 1 << endl;
                        cout << ansR << " " << ansC << endl;
                        exit(0);
                    }
                }
            }
            else if (vec[i][j] == -2) {
                for (ll k = 5; k <= 8; k++) {
                    val = 0;
                    check(i, j, k, true, true);
                    if (val == 5) {
                        cout << 2 << endl;
                        cout << ansR << " " << ansC << endl;
                        exit(0);
                    }
                }
            }
        }
    }

    cout << 0 << endl;
    return 0;
}