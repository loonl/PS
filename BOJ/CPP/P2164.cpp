#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1)
    {
        q.pop();
        int x = q.front();
        q.pop();
        q.push(x);
    }

    cout << q.front() << endl;
    return 0;
}