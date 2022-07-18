#include <iostream>
#include <vector>
#define endl '\n'
#define int long long
using namespace std;
vector<vector<vector<int>>> backup;
vector<int> pows;
int pow(int x, int k)
{
    int m = 1;
    for (int i = 0; i < k; i++)
    {
        m *= x;
    }
    return m;
}

void multi_same(vector<vector<int>>& vec1, vector<vector<int>>& vec2)
{
    backup.emplace_back(vec1);
    pows.emplace_back(pow(2, backup.size() - 1));
    int n = vec1.size();
    for (int i = 0; i < n; i++) // 행 피벗
    {
        for (int j = 0; j < n; j++) // 열 피벗
        {
            vec2[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                vec2[i][j] = (vec1[i][k] * vec1[k][j] + vec2[i][j]) % 1000;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vec1[i][j] = vec2[i][j];
        }
    }
}

void multi_diff(vector<vector<int>>& vec1, vector<vector<int>>& vec2, vector<vector<int>>& vec3)
{
    int n = vec1.size();
    for (int i = 0; i < n; i++) // 행 피벗
    {
        for (int j = 0; j < n; j++) // 열 피벗
        {
            vec3[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                vec3[i][j] = (vec1[i][k] * vec2[k][j] + vec3[i][j]) % 1000;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vec1[i][j] = vec3[i][j];
        }
    }
}

signed main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n, b; cin >> n >> b;
    vector<vector<int>> vec1(n, vector<int>(n));
    vector<vector<int>> orig(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec1[i][j];
            orig[i][j] = vec1[i][j];
        }
    }

    vector<vector<int>> vec2(n, vector<int>(n));
    if (b == 1)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != n - 1)
                    cout << vec1[i][j] % 1000 << " ";
                else
                    cout << vec1[i][j] % 1000;
            }
            cout << endl;
        }
        exit(0);
    }

    int cur = 1;
    while (b / cur != 1) 
    {
        multi_same(vec1, vec2);
        cur *= 2;
    }

    int remain = b - cur;
    while (remain > 0)
    {
        for (int i = pows.size() - 1; i >= 0; i--)
        {
            if (remain / pows[i] == 1)
            {
                remain -= pows[i];
                multi_diff(vec1, backup[i], vec2);
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != n - 1)
                cout << vec2[i][j] << " ";
            else
                cout << vec2[i][j];
        }
        cout << endl;
    }
    return 0;
}