#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        vector<vector<long long>> vec;
        vector<vector<long long>> vec2;
        // 0 = a ... 11 = z
        for (int i = 0; i < 11; i++) {
            vector<long long> temp(11, 0);
            vec.push_back(temp);
            vec2.push_back(temp);
        }

        char A, B; long long a, b;
        for (int i = 0; i < n; i++) {
            cin >> A >> B;
            a = (int)A - 97;
            b = (int)B - 97;
            vec[a][b]++;
            vec2[b][a]++;
        }

        long long count = 0;
        for (int i = 0; i < 11; i++) {
            long long count_one = 0;
            for (int j = 0; j < 11; j++) {
                for (int k = j + 1; k < 11; k++) {
                    count_one += (vec[i][j] * vec[i][k]);
                    count_one += (vec2[i][j] * vec2[i][k]);
                }
            }
            count += count_one;
        }

        cout << count << "\n";
    }

    return 0;
}