#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
// compile : Ctrl F11 -> Ctrl F10

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    
    ll tc, t1, t2; cin >> tc;
    ll hap = 0, xr = 0;
    while (tc--) {
        cin >> t1;
        if (t1 == 1) {
            cin >> t2;
            hap += t2;
            xr ^= t2;
        }
        else if (t1 == 2) {
            cin >> t2;
            hap -= t2;
            xr ^= t2;
        }
        else if (t1 == 3)
            cout << hap << endl;
        else
            cout << xr << endl;
    }

    return 0;
}
