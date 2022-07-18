#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


typedef map<int, int>::iterator map_iterator;
map<int, int> ma;
int k;

// < 검색키값, result>
// result ==>>  0 => 정상처리, 1 => 2개 이상, 2 => 없음
pair<map_iterator, int> search_(int key) {
    auto iter = ma.lower_bound(key);
    if (iter == ma.begin()) {
        if (iter->first - key > k)
            return make_pair(iter, 2);
        return make_pair(iter, 0);
    }
    if (iter == ma.end()) {
        auto manual = --iter;
        if (key - manual->first > k)
            return make_pair(ma.end(), 2);
        return make_pair(manual, 0);
    }

    if (iter->first == key)
        return make_pair(iter, 0);

    auto back_iter = iter;
    back_iter--;
    int dif1 = iter->first - key;
    int dif2 = key - back_iter->first;
    if (dif1 == dif2)
        return make_pair(iter, 1);
    if (dif1 > k && dif2 > k)
        return make_pair(iter, 2);
    if (dif1 > dif2)
        return make_pair(back_iter, 0);
    if (dif1 < dif2)
        return make_pair(iter, 0);
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m; cin >> n >> m >> k;
    int key = 0;
    int val = 0;
    for (int i = 0; i < n; i++) {
        cin >> key >> val;
        ma[key] = val;
    }

    // commands
    int command;
    for (int i = 0; i < m; i++) {
        cin >> command;

        // insert new key & value
        if (command == 1) {
            cin >> key >> val;
            ma[key] = val;
        }

        // change value
        else if (command == 2) {
            cin >> key >> val;
            auto result = search_(key);
            auto iter = result.first;
            int code = result.second;
            if (code != 0)
                continue;
            iter->second = val;
        }

        // search key & print value
        else if (command == 3) {
            cin >> key;
            auto result = search_(key);
            auto iter = result.first;
            int code = result.second;
            // print
            if (code == 1) { cout << "?\n"; continue; }
            if (code == 2) { cout << "-1\n"; continue; }
            cout << iter->second << "\n";
        }
    }
    return 0;
}