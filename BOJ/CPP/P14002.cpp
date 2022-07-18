#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_idx(vector<pair<int, vector<int>>>& vec) {
    int idx = -1; int max_val = INT_MIN;
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].first > max_val) {
            idx = i; max_val = vec[i].first;
        }
    }

    return idx;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<pair<int, vector<int>>> dp;
    for (int i = 0; i <= n; i++) {
        dp.push_back(make_pair(0, vector<int>(0)));
    }
    vector<int> vec(n+1, 1);

    for (int i = 1; i <= n; i++) {
        cin >> vec[i];
    }

    dp[1].first++; dp[1].second.push_back(vec[1]);
    for (int i = 2; i <= n; i++) {
        // 초기 세팅
        dp[i].first = 1;
        dp[i].second.push_back(vec[i]);

        for (int j = 1; j < i; j++) {
            if (vec[i] > vec[j] && dp[i].first <= dp[j].first) {
                dp[i].first = dp[j].first + 1;
                dp[i].second = dp[j].second;
                dp[i].second.push_back(vec[i]);
            }
        }
    }

    int max = max_idx(dp);
    cout << dp[max].first << "\n";
    for (int i = 0; i < dp[max].second.size(); i++) {
        cout << dp[max].second[i] << " ";
    }
    return 0;
}