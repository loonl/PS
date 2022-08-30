#include <bits/stdc++.h>
#define FASTI cin.tie(0)->sync_with_stdio(false)
#define endl "\n"
#define P pair<int64_t, int64_t>
using namespace std;
typedef long long int ll;
typedef __int128_t lll;
ll MAX = pow(10, 17);

int main()
{
    FASTI;
    #ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    #endif // ONLINE_JUDGE

    string str1, str2, str3; cin >> str1 >> str2 >> str3;
    ll len1 = str1.length(), len2 = str2.length(), len3 = str3.length();
    vector<vector<vector<ll>>> dp(len1 + 1, vector<vector<ll>>(len2 + 1, vector<ll>(len3 + 1, 0)));

    for (ll i = 1; i <= len1; i++) {
        for (ll j = 1; j <= len2; j++) {
            for (ll k = 1; k <= len3; k++) {
                if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
            }
        }
    }

    cout << dp[len1][len2][len3] << endl;
    return 0;
}
