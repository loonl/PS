#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min(int a, int b)
{
    if (a > b) return b;
    return a;
}

int main()
{
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--)
    {
        int n; cin >> n;
        vector<int> file(n + 1, 0);
        vector<int> psum(n + 1, 0);
        vector<vector<int>> pSum(n + 1, vector<int>(n + 1));
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));

        // input
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> file[i];
            sum += file[i];
            psum[i] = sum;
            dp[i][i] = file[i];
        }

        //pSum 채워주기
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                pSum[i][j] = psum[j] - psum[i - 1];
            }
        }

        // 2개 합까진 넣어주기
        for (int i = 2; i <= n; i++)
        {
            dp[i - 1][i] = file[i - 1] + file[i];
        }

        // DP
        for (int i = 3; i <= n; i++) // length
        {
            for (int j = 1; j <= n + 1 - i; j++) // 시작점
            {
                for (int k = j; k <= j + i - 2; k++) // 나눠지는 부분의 끝점
                {
                    if (k == j)
                        dp[j][j+i-1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + pSum[j+1][j + i - 1]);
                    else if (k == j + i - 2)
                        dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][k] + dp[k + 1][j + i - 1] + pSum[j][j + i - 2]);
                    else
                        dp[j][j + i - 1] = min(dp[j][j+i-1], dp[j][k] + dp[k + 1][j + i - 1] + pSum[j][j + i - 1]);
                }
            }
        }

        cout << dp[1][n] << "\n";
    }
    return 0;
}