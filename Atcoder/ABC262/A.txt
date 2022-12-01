#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    ll y;
    cin >> y;
    if (y % 4 == 3) {
        cout << y + 3 << endl;
    }
    else {
        cout << (y / 4) * 4 + 2 << endl;
    }

    return 0;
}
