#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;

ll min(ll a, ll b)
{
    if (a > b)
        return b;
    return a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str; cin >> str;
    vector<char> vec;
    for (int i = 0; i < str.length(); i++)
    {
        vec.emplace_back(str[i]);
    }
    int sz = vec.size();

    ll dp[3001][2]; //[][0] : capsLock이 꺼진 상태, [][1] : capsLock이 켜진 상태

    // first element set
    if (isupper(vec[0])) // 대문자라면
    {
        dp[0][0] = 2;
        dp[0][1] = 2;
    }
    else
    {
        dp[0][0] = 1;
        dp[0][1] = 2;
    }

    for (int i = 1; i < sz; i++)
    {
        if (isupper(vec[i]))
        {
            dp[i][0] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 1);
        }
        else
        {
            dp[i][0] = min(dp[i - 1][0] + 1, dp[i - 1][1] + 2);
            dp[i][1] = min(dp[i - 1][0] + 2, dp[i - 1][1] + 2);
        }
    }

    cout << min(dp[sz - 1][0], dp[sz - 1][1]);
    return 0;
}