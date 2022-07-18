#include <iostream>
using namespace std;

int max(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    return c;
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false); cout.tie(0);
    int n; cin >> n;
    int value[10001] = {0,};
    int hap[10001];
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        value[i] = temp;
    }
    if (n == 1) {
        cout << value[1] << endl;
        exit(0);
    }
    if (n == 2) {
        cout << value[1] + value[2] << endl;
        exit(0);
    }
    if (n == 3) {
        cout << max(value[1] + value[2], value[2] + value[3], value[1] + value[3]) << endl;
        exit(0);
    }

    hap[1] = value[1];
    hap[2] = value[1] + value[2];
    hap[3] = max(value[1] + value[2], value[2] + value[3], value[1] + value[3]);

    for (int i = 4; i <= n; i++) {
        hap[i] = max(hap[i - 2] + value[i], hap[i - 3] + value[i - 1] + value[i], hap[i-1]);
    }

    cout << max(hap[n - 2], hap[n - 1], hap[n]) << endl;
    return 0;
}