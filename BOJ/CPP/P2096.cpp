#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int max(int a, int b, int c) {
    return max(max(a,b),c);
}

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

int min(int a, int b, int c) {
    return min(min(a,b),c);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int dp_min[2][3] = {0,};
    int dp_max[2][3] = {0,};
    int values[100000][3] = {0,};
    
    // 문제 메모리 제한 꼬라지 ㅋㅋ;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> values[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        dp_max[0][i] = values[0][i];
        dp_min[0][i] = values[0][i];
    }

    for (int i = 1; i < n; i++) {
        dp_max[1][0] = max(dp_max[0][0], dp_max[0][1]) + values[i][0];
        dp_max[1][1] = max(dp_max[0][0], dp_max[0][1], dp_max[0][2]) + values[i][1];
        dp_max[1][2] = max(dp_max[0][1], dp_max[0][2]) + values[i][2];

        dp_max[0][0] = dp_max[1][0];
        dp_max[0][1] = dp_max[1][1];
        dp_max[0][2] = dp_max[1][2];
    }

    for (int i = 1; i < n; i++) {
        dp_min[1][0] = min(dp_min[0][0], dp_min[0][1]) + values[i][0];
        dp_min[1][1] = min(dp_min[0][0], dp_min[0][1], dp_min[0][2]) + values[i][1];
        dp_min[1][2] = min(dp_min[0][1], dp_min[0][2]) + values[i][2];

        dp_min[0][0] = dp_min[1][0];
        dp_min[0][1] = dp_min[1][1];
        dp_min[0][2] = dp_min[1][2];
    }
    
    cout << max(dp_max[0][0], dp_max[0][1], dp_max[0][2]) << " " << min(dp_min[0][0], dp_min[0][1], dp_min[0][2]) << "\n";
    return 0;
}