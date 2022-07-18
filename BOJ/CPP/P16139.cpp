#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str; cin >> str;
    int len = str.length();
    vector<vector<int>> vec;
    vector<int> temp(26, 0);

    for (int i = 0; i < len; i++)
    {
        temp[(int)str[i] - 97]++;
        vec.push_back(temp);
    }


    int tc; cin >> tc;
    char alpha; int start, end;
    while (tc--)
    {
        cin >> alpha >> start >> end;
        int idx = (int)alpha - 97;
        if (start == 0)
            cout << vec[end][idx] << endl;
        else
            cout << vec[end][idx] - vec[start - 1][idx] << endl;
    }
    return 0;
}