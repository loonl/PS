#include <iostream>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    string str;
    while (tc--)
    {
        cin >> str;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < 3; i++)
        {
            count1 += stoi(str.substr(i, 1));
        }

        for (int i = 3; i < 6; i++)
        {
            count2 += stoi(str.substr(i, 1));
        }

        if (count1 == count2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}