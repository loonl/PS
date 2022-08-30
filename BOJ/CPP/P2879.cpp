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
    ll ans = 0;
    vector<ll> vec1(n + 1, 0);
    vector<ll> vec2(n + 1, 0);
    vector<ll> vec3(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec1[i];

    for (ll i = 1; i <= n; i++)
        cin >> vec2[i];

    for (ll i = 1; i <= n; i++)
        vec3[i] = vec1[i] - vec2[i];

    for (ll i = 1; i <= n; i++) {
        if (vec3[i - 1] * vec3[i] > 0 && abs(vec3[i]) > abs(vec3[i - 1]))
            ans += abs(vec3[i] - vec3[i - 1]);
        else if (vec3[i - 1] * vec3[i] > 0 && abs(vec3[i]) <= abs(vec3[i - 1]))
            continue;
        else
            ans += abs(vec3[i]);
    }

    cout << ans << endl;
    return 0;
}
