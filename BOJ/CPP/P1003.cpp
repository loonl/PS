#include <iostream>
#include <map>
#include <climits>
#include <vector>
using namespace std;
int main()
{
    map<int, pair<int, int>> m; // 값, 0 갯수, 1갯수
    vector<int> vec;
    int n; cin >> n;
    int temp;
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        vec.push_back(temp);
        if (max < temp) {
            max = temp;
        }
    }

    m[0] = make_pair(1, 0);
    m[1] = make_pair(0, 1);
    for (int i = 2; i <= max; i++) {
        int zero1, zero2;
        int one1, one2;
        zero1 = m[i - 1].first;
        zero2 = m[i - 2].first;
        one1 = m[i - 1].second;
        one2 = m[i - 2].second;

        m[i] = make_pair(zero1 + zero2, one1 + one2);
    }

    for (auto it = vec.begin(); it != vec.end(); it++) {
        cout << m[*it].first << " " << m[*it].second << "\n";
    }

    return 0;
}