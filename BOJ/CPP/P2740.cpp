#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int r, c; cin >> r >> c;
    vector<vector<int>> vec1(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> vec1[i][j];
        }
    }

    int r2, c2;
    cin >> r2 >> c2;
    vector<vector<int>> vec2(r2, vector<int>(c2));
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cin >> vec2[i][j];
        }
    }

    vector<vector<int>> vec3(r, vector<int>(c2));
    for (int i = 0; i < r; i++) // 행 피벗
    {
        for (int j = 0; j < c2; j++) // 열 피벗
        {
            vec3[i][j] = 0;
            for (int k = 0; k < r2; k++)
            {
                vec3[i][j] += (vec1[i][k] * vec2[k][j]);
            }
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << vec3[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}