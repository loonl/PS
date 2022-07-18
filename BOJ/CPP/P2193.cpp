#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long dp[91][2]; // dp[자릿수][끝의 자리]
    dp[1][0] = 0; dp[1][1] = 1;
    dp[2][0] = 1; dp[2][1] = 0;
    dp[3][0] = 1; dp[3][1] = 1; 
    for (int i = 4; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    cout << dp[n][0] + dp[n][1] << endl;
    return 0;
}