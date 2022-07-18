#include <iostream>
#include <stack>
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
        stack<char> st;
        cin >> str;
        int cnt_open = 0;
        int cnt_close = 0;
        for (int i = 0; i < str.length(); i++)
        {
            char tmp = str[i];
            if (tmp == '(')
                cnt_open++;
            if (tmp == ')')
                cnt_close++;
            st.emplace(tmp);
        }

        if (cnt_open != cnt_close)
        {
            cout << "NO" << endl;
            continue;
        }

        bool no = false;
        cnt_open = 0; cnt_close = 0;
        while (!st.empty())
        {
            char tmp = st.top();
            st.pop();
            if (tmp == '(')
                cnt_open++;
            else if (tmp == ')')
                cnt_close++;
            if (cnt_open > cnt_close)
            {
                no = true;
                break;
            }
        }

        if (no)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}