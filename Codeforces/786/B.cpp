#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define end '\n'
using namespace std;

int idx(vector<string>& vec, string str)
{
    for (int i = 1; i <= 650; i++)
    {
        if (str == vec[i])
            return i;
    }
    return -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    vector<string> dic(651);
    vector<string> alphas = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

    int index = 1;
    for (int i = 0; i < alphas.size(); i++)
    {
        for (int j = 0; j < alphas.size(); j++)
        {
            if (i == j)
                continue;

            dic[index] = alphas[i] + alphas[j];
            index++;
        }
    }

    int tc; cin >> tc;
    string s;
    while (tc--)
    {
        cin >> s;
        cout << idx(dic, s) << endl;
    }

    return 0;
}