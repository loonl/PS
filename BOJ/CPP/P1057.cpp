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

    ll n, kjm, ihs; cin >> n >> kjm >> ihs;
    if (n % 2 == 1)
        n++;

    if (kjm % 2 == 1)
        kjm++;
    if (ihs % 2 == 1)
        ihs++;

    ll rd = 0;

    while (1) {
        rd++;

        if (kjm == ihs)
            break;

        n /= 2;
        if (n % 2 == 1)
            n++;

        kjm /= 2;
        ihs /= 2;
        if (kjm % 2 == 1)
            kjm++;
        if (ihs % 2 == 1)
            ihs++;
    }

    cout << rd << endl;
    return 0;
}
