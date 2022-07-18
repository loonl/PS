#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
typedef long long ll;
using namespace std;
int n;
vector<int> answer(3, 0);

// all -1 = -1  all 0 = 0 all 1 = 1 mixed = 2
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
    int one = length / 3; int two = length * 2 / 3;
    vector<pair<int, int>> loc;
    loc.emplace_back(make_pair(row, col));             // 1
    loc.emplace_back(make_pair(row, col + one));       // 2
    loc.emplace_back(make_pair(row, col + two));       // 3
    loc.emplace_back(make_pair(row + one, col));       // 4
    loc.emplace_back(make_pair(row + one, col + one)); // 5
    loc.emplace_back(make_pair(row + one, col + two)); // 6
    loc.emplace_back(make_pair(row + two, col));       // 7
    loc.emplace_back(make_pair(row + two, col + one)); // 8
    loc.emplace_back(make_pair(row + two, col + two)); // 9
    for (int i = 0; i < 9; i++)
    {
        int r = loc[i].first, c = loc[i].second;
        int result = check(vec, r, c, length / 3);
        if (result != 2) 
            answer[vec[r][c] + 1]++;
        else
            divide(vec, r, c, length / 3);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector<vector<int>> vec(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec[i][j];
        }
    }

    if (check(vec, 0, 0, n) != 2)
    {
        answer[vec[0][0] + 1]++;
        cout << answer[0] << endl << answer[1] << endl << answer[2] << endl;
        exit(0);
    }

    divide(vec, 0, 0, n);
    cout << answer[0] << endl << answer[1] << endl << answer[2] << endl;
    return 0;
}

