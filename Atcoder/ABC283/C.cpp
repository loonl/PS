#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
typedef long double ld;
typedef double d;
ll MAX = 1e+17;
ll MOD = 1e9+7;

int main() {
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE
    string str; cin >> str;
    ll ans = 0;
    string temp = "";
    for (ll i = 0; i < str.length(); i++) {
        temp.push_back(str[i]);
        if (temp == "0")
            continue;
        else if (temp.length() == 1 && temp != "0") {
            ans++;
            temp = "";
        }
        else if (temp.length() == 2 && temp == "00") {
            ans++;
            temp = "";
        }
        else if (temp.length() == 2 && temp != "00") {
            ans += 2;
            temp = "";
        }
    }
    if (temp == "0")
        ans++;

    cout << ans << endl;
    return 0;
}