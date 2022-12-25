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

    double x, y, c; cin >> x >> y >> c;
    cout << fixed; cout.precision(10);
    double low = 1, ans = 0, high = min(x, y);
    while (low + 0.00001 <= high) {
        double w = (low + high) / 2;
        double h1 = sqrt(x * x - w * w);
        double h2 = sqrt(y * y - w * w);
        double tempC = (h1 * h2) / (h1 + h2);
        if (tempC >= c) {
            ans = w;
            low = w;
        }
        else
            high = w;
    }

    cout << ans << endl;
    return 0;
}