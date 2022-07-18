#include <iostream>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int n; cin >> n;
    int a[12]; int tmp;
    a[1] = 1; a[2] = 2; a[3] = 4;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (tmp < 4) {
            cout << a[tmp] << "\n";
            continue;
        }

        for (int j = 4; j <= tmp; j++) {
            a[j] = a[j - 1] + a[j - 2] + a[j-3];
        }
        cout << a[tmp] << "\n";
    }

    return 0;
}