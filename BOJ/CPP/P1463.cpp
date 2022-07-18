#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int main()
{
    int n; cin >> n;
    vector<int> dp(1000000, 0);
    dp[0] = 0; dp[1] = 0; dp[2] = 1; dp[3] = 1;
    if (n <= 3) {
        cout << dp[n] << endl;
        exit(0);
    }

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }

        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}