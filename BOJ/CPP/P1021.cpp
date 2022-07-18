#include <iostream>
#include <deque>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, iwant; cin >> n >> iwant;
    vector<int> wants(n, -1);
    for (int i = 0; i < iwant; i++)
    {
        cin >> wants[i];
    }

    deque<int> dq;
    for (int i = 1; i <= n; i++)
    {
        dq.push_back(i);
    }

    deque<int> dq1, dq2;
    int count = 0;
    for (int i = 0; i < iwant; i++) {
        int want = wants[i];
        dq1 = dq; dq2 = dq;

        // 1트
        if (dq.front() == want)
        {
            dq.pop_front();
            continue;
        }

        int count1 = 0; int count2 = 0;
        while (dq1.front() != want)
        {
            int backup = dq1.front();
            dq1.pop_front();
            dq1.push_back(backup);
            count1++;
        }

        while (dq2.front() != want)
        {
            int backup = dq2.back();
            dq2.pop_back();
            dq2.push_front(backup);
            count2++;
        }

        if (count1 > count2)
        {
            dq = dq2;
            dq.pop_front();
            count += count2;
        }
        else
        {
            dq = dq1;
            dq.pop_front();
            count += count1;
        }
    }

    cout << count << endl;
    return 0;
}