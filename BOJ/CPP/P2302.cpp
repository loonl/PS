#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;

    // 걸러주기
    if (n == m || m == n - 1) {
        cout << 1 << endl;
        exit(0);
    }

    vector<int> vec; int fixed;
    for (int i = 0; i < m; i++) {
        cin >> fixed;
        vec.push_back(fixed);
    }
    sort(vec.begin(), vec.end());

    int start, end;
    vector<int> gop;

    // 걸러주기
    if (m == 0) {
        int x[1000];
        x[1] = 1; x[2] = 2;
        for (int i = 3; i <= n; i++) {
            x[i] = x[i - 1] + x[i - 2];
        }
        cout << x[n] << endl;
        exit(0);
    }

    // 시작
    int a[1000];
    a[1] = 1; a[2] = 2;
    for (int i = 3; i < vec[0]; i++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    if (vec[0] <= 2) {
        gop.push_back(1);
    }
    else {
        gop.push_back(a[vec[0] - 1]);
    }

    // 중간
    for (int i = 1; i <= vec.size(); i++) {
        int size;
        if (i == vec.size()) {
            size = n - vec[i - 1];
        }
        else {
            size = vec[i] - vec[i - 1] - 1;
        }
        if (size == 0)
            continue;

        if (size == 1) {
            gop.push_back(1);
            continue;
        }
        else if (size == 2) {
            gop.push_back(2);
            continue;
        }

        int dp[1000];
        dp[1] = 1; dp[2] = 2;
        for (int j = 3; j <= size; j++) {
            dp[j] = dp[j-1] + dp[j-2];
        }
        gop.push_back(dp[size]);
    }



    int ans = 1;
    for (int i = 0; i < gop.size(); i++) {
        ans *= gop[i];
    }

    cout << ans << endl;
    return 0;
}