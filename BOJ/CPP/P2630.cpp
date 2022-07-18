#include <iostream>
#include <vector>
#define endl '\n'
typedef long long ll;
using namespace std;
int n;
vector<int> answer(3, 0);

// all white = 0, all blue = 1, mixed = 2
int check(vector<vector<int>>& vec, int start_row, int start_col, int length)
{
    int pattern = vec[start_row][start_col];
    for (int i = start_row; i < start_row + length; i++)
    {
        for (int j = start_col; j < start_col + length; j++)
        {
            if (vec[i][j] != pattern)
                return 2;
        }
    }
    return pattern;
}

void divide(vector<vector<int>>& vec, int row, int col, int length)
{
    int check1, check2, check3, check4;
    check1 = check(vec, row, col, length / 2);
    check2 = check(vec, row, col + length / 2, length / 2);
    check3 = check(vec, row + length / 2, col, length / 2);
    check4 = check(vec, row + length / 2, col + length / 2, length / 2);
    if (check1 != 2)
        answer[check1]++;
    else
        divide(vec, row, col, length / 2);

    if (check2 != 2)
        answer[check2]++;
    else
        divide(vec, row, col + length / 2, length / 2);

    if (check3 != 2)
        answer[check3]++;
    else
        divide(vec, row + length / 2, col, length / 2);

    if (check4 != 2)
        answer[check4]++;
    else
        divide(vec, row + length / 2, col + length / 2, length / 2);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }
    int checkall = check(vec, 0, 0, n);
    if (checkall != 2)
    {
        answer[checkall]++;
        cout << answer[0] << endl << answer[1] << endl;
        exit(0);
    }

    divide(vec, 0, 0, n);
    cout << answer[0] << endl << answer[1] << endl;
    return 0;
}

