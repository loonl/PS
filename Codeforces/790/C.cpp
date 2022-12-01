#include <iostream>
#include <string>
#include <climits>
#include <vector>
#define endl '\n'
using namespace std;
int makeplus(int a)
{
    int num;
    if (a < 0)
        num = -a;
    else
        num = a;
    return num;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        int n, len; cin >> n >> len;
        vector<string> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        int min = INT_MAX;
        for (int i = 0; i < n; i++) // strings that will be a standard
        {
            string standard = vec[i];

            for (int j = i + 1; j < n; j++) // strings to compare
            {
                int sum = 0;
                string cmpstr = vec[j];
                if (i == j)
                    continue;
                for (int k = 0; k < len; k++) // make count
                {
                    char ch1, ch2;
                    ch1 = cmpstr[k]; ch2 = standard[k];
                    sum += makeplus((int)ch1 - (int)ch2);
                }

                if (min > sum)
                    min = sum;
            }
        }

        cout << min << endl;
    }

    return 0;
}