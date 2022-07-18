#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int, int>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
// compile : Ctrl F11 -> Ctrl F10

bool custom_sort(vector<ll> a, vector<ll> b) {
    return a[4] < b[4];
}

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    ll ans = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
    if (ans < 0)
        return -1;
    else if (ans > 0)
        return 1;
    return 0;
}

bool cross(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    if (make_pair(x1, y1) > make_pair(x2, y2)) {
        swap(x1, x2);
        swap(y1, y2);
    }

    if (make_pair(x3, y3) > make_pair(x4, y4)) {
        swap(x3, x4);
        swap(y3, y4);
    }

    if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
        ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0 &&
        make_pair(x1, y1) <= make_pair(x4, y4) &&
        make_pair(x2, y2) >= make_pair(x3, y3))
            return true;
    return false;
}

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll t1,t2,t3,t4,t5,t6,t7,t8;
    cin >> t1 >> t2 >> t3 >> t4 >> t5 >> t6 >> t7 >> t8;
    if (cross(t1, t2, t3, t4 , t5, t6, t7, t8))
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
