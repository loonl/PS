#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
ll MAX = 1e+17;
ll MOD = 1e9+7;

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
    ll l = 0, r = vec.size() - 1, ans1, ans2, pivot = MAX;
    while (l < r) {
        ll cur = vec[l] + vec[r];
        if (abs(cur) < pivot) {
            pivot = abs(cur);
            ans1 = l, ans2 = r;
        }
        if (cur < 0)
            l++;
        else
            r--;
    }

    if (vec[ans1] > vec[ans2])
        swap(ans1, ans2);

    cout << vec[ans1] << " " << vec[ans2] << endl;
    return 0;
}