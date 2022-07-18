#include <iostream>
#include <deque>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    deque<int> dq;
    while (tc--)
    {
        string str; cin >> str;
        int val;
        if (str == "push_back")
        {
            cin >> val;
            dq.push_back(val);
        }

        else if (str == "push_front")
        {
            cin >> val;
            dq.push_front(val);
        }

        else if (str == "front")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
                cout << dq.front() << endl;
        }

        else if (str == "back")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
                cout << dq.back() << endl;
        }

        else if (str == "size")
        {
            cout << dq.size() << endl;
        }

        else if (str == "empty")
        {
            if (dq.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }

        else if (str == "pop_front")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }

        else if (str == "pop_back")
        {
            if (dq.empty())
                cout << -1 << endl;
            else
            {
                cout << dq.back() << endl;
                dq.pop_back();
            }
        }
    }

    return 0;
}