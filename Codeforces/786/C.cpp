#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define endl '\n'
#define int long long
using namespace std;

bool containsA(string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'a')
            return true;
    }
    return false;
}

int sqr(int x, int n)
{
    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp *= x;
    }
    return temp;
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);

    int tc; cin >> tc;
    while (tc--)
    {
        string a, b; cin >> a >> b;
        int lenb = b.length();
        if (lenb > 1 && containsA(b))
        {
            cout << -1 << endl;
            continue;
        }
        // b = 'a'
        else if (b == "a")
        {
            cout << 1 << endl;
            continue;
        }

        // b not including 'a'
        cout << sqr(2, a.length()) << endl;

    }

    return 0;
}