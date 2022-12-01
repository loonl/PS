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

    vector<vector<ll>> vec(10, vector<ll>(10, 0));
    vector<P> blank; char x;
    for (ll i = 1; i <= 9; i++) {
        for (ll j = 1; j <= 9; j++) {
            cin >> x;
            vec[i][j] = x - '0';
        }
    }

    function<void(ll, vector<bool>&)> check_col = [&](ll r, vector<bool>& res) -> void {
        vector<bool> used(10, false);
        for (ll i = 1; i <= 9; i++) {
            auto num = vec[r][i];
            if (num == 0)
                continue;

            if (!used[num])
                used[num] = true;
        }

        for (ll i = 1; i <= 9; i++) {
            if (used[vec[r][i]])
                res[vec[r][i]] = false;
        }
    };

    function<void(ll, vector<bool>&)> check_row = [&](ll c, vector<bool>& res) -> void {
        vector<bool> used(10, false);
        for (ll i = 1; i <= 9; i++) {
            auto num = vec[i][c];
            if (num == 0)
                continue;

            if (!used[num])
                used[num] = true;
        }

        for (ll i = 1; i <= 9; i++) {
            if (used[vec[i][c]])
                res[vec[i][c]] = false;
        }
    };

    function<void(ll, ll, vector<bool>&)> check_sq = [&](ll r, ll c, vector<bool>& res) -> void {
        vector<bool> used(10, false);
        ll Rbase = (r - 1) / 3, Cbase = (c - 1) / 3;
        vector<P> groups = { {Rbase * 3 + 1, Cbase * 3 + 1}, {Rbase * 3 + 1, Cbase * 3 + 2}, {Rbase * 3 + 1, Cbase * 3 + 3},
                             {Rbase * 3 + 2, Cbase * 3 + 1}, {Rbase * 3 + 2, Cbase * 3 + 2}, {Rbase * 3 + 2, Cbase * 3 + 3},
                             {Rbase * 3 + 3, Cbase * 3 + 1}, {Rbase * 3 + 3, Cbase * 3 + 2}, {Rbase * 3 + 3, Cbase * 3 + 3} };

        for (ll i = 0; i < groups.size(); i++) {
            auto [curR, curC] = groups[i];
            auto num = vec[curR][curC];
            if (num == 0)
                continue;

            if (!used[num])
                used[num] = true;
        }

        for (ll i = 0; i < groups.size(); i++) {
            auto [curR, curC] = groups[i];
            auto num = vec[curR][curC];
            if (used[num])
                res[num] = false;
        }
    };

    function<void(ll, ll)> back_track = [&](ll curR, ll curC) -> void {
        if (curC == 10) {
            curR++;
            curC = 1;
        }

        if (curR == 10 && curC == 1) {
            for (ll i = 1; i <= 9; i++) {
                for (ll j = 1; j <= 9; j++)
                    cout << vec[i][j];
                cout << endl;
            }
            exit(0);
        }

        ll orig = vec[curR][curC];
        if (orig == 0) {

            vector<bool> ok(10, true);
            check_col(curR, ok);
            check_row(curC, ok);
            check_sq(curR, curC, ok);
            vector<ll> usable;
            for (ll i = 1; i <= 9; i++) {
                if (ok[i])
                    usable.emplace_back(i);
            }

            if (usable.empty())
                return;

            for (ll i = 0; i < usable.size(); i++) {
                vec[curR][curC] = usable[i];
                back_track(curR, curC + 1);
                vec[curR][curC] = orig;
            }
        }
        else
            back_track(curR, curC + 1);
    };

    back_track(1, 1);
    return 0;
}
