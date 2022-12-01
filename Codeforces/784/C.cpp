#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int arr[101];

        bool odd_odd = false;
        bool even_odd = false;
        bool yes = true;

        // index = 0
        cin >> arr[1];
        if (arr[1] % 2 == 1)
            odd_odd = true;

        cin >> arr[2];
        if (arr[2] % 2 == 1)
            even_odd = true;

        for (int i = 3; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 3; i <= n; i++) {
            if (i % 2 == 1) {
                if (odd_odd and arr[i] % 2 == 0) {
                    yes = false;
                    break;
                }
                if (not (odd_odd) and arr[i] % 2 == 1) {
                    yes = false;
                    break;
                }
            }
            else {
                if (even_odd and arr[i] % 2 == 0) {
                    yes = false;
                    break;
                }
                if (not (even_odd) and arr[i] % 2 == 1) {
                    yes = false;
                    break;
                }
            }
        }

        if (yes)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}