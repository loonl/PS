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

    string str; cin >> str;
    string _first = "", _second = "";
    bool first = true;
    vector<ll> digits;
    bool ok = true;
    for (ll i = 0; i < str.length(); i++) {
        auto cur = str[i];
        if (isdigit(cur)) {
            if (first)
                first = false;

            digits.emplace_back(cur - '0');
        }
        else {
            if (first) {
                if (!isupper(cur)) {
                    ok = false;
                    break;
                }
                else
                    _first.push_back(cur);
            }
            else {
                if (!isupper(cur)) {
                    ok = false;
                    break;
                }
                else
                    _second.push_back(cur);
            }
        }
    }

    if (_first.length() != 1 || _second.length() != 1 || digits.size() != 6)
        ok = false;

    if (ok) {
        ll num = 0;
        for (ll i = 0; i < 6; i++)
            num += digits[i] * pow(10, 5 - i);

        if (!(num >= 100000 && num <= 999999))
            ok = false;
    }

    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}