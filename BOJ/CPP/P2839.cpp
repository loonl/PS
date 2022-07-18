#include <iostream> 
using namespace std;

int main() {
    int a; cin >> a; int ans = 1;
    int five = a / 5; int remain = a % 5;
    if (a < 3 || a > 5000) { ans = -1; remain = 0; }
    if (remain % 3 == 0) { ans = five + remain / 3; }
    while (remain % 3 != 0) {
        if (five == 0) { ans = -1; break; }
        remain += 5; five--; ans = five + remain / 3;
    }
    cout << ans << endl;
    return 0;
}