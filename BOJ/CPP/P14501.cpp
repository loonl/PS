#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int time[16]; int profit[16];

    for (int i = 1; i <= n; i++) {
        cin >> time[i] >> profit[i];
    }

    int dp[20];
    for (int i = 1; i <= 20; i++) {
        dp[i] = 0;
    }
    
    dp[1] = 0; 
    if (time[1] <= n + 1)
        dp[time[1] + 1] = profit[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i]);
        if (time[i] + i <= n + 1) {
            dp[time[i] + i] = max(dp[time[i] + i], dp[i] + profit[i]);
        }
    }

    cout << max(dp[n], dp[n+1]) << "\n";
    return 0;
}