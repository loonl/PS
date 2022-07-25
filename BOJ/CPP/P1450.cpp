#include <bits/stdc++.h>
#define FASTIO cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    ll n, c; cin >> n >> c;
    vector<ll> vec(n);
    vector<ll> A, B;
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }

    A.clear(); B.clear();

    function<void(ll, ll, ll)> combineA = [&](ll left, ll right, ll sum) -> void {
        if (left > right) {
            A.emplace_back(sum);
            return;
        }

        combineA(left + 1, right, sum);
        combineA(left + 1, right, sum + vec[left]);
    };

    function<void(ll, ll, ll)> combineB = [&](ll left, ll right, ll sum) -> void {
        if (left > right) {
            B.emplace_back(sum);
            return;
        }

        combineB(left + 1, right, sum);
        combineB(left + 1, right, sum + vec[left]);
    };

    combineA(0, n / 2, 0);
    combineB((n / 2) + 1, n - 1, 0);

    sort(B.begin(), B.end());
    ll cnt = 0;

    for (ll i = 0; i < A.size(); i++) {
        cnt += upper_bound(B.begin(), B.end(), c - A[i]) - B.begin();
    }

    cout << cnt << endl;
    return 0;
}
