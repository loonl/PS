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
    cout << fixed;
    cout.precision(9);

    double ax, ay, bx, by, cx, cy, dx, dy, ans = 0; cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    function<double(double, double, double, double)> dist = [&](double x1, double y1, double x2, double y2) -> double {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    double lo = 0, hi = 1;
    while (hi - lo >= 1e-10) {
        double mid1 = lo + (hi - lo) / 3, mid2 = lo + 2 * (hi - lo) / 3;
        double mid1Ax, mid1Ay, mid1Bx, mid1By, dist1;
        mid1Ax = (1 - mid1) * ax + mid1 * bx, mid1Ay = (1 - mid1) * ay + mid1 * by;
        mid1Bx = (1 - mid1) * cx + mid1 * dx, mid1By = (1 - mid1) * cy + mid1 * dy;
        dist1 = dist(mid1Ax, mid1Ay, mid1Bx, mid1By);

        double mid2Ax, mid2Ay, mid2Bx, mid2By, dist2;
        mid2Ax = (1 - mid2) * ax + mid2 * bx, mid2Ay = (1 - mid2) * ay + mid2 * by;
        mid2Bx = (1 - mid2) * cx + mid2 * dx, mid2By = (1 - mid2) * cy + mid2 * dy;
        dist2 = dist(mid2Ax, mid2Ay, mid2Bx, mid2By);

        if (dist1 > dist2)
            lo = mid1;
        else
            hi = mid2;
    }

    double ansAx, ansAy, ansBx, ansBy, dist1;
    ansAx = (1 - lo) * ax + lo * bx, ansAy = (1 - lo) * ay + lo * by;
    ansBx = (1 - lo) * cx + lo * dx, ansBy = (1 - lo) * cy + lo * dy;
    cout << dist(ansAx, ansAy, ansBx, ansBy) << endl;
    return 0;
}