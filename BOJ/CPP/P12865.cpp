#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    int dp[101][100001];
    int weight[101];
    int value[101];

    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - weight[i] < 0) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout << dp[n][k] << endl;
    return 0;
}