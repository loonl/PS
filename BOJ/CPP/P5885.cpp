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
    vector<P> vec; ll t1;
    for (ll i = 0; i < n; i++) {
        cin >> t1;
        vec.emplace_back(make_pair(t1, i));
    }

    sort(vec.begin(), vec.end(), greater<>());
    vector<bool> used(n, false);
    auto [pivot, idx] = vec[0];
    used[idx] = true; ll ans = 0, island = 1;
    for (ll i = 1; i < n; i++) {
        if (vec[i].first != pivot) {
            if (island > ans)
                ans = island;
        }

        pivot = vec[i].first, idx = vec[i].second; ll Used = 0;
        if (idx - 1 >= 0) {
            if (used[idx - 1])
                Used++;
        }
        if (idx + 1 < n) {
            if (used[idx + 1])
                Used++;
        }

        used[idx] = true;

        if (Used == 0)
            island++;
        else if (Used == 2)
            island--;
    }

    cout << ans << endl;
    return 0;
}
