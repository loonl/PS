#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;
bool custom_sort(P a, P b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, t1; cin >> n; vector<P> vec(n); vector<ll> vec2(n, 0);
    vector<ll> ans;
    for (ll i = 0; i < n; i++) {
        cin >> vec2[i];
        vec[i] = make_pair(vec2[i], i);
    }

    ll limit; cin >> limit;

    sort(vec.begin(), vec.end(), custom_sort);
    vector<bool> ableFirst(n, false);
    for (ll i = 0; i < n; i++) {
        if (limit >= vec2[i])
            ableFirst[i] = true;
    }

    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (ableFirst[i])
            cnt++;
    }

    if (ableFirst[0] && cnt == 1) {
        cout << 0 << endl;
        exit(0);
    }

    if (vec[0].second == 0) {
        ans.emplace_back(vec[1].second);
        limit -= vec[1].first;
    }
    else {
        ans.emplace_back(vec[0].second);
        limit -= vec[0].first;
    }

    while (limit > 0) {
        ans.emplace_back(vec[0].second);
        limit -= vec[0].first;
    }

    if (limit < 0) {
        limit += vec2[*ans.rbegin()];
        ans.pop_back();


        for (ll i = 0; i < ans.size(); i++) {
            ll newLimit = limit + vec2[ans[i]], newOne = ans[i];
            for (ll j = n - 1; j > ans[i]; j--) {
                if (newLimit - vec2[j] >= 0) {
                    newLimit -= vec2[j];
                    newOne = j;
                    break;
                }
            }

            if (ans[i] != newOne) {
                ans[i] = newOne;
                limit = newLimit;
            }
        }
    }

    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i];
    cout << endl;

    return 0;
}
