#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    ll len = 3, s = 0;
    vector<ll> lengths;

    while (n > len) {
        lengths.emplace_back(len);
        s++;
        len = 2 * len + (3 + s);
    }

    lengths.emplace_back(len);

    function<char(ll, ll)> moo = [&](ll cur, ll m) -> char {
        if (cur == 0) {
            if (m == 1)
                return 'm';
            else
                return 'o';
        }

        if (m <= lengths[cur - 1])
            return moo(cur - 1, m);
        else if (lengths[cur - 1] < m && m <= lengths[cur - 1] + 3 + cur) {
            if (m == lengths[cur - 1] + 1)
                return 'm';
            else
                return 'o';
        }
        else
            return moo(cur - 1, m - cur - 3 - lengths[cur - 1]);
    };

    cout << moo(s, n) << endl;
    return 0;
}
