#include <iostream>
#include <vector>
#include <queue>
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;
    int x; cin >> x; int tmp;
    for (int n = 0; n < x; n++)
    {
        cin >> tmp;
        if (min_heap.size() == max_heap.size())
            max_heap.push(tmp);
        else
            min_heap.push(tmp);

        if (!max_heap.empty() && !min_heap.empty())
        {
            if (max_heap.top() > min_heap.top())
            {
                int tmp1 = max_heap.top(), tmp2 = min_heap.top();
                max_heap.pop(); min_heap.pop();
                max_heap.push(tmp2); min_heap.push(tmp1);
            }
        }
        cout << max_heap.top() << endl;
    }
    return 0;
}