#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    long long dp[1001][2]; // 0 = 증가, 1 = 감소
    int input[1001];

    for (int i = 1; i <= n; i++) {
        cin >> input[i];
    }

    dp[1][0] = 1; dp[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        // 초기화
        dp[i][0] = 1; dp[i][1] = 1;
        for (int j = 1; j < i; j++) {
            if (input[j] < input[i] and dp[j][0] >= dp[i][0])
                dp[i][0] = dp[j][0] + 1;
            if (input[j] > input[i] and dp[j][0] >= dp[i][1])
                dp[i][1] = dp[j][0] + 1;
            if (input[j] > input[i] and dp[j][1] >= dp[i][1])
                dp[i][1] = dp[j][1] + 1;
        }
    }

    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < dp[i][0])
            max = dp[i][0];
        if (max < dp[i][1])
            max = dp[i][1];
    }

    cout << max << endl;
    return 0;
}