#include <iostream>
#include <climits>
using namespace std;

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int main()
{
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);
    int a[100001];
    int n; cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        a[i] = tmp;
    }

    int hap[100001];
    hap[1] = a[1];
    if (a[1] < 0)
        hap[2] = a[2];
    else
        hap[2] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        hap[i] = max(hap[i - 1] + a[i], a[i]);
    }

    int max_val = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (max_val < hap[i])
            max_val = hap[i];
    }

    cout << max_val << endl;
    return 0;
}