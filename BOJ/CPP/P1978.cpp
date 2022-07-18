#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a; cin >> a; int ans = 0;
    for (int i = 0; i < a; i++) {
        int b; cin >> b; if (b == 1) { continue; } bool sosu = true;
        int c = sqrt(b) + 1;
        for (int j = 2; j < c; j++) {
            if (b % j == 0) { sosu = false; break; }
        }
        if (sosu) { ans++; }
    }
    cout << ans << endl;
    return 0;
}