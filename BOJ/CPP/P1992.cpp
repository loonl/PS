#include <iostream>
#include <vector>
#include <string>
#define endl '\n'
typedef long long ll;
using namespace std;
int n;
string result;

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

void compress(vector<vector<int>>& vec, int row, int col, int length)
{
    result += "(";
    int check1, check2, check3, check4;
    check1 = check(vec, row, col, length / 2);
    check2 = check(vec, row, col + length / 2, length / 2);
    check3 = check(vec, row + length / 2, col, length / 2);
    check4 = check(vec, row + length / 2, col + length / 2, length / 2);

    // to next recur
    if (check1 != 2)
        result += to_string(check1);
    else
        compress(vec, row, col, length / 2);
    
    if (check2 != 2)
        result += to_string(check2);
    else
        compress(vec, row, col + length / 2, length / 2);

    if (check3 != 2)
        result += to_string(check3);
    else
        compress(vec, row + length / 2, col, length / 2);

    if (check4 != 2)
        result += to_string(check4);
    else
        compress(vec, row + length / 2, col + length / 2, length / 2);
    result += ")";
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n; result = "";
    vector<vector<int>> vec(n, vector<int>(n, 0));
    char temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            vec[i][j] = (int)temp - (int)'0';
        }
    }
    int checkall = check(vec, 0, 0, n);
    if (checkall != 2)
    {
        cout << checkall << endl;
        exit(0);
    }

    compress(vec, 0, 0, n);
    cout << result << endl;
    return 0;
}

