#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, a, b, c; cin >> n >> a >> b >> c;
    ll t1;
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end(), greater<>());
    ll ans = c / a, curCal = c, cur$ = a;
    for (ll i = 0; i < vec.size(); i++) {
        cur$ += b;
        curCal += vec[i];
        ll temp = curCal / cur$;
        if (temp < ans)
            break;

        ans = temp;
    }

    cout << ans << endl;
    return 0;
}
