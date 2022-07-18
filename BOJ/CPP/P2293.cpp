#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n, k; cin >> n >> k;
    vector<int> dp(k+1, 0);
    vector<int> coins(n+1,0);
    for (int i = 1; i <= n; i++) {
        cin >> coins[i];
    }
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - coins[i] < 0) { continue; }
            dp[j] += dp[j-coins[i]];
        }
    }
    
    cout << dp[k];
    return 0;
}