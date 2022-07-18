#include <iostream>
#include <stack>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    string str;
    while (true)
    {
        getline(cin, str);
        if (str == ".")
            break;

        stack<char> st;
        for (int i = 0; i < str.length(); i++)
        {
            char tmp = str[i];
            if (tmp == '(' || tmp == ')' || tmp == '[' || tmp == ']')
                st.push(tmp);
        }

        bool no = false;
        int cnt_open = 0; int cnt_close = 0;
        int cnt_bigopen = 0; int cnt_bigclose = 0;

        stack<char> closed;
        while (!st.empty())
        {
            char tmp = st.top();
            st.pop();

            if (tmp == '(')
            {
                cnt_open++;

                if (closed.empty() || closed.top() != ')')
                {
                    no = true;
                    break;
                }

                closed.pop();
            }
            else if (tmp == '[')
            {
                cnt_bigopen++;

                if (closed.empty() || closed.top() != ']')
                {
                    no = true;
                    break;
                }

                closed.pop();
            }
            else if (tmp == ')')
            {
                cnt_close++;
                closed.push(tmp);
            }
            else if (tmp == ']')
            {
                cnt_bigclose++;
                closed.push(tmp);
            }

            if (cnt_open > cnt_close || cnt_bigopen > cnt_bigclose)
            {
                no = true;
                break;
            }
        }
        if (!closed.empty())
            no = true;

        if (no)
        {
            cout << "no" << endl;
        }
        else
        {
            cout << "yes" << endl;
        }
    }
    return 0;
}