#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str; cin >> str;
    bool minus = false;
    int answer = 0;
    string num = ""; auto len = str.length();
    for (int i = 0; i < len; i++)
    {
        auto x = str[i];
        if (x == '+' || x == '-')
        {
            if (x == '-' && !minus)
            {
                minus = true;
                answer += stoi(num);
                num = "";
                continue;
            }

            if (minus)
            {
                answer -= stoi(num);
                num = "";
            }
            else if (!minus)
            {
                answer += stoi(num);
                num = "";
            }
        }
        else
        {
            num += x;
            if (i == len - 1)
            {
                if (minus)
                    answer -= stoi(num);
                else
                    answer += stoi(num);
            }
        }
    }

    cout << answer << endl;
    return 0;
}