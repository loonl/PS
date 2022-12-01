#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    ll tc; cin >> tc;
    while (tc--) {
        ll t1, t2, t3, t4;
        cin >> t1 >> t2 >> t3 >> t4;
        if (t1 == t2 && t2 == t3 && t3 == t4 && t1 == 0) {
            cout << 0 << endl;
        }
        else if (t1 == t2 && t2 == t3 && t3 == t4 && t1 == 1) {
            cout << 2 << endl;
        }
        else
            cout << 1 << endl;
    }
    return 0;
}
