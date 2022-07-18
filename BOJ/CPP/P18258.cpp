#include <iostream>
#include <queue>
#include <string>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    queue<int> q;
    int tc; cin >> tc;
    string cmd; int num;
    while (tc--)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> num;
            q.push(num);
        }
        else if (cmd == "front")
        {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << -1 << endl;
        }
        else if (cmd == "back")
        {
            if (!q.empty())
                cout << q.back() << endl;
            else
                cout << -1 << endl;
        }
        else if (cmd == "size")
            cout << q.size() << endl;
        else if (cmd == "empty")
            cout << q.empty() << endl;
        else if (cmd == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << endl;
                q.pop();
            }
            else
            {
                cout << -1 << endl;
            }
        }

    }

    return 0;
}