#include <iostream>
#include <queue>
using namespace std;


int main()
{
    cin.tie(0); cout.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int n; cin >> n;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
                continue;
            }

            cout << pq.top() << "\n";
            pq.pop();
        }
        else if (temp > 0) {
            pq.push(temp);
        }
    }
    return 0;
}