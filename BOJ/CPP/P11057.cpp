#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[1100][10];
    for (int i = 0; i < 10; i++) {
        a[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            a[i][j] = 0;
            for (int k = 0; k <= j; k++) {
                a[i][j] += a[i - 1][k];
            }
            a[i][j] %= 10007;
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += a[n][i];
    }

    cout << sum % 10007 << endl;
    return 0;
}