#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int a[1001]; int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        a[i] = tmp;
    }
    int hap[1001];

    hap[1] = a[1];
    if (a[2] / 2 < a[1])
        hap[2] = a[1] * 2;
    else
        hap[2] = a[2];

    for (int i = 3; i <= n; i++) {
        int val = INT_MIN;
        for (int j = 1; j < i; j++) {
            if (val < hap[j] + a[i - j])
                val = hap[j] + a[i - j];
        }
        hap[i] = max(val, a[i]);
    }

    cout << hap[n] << endl;
    return 0;
}