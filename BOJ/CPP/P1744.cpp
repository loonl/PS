#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;

struct compare
{
    bool operator()(const P a, const P b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
};

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ll n; cin >> n;
    ll ans = 0, t1;
    ll up2 = 0, zero = 0;
    priority_queue<ll, vector<ll>, greater<ll>> minuss;
    vector<ll> vec(2001, 0);
    for (ll i = 0; i < n; i++) {
        cin >> t1;
        if (t1 > 1)
            up2++;
        else if (t1 < 0)
            minuss.emplace(t1);
        else if (t1 == 0)
            zero++;
        else // 1
            ans += t1;

        if (t1 != 1 && t1 != 0)
            vec[t1 + 1000]++;
    }

    if (up2 >= 2) {
        ll first = LLONG_MAX, second = LLONG_MAX, ptr = 2000;
        while (ptr >= 1002) {
            if (first == LLONG_MAX) {
                // add things in first
                if (vec[ptr] > 0) {
                    first = ptr - 1000;
                    vec[ptr]--;
                }

                if (vec[ptr] == 0)
                    ptr--;
            }
            else if (second == LLONG_MAX) {
                // add things in second
                if (vec[ptr] > 0) {
                    second = ptr - 1000;
                    vec[ptr]--;
                }

                if (vec[ptr] == 0)
                    ptr--;
            }
            else {
                ans += first * second;
                first = LLONG_MAX, second = LLONG_MAX;
            }
        }

        if (first != LLONG_MAX && second == LLONG_MAX)
            ans += first;
        else if (first != LLONG_MAX && second != LLONG_MAX)
            ans += first * second;
    }

    while (minuss.size() > 1) {
        ll a = minuss.top(); minuss.pop();
        ll b = minuss.top(); minuss.pop();

        vec[a + 1000]--; vec[b + 1000]--;
        ans += a * b;
    }

    while (zero > 0 && !minuss.empty()) {
        ll mix = minuss.top();
        minuss.pop();
        vec[mix + 1000]--;
        zero--;
    }

    for (ll i = 0; i < 2000; i++) {
        if (vec[i] > 0)
            ans += vec[i] * (i - 1000);
    }

    cout << ans << endl;
    return 0;
}
