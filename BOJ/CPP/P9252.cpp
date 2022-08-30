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

    string str1, str2; cin >> str1 >> str2;
    vector<vector<ll>> dp(str1.length() + 1, vector<ll>(str2.length() + 1, 0));
    ll len1 = str1.length(), len2 = str2.length();

    for (ll i = 1; i <= len1; i++) {
        for (ll j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    ll answer = dp[len1][len2];
    if (answer > 0) {
        stack<char> q;
        ll i = len1, j = len2;
        while (i > 0 && j > 0) {
            if (dp[i][j] == dp[i - 1][j])
                i--;
            else if (dp[i][j] == dp[i][j - 1])
                j--;
            else {
                q.emplace(str1[i - 1]);
                i--;
                j--;
            }
        }

        cout << answer << endl;
        while (!q.empty()) {
            cout << q.top();
            q.pop();
        }
    }
    else
        cout << answer << endl;
    return 0;
}
