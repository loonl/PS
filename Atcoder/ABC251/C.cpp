#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

bool custom_sort(pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
    if (a.second.first == b.second.first) {
        return a.second.second < b.second.second;
    }
    else
        return a.second.first > b.second.first;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    map<string, pair<int, int>> m; // score, index
    string str; int score;
    for (int i = 0; i < tc; i++) {
        cin >> str >> score;
        auto res = m.find(str);
        if (res == m.end()) {
            m[str] = make_pair(score, i);
        }
    }

    vector<pair<string, pair<int, int>>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), custom_sort);
    cout << vec[0].second.second + 1 << endl;
    return 0;
}