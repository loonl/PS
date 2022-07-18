#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    while (true) {
        int a; cin >> a; int start = a + 1; int end = 2 * a; int cnt = 0;
        if (a == 1) { cout << 1 << "\n"; continue; } else if (a == 0) { break; }
        for (int j = start; j < end; j++) {
            bool sosu = true;
            int root = sqrt(j) + 1;
            for (int k = 2; k < root; k++) {
                if (j % k == 0) { sosu = false; break; }
            }
            if (sosu) { cnt++; }
        }
        cout << cnt << "\n";
    }
    return 0;
}