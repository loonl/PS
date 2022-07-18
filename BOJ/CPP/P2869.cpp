#include <iostream> 
using namespace std;

int main() {
    long long a, b, v; cin >> a >> b >> v;
    long long haru = a - b; long long purpose = v - a; long long ans;
    if (purpose % haru == 0) { ans = purpose / haru + 1; } else { ans = purpose / haru + 2; }
    if (a >= v) { cout << 1 << endl; } else { cout << ans << endl; }
    return 0;
}