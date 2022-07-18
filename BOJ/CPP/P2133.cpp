#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long dp[31];
    dp[1] = 0;
    dp[2] = 3;
    dp[3] = 0;
    dp[4] = 11;
    for (int i = 5; i <= n; i++) {
        dp[i] = 0;
        if (i % 2 == 1)
            continue;
        for (int j = 2; j <= i - 4; j+= 2) {
            // (4이상의 짝수)x3을 채울 수 있는 가짓수 = 2가지
            dp[i] += dp[j] * 2; 
        }
        // 2x3을 채울 수 있는 가짓수 = 3가지 
        // i자리만이 가질 수 있는 가짓수 = 2가지
        dp[i] += dp[i - 2] * 3 + 2;
    }
    cout << dp[n] << endl;
    return 0;
}