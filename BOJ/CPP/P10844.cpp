#include <iostream>
#include <vector>
#define w 1000000000
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false); cout.tie(0);
    int n; cin >> n;
    int dp[101][10];
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    dp[1][0] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % w;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][3]) % w;
        dp[i][3] = (dp[i - 1][2] + dp[i - 1][4]) % w;
        dp[i][4] = (dp[i - 1][3] + dp[i - 1][5]) % w;
        dp[i][5] = (dp[i - 1][4] + dp[i - 1][6]) % w;
        dp[i][6] = (dp[i - 1][5] + dp[i - 1][7]) % w;
        dp[i][7] = (dp[i - 1][6] + dp[i - 1][8]) % w;
        dp[i][8] = (dp[i - 1][7] + dp[i - 1][9]) % w;
        dp[i][9] = dp[i - 1][8] % w;
    }

    long long hap = 0;
    for (int i = 0; i < 10; i++) {
        hap += dp[n][i];
    }

    cout << hap % w << endl;
    return 0;
}