#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        if (n >= 1900)
            cout << "Division 1\n";
        else if (n >= 1600 and n <= 1899)
            cout << "Division 2\n";
        if (n >= 1400 and n <= 1599)
            cout << "Division 3\n";
        if (n <= 1399)
            cout << "Division 4\n";
    }
 
    return 0;
}