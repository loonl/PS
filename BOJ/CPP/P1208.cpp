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

    ll n, s; cin >> n >> s;
    vector<ll> a, b;
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];

    function<void(ll, ll, ll, ll)> recur = [&](ll left, ll right, ll sum, ll code) -> void {
        if (left > right) {
            if (code == 1)
                a.emplace_back(sum);
            else
                b.emplace_back(sum);
            return;
        }

        recur(left + 1, right, sum, code);
        recur(left + 1, right, sum + vec[left], code);
    };

    recur(0, n / 2, 0, 1);
    recur(n / 2 + 1, n - 1, 0, 2);

    ll ans = 0;
    sort(b.begin(), b.end());

    for (ll i = 0; i < a.size(); i++) {
        auto low = lower_bound(b.begin(), b.end(), s - a[i]);
        auto up = upper_bound(b.begin(), b.end(), s - a[i]);
        ans += up - low;
    }

    if (s == 0)
        ans--;
    cout << ans << endl;
    return 0;
}
