#include <iostream>
using namespace std;
unsigned long long a[1000001];

int main()
{
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        exit(0);
    }
    if (n == 2) {
        cout << 2 << endl;
        exit(0);
    }

    a[0] = 1; a[1] = 2;
    for (int i = 2; i < n; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % 15746;
    }
    cout << a[n - 1] << endl;
    return 0;
}