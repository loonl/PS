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

    ll tc; cin >> tc;
    while (tc--)
    {
        ll n; cin >> n;
        if (n < 10) {
            cout << n << endl;
            continue;
        }

        string ans = "";
        ll pivot = 9;
        vector<bool> used(n + 1, false);
        while (n >= 10) {
            ans = to_string(pivot) + ans;

            n -= pivot;
            used[pivot] = true;
            pivot--;
        }

        if (used[n]) {
            while (n - pivot >= 0) {
                ans = to_string(pivot) + ans;

                if (n - pivot == 0)
                    goto print;
                n -= pivot;
                pivot--;
            }

            if (n - pivot < 0)
                ans = to_string(n) + ans;
        }
        else
            ans = to_string(n) + ans;

print:
        cout << ans << endl;
    }
    return 0;
}
