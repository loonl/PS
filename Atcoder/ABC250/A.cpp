#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int h, w, r, c; cin >> h >> w >> r >> c;

    int count = 4;
    if (h == 1)
        count--;
    if (w == 1)
        count--;
    if (r == h || r == 1)
        count--;
    if (c == w || c == 1)
        count--;
    cout << count << endl;
    return 0;
}