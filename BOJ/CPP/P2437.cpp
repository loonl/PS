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
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    sort(vec.begin(), vec.end());

    ll psum = 0;
    for (ll i = 0; i < n; i++) {
        if (vec[i] >= psum + 2)
            break;
        psum += vec[i];
    }

    cout << psum + 1 << endl;

    return 0;
}
