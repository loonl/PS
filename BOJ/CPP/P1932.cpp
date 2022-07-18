#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

ll max(ll a, ll b) {
    if (a > b)
        return a;
    return b;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout.tie(0);
    
    int n; cin >> n;
    vector<vector<int>> triangle;
    vector<vector<ll>> haps;
    int temp;

    // 1과 2일때는 직접 출력해주고 exit ㄱㄱ
    if (n == 1) {
        cin >> temp;
        cout << temp << endl;
        exit(0);
    }
    if (n == 2) {
        int first, second, third;
        cin >> first >> second >> third;
        cout << max(first + second, first + third) << endl;
        exit(0);
    }

    for (int i = 1; i <= n; i++) {
        vector<int> vec;
        for (int j = 0; j < i; j++) {
            cin >> temp;
            vec.emplace_back(temp);
        }
        triangle.emplace_back(vec);
    }
    // 0,1번 index 줄은 직접 넣어주기
    vector<ll> tmp_vec;
    tmp_vec.push_back(triangle[0][0]);
    haps.push_back(tmp_vec);
    
    vector<ll> second;
    second.push_back(triangle[1][0] + triangle[0][0]);
    second.push_back(triangle[1][1] + triangle[0][0]);
    haps.push_back(second);

    for (int i = 2; i < triangle.size(); i++) { // row
        vector<ll> vec;
        for (int j = 0; j <= i; j++) { // column
            // 첫번째 index
            if (j == 0) {
                vec.push_back(haps[i - 1][0] + triangle[i][0]);
            }

            // 마지막 index
            else if (j == i) {
                vec.push_back(haps[i - 1][j - 1] + triangle[i][j]);
            }

            // 중간 index
            else {
                vec.push_back(max(haps[i - 1][j - 1] + triangle[i][j], haps[i - 1][j] + triangle[i][j]));
            }
        }

        haps.push_back(vec);
    }

    auto fin = haps[haps.size() - 1];
    cout << *max_element(fin.begin(), fin.end()) << endl;
    return 0;
}