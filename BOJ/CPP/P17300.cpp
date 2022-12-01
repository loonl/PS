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
    vector<ll> vec(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> vec[i];
    vector<bool> ok(10, false);
    map<P, ll> code;
    code[make_pair(1, 3)] = 2;
    code[make_pair(1, 7)] = 4;
    code[make_pair(1, 9)] = 5;
    code[make_pair(2, 8)] = 5;
    code[make_pair(3, 1)] = 2;
    code[make_pair(3, 7)] = 5;
    code[make_pair(3, 9)] = 6;
    code[make_pair(4, 6)] = 5;
    code[make_pair(6, 4)] = 5;
    code[make_pair(7, 1)] = 4;
    code[make_pair(7, 3)] = 5;
    code[make_pair(7, 9)] = 8;
    code[make_pair(8, 2)] = 5;
    code[make_pair(9, 1)] = 5;
    code[make_pair(9, 3)] = 6;
    code[make_pair(9, 7)] = 8;

    bool ans = true;
    ll prev = vec[0];
    ok[vec[0]] = true;
    for (ll i = 1; i < vec.size(); i++) {
        ll cur = vec[i];

        if (ok[cur]) {
            ans = false;
            break;
        }

        if (code[make_pair(prev, cur)] != 0) {
            auto ShouldPass = code[make_pair(prev, cur)];
            if (!ok[ShouldPass]) {
                ans = false;
                break;
            }
            else {
                ok[cur] = true;
                prev = cur;
            }
        }
        else {
            ok[cur] = true;
            prev = cur;
        }
    }

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}