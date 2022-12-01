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
ll MOD = 1e+9 + 7;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n;
    vector<ll> vec(n + 1, 0);
    for (ll i = 1; i <= n; i++)
        cin >> vec[i];

    ll ppl; cin >> ppl;
    ll t1, t2;
    vector<P> person;
    for (ll i = 1; i <= ppl; i++) {
        cin >> t1 >> t2;
        person.emplace_back(make_pair(t1, t2));
    }

    for (auto [gender, num]: person) {
        if (gender == 1) {
            for (ll i = num; i <= n; i += num) {
                if (vec[i] == 1)
                    vec[i] = 0;
                else
                    vec[i] = 1;
            }
        }
        else {
            ll left = num - 1, right = num + 1;
            if (vec[num] == 1)
                vec[num] = 0;
            else
                vec[num] = 1;

            while (left > 0 && right < n + 1) {
                if (vec[left] != vec[right])
                    break;

                if (vec[left] == 1)
                    vec[left] = 0;
                else
                    vec[left] = 1;

                if (vec[right] == 1)
                    vec[right] = 0;
                else
                    vec[right] = 1;

                left--;
                right++;
            }
        }
    }
    for (ll i = 1; i <= n; i++) {
        cout << vec[i] << " ";
        if (i % 20 == 0)
            cout << endl;
    }
    return 0;
}