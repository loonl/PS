#include <iostream>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, a, b; cin >> n >> a >> b;
    for (int r = 0; r < a * n; r++)
    {
        int judge1 = (r / a) % 2; // 1
        for (int c = 0; c < b * n; c++)
        {
            int judge2 = (c / b) % 2; // 1
            if ((judge1 + judge2) % 2 == 0)
                cout << ".";
            else
                cout << "#";
        }
        cout << endl;
    }
    return 0;
}