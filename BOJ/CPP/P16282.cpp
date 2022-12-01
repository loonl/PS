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

    function<ll(ll, ll)> pow = [&](ll a, ll b) -> ll {
        if (b == 1)
            return a;

        if (b % 2 == 0) {
            auto temp = pow(a, b / 2);
            return temp * temp;
        }
        else {
            auto temp = pow(a, b / 2);
            return temp * temp * a;
        }
    };

    ll n; cin >> n;
    ll pivot = 1;
    while (n > pow(2, pivot + 1) * (pivot + 1) - 1)
        pivot++;

    cout << pivot << endl;

    return 0;
}
