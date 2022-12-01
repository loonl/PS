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

    ll styr, stmn, stdy, edyr, edmn, eddy; cin >> styr >> stmn >> stdy >> edyr >> edmn >> eddy;
    if (edyr - styr > 1000 || (edyr - styr == 1000 && (edmn > stmn || (eddy >= stdy && edmn == stmn)))) {
        cout << "gg" << endl;
        exit(0);
    }

    vector<ll> monthsST = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<ll> monthsED = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (styr % 4 == 0 && (!(styr % 100 == 0) || styr % 400 == 0))
        monthsST[2] = 29;
    if (edyr % 4 == 0 && (!(edyr % 100 == 0) || edyr % 400 == 0))
        monthsED[2] = 29;

    ll ans = 0;
    for (ll i = styr + 1; i < edyr; i++) {
        bool isLunar = false;
        if (i % 4 == 0 && (!(i % 100 == 0) || i % 400 == 0))
            isLunar = true;

        if (isLunar)
            ans += 366;
        else
            ans += 365;
    }

    if (styr != edyr) {
        ll start = 0, end = 0;
        for (ll i = 1; i < stmn; i++)
            start += monthsST[i];
        start += stdy;

        ll Sum = 0;
        for (ll i = 1; i <= 12; i++)
            Sum += monthsST[i];

        ans += Sum - start;

        for (ll i = 1; i < edmn; i++)
            end += monthsED[i];

        end += eddy;
        ans += end;
    }
    else {
        ll start = stdy, end = eddy;
        for (ll i = 1; i < stmn; i++)
            start += monthsST[i];

        for (ll i = 1; i < edmn; i++)
            end += monthsED[i];

        ans = end - start;
    }

    cout << "D-" << ans << endl;
    return 0;
}
