#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n; cin >> m >> n; bool sosu; int hap = 0; int min = 0;
    for (int i = m; i <= n; i++) {
        sosu = true; if (i == 1) { continue; } 
        int max_ = sqrt(i) + 1;
        for (int j = 2; j < max_; j++) {
            if (i % j == 0) { sosu = false; break; }
        }
        if (sosu) { if (min == 0) { min = i; } hap += i; }
    }
    if (hap != 0) { cout << hap << endl; cout << min << endl; } else { cout << -1 << endl; }
    return 0;
}