#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int map[1000][1000];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int dp[1000][1000];
    dp[0][0] = map[0][0];
    for (int i = 1; i < m; i++) {
        dp[0][i] = map[0][i] + dp[0][i - 1];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + map[i][0];
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl;
    return 0;
}