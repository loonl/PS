#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
#define T tuple<int64_t, int64_t, int64_t>
using namespace std;
typedef int64_t ll;
typedef __int128_t lll;
ll MAX = 1e+17;

int main()
{
    FASTI;
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
#endif // ONLINE_JUDGE

    ll n; cin >> n; ll act = 0;
    while (n != 0) {
        string num = to_string(n);
        ll flag = -1;
        act++;

        for (ll i = 0; i < num.length(); i++) {
            if (num[i] == '1') {
                flag = i;
                break;
            }
        }

        if (flag != -1) {
            num = num.substr(0, flag) + num.substr(flag + 1, num.length() - flag - 1);
            if (num != "")
                n = stoll(num);
            else
                n = 0;
        }
        else
            n--;
    }
    cout << act << endl;
    return 0;
}
