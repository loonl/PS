#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

int min(int a, int b, int c) {
    return min(min(a, b), c);
}

int min(int a, int b, int c, int d) {
    return (min(min(a, b), min(c, d)));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> dp(2001, 10000);
    int n; cin >> n;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {

        dp[i] = min(i, dp[i], dp[i + 1] + 1, dp[i + 2] + 2);

        for (int j = 2; j <= 2000 / i; j++) {
            dp[j * i] = min(dp[j * i], j + dp[i]);
        }
        //cout << "dp[" << i << "] = " << dp[i] << endl;
    }

    cout << dp[n] << "\n";
    return 0;
}