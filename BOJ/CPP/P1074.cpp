#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef unsigned long long ull;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, r, c; cin >> n >> r >> c;
    ll num = 0;
    function<ll(ll, ll, ll)> dnc = [&](ll curR, ll curC, ll pivot) -> ll {

        if (pivot == 1) {
            if (curR == 0 && curC == 0)
                return 0;
            else if (curR == 0 && curC == 1)
                return 1;
            else if (curR == 1 && curC == 0)
                return 2;
            else
                return 3;
        }

        ll piv = pivot * pivot;
        ll quoR = curR / pivot, quoC = curC / pivot;
        ll remR = curR % pivot, remC = curC % pivot;
        if (quoR == 0 && quoC == 0)
            return dnc(remR, remC, pivot / 2);
        else if (quoR == 0 && quoC == 1)
            return piv + dnc(remR, remC, pivot / 2);
        else if (quoR == 1 && quoC == 0)
            return piv * 2 + dnc(remR, remC, pivot / 2);
        else if (quoR == 1 && quoC == 1)
            return piv * 3 + dnc(remR, remC, pivot / 2);
    };

    cout << dnc(r, c, pow(2, n) / 2) << endl;
    return 0;
}
