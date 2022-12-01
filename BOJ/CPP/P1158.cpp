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

    ll n, k; cin >> n >> k;
    vector<pair<ll, bool>> vec;
    for (ll i = 1; i <= n; i++) {
        if (i != n)
            vec.emplace_back(make_pair(i, true));
        else
            vec.emplace_back(make_pair(i, true));
    }

    vector<ll> ans; ll acc = 0, ptr = -1;
    while (ans.size() < n - 1) {
        ptr++;
        if (ptr >= vec.size())
            ptr = 0;

        if (!vec[ptr].second)
            continue;

        acc++;

        if (acc == k) {
            acc = 0;
            ans.emplace_back(vec[ptr].first);
            vec[ptr].second = false;
        }
    }
    
    for (ll i = 0; i < vec.size(); i++) {
        if (vec[i].second)
            ans.emplace_back(vec[i].first);
    }

    cout << "<";
    for (ll i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << ", ";
    cout << *ans.rbegin() << ">" << endl;

    return 0;
}
