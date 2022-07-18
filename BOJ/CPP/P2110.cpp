#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, c; cin >> n >> c;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());

    int start = 1; int end = vec[n - 1] - vec[0];
    int mid; int result = 0;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        int count = 1;
        int last = vec[0];
        for (int i = 0; i < n; i++)
        {
            if (mid <= vec[i] - last)
            {
                count++;
                last = vec[i];
            }
        }

        if (count >= c)
        {
            result = max(result, mid);
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    
    cout << result << endl;
    return 0;
}