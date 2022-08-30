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
    string cmd; ll k;
    ll x = 0;
    ll tc; cin >> tc;
    while (tc--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> k;
            x |= (1 << k);
        }
        else if (cmd == "remove") {
            cin >> k;
            x &= ~(1 << k);
        }
        else if (cmd == "check") {
            cin >> k;
            cout << ((x >> k) & 1) << endl;
        }
        else if (cmd == "toggle") {
            cin >> k;
            x ^= (1 << k);
        }
        else if (cmd == "all")
            x = (1 << 21) - 1;
        else
            x = 0;
    }

    return 0;
}
