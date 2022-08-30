#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n; cin >> n;
    if (n < 5)
        cout << n << endl;
    else {
        ll ans = 1;
        while (n >= 5) {
            n -= 3;
            ans *= 3;
            ans %= 10007;
        }

        cout << (ans * n) % 10007 << endl;
    }
    return 0;
}
