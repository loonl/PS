#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, t1;
    while (cin >> n) {
        vector<ll> vec;
        for (ll i = 0; i < n; i++) {
            cin >> t1;
            auto found = lower_bound (vec.begin (), vec.end (), t1);
            if (found == vec.end())
                vec.emplace_back (t1);
            else
                *found = t1;
        }

        cout << vec.size() << endl;
    }
    return 0;
}
