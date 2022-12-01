#include <iostream>
#include <map>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; int temp;
        cin >> n;
        map<int, int> m;
 
        for (int i = 0; i < n; i++) {
            cin >> temp;
            auto found = m.find(temp);
            if (found == m.end()) {
                m[temp] = 1;
            }
            else {
                m[temp]++;
            }
        }
 
        bool no3 = true; int a;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second >= 3) {
                a = it->first;
                no3 = false;
                break;
            }
        }
 
        if (no3) {
            cout << -1 << "\n";
        }
        else {
            cout << a << "\n";
        }
    }
 
    return 0;
}