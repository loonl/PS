#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[1001]; int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a[i] = temp;
    }

    int len[1001] = {0,};
    len[1] = 1; 
    if (a[1] > a[2]) { len[2] = 2; } else { len[2] = 1; }
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[j] > a[i] && len[i] <= len[j])
                len[i] = len[j] + 1;
        }
        if (len[i] == 0)
            len[i] = 1;
    }
    
    int max = 0;
    for (int i = 1; i <= n; i++) {
        if (max < len[i])
            max = len[i];
    }

    cout << max << endl;
    return 0;
}