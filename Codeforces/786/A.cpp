#include <iostream>
#include <vector>
#define end '\n'
using namespace std;

int sq(int x, int n)
{
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp *= x;
    }
    return temp;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    int x, y, a, b;
    while (tc--)
    {
        cin >> x >> y;
        if (x > y || y % x != 0)
        {
            cout << 0 << " " << 0 << endl;
            continue;
        }

        if (x == y)
        {
            cout << 1 << " " << 1 << endl;
            continue;
        }

        int temp = y / x;

        vector<int> sosus = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

        for (int i = 2; i <= 100; i++)
        {
            int w;
            if (i == 2)
                w = sosus.size();
            else
                w = 7;
            for (int j = 0; j < w; j++)
            {
                if (sq(i, j) == temp)
                {
                    a = j;
                    b = i;
                    goto breakloop;
                }
            }
        }

    breakloop:
        cout << a << " " << b << endl;
    }
    return 0;
}