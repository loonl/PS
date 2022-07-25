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
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE
    ll n, m; cin >> n >> m;
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }

    function<ll(ll)> howmany = [&](ll time) -> ll {
        ll ret = 0;
        for (ll i = 0; i < n; i++) {
            ret += time / vec[i];
            if (ret > m)
                break;
        }
        return ret;
    };

    ll start = 1, end = *max_element(vec.begin(), vec.end()) * m, mid;
    while (start <= end) {
        mid = (start + end) / 2;
        ll amount = howmany(mid);
        if (amount < m)
            start = mid + 1;
        else {
            end = mid - 1;
        }
    }

    cout << start << endl;
    return 0;
}
