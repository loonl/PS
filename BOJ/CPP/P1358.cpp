#include <iostream>
#define endl '\n'
typedef long long ll;
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    ll w, h, x, y, p;
    cin >> w >> h >> x >> y >> p;
    double r = h / 2;
    int cnt = 0;
    for (auto i = 0; i < p; i++)
    {
        ll X, Y;
        cin >> X >> Y;
        ll dist1 = (X - x) * (X - x) + (Y - y - r) * (Y - y - r);
        ll dist2 = (X - x - w) * (X - x - w) + (Y - y - r) * (Y - y - r);
        if (x <= X and X <= x + w and y <= Y and Y <= y + h)
            cnt++;
        else
        {
            if (X < x and dist1 <= r * r)
                cnt++;
            if (X > x + w and dist2 <= r * r)
                cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}

