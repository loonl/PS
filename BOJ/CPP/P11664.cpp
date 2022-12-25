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
    cout.precision(10);
    function<double(double, double, double, double, double, double)> dist = [&](double x, double y, double z, double dx, double dy, double dz) -> double {
        return sqrt((x - dx) * (x - dx) + (y - dy) * (y - dy) + (z - dz) * (z - dz));
    };

    double x1, x2, y1, y2, z1, z2, ax, ay, az; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> ax >> ay >> az;
    double lo = 0, hi = 1;

    double mid1, mid2;
    while (hi - lo >= 1e-8) {
        double mid1x, mid1y, mid1z, mid2x, mid2y, mid2z, dist1, dist2;
        mid1 = (2 * lo + hi) / 3, mid2 = (lo + 2 * hi) / 3;
        mid1x = x1 * mid1 + x2 * (1 - mid1), mid2x = x1 * mid2 + x2 * (1 - mid2);
        mid1y = y1 * mid1 + y2 * (1 - mid1), mid2y = y1 * mid2 + y2 * (1 - mid2);
        mid1z = z1 * mid1 + z2 * (1 - mid1), mid2z = z1 * mid2 + z2 * (1 - mid2);
        dist1 = dist(ax, ay, az, mid1x, mid1y, mid1z), dist2 = dist(ax, ay, az, mid2x, mid2y, mid2z);
        if (dist1 > dist2)
            lo = mid1;
        else
            hi = mid2;
    }

    double ansx, ansy, ansz;
    ansx = x1 * lo + x2 * (1 - lo);
    ansy = y1 * lo + y2 * (1 - lo);
    ansz = z1 * lo + z2 * (1 - lo);
    cout << dist(ansx, ansy, ansz, ax, ay, az) << endl;
    return 0;
}