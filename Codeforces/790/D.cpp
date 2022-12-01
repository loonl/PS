#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
int n, m;

int calc(vector<vector<int>> map, int bsr, int bsc);
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int tc; cin >> tc;
    while (tc--)
    {
        cin >> n >> m; // chess board size
        vector<vector<int>> map(n + 1, vector<int>(m + 1, 0)); // not using index 0
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
            }
        }

        // solv
        int ans = -1;
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= m; j++)
            {
                // locate bishop
                int bsr, bsc;
                bsr = i; bsc = j;

                int profit = calc(map, bsr, bsc);
                if (ans < profit)
                    ans = profit;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

int calc(vector<vector<int>> map, int bsr, int bsc)
{
    int value = 0;
    if (bsr == 1 && bsc == 1)
    {
        int r = 1; int c = 1;
        while (r <= n && c <= m)
        {
            value += map[r][c];
            r++; c++;
        }
    }
    else if (bsr == 1 && bsc == m)
    {
        int r = 1; int c = m;
        while (r <= n && c >= 1)
        {
            value += map[r][c];
            r++; c--;
        }
    }

    else if (bsr == n && bsc == 1)
    {
        int r = n; int c = 1;
        while (r >= 1 && c <= m)
        {
            value += map[r][c];
            r--; c++;
        }
    }

    else if (bsr == n && bsc == m)
    {
        int r = n; int c = m;
        while (r >= 1 && c >= 1)
        {
            value += map[r][c];
            r--; c--;
        }
    }

    else // general
    {
        // 4-ways
        int r = bsr; int c = bsc;
        while (r <= n && c <= m)
        {
            value += map[r][c];
            r++; c++;
        }

        r = bsr + 1; c = bsc - 1;
        while (r <= n && c >= 1)
        {
            value += map[r][c];
            r++; c--;
        }

        r = bsr - 1; c = bsc + 1;
        while (r >= 1 && c <= m)
        {
            value += map[r][c];
            r--; c++;
        }

        r = bsr - 1; c = bsc - 1;
        while (r >= 1 && c >= 1)
        {
            value += map[r][c];
            r--; c--;
        }
    }

    return value;
}