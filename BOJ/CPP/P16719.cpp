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
string str;
vector<bool> used;
void recur(ll l, ll r) {
    ll cur = -1;
    char x = '[';
    for (ll i = l; i <= r; i++) {
        if (!used[i] && x > str[i]) {
            x = str[i];
            cur = i;
        }
    }

    if (cur == -1)
        return;

    used[cur] = true;
    for (ll i = 0; i < str.length(); i++) {
        if (used[i])
            cout << str[i];
    }
    cout << endl;

    recur(cur + 1, r);
    recur(l, cur - 1);
}

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    cin >> str;
    used.assign(str.length(), false);
    recur(0, str.length() - 1);

    return 0;
}