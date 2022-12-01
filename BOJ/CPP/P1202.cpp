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
struct custom {
    bool operator()(ll a, ll b) {
        return a > b;
    }
};

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n, k, t1, t2; cin >> n >> k;
    vector<P> vec;
    vector<ll> bags(k, 0);
    for (ll i = 0; i < n; i++) {
        cin >> t1 >> t2;
        vec.emplace_back(make_pair(t1, t2));
    }

    for (ll i = 0; i < k; i++)
        cin >> bags[i];

    sort(vec.begin(), vec.end());
    sort(bags.begin(), bags.end());
    priority_queue<ll> pq;
    ll idx = 0, ans = 0;
    for (ll i = 0; i < k; i++) {
        while (idx < n && bags[i] >= vec[idx].first) {
            pq.emplace(vec[idx].second);
            idx++;
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << endl;
    return 0;
}