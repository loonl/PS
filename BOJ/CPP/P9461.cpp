#include <iostream>
using namespace std;


int main()
{
    int n; cin >> n;
    unsigned long long a[110];
    a[0] = 1; a[1] = 1; a[2] = 1;
    a[3] = 2; a[4] = 2;
    for (int i = 5; i < 101; i++) {
        a[i] = a[i - 5] + a[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;

        if (tmp <= 5) {
            cout << a[tmp - 1] << endl;
            continue;
        }

        cout << a[tmp - 1] << endl;
    }
    return 0;
}