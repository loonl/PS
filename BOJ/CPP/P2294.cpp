#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
    if (a > b) return b;
    return a;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;

    int coins[101];
    int value[10001];
    int val;
    for (int i = 1; i < k + 1; i++) {
        value[i] = 10001;
    }

    for (int i = 0; i < n; i++) {
        cin >> val;
        coins[i] = val;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] < 0) 
                continue;
            value[i] = min(value[i - coins[j]] + 1, value[i]);
        }
    }

    if (value[k] == 10001)
        cout << -1 << endl;
    else
        cout << value[k] << endl;

    return 0;
}