#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;

int _abs(int x) 
{
    int result = x;
    if (result < 0)
        result = -result;
    return result;
}

struct compare
{
    bool operator()(const int a, const int b)
    {
        if (_abs(a) == _abs(b))
            return a > b;
        return _abs(a) > _abs(b);
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    priority_queue<int, vector<int>, compare> pq;
    int n; cin >> n; int tmp;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (tmp == 0)
        {
            if (pq.empty())
                cout << 0 << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }

        else
        {
            pq.push(tmp);
        }
    }
    return 0;
}