#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll tc; cin >> tc; ll t1;
    while (tc--) {
        cin >> t1;
        for (ll i = 10000000000; i >= 1; i /= 10) {
            if (t1 / i > 0) {
                cout << t1 - i << endl;
                break;
            }
        }
    }
    return 0;
}
