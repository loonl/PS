#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        string cmd; cin >> cmd;

        int n; cin >> n;
        deque<int> dq;
        string arr_str; cin >> arr_str;
        arr_str = arr_str.substr(1, arr_str.length() - 2);
        string s = "";
        int len = arr_str.length();
        for (int i = 0; i < len; i++)
        {
            if (isdigit(arr_str[i]))
                s += arr_str[i];
            else
            {
                if (!s.empty())
                {
                    dq.push_back(stoi(s));
                    s = "";
                }
            }

            if (i == len - 1)
                dq.push_back(stoi(s));
        }

        // command line
        bool error = false;
        bool reverse = false;
        int cmd_num = cmd.length();

        for (int i = 0; i < cmd_num; i++)
        {
                char command = cmd[i];
                if (command == 'R')
                    reverse = !reverse;

                else if (command == 'D')
                {
                    if (dq.empty())
                    {
                        error = true;
                        break;
                    }

                    if (reverse)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
        }

        // print
        if (error)
            cout << "error" << endl;
        else
        {
            if (!dq.empty() && !reverse)
            {
                cout << "[";
                for (int i = 0; i < dq.size() - 1; i++)
                {
                    cout << dq[i] << ",";
                }
                cout << dq[dq.size() - 1] << "]" << endl;
            }
            else if (!dq.empty() && reverse)
            {
                cout << "[";
                for (int i = dq.size() - 1; i > 0; i--)
                {
                    cout << dq[i] << ",";
                }
                cout << dq[0] << "]" << endl;
            }
            else
                cout << "[]" << endl;
        }
    }
    return 0;
}